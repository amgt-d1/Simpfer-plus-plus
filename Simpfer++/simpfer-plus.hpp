#include "simpfer-plus_index.hpp"


// main operation
void online_processing(const data &query_item)
{
    unsigned int r_count = 0;

    start = std::chrono::system_clock::now();

    // norm computation & matrix
    float norm = 0;
    Eigen::MatrixXf Q(1,dimensionality);
    for (unsigned int i = 0; i < dimensionality; ++i)
    {
        norm += query_item.vec[i] * query_item.vec[i];
        Q(0,i) = query_item.vec[i];
    }
    norm = sqrt(norm);

    #pragma omp parallel num_threads(thread_num)
	{
		#pragma omp for schedule(dynamic) reduction(+:ip_count)
        for (unsigned int i = 0; i < block_set.size(); ++i)
        {
            // compute upper-bound in this block
            float upperbound = block_set[i].member[0]->norm * norm;

            // block-level filtering
            if (upperbound > block_set[i].lowerbound_array[k-1])
            {
                Eigen::MatrixXf I = block_set[i].M * Q.transpose();
                ip_count += block_set[i].member.size();

                for (unsigned int j = 0; j < block_set[i].member.size() - 1; ++j)
                {
                    if (I(j) >= block_set[i].member[j]->lowerbound_array[k-1]) ++r_count;
                }
            }
        }
    }


    end = std::chrono::system_clock::now();
	double time_ = (double)std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	time_online_processing += time_;

    block_access = 1.0 - block_access / block_set.size();
    block_access_vec.push_back(block_access);
    block_access = 0;
    result_count += (double)r_count;
}
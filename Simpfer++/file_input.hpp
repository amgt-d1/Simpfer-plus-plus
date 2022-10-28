#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <time.h>


// dataset identifier
unsigned int dataset_id = 0;

// data dimensionality
unsigned int dimensionality = 50;

// dataset sampling rate
float sampling_rate = 1.0;
float sampling_rate_user = 1.0;

// k_max
const unsigned int k_max = 25;

// top-k
unsigned int k = 0;

// #threads
unsigned int thread_num = 0;

// approx factor
float c = 1.0;


// get current time
void get_current_time()
{
	time_t t = time(NULL);
	printf(" %s\n", ctime(&t));
}

// parameter input
void input_parameter()
{
	std::ifstream ifs_dataset_id("parameter/dataset_id.txt");
	std::ifstream ifs_k("parameter/k.txt");
	std::ifstream ifs_thread("parameter/thread_num.txt");

	if (ifs_dataset_id.fail())
	{
		std::cout << " dataset_id.txt does not exist." << std::endl;
		std::exit(0);
	}
	if (ifs_k.fail())
	{
		std::cout << " k.txt does not exist." << std::endl;
		std::exit(0);
	}
	if (ifs_thread.fail())
	{
		std::cout << " thread_num.txt does not exist." << std::endl;
		std::exit(0);
	}

	while (!ifs_dataset_id.eof()) { ifs_dataset_id >> dataset_id; }
	while (!ifs_k.eof()) { ifs_k >> k; }
	while (!ifs_thread.eof()) { ifs_thread >> thread_num; }
}
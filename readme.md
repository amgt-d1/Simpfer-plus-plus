## Introduction
* This repository provides an implementation of Simpfer++.
* This is an extended algorithm of [Simpfer](https://github.com/amgt-d1/Simpfer).
* As for the detail about Simpfer++, please read our ACM TWEB paper, [Reverse Maximum Inner Product Search: Formulation, Algorithms, and Analysis](https://dl.acm.org/doi/10.1145/3587215).

## Requirement
* Linux OS (Ubuntu).
   * The others have not been tested.
* `g++ 7.5.0` (or higher version) and `Openmp`.
* [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page)

## How to use
* Parameter configuration can be done via txt files in `parameter` directory.
* Dataset should be stored in `dataset` directory, and this has to locate at `Simpfer++/dataset`..
	* We assign a unique dataset ID for each dataset. You can freely assign it.
	* In `input_matrix()` of `data.hpp`, you can freely write codes for reading your dataset.
* Computation time will be stored in `result` directory.
* Compile: `g++ -O3 -o simpfer-plus.out main.cpp -std=c++14 -fopenmp`
* Run: `./simpfer-plus.out`


## Citation
If you use our implementation, please cite the following paper.
``` 
@articles{amagata2022reverse,  
    title={Reverse Maximum Inner Product Search: Formulation, Algorithms, and Analysis},  
    author={Amagata, Daichi and Hara, Takahiro},
    journal={ACM Transactions on the Web},
    volume={17},
    number={4},
    pages={26:1--26:23},  
    year={2023}  
}
``` 

## License
Copyright (c) 2022 Daichi Amagata  
This software is released under the [MIT license](https://github.com/amgt-d1/Simpfer-plus-plus/blob/main/license.txt).

# Tests
The test module for this library has two tests :-

#### unit_tests.cpp
This file contains unit tests for the different operations, constructors and functions. It is written using the Boost unit test framework. More information on the test framework can be found [here](http://www.boost.org/doc/libs/1_53_0/libs/test/doc/html/utf.html).

#### performance_tests.cpp
This file contains test to benchmark the time taken in all the operations +,*,+=,*=. It has the following MACROS that can be edited to run the performance tests :-
* MATRIX_ROW - The number of rows of the generated matrix for tests.
* MATRIX_COL - The number of colummns of the generated matrix for tests.
* ITERATION_COUNT - The number of times each operation is carried out before taking the average.

The tests use uniformly distributed random numbers to generate 4 Matrices for every type (integer, floating_point,complex) and perform all the operations (+,*,+=,*=). This process is repeated ITERATION_COUNT times and the average is taken to benchmark the results. All of this is done in a templated function named printRuntime() for each datatype.




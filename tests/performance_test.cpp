#include "../includes/matrix.hpp"
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/uniform_real_distribution.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <complex>
#include <chrono>
#include <type_traits>
#include <cstdlib>


// Macro to control matrix dimensions 
// and iterations for performance tests

#define MATRIX_ROW 4		
#define MATRIX_COL 4
#define ITERATION_COUNT 5000

/* Helper class to extract
 * nested type from template
 */

template <typename T>
struct extractType;

template <template <typename ...> class C, typename D>
struct extractType<C<D>>
{ using subType = D; };


/* Function templates to generate
 * random numbers of integer, float
 * and complex data types
 */


// Function returns a random integer (int, unsigned int, long long, unsigned long long)
template<typename T>
T getRandom(boost::random::mt19937& gen, typename std::enable_if<std::is_integral<T>::value, T>::type =0)
{
	static boost::random::uniform_int_distribution<T> dist;
	return dist(gen);
}

// Function returns a random floating point number (flaot, double, long double)
template<typename T>
T getRandom(boost::random::mt19937& gen, typename std::enable_if<std::is_floating_point<T>::value, T>::type =0)
{
	static boost::random::uniform_real_distribution<T> dist;
	return dist(gen);
}

// Function returns a random complex number both real and floating point
template<typename T>
T getRandom(boost::random::mt19937& gen, typename std::enable_if<std::is_same<T, std::complex<typename extractType<T>::subType>>::value, T>::type = 0)
{
	typename extractType<T>::subType real = getRandom<typename extractType<T>::subType>(gen);
	typename extractType<T>::subType imag = getRandom<typename extractType<T>::subType>(gen);

	return T(real,imag);
 
}


/*
 * Function to benchmark runtime of matrix
 * library for a given datatype T.
 *
 * It performs ITERATION_COUNT number of iterations
 * on randomly generated matrices of type T for 
 * operations +,*,+=,*= and generates the average
 * runtime for each of the operations
 */

template <typename T>
void printRuntime(int nr, int nc)
{
	
	typedef std::chrono::high_resolution_clock::time_point time;

	std::cout<<"Performaing operations on 4 Random Matrices"<<std::endl;
	
	// mersenne twister for random number generation
	boost::random::mt19937 gen(std::time(0));

	double addResSum = 0;
	double mulResSum = 0;
	double addEquSum = 0;
	double mulEquSum = 0;

	// Creating 4 matrices 
	std::vector<Lib::Matrix<T> > mat(4,Lib::Matrix<T>(nr,nc));

	// Mtrices to store results of operation
	Lib::Matrix<T> addRes(nr,nc);
	Lib::Matrix<T> mulRes(nr,nc);

	time t1,t2;

	// Doing ITERATION_COUNT number of iterations

	for(int it = 0; it < ITERATION_COUNT; it++)
	{
		// Populating matrices with random values

		for(int i=0;i< 4;i++)
			for(int r=0; r< nr; r++)
				for(int c=0; c< nc; c++)
					mat[i][r][c] = getRandom<T>(gen);


		// + operation on matrices
	 	t1 = std::chrono::high_resolution_clock::now();
		addRes = mat[0] + mat[1] + mat[2] + mat[3];
		t2 = std::chrono::high_resolution_clock::now();
		addResSum += std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();
	
		// * opeation on matrices
		t1 = std::chrono::high_resolution_clock::now();
		mulRes = mat[0] * mat[1] * mat[2] * mat[3];
		t2 = std::chrono::high_resolution_clock::now();
		mulResSum += std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();

		// += operation on matrices
		t1 = std::chrono::high_resolution_clock::now();
		addRes += mat[0];
		t2 = std::chrono::high_resolution_clock::now();
		addEquSum += std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();

		// *= operation on matrices
		t1 = std::chrono::high_resolution_clock::now();
		mulRes *= mat[0];
		t2 = std::chrono::high_resolution_clock::now();
		mulEquSum += std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();

	}

	// Calculating and logging the benchmark for all operations
	std::cout<<"Runtime from "<< ITERATION_COUNT<<" iterations: \n"
			 <<"Operation +  :"<< addResSum/ITERATION_COUNT <<" microseconds\n"
			 <<"Operation *  :"<< mulResSum/ITERATION_COUNT <<" microseconds\n"
			 <<"Operation += :"<< addEquSum/ITERATION_COUNT <<" microseconds\n"
			 <<"Operation *= :"<< mulEquSum/ITERATION_COUNT <<" microseconds\n"
			 <<"\n**************************************************\n";
		
	
}
	
int main()
{

	// integer types

	std::cout<<"\nMeasuring performance for <int>\n";
	printRuntime<int> (4,4);

	std::cout<<"\nMeasuring performance for <unsigned int>\n";
	printRuntime<unsigned int> (4,4);
	
	std::cout<<"\nMeasuring performance for <long long int>\n";
	printRuntime<long long int> (4,4);

	std::cout<<"\nMeasuring performance for <unsigned long long int>\n";
	printRuntime<unsigned long long int> (4,4);


	// floating points
	
	std::cout<<"\nMeasuring performance for <float>\n";
	printRuntime<float> (4,4);

	std::cout<<"\nMeasuring performance for <double>\n";
	printRuntime<double> (4,4);

	std::cout<<"\nMeasuring performance for <long double>\n";
	printRuntime<long double> (4,4);


	// complex numbers
	
	std::cout<<"\nMeasuring performance for complex<int>\n";
	printRuntime<std::complex<int> > (4,4);

	std::cout<<"\nMeasuring performance for complex<unsigned int>\n";
	printRuntime<std::complex<unsigned int> > (4,4);

	std::cout<<"\nMeasuring performance for complex<long long int>\n";
	printRuntime<std::complex<long long int> > (4,4);

	std::cout<<"\nMeasuring performance for complex<unsigned long long int>\n";
	printRuntime<std::complex<unsigned long long int> > (4,4);

	std::cout<<"\nMeasuring performance for complex<float>\n";
	printRuntime<std::complex<float> > (4,4);

	std::cout<<"\nMeasuring performance for complex<double>\n";
	printRuntime<std::complex<double> > (4,4);

	std::cout<<"\nMeasuring performance for complex<long double>\n";
	printRuntime<std::complex<long double> > (4,4);


	return 0;
	
}

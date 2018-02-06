#include "../includes/matrix.hpp"

// Matrix class exist in namespace Lib
using namespace Lib;
using namespace std;


int main()
{

	// Default construction 0x0 matrix
	Matrix<int> m1();

	// A 3x7 matrix with every value 0 is initialised
	Matrix<int> m2(3,7);

	// A 4x5 matrix with every value 200 is initiaised
	Matrix<int> m3(4,5,200);

	/*
	*	Now you can do anything
	*	with these matrices
	*	|	|
	*	|	|
	*	|	|
	*	|	|
	*	 End
	*/
	return 0;

}
#include "../includes/matrix.hpp"

// Matrix class exist in namespace Lib
using namespace Lib;
using namespace std;


int main()
{


	// 2x2 matrix with default value 10
	Matrix<int> m1(2,2, 10);

	// 2x2 matrix with default value 15
	Matrix<int> m2(2,2, 15);

	// 2x2 matrix with default value 0
	Matrix<int> m3(2,2);

	// Multiplying two matrices
	m3 = m1 * m2;
	// printng result
	cout<<"m3 = \n";
	m3.print();

	// Multiplying three matrices using *=
	Matrix<int> m4(2,2,1);
	m4 *= m1 * m2 * m3;
	// printing result
	cout<<"m4 = \n";
	m4.print();

	
	return 0;

}

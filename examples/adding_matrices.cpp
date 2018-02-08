#include "../includes/matrix.hpp"

// Matrix class exist in namespace Lib
using namespace Lib;
using namespace std;


int main()
{

	// 2x2 matrix with default value 20
	Matrix<int> m1(2,2, 20);

	// 2x2 matrix with default value 30
	Matrix<int> m2(2,2, 30);

	// 2x2 matrix with default value 0
	Matrix<int> m3(2,2);

	// Adding two matrices
	m3 = m1+m2;
	// printng result
	cout<<"m3 = \n";
	m3.print();

	// Adding three matrices (using +=)
	Matrix<int> m4(2,2);
	m4 += m1 + m2 + m3;

	// printing result
	cout<<"m4 = \n";
	m4.print();

	// Mannual addition of cells
	// using [] operator

	m4[0][0] = m1[0][0] + m2[0][0];
	cout<<"m4 = \n";
	m4.print();


	return 0;

}

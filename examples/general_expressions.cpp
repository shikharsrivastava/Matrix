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

	// Mtrix to store result
	Matrix<int> res(2,2);

	// Any expression can be created
	res = m1 + m2 * ((m3 + m1) * (m2 + m1));

	cout<<"Res = \n";
	res.print();


	
	return 0;

}
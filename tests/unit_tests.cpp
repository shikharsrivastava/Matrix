#define BOOST_TEST_MODULE matrix_lib
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test_framework.hpp>
#include "../includes/matrix.hpp"
#include <iostream>
#include <complex>


BOOST_AUTO_TEST_SUITE(integer_addition_tests)

BOOST_AUTO_TEST_CASE(type_int) {


	Lib::Matrix<int> mat1(3,3);
	Lib::Matrix<int> mat2(3,3);
	Lib::Matrix<int> mat3(3,3);
	Lib::Matrix<int> res(3,3);

	// Test Matrix 1
	mat1[0][0] = -31, mat1[0][1] = 3, mat1[0][2] = -6, 
	mat1[1][0] = -27, mat1[1][1] = -41, mat1[1][2] = -29, 
	mat1[2][0] = 37, mat1[2][1] = -7, mat1[2][2] = 25;

	// Test Matrix 2
	mat2[0][0] = 2, mat2[0][1] = 24, mat2[0][2] = 42, 
	mat2[1][0] = 4, mat2[1][1] = -32, mat2[1][2] = -35, 
	mat2[2][0] = 18, mat2[2][1] = 6, mat2[2][2] = 6;

	// Result Matrix
	mat3[0][0] = -29, mat3[0][1] = 27, mat3[0][2] = 36, 
	mat3[1][0] = -23, mat3[1][1] = -73, mat3[1][2] = -64, 
	mat3[2][0] = 55, mat3[2][1] = -1, mat3[2][2] = 31;


	res = mat1 + mat2;
	
	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);


}

BOOST_AUTO_TEST_CASE(type_unsigned_int) {

	Lib::Matrix<unsigned int> mat1(3,3);
	Lib::Matrix<unsigned int> mat2(3,3);
	Lib::Matrix<unsigned int> mat3(3,3);
	Lib::Matrix<unsigned int> res(3,3);

	// Test Matrix 1
	mat1[0][0] = 28, mat1[0][1] = 20, mat1[0][2] = 48, 
	mat1[1][0] = 16, mat1[1][1] = 32, mat1[1][2] = 16, 
	mat1[2][0] = 36, mat1[2][1] = 10, mat1[2][2] = 12;

	// Test Matrix 2
	mat2[0][0] = 25, mat2[0][1] = 30, mat2[0][2] = 31, 
	mat2[1][0] = 12, mat2[1][1] = 10, mat2[1][2] = 39, 
	mat2[2][0] = 17, mat2[2][1] = 11, mat2[2][2] = 16;

	// Result Matrix
	mat3[0][0] = 53, mat3[0][1] = 50, mat3[0][2] = 79, 
	mat3[1][0] = 28, mat3[1][1] = 42, mat3[1][2] = 55, 
	mat3[2][0] = 53, mat3[2][1] = 21, mat3[2][2] = 28;


	
	res = mat1 + mat2;
	
	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);
}


BOOST_AUTO_TEST_CASE(type_long_long) {

	Lib::Matrix<long long int> mat1(3,3);
	Lib::Matrix<long long int> mat2(3,3);
	Lib::Matrix<long long int> mat3(3,3);
	Lib::Matrix<long long int> res(3,3);

	// Test Matrix 1
	mat1[0][0] = -877186632, mat1[0][1] = 7588840177, mat1[0][2] = 4206899582, 
	mat1[1][0] = 14364615032, mat1[1][1] = 16426047179, mat1[1][2] = -8506483267, 
	mat1[2][0] = 13446719820, mat1[2][1] = 2371266781, mat1[2][2] = 1217452567;

	// Test Matrix 2
	mat2[0][0] = 17096299677, mat2[0][1] = -4413413590, mat2[0][2] = 11506760154, 
	mat2[1][0] = 16472388843, mat2[1][1] = 15790451044, mat2[1][2] = -3202027401, 
	mat2[2][0] = -5633026978, mat2[2][1] = -635396241, mat2[2][2] = 16051633963;

	// Result Matrix
	mat3[0][0] = 16219113045, mat3[0][1] = 3175426587, mat3[0][2] = 15713659736, 
	mat3[1][0] = 30837003875, mat3[1][1] = 32216498223, mat3[1][2] = -11708510668, 
	mat3[2][0] = 7813692842, mat3[2][1] = 1735870540, mat3[2][2] = 17269086530;


	
	res = mat1 + mat2;
	
	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);
}


BOOST_AUTO_TEST_CASE(type_unsigned_long_long) {

	Lib::Matrix<unsigned long long int> mat1(3,3);
	Lib::Matrix<unsigned long long int> mat2(3,3);
	Lib::Matrix<unsigned long long int> mat3(3,3);
	Lib::Matrix<unsigned long long int> res(3,3);

	// Test Matrix 1
	mat1[0][0] = 18302456939, mat1[0][1] = 16765528081, mat1[0][2] = 13949342332, 
	mat1[1][0] = 14452782390, mat1[1][1] = 10630490612, mat1[1][2] = 14992827991, 
	mat1[2][0] = 12376961320, mat1[2][1] = 13639836136, mat1[2][2] = 19069089914;

	// Test Matrix 2
	mat2[0][0] = 15090263222, mat2[0][1] = 16721119076, mat2[0][2] = 17659175052, 
	mat2[1][0] = 15134492524, mat2[1][1] = 17358335704, mat2[1][2] = 11673549574, 
	mat2[2][0] = 12344054149, mat2[2][1] = 17687591843, mat2[2][2] = 14733059349;

	// Result Matrix
	mat3[0][0] = 33392720161, mat3[0][1] = 33486647157, mat3[0][2] = 31608517384, 
	mat3[1][0] = 29587274914, mat3[1][1] = 27988826316, mat3[1][2] = 26666377565, 
	mat3[2][0] = 24721015469, mat3[2][1] = 31327427979, mat3[2][2] = 33802149263;


	
	res = mat1 + mat2;
	
	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);

}

BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(flaoting_point_addition_tests)

BOOST_AUTO_TEST_CASE(type_float) {

	Lib::Matrix<float> mat1(3,3);
	Lib::Matrix<float> mat2(3,3);
	Lib::Matrix<float> mat3(3,3);
	Lib::Matrix<float> res(3,3);

	// Test Matrix 1
	mat1[0][0] = 35.0, mat1[0][1] = 37.0, mat1[0][2] = 35.0, 
	mat1[1][0] = 30.5, mat1[1][1] = 38.0, mat1[1][2] = 36.0, 
	mat1[2][0] = 34.5, mat1[2][1] = 36.5, mat1[2][2] = 36.5;

	// Test Matrix 2
	mat2[0][0] = 35.0, mat2[0][1] = 39.0, mat2[0][2] = 30.5, 
	mat2[1][0] = 32.0, mat2[1][1] = 35.5, mat2[1][2] = 37.5, 
	mat2[2][0] = 36.5, mat2[2][1] = 31.5, mat2[2][2] = 35.0;

	// Result Matrix
	mat3[0][0] = 70.0, mat3[0][1] = 76.0, mat3[0][2] = 65.5, 
	mat3[1][0] = 62.5, mat3[1][1] = 73.5, mat3[1][2] = 73.5, 
	mat3[2][0] = 71.0, mat3[2][1] = 68.0, mat3[2][2] = 71.5;


	
	res = mat1 + mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);
}

BOOST_AUTO_TEST_CASE(type_double) {

	Lib::Matrix<double> mat1(3,3);
	Lib::Matrix<double> mat2(3,3);
	Lib::Matrix<double> mat3(3,3);
	Lib::Matrix<double> res(3,3);


	// Test Matrix 1
	mat1[0][0] = 24.4, mat1[0][1] = 24.0, mat1[0][2] = 24.4, 
	mat1[1][0] = 24.4, mat1[1][1] = 24.0, mat1[1][2] = 24.4, 
	mat1[2][0] = 24.6, mat1[2][1] = 25.0, mat1[2][2] = 24.4;

	// Test Matrix 2
	mat2[0][0] = 24.6, mat2[0][1] = 24.6, mat2[0][2] = 24.0, 
	mat2[1][0] = 25.0, mat2[1][1] = 24.4, mat2[1][2] = 24.8, 
	mat2[2][0] = 25.0, mat2[2][1] = 24.4, mat2[2][2] = 24.6;

	// Result Matrix
	mat3[0][0] = 49.0, mat3[0][1] = 48.6, mat3[0][2] = 48.4, 
	mat3[1][0] = 49.4, mat3[1][1] = 48.4, mat3[1][2] = 49.2, 
	mat3[2][0] = 49.6, mat3[2][1] = 49.4, mat3[2][2] = 49.0;


	
	res = mat1 + mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);
	

}


BOOST_AUTO_TEST_CASE(type_long_double) {

	Lib::Matrix<long double> mat1(3,3);
	Lib::Matrix<long double> mat2(3,3);
	Lib::Matrix<long double> mat3(3,3);
	Lib::Matrix<long double> res(3,3);

	// Test Matrix 1
	mat1[0][0] = 1e20, mat1[0][1] = -18956.0, mat1[0][2] = -15456.0, 
	mat1[1][0] = -28386.0, mat1[1][1] = -23228.0, mat1[1][2] = -4898.0, 
	mat1[2][0] = -13568.0, mat1[2][1] = -21190.0, mat1[2][2] = -16004.0;

	// Test Matrix 2
	mat2[0][0] = 2e20, mat2[0][1] = -18676.0, mat2[0][2] = -8532.0, 
	mat2[1][0] = -16828.0, mat2[1][1] = -5142.0, mat2[1][2] = -21682.0, 
	mat2[2][0] = -27928.0, mat2[2][1] = 1592.0, mat2[2][2] = -12660.0;

	// Result Matrix
	mat3[0][0] = 3e20, mat3[0][1] = -37632.0, mat3[0][2] = -23988.0, 
	mat3[1][0] = -45214.0, mat3[1][1] = -28370.0, mat3[1][2] = -26580.0, 
	mat3[2][0] = -41496.0, mat3[2][1] = -19598.0, mat3[2][2] = -28664.0;


	
	res = mat1 + mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);
}


BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE(complex_addition_tests)

BOOST_AUTO_TEST_CASE(type_complex_int) {

	Lib::Matrix<std::complex<int>> mat1(3,3);
	Lib::Matrix<std::complex<int>> mat2(3,3);
	Lib::Matrix<std::complex<int>> mat3(3,3);
	Lib::Matrix<std::complex<int>> res(3,3);

	// Test Matrix 1
	mat1[0][0] = std::complex<int>(4, 5), mat1[0][1] = std::complex<int>(-1, -9), mat1[0][2] = std::complex<int>(1, 0), 
	mat1[1][0] = std::complex<int>(-4, 2), mat1[1][1] = std::complex<int>(-7, 9), mat1[1][2] = std::complex<int>(-7, 5), 
	mat1[2][0] = std::complex<int>(10, 0), mat1[2][1] = std::complex<int>(6, -6), mat1[2][2] = std::complex<int>(10, 0);

	// Test Matrix 2
	mat2[0][0] = std::complex<int>(-9, 4), mat2[0][1] = std::complex<int>(-10, -5), mat2[0][2] = std::complex<int>(-8, -9), 
	mat2[1][0] = std::complex<int>(9, 1), mat2[1][1] = std::complex<int>(4, 0), mat2[1][2] = std::complex<int>(3, 8), 
	mat2[2][0] = std::complex<int>(10, -1), mat2[2][1] = std::complex<int>(3, -2), mat2[2][2] = std::complex<int>(-1, -9);

	// Result Matrix
	mat3[0][0] = std::complex<int>(-5, 9), mat3[0][1] = std::complex<int>(-11, -14), mat3[0][2] = std::complex<int>(-7, -9), 
	mat3[1][0] = std::complex<int>(5, 3), mat3[1][1] = std::complex<int>(-3, 9), mat3[1][2] = std::complex<int>(-4, 13), 
	mat3[2][0] = std::complex<int>(20, -1), mat3[2][1] = std::complex<int>(9, -8), mat3[2][2] = std::complex<int>(9, -9);


	
	res = mat1 + mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);

}

BOOST_AUTO_TEST_CASE(type_complex_unsigned_int) {

	Lib::Matrix<std::complex<unsigned int>> mat1(3,3);
	Lib::Matrix<std::complex<unsigned int>> mat2(3,3);
	Lib::Matrix<std::complex<unsigned int>> mat3(3,3);
	Lib::Matrix<std::complex<unsigned int>> res(3,3);

	// Test Matrix 1
	mat1[0][0] = std::complex<unsigned int>(14, 14), mat1[0][1] = std::complex<unsigned int>(12, 18), mat1[0][2] = std::complex<unsigned int>(13, 19), 
	mat1[1][0] = std::complex<unsigned int>(15, 16), mat1[1][1] = std::complex<unsigned int>(20, 16), mat1[1][2] = std::complex<unsigned int>(15, 10), 
	mat1[2][0] = std::complex<unsigned int>(18, 13), mat1[2][1] = std::complex<unsigned int>(14, 13), mat1[2][2] = std::complex<unsigned int>(18, 13);

	// Test Matrix 2
	mat2[0][0] = std::complex<unsigned int>(20, 18), mat2[0][1] = std::complex<unsigned int>(13, 13), mat2[0][2] = std::complex<unsigned int>(19, 17), 
	mat2[1][0] = std::complex<unsigned int>(20, 18), mat2[1][1] = std::complex<unsigned int>(13, 11), mat2[1][2] = std::complex<unsigned int>(17, 16), 
	mat2[2][0] = std::complex<unsigned int>(10, 10), mat2[2][1] = std::complex<unsigned int>(16, 10), mat2[2][2] = std::complex<unsigned int>(11, 16);

	// Result Matrix
	mat3[0][0] = std::complex<unsigned int>(34, 32), mat3[0][1] = std::complex<unsigned int>(25, 31), mat3[0][2] = std::complex<unsigned int>(32, 36), 
	mat3[1][0] = std::complex<unsigned int>(35, 34), mat3[1][1] = std::complex<unsigned int>(33, 27), mat3[1][2] = std::complex<unsigned int>(32, 26), 
	mat3[2][0] = std::complex<unsigned int>(28, 23), mat3[2][1] = std::complex<unsigned int>(30, 23), mat3[2][2] = std::complex<unsigned int>(29, 29);


	
	res = mat1 + mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);


}


BOOST_AUTO_TEST_CASE(type_complex_long_long) {

	Lib::Matrix<std::complex<long long int>> mat1(3,3);
	Lib::Matrix<std::complex<long long int>> mat2(3,3);
	Lib::Matrix<std::complex<long long int>> mat3(3,3);
	Lib::Matrix<std::complex<long long int>> res(3,3);

	// Test Matrix 1
	mat1[0][0] = std::complex<long long int>(-6749602741, 4292949747), mat1[0][1] = std::complex<long long int>(9030790534, -9866157492), mat1[0][2] = std::complex<long long int>(1451468991, -9514940662), 
	mat1[1][0] = std::complex<long long int>(1495398305, -913849268), mat1[1][1] = std::complex<long long int>(-9406883268, 2742527750), mat1[1][2] = std::complex<long long int>(6337208242, -1371406692), 
	mat1[2][0] = std::complex<long long int>(5986995022, -7066129263), mat1[2][1] = std::complex<long long int>(-3008894921, -8289652898), mat1[2][2] = std::complex<long long int>(7810258372, -8821106904);

	// Test Matrix 2
	mat2[0][0] = std::complex<long long int>(-5462044018, -82320519), mat2[0][1] = std::complex<long long int>(-9204804124, -4281597946), mat2[0][2] = std::complex<long long int>(9706253743, 8684209902), 
	mat2[1][0] = std::complex<long long int>(9927455464, -6971174240), mat2[1][1] = std::complex<long long int>(2652695825, 9650688313), mat2[1][2] = std::complex<long long int>(-7966776861, -1973242621), 
	mat2[2][0] = std::complex<long long int>(4527877743, 91125499), mat2[2][1] = std::complex<long long int>(2191354741, -5991516838), mat2[2][2] = std::complex<long long int>(9126601664, -8142766034);

	// Result Matrix
	mat3[0][0] = std::complex<long long int>(-12211646759, 4210629228), mat3[0][1] = std::complex<long long int>(-174013590, -14147755438), mat3[0][2] = std::complex<long long int>(11157722734, -830730760), 
	mat3[1][0] = std::complex<long long int>(11422853769, -7885023508), mat3[1][1] = std::complex<long long int>(-6754187443, 12393216063), mat3[1][2] = std::complex<long long int>(-1629568619, -3344649313), 
	mat3[2][0] = std::complex<long long int>(10514872765, -6975003764), mat3[2][1] = std::complex<long long int>(-817540180, -14281169736), mat3[2][2] = std::complex<long long int>(16936860036, -16963872938);


	
	res = mat1 + mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);


}


BOOST_AUTO_TEST_CASE(type_complex_unsigned_long_long) {

	Lib::Matrix<std::complex<unsigned long long int>> mat1(3,3);
	Lib::Matrix<std::complex<unsigned long long int>> mat2(3,3);
	Lib::Matrix<std::complex<unsigned long long int>> mat3(3,3);
	Lib::Matrix<std::complex<unsigned long long int>> res(3,3);

	// Test Matrix 1
	mat1[0][0] = std::complex<unsigned long long int>(12072802582, 19897077417), mat1[0][1] = std::complex<unsigned long long int>(16740581508, 19302235052), mat1[0][2] = std::complex<unsigned long long int>(16941961520, 18712439410), 
	mat1[1][0] = std::complex<unsigned long long int>(13504173796, 12283611188), mat1[1][1] = std::complex<unsigned long long int>(12352692814, 15038034577), mat1[1][2] = std::complex<unsigned long long int>(19029886135, 11160220228), 
	mat1[2][0] = std::complex<unsigned long long int>(18069656439, 19123908253), mat1[2][1] = std::complex<unsigned long long int>(18770931815, 13888956434), mat1[2][2] = std::complex<unsigned long long int>(16587323084, 12492584620);

	// Test Matrix 2
	mat2[0][0] = std::complex<unsigned long long int>(14242818970, 16316418124), mat2[0][1] = std::complex<unsigned long long int>(16719076632, 17343691885), mat2[0][2] = std::complex<unsigned long long int>(16359014131, 16470260950), 
	mat2[1][0] = std::complex<unsigned long long int>(12422746364, 12403291936), mat2[1][1] = std::complex<unsigned long long int>(17184184785, 17254683334), mat2[1][2] = std::complex<unsigned long long int>(16167272825, 11737537264), 
	mat2[2][0] = std::complex<unsigned long long int>(17817076925, 17857146963), mat2[2][1] = std::complex<unsigned long long int>(13644324715, 19011121191), mat2[2][2] = std::complex<unsigned long long int>(19782097927, 16903553114);

	// Result Matrix
	mat3[0][0] = std::complex<unsigned long long int>(26315621552, 36213495541), mat3[0][1] = std::complex<unsigned long long int>(33459658140, 36645926937), mat3[0][2] = std::complex<unsigned long long int>(33300975651, 35182700360), 
	mat3[1][0] = std::complex<unsigned long long int>(25926920160, 24686903124), mat3[1][1] = std::complex<unsigned long long int>(29536877599, 32292717911), mat3[1][2] = std::complex<unsigned long long int>(35197158960, 22897757492), 
	mat3[2][0] = std::complex<unsigned long long int>(35886733364, 36981055216), mat3[2][1] = std::complex<unsigned long long int>(32415256530, 32900077625), mat3[2][2] = std::complex<unsigned long long int>(36369421011, 29396137734);


	
	res = mat1 + mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);


}


BOOST_AUTO_TEST_CASE(type_complex_float) {

	Lib::Matrix<std::complex<float>> mat1(3,3);
	Lib::Matrix<std::complex<float>> mat2(3,3);
	Lib::Matrix<std::complex<float>> mat3(3,3);
	Lib::Matrix<std::complex<float>> res(3,3);

	// Test Matrix 1
	mat1[0][0] = std::complex<float>(1.0, 4.5), mat1[0][1] = std::complex<float>(10.0, 9.0), mat1[0][2] = std::complex<float>(2.0, 1.0), 
	mat1[1][0] = std::complex<float>(5.5, 8.0), mat1[1][1] = std::complex<float>(10.0, 1.0), mat1[1][2] = std::complex<float>(5.0, 8.0), 
	mat1[2][0] = std::complex<float>(8.0, 9.0), mat1[2][1] = std::complex<float>(7.0, 2.5), mat1[2][2] = std::complex<float>(1.5, 5.0);

	// Test Matrix 2
	mat2[0][0] = std::complex<float>(6.5, 6.5), mat2[0][1] = std::complex<float>(6.0, 2.0), mat2[0][2] = std::complex<float>(7.0, 3.0), 
	mat2[1][0] = std::complex<float>(5.0, 1.5), mat2[1][1] = std::complex<float>(2.0, 9.0), mat2[1][2] = std::complex<float>(1.0, 2.5), 
	mat2[2][0] = std::complex<float>(7.0, 7.0), mat2[2][1] = std::complex<float>(10.0, 3.0), mat2[2][2] = std::complex<float>(7.5, 9.0);

	// Result Matrix
	mat3[0][0] = std::complex<float>(7.5, 11.0), mat3[0][1] = std::complex<float>(16.0, 11.0), mat3[0][2] = std::complex<float>(9.0, 4.0), 
	mat3[1][0] = std::complex<float>(10.5, 9.5), mat3[1][1] = std::complex<float>(12.0, 10.0), mat3[1][2] = std::complex<float>(6.0, 10.5), 
	mat3[2][0] = std::complex<float>(15.0, 16.0), mat3[2][1] = std::complex<float>(17.0, 5.5), mat3[2][2] = std::complex<float>(9.0, 14.0);


	
	res = mat1 + mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);


}

BOOST_AUTO_TEST_CASE(type_complex_double) {

	Lib::Matrix<std::complex<double>> mat1(3,3);
	Lib::Matrix<std::complex<double>> mat2(3,3);
	Lib::Matrix<std::complex<double>> mat3(3,3);
	Lib::Matrix<std::complex<double>> res(3,3);

	// Test Matrix 1
	mat1[0][0] = std::complex<double>(-6.5, -14.75), mat1[0][1] = std::complex<double>(-0.5, 1.75), mat1[0][2] = std::complex<double>(-17.0, -8.75), 
	mat1[1][0] = std::complex<double>(0.25, -11.0), mat1[1][1] = std::complex<double>(-17.75, -0.5), mat1[1][2] = std::complex<double>(-7.25, -2.0), 
	mat1[2][0] = std::complex<double>(-14.75, -13.25), mat1[2][1] = std::complex<double>(2.5, -7.25), mat1[2][2] = std::complex<double>(-7.25, 1.75);

	// Test Matrix 2
	mat2[0][0] = std::complex<double>(-7.25, -13.25), mat2[0][1] = std::complex<double>(-5.75, -4.25), mat2[0][2] = std::complex<double>(-17.75, -7.25), 
	mat2[1][0] = std::complex<double>(-16.25, -13.25), mat2[1][1] = std::complex<double>(-11.75, -12.5), mat2[1][2] = std::complex<double>(-2.75, -18.5), 
	mat2[2][0] = std::complex<double>(-1.25, -17.75), mat2[2][1] = std::complex<double>(-17.0, -9.5), mat2[2][2] = std::complex<double>(-1.25, -2.75);

	// Result Matrix
	mat3[0][0] = std::complex<double>(-13.75, -28.0), mat3[0][1] = std::complex<double>(-6.25, -2.5), mat3[0][2] = std::complex<double>(-34.75, -16.0), 
	mat3[1][0] = std::complex<double>(-16.0, -24.25), mat3[1][1] = std::complex<double>(-29.5, -13.0), mat3[1][2] = std::complex<double>(-10.0, -20.5), 
	mat3[2][0] = std::complex<double>(-16.0, -31.0), mat3[2][1] = std::complex<double>(-14.5, -16.75), mat3[2][2] = std::complex<double>(-8.5, -1.0);


	
	res = mat1 + mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);

}

BOOST_AUTO_TEST_CASE(type_complex_long_double) {

	Lib::Matrix<std::complex<long double>> mat1(3,3);
	Lib::Matrix<std::complex<long double>> mat2(3,3);
	Lib::Matrix<std::complex<long double>> mat3(3,3);
	Lib::Matrix<std::complex<long double>> res(3,3);

	// Test Matrix 1
	mat1[0][0] = std::complex<long double>(123624, 101117), mat1[0][1] = std::complex<long double>(122753, 185958), mat1[0][2] = std::complex<long double>(124782, 156033), 
	mat1[1][0] = std::complex<long double>(123560, 137424), mat1[1][1] = std::complex<long double>(105038, 103731), mat1[1][2] = std::complex<long double>(186230, 116111), 
	mat1[2][0] = std::complex<long double>(119402, 146125), mat1[2][1] = std::complex<long double>(171556, 101844), mat1[2][2] = std::complex<long double>(146701, 149338);

	// Test Matrix 2
	mat2[0][0] = std::complex<long double>(106414, 193497), mat2[0][1] = std::complex<long double>(145293, 100655), mat2[0][2] = std::complex<long double>(127597, 184976), 
	mat2[1][0] = std::complex<long double>(177990, 164854), mat2[1][1] = std::complex<long double>(106493, 111487), mat2[1][2] = std::complex<long double>(159951, 155175), 
	mat2[2][0] = std::complex<long double>(146808, 183016), mat2[2][1] = std::complex<long double>(160409, 107122), mat2[2][2] = std::complex<long double>(196457, 140595);

	// Result Matrix
	mat3[0][0] = std::complex<long double>(230038, 294614), mat3[0][1] = std::complex<long double>(268046, 286613), mat3[0][2] = std::complex<long double>(252379, 341009), 
	mat3[1][0] = std::complex<long double>(301550, 302278), mat3[1][1] = std::complex<long double>(211531, 215218), mat3[1][2] = std::complex<long double>(346181, 271286), 
	mat3[2][0] = std::complex<long double>(266210, 329141), mat3[2][1] = std::complex<long double>(331965, 208966), mat3[2][2] = std::complex<long double>(343158, 289933);


	
	res = mat1 + mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);
}


BOOST_AUTO_TEST_SUITE_END()

/* Test suite for matrix multiplication
 * multiplying 3x3 matrices
 */

BOOST_AUTO_TEST_SUITE(integer_multiplication_tests)

BOOST_AUTO_TEST_CASE(type_int) {


	Lib::Matrix<int> mat1(3,3);
	Lib::Matrix<int> mat2(3,3);
	Lib::Matrix<int> mat3(3,3);
	Lib::Matrix<int> res(3,3);

	// Test Matrix 1
	mat1[0][0] = 31, mat1[0][1] = 41, mat1[0][2] = -3, 
	mat1[1][0] = 14, mat1[1][1] = -6, mat1[1][2] = -30, 
	mat1[2][0] = 33, mat1[2][1] = 22, mat1[2][2] = -23;

	// Test Matrix 2
	mat2[0][0] = -35, mat2[0][1] = 46, mat2[0][2] = 35, 
	mat2[1][0] = 45, mat2[1][1] = -8, mat2[1][2] = 18, 
	mat2[2][0] = -10, mat2[2][1] = 46, mat2[2][2] = 25;

	// Result Matrix
	mat3[0][0] = 790, mat3[0][1] = 960, mat3[0][2] = 1748, 
	mat3[1][0] = -460, mat3[1][1] = -688, mat3[1][2] = -368, 
	mat3[2][0] = 65, mat3[2][1] = 284, mat3[2][2] = 976;


	
	res = mat1 * mat2;
	
	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);


}

BOOST_AUTO_TEST_CASE(type_unsigned_int) {

	Lib::Matrix<unsigned int> mat1(3,3);
	Lib::Matrix<unsigned int> mat2(3,3);
	Lib::Matrix<unsigned int> mat3(3,3);
	Lib::Matrix<unsigned int> res(3,3);

	// Test Matrix 1
	mat1[0][0] = 30, mat1[0][1] = 40, mat1[0][2] = 37, 
	mat1[1][0] = 43, mat1[1][1] = 44, mat1[1][2] = 42, 
	mat1[2][0] = 28, mat1[2][1] = 28, mat1[2][2] = 49;

	// Test Matrix 2
	mat2[0][0] = 22, mat2[0][1] = 17, mat2[0][2] = 36, 
	mat2[1][0] = 41, mat2[1][1] = 27, mat2[1][2] = 48, 
	mat2[2][0] = 20, mat2[2][1] = 33, mat2[2][2] = 30;

	// Result Matrix
	mat3[0][0] = 3040, mat3[0][1] = 2811, mat3[0][2] = 4110, 
	mat3[1][0] = 3590, mat3[1][1] = 3305, mat3[1][2] = 4920, 
	mat3[2][0] = 2744, mat3[2][1] = 2849, mat3[2][2] = 3822;


	
	res = mat1 * mat2;

	
	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);
}


BOOST_AUTO_TEST_CASE(type_long_long) {

	Lib::Matrix<long long int> mat1(3,3);
	Lib::Matrix<long long int> mat2(3,3);
	Lib::Matrix<long long int> mat3(3,3);
	Lib::Matrix<long long int> res(3,3);

	// Test Matrix 1
	mat1[0][0] = 1161, mat1[0][1] = -486, mat1[0][2] = -508, 
	mat1[1][0] = -116, mat1[1][1] = -834, mat1[1][2] = 1696, 
	mat1[2][0] = 127, mat1[2][1] = 78, mat1[2][2] = -386;

	// Test Matrix 2
	mat2[0][0] = 145, mat2[0][1] = 1584, mat2[0][2] = 566, 
	mat2[1][0] = -200, mat2[1][1] = 1545, mat2[1][2] = 1488, 
	mat2[2][0] = 1928, mat2[2][1] = 491, mat2[2][2] = 777;

	// Result Matrix
	mat3[0][0] = -713879, mat3[0][1] = 838726, mat3[0][2] = -460758, 
	mat3[1][0] = 3419868, mat3[1][1] = -639538, mat3[1][2] = 11144, 
	mat3[2][0] = -741393, mat3[2][1] = 132152, mat3[2][2] = -111976;


	
	res = mat1 * mat2;
	
	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);
}


BOOST_AUTO_TEST_CASE(type_unsigned_long_long) {

	Lib::Matrix<unsigned long long int> mat1(3,3);
	Lib::Matrix<unsigned long long int> mat2(3,3);
	Lib::Matrix<unsigned long long int> mat3(3,3);
	Lib::Matrix<unsigned long long int> res(3,3);

	// Test Matrix 1
	mat1[0][0] = 1382, mat1[0][1] = 1796, mat1[0][2] = 1881, 
	mat1[1][0] = 1899, mat1[1][1] = 1410, mat1[1][2] = 1554, 
	mat1[2][0] = 1777, mat1[2][1] = 1483, mat1[2][2] = 1957;

	// Test Matrix 2
	mat2[0][0] = 1946, mat2[0][1] = 1327, mat2[0][2] = 1585, 
	mat2[1][0] = 1922, mat2[1][1] = 1392, mat2[1][2] = 1060, 
	mat2[2][0] = 1907, mat2[2][1] = 1525, mat2[2][2] = 1869;

	// Result Matrix
	mat3[0][0] = 9728351, mat3[0][1] = 7202471, mat3[0][2] = 7609819, 
	mat3[1][0] = 9368952, mat3[1][1] = 6852543, mat3[1][2] = 7408941, 
	mat3[2][0] = 10040367, mat3[2][1] = 7406840, mat3[2][2] = 8046158;


	
	res = mat1 * mat2;
	
	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);

}


BOOST_AUTO_TEST_SUITE_END()

	
BOOST_AUTO_TEST_SUITE(floating_point_multiplication_tests)

BOOST_AUTO_TEST_CASE(type_float) {

	Lib::Matrix<float> mat1(3,3);
	Lib::Matrix<float> mat2(3,3);
	Lib::Matrix<float> mat3(3,3);
	Lib::Matrix<float> res(3,3);

	// Test Matrix 1
	mat1[0][0] = -20.0, mat1[0][1] = -28.0, mat1[0][2] = 2.0, 
	mat1[1][0] = -16.0, mat1[1][1] = -18.0, mat1[1][2] = 2.0, 
	mat1[2][0] = 8.0, mat1[2][1] = -4.0, mat1[2][2] = -24.0;

	// Test Matrix 2
	mat2[0][0] = 6.0, mat2[0][1] = 6.0, mat2[0][2] = 0.0, 
	mat2[1][0] = -28.0, mat2[1][1] = -30.0, mat2[1][2] = 6.0, 
	mat2[2][0] = -14.0, mat2[2][1] = -20.0, mat2[2][2] = 10.0;

	// Result Matrix
	mat3[0][0] = 636.0, mat3[0][1] = 680.0, mat3[0][2] = -148.0, 
	mat3[1][0] = 380.0, mat3[1][1] = 404.0, mat3[1][2] = -88.0, 
	mat3[2][0] = 496.0, mat3[2][1] = 648.0, mat3[2][2] = -264.0;


	
	res = mat1 * mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);
}

BOOST_AUTO_TEST_CASE(type_double) {

	Lib::Matrix<double> mat1(3,3);
	Lib::Matrix<double> mat2(3,3);
	Lib::Matrix<double> mat3(3,3);
	Lib::Matrix<double> res(3,3);


	// Test Matrix 1
	mat1[0][0] = 6.0, mat1[0][1] = -194.0, mat1[0][2] = 80.0, 
	mat1[1][0] = -2.0, mat1[1][1] = 100.0, mat1[1][2] = -182.0, 
	mat1[2][0] = -156.0, mat1[2][1] = -6.0, mat1[2][2] = -288.0;

	// Test Matrix 2
	mat2[0][0] = -230.0, mat2[0][1] = 86.0, mat2[0][2] = -74.0, 
	mat2[1][0] = -228.0, mat2[1][1] = -274.0, mat2[1][2] = -284.0, 
	mat2[2][0] = -274.0, mat2[2][1] = -190.0, mat2[2][2] = -22.0;

	// Result Matrix
	mat3[0][0] = 20932.0, mat3[0][1] = 38472.0, mat3[0][2] = 52892.0, 
	mat3[1][0] = 27528.0, mat3[1][1] = 7008.0, mat3[1][2] = -24248.0, 
	mat3[2][0] = 116160.0, mat3[2][1] = 42948.0, mat3[2][2] = 19584.0;


	
	res = mat1 * mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);
	

}


BOOST_AUTO_TEST_CASE(type_long_double) {

	Lib::Matrix<long double> mat1(3,3);
	Lib::Matrix<long double> mat2(3,3);
	Lib::Matrix<long double> mat3(3,3);
	Lib::Matrix<long double> res(3,3);

	// Test Matrix 1
	mat1[0][0] = -22124.0, mat1[0][1] = -26864.0, mat1[0][2] = -19844.0, 
	mat1[1][0] = -19372.0, mat1[1][1] = -1196.0, mat1[1][2] = -21082.0, 
	mat1[2][0] = -3084.0, mat1[2][1] = -5168.0, mat1[2][2] = -24636.0;

	// Test Matrix 2
	mat2[0][0] = -26602.0, mat2[0][1] = -27360.0, mat2[0][2] = -7296.0, 
	mat2[1][0] = -13018.0, mat2[1][1] = -16616.0, mat2[1][2] = -23332.0, 
	mat2[2][0] = 7574.0, mat2[2][1] = -17112.0, mat2[2][2] = -14206.0;

	// Result Matrix
	mat3[0][0] = 787959744.0, mat3[0][1] = 1391255392.0, mat3[0][2] = 1070111416.0, 
	mat3[1][0] = 371228404.0, mat3[1][1] = 910645840.0, mat3[1][2] = 468734076.0, 
	mat3[2][0] = -37275472.0, mat3[2][1] = 591820960.0, mat3[2][2] = 493059656.0;


	
	res = mat1 * mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);
}


BOOST_AUTO_TEST_SUITE_END()

	
BOOST_AUTO_TEST_SUITE(complex_multiplication_tests)

BOOST_AUTO_TEST_CASE(type_complex_int) {

	Lib::Matrix<std::complex<int>> mat1(3,3);
	Lib::Matrix<std::complex<int>> mat2(3,3);
	Lib::Matrix<std::complex<int>> mat3(3,3);
	Lib::Matrix<std::complex<int>> res(3,3);

	// Test Matrix 1
	mat1[0][0] = std::complex<int>(12, 16), mat1[0][1] = std::complex<int>(7, -14), mat1[0][2] = std::complex<int>(-18, -1), 
	mat1[1][0] = std::complex<int>(1, -10), mat1[1][1] = std::complex<int>(-5, -2), mat1[1][2] = std::complex<int>(-14, -20), 
	mat1[2][0] = std::complex<int>(-19, -16), mat1[2][1] = std::complex<int>(-16, -2), mat1[2][2] = std::complex<int>(18, -2);

	// Test Matrix 2
	mat2[0][0] = std::complex<int>(-12, 8), mat2[0][1] = std::complex<int>(-12, -12), mat2[0][2] = std::complex<int>(13, -8), 
	mat2[1][0] = std::complex<int>(-9, -9), mat2[1][1] = std::complex<int>(-20, 3), mat2[1][2] = std::complex<int>(10, 16), 
	mat2[2][0] = std::complex<int>(-13, -13), mat2[2][1] = std::complex<int>(14, 14), mat2[2][2] = std::complex<int>(14, 9);

	// Result Matrix
	mat3[0][0] = std::complex<int>(-240, 214), mat3[0][1] = std::complex<int>(-288, -301), mat3[0][2] = std::complex<int>(335, -92), 
	mat3[1][0] = std::complex<int>(17, 633), mat3[1][1] = std::complex<int>(58, -343), mat3[1][2] = std::complex<int>(-101, -644), 
	mat3[2][0] = std::complex<int>(222, -6), mat3[2][1] = std::complex<int>(642, 636), mat3[2][2] = std::complex<int>(-233, -198);

	
	res = mat1 * mat2;


	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);

}



BOOST_AUTO_TEST_CASE(type_complex_long_long) {

	Lib::Matrix<std::complex<long long int>> mat1(3,3);
	Lib::Matrix<std::complex<long long int>> mat2(3,3);
	Lib::Matrix<std::complex<long long int>> mat3(3,3);
	Lib::Matrix<std::complex<long long int>> res(3,3);

	// Test Matrix 1
	mat1[0][0] = std::complex<long long int>(580, 191), mat1[0][1] = std::complex<long long int>(295, 363), mat1[0][2] = std::complex<long long int>(229, 215), 
	mat1[1][0] = std::complex<long long int>(930, 850), mat1[1][1] = std::complex<long long int>(354, 465), mat1[1][2] = std::complex<long long int>(286, 413), 
	mat1[2][0] = std::complex<long long int>(322, 266), mat1[2][1] = std::complex<long long int>(868, 176), mat1[2][2] = std::complex<long long int>(188, 136);

	// Test Matrix 2
	mat2[0][0] = std::complex<long long int>(248, 889), mat2[0][1] = std::complex<long long int>(143, 768), mat2[0][2] = std::complex<long long int>(740, 312), 
	mat2[1][0] = std::complex<long long int>(291, 874), mat2[1][1] = std::complex<long long int>(903, 834), mat2[1][2] = std::complex<long long int>(811, 541), 
	mat2[2][0] = std::complex<long long int>(981, 617), mat2[2][1] = std::complex<long long int>(672, 862), mat2[2][2] = std::complex<long long int>(181, 289);

	// Result Matrix
	mat3[0][0] = std::complex<long long int>(-165382, 1278659), mat3[0][1] = std::complex<long long int>(-131547, 1388450), mat3[0][2] = std::complex<long long int>(391784, 881384), 
	mat3[1][0] = std::complex<long long int>(-802661, 2063896), mat3[1][1] = std::complex<long long int>(-751772, 2074989), mat3[1][2] = std::complex<long long int>(390938, 1645196), 
	mat3[2][0] = std::complex<long long int>(42662, 1411486), mat3[2][1] = std::complex<long long int>(487882, 1421622), mat3[2][2] = std::complex<long long int>(758744, 988576);


	
	res = mat1 * mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);


}



BOOST_AUTO_TEST_CASE(type_complex_float) {

	Lib::Matrix<std::complex<float>> mat1(3,3);
	Lib::Matrix<std::complex<float>> mat2(3,3);
	Lib::Matrix<std::complex<float>> mat3(3,3);
	Lib::Matrix<std::complex<float>> res(3,3);

	// Test Matrix 1
	mat1[0][0] = std::complex<float>(2.5, 4.5), mat1[0][1] = std::complex<float>(4.5, 4.5), mat1[0][2] = std::complex<float>(1.0, 3.0), 
	mat1[1][0] = std::complex<float>(0.5, 0.5), mat1[1][1] = std::complex<float>(5.0, 4.0), mat1[1][2] = std::complex<float>(1.0, 0.5), 
	mat1[2][0] = std::complex<float>(4.5, 3.0), mat1[2][1] = std::complex<float>(5.0, 4.5), mat1[2][2] = std::complex<float>(3.5, 2.5);

	// Test Matrix 2
	mat2[0][0] = std::complex<float>(1.5, 3.5), mat2[0][1] = std::complex<float>(1.5, 0.5), mat2[0][2] = std::complex<float>(4.5, 3.0), 
	mat2[1][0] = std::complex<float>(3.0, 0.5), mat2[1][1] = std::complex<float>(3.5, 3.5), mat2[1][2] = std::complex<float>(4.5, 2.5), 
	mat2[2][0] = std::complex<float>(3.5, 3.5), mat2[2][1] = std::complex<float>(2.0, 1.5), mat2[2][2] = std::complex<float>(3.0, 1.5);

	// Result Matrix
	mat3[0][0] = std::complex<float>(-7.75, 45.25), mat3[0][1] = std::complex<float>(-1.0, 47.0), mat3[0][2] = std::complex<float>(5.25, 69.75), 
	mat3[1][0] = std::complex<float>(13.75, 22.25), mat3[1][1] = std::complex<float>(5.25, 35.0), mat3[1][2] = std::complex<float>(15.5, 37.25), 
	mat3[2][0] = std::complex<float>(12.5, 57.25), mat3[2][1] = std::complex<float>(10.25, 50.25), mat3[2][2] = std::complex<float>(29.25, 72.5);


	
	res = mat1 * mat2;


	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);


}

BOOST_AUTO_TEST_CASE(type_complex_double) {

	Lib::Matrix<std::complex<double>> mat1(3,3);
	Lib::Matrix<std::complex<double>> mat2(3,3);
	Lib::Matrix<std::complex<double>> mat3(3,3);
	Lib::Matrix<std::complex<double>> res(3,3);

	// Test Matrix 1
	mat1[0][0] = std::complex<double>(135.5, 178.0), mat1[0][1] = std::complex<double>(123.5, 167.0), mat1[0][2] = std::complex<double>(146.5, 114.0), 
	mat1[1][0] = std::complex<double>(141.5, 146.0), mat1[1][1] = std::complex<double>(157.5, 197.0), mat1[1][2] = std::complex<double>(116.5, 111.0), 
	mat1[2][0] = std::complex<double>(120.5, 165.0), mat1[2][1] = std::complex<double>(139.5, 183.0), mat1[2][2] = std::complex<double>(144.5, 191.0);

	// Test Matrix 2
	mat2[0][0] = std::complex<double>(125.5, 145.0), mat2[0][1] = std::complex<double>(172.5, 155.0), mat2[0][2] = std::complex<double>(126.5, 164.0), 
	mat2[1][0] = std::complex<double>(176.5, 175.0), mat2[1][1] = std::complex<double>(175.5, 186.0), mat2[1][2] = std::complex<double>(155.5, 149.0), 
	mat2[2][0] = std::complex<double>(130.5, 189.0), mat2[2][1] = std::complex<double>(158.5, 141.0), mat2[2][2] = std::complex<double>(136.5, 179.0);

	// Result Matrix
	mat3[0][0] = std::complex<double>(-18659.75, 135640.0), mat3[0][1] = std::complex<double>(-6457.75, 142712.5), mat3[0][2] = std::complex<double>(-18138.75, 130893.5), 
	mat3[1][0] = std::complex<double>(-15863.75, 137677.5), mat3[1][1] = std::complex<double>(-4407.75, 145006.0), mat3[1][2] = std::complex<double>(-14872.75, 131781.0), 
	mat3[2][0] = std::complex<double>(-33447.25, 147128.0), mat3[2][1] = std::complex<double>(-18372.25, 155851.5), mat3[2][2] = std::complex<double>(-31856.25, 141813.5);


	
	res = mat1 * mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);

}

BOOST_AUTO_TEST_CASE(type_complex_long_double) {

	Lib::Matrix<std::complex<long double>> mat1(3,3);
	Lib::Matrix<std::complex<long double>> mat2(3,3);
	Lib::Matrix<std::complex<long double>> mat3(3,3);
	Lib::Matrix<std::complex<long double>> res(3,3);

	// Test Matrix 1
	mat1[0][0] = std::complex<long double>(1204.5, 1631.0), mat1[0][1] = std::complex<long double>(1637.5, 1099.0), mat1[0][2] = std::complex<long double>(1700.5, 1817.0), 
	mat1[1][0] = std::complex<long double>(1450.5, 1721.0), mat1[1][1] = std::complex<long double>(1594.5, 1470.0), mat1[1][2] = std::complex<long double>(1200.5, 1136.0), 
	mat1[2][0] = std::complex<long double>(1281.5, 1824.0), mat1[2][1] = std::complex<long double>(1139.5, 1920.0), mat1[2][2] = std::complex<long double>(1919.5, 1135.0);

	// Test Matrix 2
	mat2[0][0] = std::complex<long double>(1070.5, 1011.0), mat2[0][1] = std::complex<long double>(1854.5, 1301.0), mat2[0][2] = std::complex<long double>(1888.5, 1326.0), 
	mat2[1][0] = std::complex<long double>(1032.5, 1815.0), mat2[1][1] = std::complex<long double>(1185.5, 1220.0), mat2[1][2] = std::complex<long double>(1947.5, 1610.0), 
	mat2[2][0] = std::complex<long double>(1423.5, 1386.0), mat2[2][1] = std::complex<long double>(1810.5, 1674.0), mat2[2][2] = std::complex<long double>(1659.5, 1010.0);

	// Result Matrix
	mat3[0][0] = std::complex<long double>(-761190.25, 12013907.5), mat3[0][1] = std::complex<long double>(749387.75, 14028674.0), mat3[0][2] = std::complex<long double>(2518443.25, 14186804.5), 
	mat3[1][0] = std::complex<long double>(-1074483.75, 11001567.5), mat3[1][1] = std::complex<long double>(819652.25, 12833035.0), mat3[1][2] = std::complex<long double>(2040681.75, 13701138.5), 
	mat3[2][0] = std::complex<long double>(-1621186.25, 11574880.5), mat3[2][1] = std::complex<long double>(587259.75, 13984350.0), mat3[2][2] = std::complex<long double>(1168525.25, 14539915.5);


	
	res = mat1 * mat2;

	// Checking dimensions of result matrix
	BOOST_CHECK(mat3.getRow() == mat1.getRow() && mat3.getRow() == mat2.getRow());
	BOOST_CHECK(mat3.getCol() == mat1.getCol() && mat3.getCol() == mat2.getCol());

	// Checking for generated values
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
			BOOST_CHECK(res[i][j] == mat3[i][j]);
}



BOOST_AUTO_TEST_SUITE_END()





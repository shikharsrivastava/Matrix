/* 
 * A simple header only Matrix library using
 * expression templates and generic lambdas 
 * for efficient matrix computations
 */


#ifndef INCLUDED_MATRIX
#define INCLUDED_MATRIX
#include<bits/stdc++.h>


	///////////////////////
	//                   //
	// class BinaryExpr  //
	//                   //
	///////////////////////

/* Class to repressent binary expressions
 * while evaluating the expression tree using
 * expression templates
 */

template<typename Expr1, typename Expr2, typename OP>
class BinaryExpr
{
	protected:
	Expr1		_l;
	Expr2		_r;

	public:
	BinaryExpr(const Expr1 &l, const Expr2 &r)
	: _l(l)
	, _r(r)
	{}

	inline auto eval() 
	{
		return OP::_op(_l.eval(),_r.eval()); 
	}
};

/* Class to represent unary expressions 
 * while evaluating the expression tree.
 * By default it represents just an expression
 * without any operand
 */


/* Matrix class represents the Matrix
 * and all operations associated
 */

template <typename T>
class Matrix 
{
	public:

	// typedefs
	typedef std::vector< std::vector<T> > 	type;
	
	// Data members
	uint 			_row;
	uint			_col;
	type			_mat;

	// Constructors
	Matrix();
	Matrix(int r, int c);
	Matrix(const Matrix& dup);


	// Getters
	const uint& getRow();
	const uint& getCol();

	// Overloaded operators
	std::vector<T>& operator[](const uint ind);
	
	template<typename Expr1, typename Expr2, typename OP>
	Matrix<T>& operator=(BinaryExpr<Expr1, Expr2, OP> bexp);

	void operator+=(const Matrix<T>& rhs);

	void operator*=(const Matrix<T>& rhs);

	// General functions
	Matrix& eval();
	void print()
	{
		for(int i=0;i< _row; i++) {
			for(int j=0; j<_col;j++)
				std::cout<<_mat[i][j]<< " ";
			std::cout<<std::endl;
		}
		std::cout<<std::endl;
	}
};

		///////////////////
		//               //
		//  Class Matrix //
		//               //
		///////////////////

// Constructors
template<typename T>
Matrix<T>::	Matrix()
: _row(0)
, _col(0)
,_mat(0,std::vector<T>(0))
{}

template<typename T>
Matrix<T>::Matrix(int r, int c)
: _row(r)
, _col(c)
, _mat(r,std::vector<T>(c))
{}

template<typename T>
Matrix<T>::Matrix(const Matrix& dup)
: _row(dup._row)
, _col(dup._col)
, _mat(_row, std::vector<T>(_col))
{
	for(int i=0; i < _row; i++)
		for(int j=0; j< _col; j++)
			_mat[i][j] = dup._mat[i][j];
}

// Getters
template<typename T>
inline const uint& Matrix<T>::getRow()
{
	return _row;
}

template<typename T>
inline const uint& Matrix<T>::getCol()
{
	return _col;
}

// Overloaded operators
template<typename T>
inline std::vector<T>& Matrix<T>::operator[](const uint ind)
{
	return _mat[ind];
}

template <typename T>
template <typename Expr1, typename Expr2, typename OP>
inline Matrix<T>& Matrix<T>::operator=(BinaryExpr<Expr1, Expr2, OP> bexp)
{
	_mat = bexp.eval()._mat;
	return *this;
}

template<typename T>
void Matrix<T>::operator+=(const Matrix<T>& rhs)
{
	if(_row != rhs._row || _col != rhs._col)
	{
		std::cerr << "Dimension  mismatch\n";
		return;
	}
	for(int i=0; i < _row; i++)
		for(int j=0; j < _col; j++)
			_mat[i][j] += rhs._mat[i][j];
	return;
}

template<typename T>
void Matrix<T>::operator *=(const Matrix<T>& rhs)
{
	if( _col != rhs._row)
	{
		std::cerr << "Dimension  mismatch\n";
		return;
	}
	Matrix<T> result(_row, rhs._col);
	for(int i=0 ;i< _row; i++)
		for(int j=0; j< rhs._col; j++)
		{
			result._mat[i][j] = 0;
			for(int k=0; k< _col; k++)
				result._mat[i][j] += _mat[i][k] * rhs._mat[k][j];  
		}
	_col = rhs._col;
	_mat = result._mat;

}

// General functions
template <typename T>
inline Matrix<T>& Matrix<T>::eval()
{
	return *this;
}



/* Adds matrices using
 * generic lambda
 */
struct ADD
{
	template<typename T>
	inline static Matrix<T> _op(const Matrix<T> &a, const Matrix<T> &b)
	{
		auto add_lambda = [](auto a, auto b){
						  auto ret = a;
						  if(a._row != b._row || a._col != b._col)
						  {
							  std::cerr << " Wrong size\n";
							return ret;
						  }

						  for(int i=0; i < a._row; i++)
							  for(int j=0; j < a._col; j++)
									ret[i][j] = a[i][j] + b[i][j];

						return ret;
		};
		return add_lambda(a,b);
	}
};

/* Multiplies matrices using
 * generic lambda
 */

struct MUL
{
	template <typename T>
		inline static Matrix<T> _op(const Matrix<T> &a, const Matrix<T> &b)
		{
			auto mul_lambda = [](auto a, auto b) {
							  auto ret = a;
			   				  if(a._col != b._row)
							  {
								  std::cerr<< "Wrong size\n";
								  return a;
							  }
							  
							  for(int i=0; i < a._row; i++)
									ret[i].resize(b._col);

							  for(int i=0; i < a._row; i++)
								  for(int j=0; j < b._col; j++)
								  {
									  ret[i][j] = 0;
									  for(int k=0; k < a._col; k++)
										  ret[i][j] += a[i][k] * b[k][j];
								  }
							  return ret;

			};
			return mul_lambda(a, b);
		}
};

/* Overloaded operator for creating
 * expression templates while evaluating
 * syntax
 */
template <typename Expr1, typename Expr2>
BinaryExpr<Expr1, Expr2, ADD> operator+ (const Expr1 &l, const Expr2 &r)
{
	return BinaryExpr<Expr1, Expr2, ADD>(l,r);
}
template <typename Expr1, typename Expr2>
BinaryExpr<Expr1, Expr2, MUL> operator* (const Expr1 &l, const Expr2 &r)
{
	return BinaryExpr<Expr1, Expr2, MUL>(l,r);
}



int main()
{
	Matrix<int> mat1(20,20);
	Matrix<int> mat2(20,20);
	Matrix<int> mat3(20,20);
	Matrix<int> mat4(20,20);

	for(int i=0;i<20;i++)
		for(int j=0;j<20;j++)
			mat1[i][j] = mat2[i][j] = mat3[i][j] = mat4[i][j] = 2;


	Matrix<int> mat5(20,20);
    mat5 = mat1 * mat2 * mat3 * mat4;

	mat5.print();

}


#endif

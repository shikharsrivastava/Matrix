/* 
 * A simple header only Matrix library using
 * expression templates and generic lamdas 
 * for efficient matrix computations
 */


#ifndef INCLUDED_MATRIX
#define INCLUDED_MATRIX
#include<bits/stdc++.h>


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
	BinaryExpr(Expr1 &l, Expr2 &r)
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
	typedef unsigned int					size_type;
	
	// Data members
	size_type		_row;
	size_type		_col;
	type			_mat;

	// Constructors
	Matrix()
	: _row(0)
	, _col(0)
	,_mat(0,std::vector<T>(0))
	{}

	Matrix(int r, int c)
	: _row(r)
	, _col(c)
	, _mat(r,std::vector<T>(c))
	{}

	Matrix(const Matrix& dup)
	: _row(dup._row)
	, _col(dup._col)
	, _mat(_row, std::vector<T>(_col))
	{
		for(int i=0; i < _row; i++)
			for(int j=0; j< _col; j++)
				_mat[i][j] = dup._mat[i][j];
	}


	// Overloaded operators
	template <typename Expr1, typename Expr2, typename OP>
	inline Matrix<T>& operator=(BinaryExpr<Expr1, Expr2, OP> bexp)
	{
		_mat = bexp.eval()._mat;
		return *this;
	}

	void operator+=(Matrix<T>& rhs)
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

	void operator *=(Matrix<T>& rhs)
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
	Matrix& eval()
	{
		return *this;
	}
	
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

/* Adds matrices using
 * generic lambda
 */
struct ADD
{
	template<typename T>
	inline static Matrix<T> _op(Matrix<T> &a, Matrix<T> &b)
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
									ret._mat[i][j] = a._mat[i][j] + b._mat[i][j];

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
		inline static Matrix<T> _op(Matrix<T> &a, Matrix<T> &b)
		{
			auto mul_lambda = [](auto a, auto b) {
							  auto ret = a;
			   				  if(a._col != b._row)
							  {
								  std::cerr<< "Wrong size\n";
								  return a;
							  }
							  
							  for(int i=0; i < a._row; i++)
									ret._mat[i].resize(b._col);

							  for(int i=0; i < a._row; i++)
								  for(int j=0; j < b._col; j++)
								  {
									  ret._mat[i][j] = 0;
									  for(int k=0; k < a._col; k++)
										  ret._mat[i][j] += a._mat[i][k] * b._mat[k][j];
								  }
							  return ret;

			};
			return mul_lambda(a, b);
		}
};

/* Overloaded operator for creating
 * expression templates
 */
template <typename Expr1, typename Expr2>
BinaryExpr<Expr1, Expr2, ADD> operator+ (Expr1 &l, Expr2 &r)
{
	return BinaryExpr<Expr1, Expr2, ADD>(l,r);
}
template <typename Expr1, typename Expr2>
BinaryExpr<Expr1, Expr2, MUL> operator* (Expr1 &l, Expr2 &r)
{
	return BinaryExpr<Expr1, Expr2, MUL>(l,r);
}



int main()
{
	Matrix<int> mat1(2,2);
	Matrix<int> mat2(2,2);

	mat1._mat[0][0] = 1;
	mat1._mat[0][1] = 0;
	mat1._mat[1][0] = 0;
	mat1._mat[1][1] = 1;

	mat1.print();



	mat2._mat[0][0] = 1;
	mat2._mat[0][1] = 0;
	mat2._mat[1][0] = 0;
	mat2._mat[1][1] = 1;

	mat2.print();

	Matrix<int> mat3(2,2);
    mat3	= mat1 + mat2;

	mat3.print();

}


#endif

/* 
 * A simple header only Matrix library using
 * expression templates and generic lamdas 
 * for efficient matrix computations
 */


#ifndef INCLUDED_MATRIX
#define INCLUDED_MATRIX
#include<bits/stdc++.h>

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

template<typename Expr, typename OP>
class UnaryExpr
{
	protected:
	Expr	_exp;
	
	public:
	UnaryExpr(Expr	&e)
	: _exp(e)
	{}

	inline auto eval()
	{
		return OP::op(_exp.eval());
	}
};

template <typename T>
class Matrix 
{
	public:
	typedef std::vector< std::vector<T> > 	type;
	typedef unsigned int					size_type;
	
	size_type		_row;
	size_type		_col;
	type			_mat;

	Matrix(int r, int c)
	:  _row(r)
	,  _col(c)
	,  _mat(r,std::vector<T>(c))
	{}

/*
	inline Matrix<T>& operator=(Matrix<T> a)
	{
		_mat = a._mat;
		return *this;
	}

*/
	template <typename Expr1, typename Expr2, typename OP>
	inline Matrix<T>& operator=(BinaryExpr<Expr1, Expr2, OP> bexp)
	{
		_mat = bexp.eval()._mat;
		return *this;
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
						  if(a._row != b._row || a._col != b._col)
						  {
							  std::cerr << " Wrong size\n";
							  return Matrix<T>(1,1);
						  }
						  Matrix<T> ret(a._row, a._col);
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
class multiply
{
};

template <typename Expr1, typename Expr2>
BinaryExpr<Expr1, Expr2, ADD> operator+ (Expr1 &l, Expr2 &r)
{
	return BinaryExpr<Expr1, Expr2, ADD>(l,r);
}


int main()
{
	Matrix<int> mat1(2,2);
	Matrix<int> mat2(2,2);

	mat1._mat[0][0] = 1;
	mat1._mat[0][1] = 1;
	mat1._mat[1][0] = 1;
	mat1._mat[1][1] = 1;

	mat1.print();



	mat2._mat[0][0] = 1;
	mat2._mat[0][1] = 1;
	mat2._mat[1][0] = 1;
	mat2._mat[1][1] = 1;

	mat2.print();

	Matrix<int> mat3(2,2);
    mat3	= mat1 + mat2;

	mat3.print();

}


#endif

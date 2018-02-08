/* 
 * A simple header only Matrix library using
 * expression templates and generic lambdas 
 * for efficient matrix computations
 *
 * Author - Shikhar Srivastava
 */


#ifndef INCLUDED_MATRIX
#define INCLUDED_MATRIX
#include<iostream>
#include<vector>


namespace Lib
{


/* Class to repressent binary expressions
 * while evaluating the expression tree using
 * expression templates
 */

template<typename Expr1, typename Expr2, typename OP>
class Expression
{
	protected:
	Expr1		_l;
	Expr2		_r;

	public:
	Expression(const Expr1 &l, const Expr2 &r);
	auto eval(); 
};


// Forward declaration of Matrix class
template<typename T>
class Matrix;

/* Adds matrices using
 * generic lambda
 */

struct ADD
{
	template<typename T>
	static Matrix<T> _op(const Matrix<T> &a, const Matrix<T> &b);

};

/* Multiplies matrices using
 * generic lambda
 */

struct MUL
{
	template <typename T>
	inline static Matrix<T> _op(const Matrix<T> &a, const Matrix<T> &b);

};


/* Matrix class represents the Matrix
 * and all operations associated
 */

template <typename T>
class Matrix 
{
	public:

	// typedefs
	typedef std::vector< std::vector<T> > 	type;
	
	protected:
	// Data members
	uint 			_row;
	uint			_col;
	type			_mat;


	public:
	// Constructors
	Matrix();
	Matrix(int r, int c);
	Matrix(int r, int c, int def);
	Matrix(const Matrix& dup);


	// Getters
	const uint& getRow() const;
	const uint& getCol() const;

	// Setters
	void setRow(const uint r);
	void setCol(const uint c);

	// Overloaded operators
	std::vector<T>& operator[](const uint ind);
	
	template<typename Expr>
	Matrix<T>& operator=(Expr bexp);

	template<typename Expr>
	void operator+=(Expr bexp);

	template<typename Expr>
	void operator*=(Expr bexp);

	// General functions
	Matrix& eval();
	void print();
	
};



	///////////////////////
	//                   //
	// class Expression  //
	//                   //
	///////////////////////
	
// Constructors
template<typename Expr1, typename Expr2, typename OP>
Expression<Expr1, Expr2, OP>::Expression(const Expr1 &l, const Expr2 &r)
: _l(l)
, _r(r)
{}

// Eval function
template<typename Expr1, typename Expr2, typename OP>
inline auto Expression<Expr1, Expr2, OP>::eval() 
{
	return OP::_op(_l.eval(),_r.eval()); 
}




	///////////////////
	//               //
	//  Class ADD    //
	//               //
	///////////////////

// _op function for addition
template <typename T>
inline Matrix<T> ADD::_op(const Matrix<T> &a, const Matrix<T> &b)
{
	auto add_lambda = [](auto a, auto b){
					  auto ret = a;
					  if(a.getRow() != b.getRow() || a.getCol() != b.getCol())
					  {
						  std::cerr << " Wrong size\n";
						return ret;
					  }

					  for(int i=0; i < a.getRow(); i++)
						  for(int j=0; j < a.getCol(); j++)
								ret[i][j] = a[i][j] + b[i][j];

					return ret;
	};
	return add_lambda(a,b);
}


	///////////////////
	//               //
	//  Class MUL    //
	//               //
	///////////////////

// _op function for multiplication
template <typename T>
inline Matrix<T> MUL::_op(const Matrix<T> &a, const Matrix<T> &b)
{
	auto mul_lambda = [](auto a, auto b) {
					  auto ret = a;
	   				  if(a.getCol() != b.getRow())
					  {
						  std::cerr<< "Wrong size\n";
						  return a;
					  }

					  for(int i=0; i < a.getRow(); i++)
							ret[i].resize(b.getCol());

					  for(int i=0; i < a.getRow(); i++)
						  for(int j=0; j < b.getCol(); j++)
						  {
							  ret[i][j] = 0;
							  for(int k=0; k < a.getCol(); k++)
							  	ret[i][j] += a[i][k] * b[k][j];
						  }
					  return ret;
		};
	return mul_lambda(a, b);
}


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
, _mat(r,std::vector<T>(c, 0))
{}

template<typename T>
Matrix<T>::Matrix(int r, int c, int def)
: _row(r)
, _col(c)
, _mat(r,std::vector<T>(c, def))
{}

template<typename T>
Matrix<T>::Matrix(const Matrix& dup)
: _row(dup.getRow())
, _col(dup.getCol())
, _mat(_row, std::vector<T>(_col))
{
	for(int i=0; i < _row; i++)
		for(int j=0; j< _col; j++)
			_mat[i][j] = dup._mat[i][j];
}


// Getters
template<typename T>
inline const uint& Matrix<T>::getRow() const
{
	return _row;
}

template<typename T>
inline const uint& Matrix<T>::getCol() const
{
	return _col;
}

//Setters
template<typename T>
inline void Matrix<T>::setRow(const uint r)
{
	_row = r;
	_mat.resize(_row, std::vector<T>(_col));
	return;
}

template<typename T>
inline void Matrix<T>::setCol(const uint c)
{
	_col = c;
	for(int i=0;i<_row;i++)
		_mat[i].resize(_col);

}

// Overloaded operators
template<typename T>
inline std::vector<T>& Matrix<T>::operator[](const uint ind)
{
	return _mat[ind];
}

template <typename T>
template <typename Expr>
inline Matrix<T>& Matrix<T>::operator=(Expr bexp)
{
	*this = bexp.eval();	
	return *this;
}

template<typename T>
template<typename Expr>
inline void Matrix<T>::operator+=(Expr bexp)
{
	*this = ADD::_op(*this, bexp.eval());
	
}

template<typename T>
template<typename Expr>
inline void Matrix<T>::operator*=(Expr bexp)
{
	*this = MUL::_op(*this, bexp.eval());

}


// General functions
template <typename T>
inline Matrix<T>& Matrix<T>::eval()
{
	return *this;
}

template <typename T>
inline void Matrix<T>::print()
{
	for(int i=0;i< _row; i++) {
		for(int j=0; j<_col;j++)
			std::cout<<_mat[i][j]<< " ";

		std::cout<<std::endl;
	}
		std::cout<<std::endl;
}

	

/* Overloaded operator for creating
 * expression templates while evaluating
 * syntax
 */
template <typename Expr1, typename Expr2>
Expression<Expr1, Expr2, ADD> operator+ (const Expr1 &l, const Expr2 &r)
{
	return Expression<Expr1, Expr2, ADD>(l,r);
}
template <typename Expr1, typename Expr2>
Expression<Expr1, Expr2, MUL> operator* (const Expr1 &l, const Expr2 &r)
{
	return Expression<Expr1, Expr2, MUL>(l,r);
}


} // namespace Lib ends





#endif


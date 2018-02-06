# Matrix Library
It is simple header only C++ matrix library using expression templates. It is compatible with C++14 and later. It can be used with any type of data (int,float, complex,etc).

## Usage
Just include the matrix.hpp file in your program and you are ready to go. The Matrix class exists in the namespace Lib. You can see the examples [here](/examples) It has the following functions to use -
#### Constructors
The library has 3 constructors :-
* Default Constructor
* Constructor with row and column values
* Constructor with row, column and a default value
* Copy Constructor to make a deep copy 
#### Getters
The getter function to get attributes of the Matrix :-
* getRow() - gets you the row count of the matrix
* getCol() - gets you the column count of the matrix

#### Setters
The setter fuunctions to help you set the attributes of the matrix:-
* setRow() - resizes the matrix and sets the new row count
* setCol() - resizes the matrix and sets the new column count

#### Operations
* Addition - Addition operation is overloaded so you can add two matrices m1 and m2 as m1+m2.
* Multiplication - Multiplication operation is overloaded so you can multiply two matrices m1 and m2 as m1*m2.
* Compound operations like +=  and *= are also overloaded.
* [] operator is overloaded so you can access elements just like a 2D array.
* print() - a print function to print the matrix

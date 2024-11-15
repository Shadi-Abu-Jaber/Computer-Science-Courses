# Lab 2 Topic: Special Matrices

Introduction:

A matrix is ​​a two-dimensional structure that contains a collection of numbers.

The classic implementation of a matrix is ​​a two-dimensional array of size mn.

The basic operations needed to work with a matrix are:

get(i,j) which returns the element at position (i,j).

set(i,j,x) which updates the element at position (i,j) to be x.

The time complexity of these two operations is O(1).

The space complexity of the structure is O(mn).

However, when a matrix has a special structure, a smarter implementation can be proposed and thus improve the complexity.


Objectives: In this lab we will get to know implementations of a special matrix - a diagonal matrix

Description: An n*n square matrix in which the values ​​in each diagonal are equal is called a diagonal matrix.

Standard implementation complexity:

get(i,j) in O(1) time.

set(i,j,x) in O(n) time because all diagonal elements need to be updated.

We propose an alternative implementation using a one-dimensional array of size 2n-1:

Note that the number of different diagonals in the array is 2n-1. For each diagonal, we allocate one cell in the array.

The complexity of get(i,j) is O(1).

The complexity of set(i,j,x) is O(1).

So we have saved both space and time! The only task is to correctly translate the indices of the given matrix to the one-dimensional matrix and back.

Write an interface called Matrix with the following actions and the MAX_SIZE constant set to 100.


- double get(int i, int j)

Precondition: 1 ≤ i,j ≤ n

Postcondition: returns the value of the element at position (i,j).

- void set(int i, int j, double x)

Precondition: 1 ≤ i,j ≤ n.

Postcondition: update the value of the element at position (i,j) to x.

- void transpose()

Postcondition: replace the current matrix with its transpose.

- Matrix getTranspose()

Postcondition: returns a new matrix which is equal to the transpose of the current matrix.

Write a class named DiagonalMatrix that implements the above interface as a diagonal matrix (i.e., if you change an element in the matrix, 
then all elements on the same diagonal also change) and contains the following constructors:

- DiagonalMatrix(int ​​size)
 
Precondition: size>0

Postcondition: Initializes a size*size diagonal matrix using an array of length 2*size-1.

- DiagonalMatrix( )
  
Initializes an MAX_SIZE * MAX_SIZE diagonal matrix

In addition, the class contains the following method:

- String toString( )

Postcondition: Returns the matrix in its natural n*n form as a string (with \t between entries of the same row and \n between rows).

The transpose method should be implemented in time complexity of O(1), and getTranspose in O(size)

In case the precondition condition is not met (for example, row number is less than 1 or greater than the number of rows), a runtime exception should be thrown Suitable.

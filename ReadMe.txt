Final assignment for CS161
Write a class called SBoard that represents a 10x10 grid, where a token may be placed at any (row, column) coordinates.

It should have two data members: a 2D array of char for the grid, and an int to keep track of how many tokens have been placed.

It should have a default constructor that initializes all elements of the array to being empty (you can use whatever characters you want to represent that a square is empty or has a token), and also initializes the number of tokens placed (at the beginning there are no tokens on the board).

It should have a method named getNumTokens that returns the number of tokens placed so far.

It should have a method named placeToken that takes two ints (the row and column, in that order). If that location already has a token, or if the row or column are out of the range 0-9, then a token should not be placed and the method should return -1. Otherwise, a token should be placed there and the method should return the number of squares completed by placing that token (where only the four corners are needed to complete a square). For example, if we have the following grid, where x marks each existing token:

. . . . . . . . . .
. . . . . . . . . .
. x . x . . . x . x
x . . x . . . . . .
. . . x . x . . . .
x . . x x . . . x .
x . x # . x . x . .
. . x x . . . . . .
. . . . . . . . . .
. . . . . . . . . .
then playing a token at the spot marked # will complete four squares - a 2x2, a 3x3, a 4x4, and a 5x5 (1x1 doesn't count).

It should have a method named readPlacementsFromFile that takes a string (the name of the file to read). The file will have the following format:

2 1
2 3
3 0
7 3
Where the left number on each line is the row and the right number is the column. The method should place a token at the coordinates given in each row of the file. To do this, it will call the placeToken method (ignoring the return value). Remember to close the file.

It's not required, but you'll probably find it useful for testing and debugging to have a method that prints out the board.

Whether you think of the array indices as being [row] or [column] doesn't matter as long as you're consistent.

The files must be named: SBoard.hpp and SBoard.cpp.
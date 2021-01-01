/********************************************************************* 
** Author: Phillip Wellheuser
** Date: 3/13/19
** Description: The SBoard.cpp file implements the SBoard class which
** manages a 2D array of chars which can be printed to console as a 
** grid. It also updates elements of the array to 'X', tracks how 
** many elements have been updated and calculates how many squares 
** have been formed by the Xs when the array is viewed in grid form. 
*********************************************************************/
#include <string>
#include <iostream>
#include <fstream>
#include "SBoard.hpp"

//Getters for NumTokens and TotalSquares attributes
int SBoard::getNumTokens(){
   return tokensPlaced;
}
int SBoard::getTotalSquares(){
   return totalSquares;
}
/********************************************************************* 
** Description: The setGridSize method is intended [but not yet 
** implemented] to resize the grid array dynamically so that users
** can input their own size for it
*********************************************************************/ 
/*void SBoard::setGridSize(int size){
   //GRID_SIZE= size;
}*/

/********************************************************************* 
** Description: The printGrid method is a supplementeary method which 
** prints the SBoard's grid array to the console for visualization.
*********************************************************************/
void SBoard::printGrid(){
      std::cout<< std::endl; 
      std::cout<< "  ";
  for(int i=0; i<GRID_SIZE; i++){
      std::cout<< i<< " ";
  }
  std::cout<<" "<< std::endl;
  for(int i=0; i<GRID_SIZE; i++){
      std::cout<< i<< " ";
      for(int j=0; j<GRID_SIZE; j++){
         if (grid[j][i]== 'X'){
            std::cout<< grid[j][i]<< " ";
         }
         else {
            std::cout<< ". ";
         }
      }
      std::cout<< std::endl;
   }
}

/********************************************************************* 
** Description: The placeToken method receives row and column  int 
** parameters and uses them to alter an element of the grid array 
** from '.' to 'X', returning -1 for invalid locations or elements 
** which already contain 'X'.
*********************************************************************/
int SBoard::placeToken(int row, int column){
   if((row> GRID_SIZE || row < 0) || (column> GRID_SIZE || column < 0)){
      return -1;
   }
   else if(grid[row][column]== 'X'){
      return -1;
   }
   else if(grid[row][column]!= 'X'){
      grid[row][column]= 'X';
      tokensPlaced++;
      return squaresCompleted(row, column);
   }
   else
      return -1;
}

/********************************************************************* 
** Description: The readPlacementsFromFile method receives a string
** of the file path for a .txt file containing locations in int form
** which are read and used to place tokens in the grid array with the 
** placeToken() method
*********************************************************************/ 
void SBoard::readPlacementsFromFile(std::string filePath){
   std::ifstream infile(filePath);
   int row, column;
   while (infile >> row >> column){
      placeToken(row, column);
   }
   infile.close();
}

/********************************************************************* 
** Description: the squaresCompleted method receives two int parameters
** describing an element of the grid array and uses that as a starting
** location to determine whether any squares are formed around its
** relative coordinates in grid form then returns the number formed. 
** It detects new squares by testing diagonally for opposite corners of 
** a square and then testing for the remaining corners if an opposite 
** exists. 
*********************************************************************/ 
int SBoard::squaresCompleted(int row, int column){
   int newSquares= 0;
   //check along slope 1/1 [verified]
   for(int i= 0; i+ row< GRID_SIZE && i+ column< GRID_SIZE; i++){
      //check diagonal coordinates
      if(grid[row+ i][column+ i]== 'X' && i!= 0){
         //check same column and same row
         if(grid[row+ i][column]== 'X' && grid[row][column+ i]=='X'){
            newSquares++;
         }
      }
   }
   //check along slope -1/-1 [verified]
   for(int i=0; row- i>= 0 && column- i>= 0; i++){
      //check diagonal coordinates
      if(grid[row- i][column- i]== 'X' && i!= 0){
         //check same column and same row
         if(grid[row- i][column]== 'X' && grid[row][column- i]=='X'){
            newSquares++;
         }
      }
   }
   //check along slope -1/1 [verified]
   for(int i=0; i+ row< GRID_SIZE && column- i>= 0; i++){
      //check diagonal coordinates
      if(grid[row+ i][column- i]== 'X' && i!=0){
         //check same column and same row
         if(grid[row+ i][column]== 'X' && grid[row][column- i]=='X'){
            newSquares++;
         }
      }
   }
   //check along slope 1/-1 [verified]
   for(int i=0; row- i>= 0 && i+ column< GRID_SIZE; i++){
      //check diagonal coordinates
      if(grid[row- i][column+ i]== 'X' && i!=0){
         //check same column and same row
         if(grid[row- i][column]== 'X' && grid[row][column+ i]=='X'){
            newSquares++;
         }
      }
   }
   totalSquares+= newSquares;
   return newSquares;
}
/********************************************************************* 
** Author: Phillip Wellheuser
** Date: 3/13/19
** Description: The SBoard.hpp header file specifies the 
**              SBoard object class and defines its member 
**              attributes and functions
*********************************************************************/
#ifndef SBOARD_HPP
#define SBOARD_HPP

class SBoard{
private:
   int tokensPlaced, totalSquares;

   static const int GRID_SIZE= 10;

   char grid[GRID_SIZE][GRID_SIZE]; 
   
   int squaresCompleted(int row, int column);
      
public: 
/********************************************************************* 
** Description: Zero parameter constructor initializes the elements
** of the SBoard object's grid attribute array
*********************************************************************/
   SBoard(){
      for(int i= 0; i< GRID_SIZE; i++){
         for(int j= 0; j<GRID_SIZE; j++){
            grid[i][j]= '.';
         }
      }
      tokensPlaced= 0;
      totalSquares= 0;
   }

   int getTotalSquares();

   void printGrid();

   int placeToken(int row, int column);

   int getNumTokens();

   void readPlacementsFromFile(std::string filePath);

//   void setGridSize(int size);
};
#endif // end definition of SBoard.hpp
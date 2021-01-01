#include <iostream>
#include "./SBoard.hpp"

int main() {
   SBoard testGrid;
   testGrid.readPlacementsFromFile("diagSquaresTest.txt");
   testGrid.printGrid();
   std::cout<< "Tokens placed: "<< testGrid.getNumTokens()<< std::endl; 
      std::cout<< "Total Squares: "<< testGrid.getTotalSquares()<< std::endl;

   
   SBoard alconTest;
   alconTest.readPlacementsFromFile("alconTest.txt");
   alconTest.printGrid();
   std::cout<< "Tokens placed: "<< alconTest.getNumTokens()<< std::endl; 
      std::cout<< "Total Squares: "<< alconTest.getTotalSquares()<< std::endl;


   SBoard cornerTest;
   cornerTest.readPlacementsFromFile("cornerTest.txt");
   cornerTest.printGrid();
   std::cout<< "Tokens placed: "<< cornerTest.getNumTokens()<< std::endl; 
   std::cout<< "Total Squares: "<< cornerTest.getTotalSquares()<< std::endl;
      
   /*std::cout<< testGrid.placeToken(1,1)<< std::endl; 
   std::cout<< testGrid.placeToken(5,1)<< std::endl; 
   std::cout<< testGrid.placeToken(5,4)<< std::endl; 
   std::cout<< testGrid.placeToken(6,4)<< std::endl; 
   std::cout<< testGrid.placeToken(1,5)<< std::endl; 
   std::cout<< testGrid.placeToken(2,5)<< std::endl; 
   std::cout<< testGrid.placeToken(6,5)<< std::endl; 
   std::cout<< testGrid.placeToken(7,5)<< std::endl; 
   std::cout<< testGrid.placeToken(5,7)<< std::endl; 
   std::cout<< testGrid.placeToken(7,7)<< std::endl; 
   std::cout<< testGrid.placeToken(2,8)<< std::endl; 
   std::cout<< testGrid.placeToken(5,8)<< std::endl; 
   testGrid.printGrid();
   std::cout<< testGrid.placeToken(5, 5)<< std::endl;*/ 

   /*char grid[10][10];
   for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
        //grid[i][j]= '.';
        std::cout<< grid[i][j]<< " ";
      }
      std::cout<< i<< std::endl; 
   }*/

   std::cout << "Press Enter to Continue";
   std::cin.ignore();
   return 0;
}
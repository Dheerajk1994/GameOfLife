#ifndef GAMELOGIC_C
#define GAMELOGIC_C

#include <stdbool.h>
#include "cell.c"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600
#define CELL_SIZE 10


bool isWithinBoundary(int x, int y){
 return
   x >= 0 && x < (WINDOW_WIDTH) &&
   y >= 0 && y < (WINDOW_HEIGHT);
}

int getNumberOfNeighbors(cell** cellInfo, int xIndex, int yIndex){
  int count = 0;
  //left
  if(isWithinBoundary(xIndex - 1, yIndex + 1) && cellInfo[xIndex - 1][yIndex + 1].occupied == true)
    count++;
  if(isWithinBoundary(xIndex - 1, yIndex)     && cellInfo[xIndex - 1][yIndex].occupied == true)
    count++; 
  if(isWithinBoundary(xIndex - 1, yIndex - 1) && cellInfo[xIndex - 1][yIndex - 1].occupied == true)
    count++;
  //center
  if(isWithinBoundary(xIndex, yIndex + 1) && cellInfo[xIndex][yIndex + 1].occupied == true)
    count++;
  if(isWithinBoundary(xIndex, yIndex - 1) && cellInfo[xIndex][yIndex - 1].occupied == true)
    count++;
//right
  if(isWithinBoundary(xIndex + 1, yIndex + 1) && cellInfo[xIndex + 1][yIndex + 1].occupied == true)
    count++;
  if(isWithinBoundary(xIndex + 1, yIndex)     && cellInfo[xIndex + 1][yIndex].occupied == true)
    count++; 
  if(isWithinBoundary(xIndex + 1, yIndex - 1) && cellInfo[xIndex + 1][yIndex - 1].occupied == true)
    count++;

  return count;
}

void updateCells(cell** cellInfo, int numCol, int numRow){
  cell tempCells[numCol][numRow];
  int neighbors = 0;

  for(int col = 0; col < numCol; ++col){
    for(int row = 0; row < numRow; ++row){
      neighbors = getNumberOfNeighbors(cellInfo, col, row);
      if(cellInfo[col][row].occupied && (neighbors == 2 || neighbors == 3)){
	tempCells[col][row].occupied = true;
      }
      else if(cellInfo[col][row].occupied == false && neighbors == 3){
	tempCells[col][row].occupied = true;
      }
      else{
	tempCells[col][row].occupied = false;
      }
    }
  }

  for(int col = 0; col < numCol; ++col){
    for(int row = 0; row < numRow; ++row){
      cellInfo[col][row] = tempCells[row][col];
    }
  }
}

#endif

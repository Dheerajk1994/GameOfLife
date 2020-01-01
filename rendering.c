#ifndef RENDERING_C
#define RENDERING_C

//rendering.c
#include <stdbool.h>
#include "SDL2/SDL.h"
#include "gamelogic.c"
//void renderGrid(SDL_Renderer* renderer, int cellSize, const int numCols, const int numRows){
//  for(int c = 0; c < numCols; ++c){
//    SDL_RenderDrawLine(renderer, c * cellSize, 0, c * cellSize, WINDOW_HEIGHT);
//  }
//  for(int r = 0; r < numRows; ++r){
//    SDL_RenderDrawLine(renderer, 0, r * cellSize, WINDOW_WIDTH, r * cellSize);
//  }
//}

void renderCells(SDL_Renderer* renderer, cell** cellInfo, int cellSize, const int colCount, const int rowCount){
  SDL_Rect rect;
  for(int col = 0; col < colCount; ++col){
    for(int row = 0; row < rowCount; ++row){
      if(cellInfo[col][row].occupied == true){
	rect.x = col * cellSize;
	rect.y = row * cellSize;
	rect.w = cellSize;
	rect.h = cellSize;
	SDL_RenderDrawRect(renderer, &rect);
      }
    }
  }
}

#endif

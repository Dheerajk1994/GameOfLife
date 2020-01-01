#include <stdlib.h>
#include <stdbool.h>
#include "SDL2/SDL.h"

#include "rendering.c"

int main(int argc, char** argv){
  if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_EVENTS) != 0){
    SDL_Log("cannot initialize SDL: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Window* window = SDL_CreateWindow("Game Of Life",
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					WINDOW_WIDTH,
					WINDOW_HEIGHT,
					0);

  if(!window){
    SDL_Log("cannot create SDL window: %s\n", SDL_GetError());
    return 1;
  }

  Uint32 renderFlags = SDL_RENDERER_ACCELERATED;
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, renderFlags);

  bool quitInitiated = false;
  SDL_Event event;

  //game logic
  int numCols = WINDOW_WIDTH / CELL_SIZE;
  int numRows = WINDOW_HEIGHT / CELL_SIZE;

  cell** cellArray = malloc(sizeof(cell*) * numCols);
  for(int i = 0; i < numCols; ++i){
    cellArray[i] = calloc(numRows, sizeof(cell));
  }
  
  while(!quitInitiated){
    //event poll
    while(SDL_PollEvent(&event)){
      switch(event.type){
      case SDL_QUIT:
	quitInitiated = true;
	break;
      }
    }
    //end of event poll

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    //renderGrid(renderer, numCols, numRows);
    renderCells(renderer, cellArray, CELL_SIZE, numCols, numRows);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);

    updateCells(cellArray, numCols, numRows);

    SDL_Delay(100);
  }
    
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  return 0;
}

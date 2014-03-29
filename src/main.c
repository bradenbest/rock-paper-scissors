#include <stdio.h>

#include "game.h"

int main(void){
  player p = {0,0,0,1};
  while(p.playing){
    start_game(&p);
    //ask to play again
  }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "player.h"
#include "game.h"
#include "input.h"
#include "version.h"


int main(void){
  srand(time(0));
  player p = {0,0,0,1,0};
  printf("Welcome to Rock Paper Scissors!\n");
  get_version();
  printf("\n  R for Rock\n  P for Paper\n  S for Scissors\n\n");
  while(p.playing){
    start_game(&p);
    ask_replay(&p);
  }
  return 0;
}

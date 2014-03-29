#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "player.h"
#include "game.h"
#include "input.h"

static void lose(int pc, int cc, player *p){
  char action[10] = {0};

  if(cc == rock){
    strcpy(action, "crushed");
  } else if(cc == paper){
    strcpy(action, "covered");
  } else if(cc == scissors){
    strcpy(action, "cut");
  }

  printf("%s gets %s by %s.\n\nOh boo! You lost.\n", rps(pc), action, rps(cc));
  p->losses += 1;
}

static void win(int pc, int cc, player *p){
  char action[10] = {0};
  
  if(pc == rock){
    strcpy(action, "crushes");
  } else if(pc == paper){
    strcpy(action, "covers");
  } else if(pc == scissors){
    strcpy(action, "cuts");
  }

  printf("%s %s %s.\n\nYou Win!\n", rps(pc), action, rps(cc));
  p->wins += 1;
}

static void draw(player *p){
  printf("Draw!\n");
  p->draws += 1;
}

static void judge_winner(player *p){
  int p_choice = p->choice;
  int c_choice = rand() % 3;

  if(c_choice == p_choice){              // Computer and player chose the same thing
    draw(p);
  } else if(c_choice == rock){           // Computer -> rock
    if(p_choice == scissors){            //   Player -> scissors
      lose(p_choice, c_choice, p);  
    } else if(p_choice == paper){        //   Player -> paper
      win(p_choice, c_choice, p);
    }
  }else if(c_choice == paper){           // Computer -> paper
    if(p_choice == rock){                //   Player -> rock
      lose(p_choice, c_choice, p);
    } else if(p_choice == scissors){     //   Player -> scissors
      win(p_choice, c_choice, p);
    }
  }else if(c_choice == scissors){        // Computer -> scissors
    if(p_choice == paper){               //   Player -> paper
      lose(p_choice, c_choice, p);
    } else if(p_choice == rock){         //   Player -> rock
      win(p_choice, c_choice, p);
    }
  }
}

static void print_stats(player *p){
  printf("\
  \rWins:\t%i\n\
  \rLosses:\t%i\n\
  \rDraws:\t%i\n\
  \r",p->wins, p->losses, p->draws);
}

void start_game(player *p){
  p->choice = get_choice();
  if(p->choice != -1)
    judge_winner(p);
  print_stats(p);
}

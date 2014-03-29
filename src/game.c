#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#include "game.h"

#define rps(c) ((!c)?("rock"):(c==1)?("paper"):("scissors"))

static void lose(int pc, int cc, player *p){
  char action[10] = {0};

  if(cc == 0){
    strcpy(action, "crushed");
  } else if(cc == 1){
    strcpy(action, "covered");
  } else if(cc == 2){
    strcpy(action, "cut");
  }

  printf("%s gets %s by %s.\n\nOh boo! You lost.\n", rps(pc), action, rps(cc));
  p->losses += 1;
}

static void win(int pc, int cc, player *p){
  char action[10] = {0};
  
  if(pc == 0){
    strcpy(action, "crushes");
  } else if(pc == 1){
    strcpy(action, "covers");
  } else if(pc == 2){
    strcpy(action, "cuts");
  }

  printf("%s %s %s.\n\nYou Win!\n", rps(pc), action, rps(cc));
  p->wins += 1;
}

static void draw(player *p){
  printf("Draw!\n");
  p->draws += 1;
}

void start_game(player *p){
  srand(time(0));
  char choice[9] = {0};
  int p_choice = -1;         // player choice
  int c_choice = rand() % 3; // computer choice
  enum{rock, paper, scissors};
  printf("You choose... ");
  if( fgets(choice, sizeof(choice), stdin) );
  printf("Rock, Paper, Scissors!\n");

  printf("1...");
  fflush(stdout);
  usleep(1000000);

  printf("2...");
  fflush(stdout);
  usleep(1000000);

  printf("3...");
  fflush(stdout);
  usleep(1000000);

  putchar(10);

  if(choice[0] == 'r' || choice[0] == 'R')    p_choice = rock;
  if(choice[0] == 'p' || choice[0] == 'P')    p_choice = paper;
  if(choice[0] == 's' || choice[0] == 'S')    p_choice = scissors;

  if(c_choice == p_choice)      draw(p);
  if(c_choice == rock){
    if(p_choice == scissors)    lose(p_choice, c_choice, p);
    if(p_choice == paper)       win(p_choice, c_choice, p);
  }else if(c_choice == paper){
    if(p_choice == rock)        lose(p_choice, c_choice, p);
    if(p_choice == scissors)    win(p_choice, c_choice, p);
  }else if(c_choice == scissors){
    if(p_choice == paper)       lose(p_choice, c_choice, p);
    if(p_choice == rock)        win(p_choice, c_choice, p);
  }
}

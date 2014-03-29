#include <stdio.h>
#include <unistd.h>

#include "player.h"
#include "game.h"
#include "input.h"

static void wait(char c){
  int i;
  for(i = 0; i < 4; i++){
    putchar(i ? '.' : c);
    fflush(stdout);
    usleep(1000000/8);
  }
  usleep(1000000/8);
}

static char get_input(){ // get char abstraction
  char c;
  c = getc(stdin);
  fflush(stdin);
  if(c != 10){
    return c;
  }else{
    while((c = get_input()) == 10);
    return c;
  }
}

static void clear_line(){
  printf("\r\033[K\r");
}

int get_choice(){
  char choice;
  int p_choice;
  clear_line();
  printf("You choose... ");
  choice = get_input();

  if(choice >= 'p' && choice <= 's'){
    choice -= ' ';
  }
  if(choice >= 'P' && choice <= 'S'){
    if(choice == 'R'){
      p_choice = rock;
    } else if(choice == 'P'){
      p_choice = paper;
    } else if(choice == 'S'){
      p_choice = scissors;
    } else{
      printf("...what?\n");
      return -1;
    }
  } else {
    return -1;
  }

  printf("Rock, Paper, Scissors!\n");
  wait('1');
  wait('2');
  wait('3');
  putchar(10);
  fflush(stdout);

  return p_choice;
}

void ask_replay(player *p){
  char c = 0;
  clear_line();
  printf("Play again? [y/n] ");
  while(c != 'y' && c != 'n')
    c = get_input();
  if(c == 'y')
    p->playing = 1;
  else
    p->playing = 0;
}

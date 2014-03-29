#define rps(c) ((!c)?("rock"):(c==1)?("paper"):("scissors"))

enum{
  rock, 
  paper, 
  scissors
};

void start_game(player *p);

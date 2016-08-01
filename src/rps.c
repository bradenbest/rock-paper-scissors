/* A Game of Rock Paper Scissors
 * The banter makes it entertaining.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define SECOND 1000000

enum hand { rock, paper, scissors };
enum outcome { win, loss, draw };

struct game {
    unsigned int wins;
    unsigned int losses;
    unsigned int draws;
    unsigned int games;
};

struct play {
    enum hand player;
    enum hand computer;
};

const char *outcome_str[] = {
    "You Win!",
    "Oh bummer! You Lose.",
    "Draw!"
};

const char *describe_str[] = {
    "Rock crushes scissors. ",
    "Paper covers rock. ",
    "Scissors cut paper. "
};

const char *snark_str[] = {
    "you're getting your ass kicked",
    "try harder",
    "doing pretty good",
    "why the seriousness?"
};

const int snark_threshold[] = {
    4,
    30,
    60,
    90,
    100
};

const char *banter[] = {
    "Umm...ignore the man behind that curtain!",
    "95% of all rock paper scissors games are won randomly, y'know.",
    "You can't keep this up forever...",
    "My RNG is more randomer than you are. I'll show you!",
    "Cheater",
    "I hate you",
    ":)",
    "0100011001010101",
    "Meh, I could do better.",
    "Good game.",
    "Winning!",
    "This is war",
    "Oh, now it is ON!",
    "I'll beat you at this. Just watch.",
    "No fair!",
    "Aww, man!",
    "u wot m8?"

};

const int banter_length = 17;

int
chinstr(char c, char *str)
{/*{{{*/
    while(*str)
        if(c == *(str++))
            return 1;

    return 0;
}/*}}}*/

enum hand
get_random()
{/*{{{*/
    return rand() % 3;
}/*}}}*/

enum hand
get_player()
{/*{{{*/
    int c = 0;

    printf( "Choose your hand:\n"
            "    R - Rock\n"
            "    P - Paper\n"
            "    S - Scissors\n"
            "    ? - Random\n"
            "> ");

    while(!chinstr(c, "rpsRPS?"))
        c = fgetc(stdin);

    switch(c){
        case 'r':
        case 'R':
            return rock;
        case 'p':
        case 'P':
            return paper;
        case 's':
        case 'S':
            return scissors;
        case '?':
            return get_random();
    }
}/*}}}*/

void
play_get(struct play *p)
{/*{{{*/
    p->player = get_player();
    p->computer = get_random();
}/*}}}*/

void
wprint(char *msg)
{/*{{{*/
    while(*msg){
        switch(*msg){
            case 1:
                usleep(SECOND / 4);
                break;
            default:
                putchar(*msg);
                fflush(stdout);
                usleep(SECOND / 40);
                break;
        }

        msg++;
    }
}/*}}}*/

const char *
smartass(float percent)
{/*{{{*/
    int i;

    for(i = 0; i <= *snark_threshold; i++)
        if(percent <= snark_threshold[1 + i])
            return snark_str[i];

    return "...";
}/*}}}*/

void
stats(struct game *g)
{/*{{{*/
    float non_draws = (float)g->games - (float)g->draws,
          percent = ((float)g->wins / non_draws) * 100;

    printf("Stats:\n");
    printf("    Total Games: %u\n", g->games);
    printf("    Wins/Losses: %u/%u (%0.2f%% win rate) (%s)\n", g->wins, g->losses, percent, smartass(percent));
    printf("    Draws:       %u\n\n", g->draws);
    printf("Opponent says: \e[0;32m%s\e[0m\n\n", banter[rand() % banter_length]);
}/*}}}*/

int
numinset(int num, int *set)
{/*{{{*/
    while(*set)
        if(num == *(set++))
            return 1;

    return 0;
}/*}}}*/

enum outcome
get_outcome(struct play *p)
{/*{{{*/
    int diff = p->player - p->computer;
    int victory[3] = {1, -2, 0};

    return !diff
        ? draw
        : numinset(diff, victory)
            ? win
            : loss;
}/*}}}*/

void
play_finish(struct game *g, enum hand winner, enum outcome result)
{/*{{{*/
    switch(result){
        case draw: g->draws++;  break;
        case win:  g->wins++;   break;
        case loss: g->losses++; break;
    }


    fputs("\e[0;30;47m",stdout);

    if(result != draw)
        fputs(describe_str[winner], stdout);

    fputs(outcome_str[result], stdout);
    fputs("\e[0m\n",stdout);
}/*}}}*/

void
play_check(struct play *p, struct game *g)
{/*{{{*/
    enum outcome result = get_outcome(p);
    enum hand winner = result == win ? p->player : p->computer;

    play_finish(g, winner, result);
    g->games++;
}/*}}}*/

int
prompt_playing()
{/*{{{*/
    int c;

    fgetc(stdin);
    fputs("Play again? [Y/n]", stdout);

    while(!chinstr(c, "nyNY\r\n"))
        c = fgetc(stdin);

    return !chinstr(c, "nN");
}/*}}}*/

void
loop(struct game *g)
{/*{{{*/
    char *wait_msg = "Rock... \1Paper... \1Scissors... \1Go!\1\n";
    struct play p;
    int playing = 1;

    while(playing){
        play_get(&p);
        wprint(wait_msg);
        play_check(&p, g);
        stats(g);
        playing = prompt_playing();
    }
}/*}}}*/

void
intro()
{/*{{{*/
    puts( "##################################################\n"
          "## A game of Rock Paper Scissors by Braden Best ##\n"
          "##     To play, choose a hand and be lucky      ##\n"
          "##                                              ##\n"
          "## This friendly computer will be your opponent ##\n"
          "##################################################\n");
}/*}}}*/

int
main()
{
    struct game g = {0};

    srand(time(0));
    intro();
    loop(&g);
    puts("Opponent says: \e[0;32mBye!\e[0m");

    return 0;
}

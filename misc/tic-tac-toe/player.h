/* This header contains the structures concerning players in the game */
#ifndef PLAYER
#define PLAYER
#define MAX_LEN_NAME 100
typedef enum marker { X, O } Marker;

struct player {
    int wins;           // number of games won
    int losses;         // number of games lost
    Marker sign;        // the sign to use, either 'X' or 'O'
    char *name;
};

struct player* initialize_player(Marker sign, char *name);     // used to initialize player structure (pick sign)
void win(struct player *p);                             // used when player wins
void lose(struct player *p);                            // used when player loses
#endif

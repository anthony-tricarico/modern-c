#include <stdio.h>

/* (a) Define two enumerated types: Piece, which has seven possible values, and Color, which has two */
typedef enum {empty, knight, bishop, rook, queen, king, pawn} Piece;
typedef enum {black, white} Color;

/* (b) Using the types from part (a), define a structure type named Square that can store both the type of a piece and a color */
typedef struct {
    Piece piece;
    Color color;
} Square;

/* (c) Using the Square type from part (b), declare an 8x8 array named board that can store the entire contents of a chessboard */
Square board[8][8] = {
    {
        {rook, black},
        {knight, black},
        {bishop, black},
        {king, black},
        {queen, black},
        {bishop, black},
        {knight, black},
        {rook, black}
    }, // initialize the first row
    {[0 ... 7] = {pawn, black}}, // initialize the second row
    { {empty, black} },
    { {empty, black} },
    { {empty, black} },
    { {empty, black} },
    {[0 ... 7] = {pawn, white}}, // initialize the seventh row
    {
        {rook, white},
        {knight, white},
        {bishop, white},
        {king, white},
        {queen, white},
        {bishop, white},
        {knight, white},
        {rook, white}
    } // initialize the eigth row
};

int main(void) {
    printf("The piece in the second row and fourth col is %d %d\n", board[1][3].piece, board[1][3].color); 
    return 0;
}


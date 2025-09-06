/* Let chess_pieces be the following enumeration */
enum chess_pieces {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};

/* (a) Write a declaration (including an initializer) for a constant array of integers named piece_value that stores the numbers
* 200, 9, 5, 3, 3, and 1 */
#if 0
const int piece_value[] = {200, 9, 5, 3, 3, 1};
#endif

/* (b) (C99) Use a designated initializer to initialize the array. Use the enumeration constants in
* chess_pieces as subscripts in the designators */
const int piece_value[] = {[KING] = 200, [QUEEN] = 9, [ROOK] = 5, [BISHOP] = 3, [KNIGHT] = 3, [PAWN] = 1};

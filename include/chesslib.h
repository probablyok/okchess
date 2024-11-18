#ifndef CHESSLIB_H
#define CHESSLIB_H

#define START_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"

#include <stdio.h>

#define NOP 0b0000 // No piece.
#define NOV 0b1111 // No valid.

// White pieces.
#define W_P 0b0001
#define W_N 0b0010
#define W_B 0b0011
#define W_R 0b0100
#define W_Q 0b0101
#define W_K 0b0110

// Black pieces.
#define B_P 0b1001
#define B_N 0b1010
#define B_B 0b1011
#define B_R 0b1100
#define B_Q 0b1101
#define B_K 0b1110

void init_board(int[8][8], char*);
void display_board(int[8][8]);
char get_char_rep(int);
int get_binary_rep(char);
void move_piece(int[8][8], int[2], int[2]);

#endif
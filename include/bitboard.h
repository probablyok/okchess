#ifndef BITBOARD_H
#define BITBOARD_H

#include <stdint.h>

#define IS_BIT_SET(bitboard, square) ((bitboard) & (1ULL << (square)))
#define START_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"

// 64-bit word representing positions for piece type on board.
// Bit 0 represents A1, bit 7 represents h1, up until bit 63 is h8.
typedef uint64_t Bitboard;

// Stores bitboards for each piece.
typedef struct {
    Bitboard wp;
    Bitboard wn;
    Bitboard wb;
    Bitboard wr;
    Bitboard wq;
    Bitboard wk;

    Bitboard bp;
    Bitboard bn;
    Bitboard bb;
    Bitboard br;
    Bitboard bq;
    Bitboard bk;
} ChessBoard;

// Simple enum for piece types
enum PieceType {
    WHITE_PAWN   = 'P',
    WHITE_KNIGHT = 'N',
    WHITE_BISHOP = 'B',
    WHITE_ROOK   = 'R',
    WHITE_QUEEN  = 'Q',
    WHITE_KING   = 'K',
    BLACK_PAWN   = 'p',
    BLACK_KNIGHT = 'n',
    BLACK_BISHOP = 'b',
    BLACK_ROOK   = 'r',
    BLACK_QUEEN  = 'q',
    BLACK_KING   = 'k',
};

void init_board(ChessBoard*, char*);
void clear_board(ChessBoard*);
void set_square(ChessBoard*, enum PieceType piece, int, int);
void display_board(ChessBoard*);

#endif
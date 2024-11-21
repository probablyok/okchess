#ifndef BITBOARD_H
#define BITBOARD_H

#include <stdint.h>

#define IS_BIT_SET(bitboard, square) ((bitboard) & (1ULL << (square)))

#define START_FEN "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR"

#define RANK1 0x00000000000000FF
#define RANK2 0x000000000000FF00
#define RANK3 0x0000000000FF0000
#define RANK4 0x00000000FF000000
#define RANK5 0x000000FF00000000
#define RANK6 0x0000FF0000000000
#define RANK7 0x00FF000000000000
#define RANK8 0xFF00000000000000

#define FILEA 0x0101010101010101
#define FILEB 0x0202020202020202
#define FILEC 0x0404040404040404
#define FILED 0x0808080808080808
#define FILEE 0x1010101010101010
#define FILEF 0x2020202020202020
#define FILEG 0x4040404040404040
#define FILEH 0x8080808080808080

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
void display_bitboard(Bitboard*);

Bitboard occupied_spaces(ChessBoard*);
Bitboard unoccupied_spaces(ChessBoard*);

Bitboard b_pieces(ChessBoard*);
Bitboard w_pieces(ChessBoard*);

#endif
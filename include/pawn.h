#ifndef MOVES_H
#define MOVES_H

#include "bitboard.h"

Bitboard wp_push_targets(ChessBoard*, Bitboard*);
Bitboard wp_dbl_push_targets(ChessBoard*, Bitboard*);
Bitboard wp_can_push(ChessBoard*, Bitboard*);
Bitboard wp_can_dbl_push(ChessBoard*, Bitboard*);

Bitboard bp_push_targets(ChessBoard*, Bitboard*);
Bitboard bp_dbl_push_targets(ChessBoard*, Bitboard*);
Bitboard bp_can_push(ChessBoard*, Bitboard*);
Bitboard bp_can_dbl_push(ChessBoard*, Bitboard*);

#endif
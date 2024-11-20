#ifndef MOVES_H
#define MOVES_H

#include "bitboard.h"

Bitboard wp_push_targets(ChessBoard*);
Bitboard bp_push_targets(ChessBoard*);

Bitboard wp_dbl_push_targets(ChessBoard*);
Bitboard bp_dbl_push_targets(ChessBoard*);


#endif
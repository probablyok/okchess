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

Bitboard wp_east_attacks(ChessBoard*);
Bitboard wp_west_attacks(ChessBoard*);
Bitboard wp_any_attacks(ChessBoard*);
Bitboard wp_capture_targets(ChessBoard*);
Bitboard wp_can_capture_east(ChessBoard*);
Bitboard wp_can_capture_west(ChessBoard*);
Bitboard wp_can_capture_any(ChessBoard*);

Bitboard bp_east_attacks(ChessBoard*);
Bitboard bp_west_attacks(ChessBoard*);
Bitboard bp_any_attacks(ChessBoard*);
Bitboard bp_capture_targets(ChessBoard*);
Bitboard bp_can_capture_east(ChessBoard*);
Bitboard bp_can_capture_west(ChessBoard*);
Bitboard bp_can_capture_any(ChessBoard*);

#endif
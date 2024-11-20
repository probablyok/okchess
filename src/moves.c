#include "moves.h"
#include "bitboard.h"

#include <stdio.h>

Bitboard wp_push_targets(ChessBoard* board) {
    Bitboard push = board->wp << 8;
    return (push & unoccupied_spaces(board));
}

Bitboard wp_dbl_push_targets(ChessBoard* board) {
    Bitboard single_push = wp_push_targets(board);
    Bitboard double_push = single_push << 8;
    return (double_push & unoccupied_spaces(board) & RANK4);
}

Bitboard bp_push_targets(ChessBoard* board) {
    Bitboard push = board->bp >> 8;
    return (push & unoccupied_spaces(board));
}

Bitboard bp_dbl_push_targets(ChessBoard* board) {
    Bitboard single_push = bp_push_targets(board);
    Bitboard double_push = single_push >> 8;
    return (double_push & unoccupied_spaces(board) & RANK5);
}
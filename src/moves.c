#include "moves.h"
#include "bitboard.h"

#include <stdio.h>

Bitboard wp_push_targets(ChessBoard* board) {
    // Move each white pawn up north.
    Bitboard push = board->wp << 8;
    return (push & unoccupied_spaces(board));
}
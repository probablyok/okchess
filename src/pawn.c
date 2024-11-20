#include "pawn.h"
#include "bitboard.h"

#include <stdio.h>


// The positions of every valid single push for white pawns.
Bitboard wp_push_targets(ChessBoard* board, Bitboard* empty) {
    Bitboard push = board->wp << 8;
    return (push & *empty);
}

// The positions of every valid double push for white pawns. 
Bitboard wp_dbl_push_targets(ChessBoard* board, Bitboard* empty) {
    Bitboard single_push = wp_push_targets(board, empty);
    Bitboard double_push = single_push << 8;
    return (double_push & *empty & RANK4);
}

// The position of each white pawn that is able to single push.
Bitboard wp_can_push(ChessBoard* board, Bitboard* empty) {
    Bitboard reverse_push = *empty >> 8;
    return (reverse_push & board->wp);
}

// The position of each white pawn that is able to double push.
Bitboard wp_can_dbl_push(ChessBoard* board, Bitboard* empty) {
    Bitboard empty_in_rank3_and_4 = ((*empty & RANK4) >> 8) & *empty;
    return (wp_can_push(board, &empty_in_rank3_and_4));
}

// The positions of every valid double push for black pawns.
Bitboard bp_push_targets(ChessBoard* board, Bitboard* empty) {
    Bitboard push = board->bp >> 8;
    return (push & *empty);
}

// The positions of every valid double push for black pawns.
Bitboard bp_dbl_push_targets(ChessBoard* board, Bitboard* empty) {
    Bitboard single_push = bp_push_targets(board, empty);
    Bitboard double_push = single_push >> 8;
    return (double_push & *empty & RANK5);
}

// The position of each black pawn that is able to single push.
Bitboard bp_can_push(ChessBoard* board, Bitboard* empty) {
    Bitboard reverse_push = *empty << 8;
    return (reverse_push & board->bp);
}

// The position of each black pawn that is able to double push.
Bitboard bp_can_dbl_push(ChessBoard* board, Bitboard* empty) {
    Bitboard empty_in_rank5_and_6 = ((*empty & RANK5) << 8) & *empty;
    return (wp_can_push(board, &empty_in_rank5_and_6));
}
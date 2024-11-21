#include "pawn.h"
#include "bitboard.h"

#include <stdio.h>

// PUSHING

// WHITE

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

// BLACK

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

// CAPTURING

// WHITE

Bitboard wp_east_attacks(ChessBoard* board) {
    return ((board->wp << 9) & ~FILEA);
}

Bitboard wp_west_attacks(ChessBoard* board) {
    return ((board->wp << 7) & ~FILEH);
}

Bitboard wp_any_attacks(ChessBoard* board) {
    return (wp_east_attacks(board) | wp_west_attacks(board));
}

Bitboard wp_capture_targets(ChessBoard* board) {
    return (wp_any_attacks(board) & b_pieces(board));
}

Bitboard wp_can_capture_east(ChessBoard* board) {
    return (board->wp & b_pieces(board) >> 9 & ~FILEH);
}

Bitboard wp_can_capture_west(ChessBoard* board) {
    return (board->wp & b_pieces(board) >> 7 & ~FILEA);
}

Bitboard wp_can_capture_any(ChessBoard* board) {
    return (wp_can_capture_east(board) | wp_can_capture_west(board));
}

// BLACK

Bitboard bp_east_attacks(ChessBoard* board) {
    return ((board->wp >> 7) & ~FILEA);
}

Bitboard bp_west_attacks(ChessBoard* board) {
    return ((board->wp >> 9) & ~FILEH);
}

Bitboard bp_any_attacks(ChessBoard* board) {
    return (bp_east_attacks(board) | bp_west_attacks(board));
}

Bitboard bp_capture_targets(ChessBoard* board) {
    return (bp_any_attacks(board) & w_pieces(board));
}

Bitboard bp_can_capture_east(ChessBoard* board) {
    return (board->bp & w_pieces(board) << 7 & ~FILEH);
}

Bitboard bp_can_capture_west(ChessBoard* board) {
    return (board->bp & w_pieces(board) << 9 & ~FILEA);
}

Bitboard bp_can_capture_any(ChessBoard* board) {
    return (bp_can_capture_east(board) | bp_can_capture_west(board));
}
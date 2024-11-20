#include <stdio.h>
#include "bitboard.h"

Bitboard occupied_spaces(ChessBoard* board) {
    // Return union of all bitboards for each piece.
    return (
        board->wp | board->wn | board->wb | board->wr |
        board->wk | board->wq | board->bp | board->bn |
        board->bb | board->br | board->bk | board->bq
    );
}

Bitboard unoccupied_spaces(ChessBoard* board) {
    Bitboard occupied = occupied_spaces(board);
    return ~occupied;
}

void display_bitboard(Bitboard* bitboard) {
    printf("   a b c d e f g h\n");
    for (int rank = 0; rank < 8; rank++) {
        printf("%d ", rank+1);
        for (int file = 0; file < 8; file++) {
            int square = rank * 8 + file;
            (IS_BIT_SET(*bitboard, square)) ? printf("|1") : printf("|0");
        }
        printf("| %d\n", rank+1);
    }
    printf("   a b c d e f g h\n");
}

void display_board(ChessBoard* board) {
    printf("   a b c d e f g h\n");
    for (int rank = 0; rank < 8; rank++) {
        printf("%d ", rank+1);
        for (int file = 0; file < 8; file++) {
            int square = rank * 8 + file;

            if      IS_BIT_SET(board->wp, square) printf("|P");
            else if IS_BIT_SET(board->wn, square) printf("|N");
            else if IS_BIT_SET(board->wb, square) printf("|B");
            else if IS_BIT_SET(board->wr, square) printf("|R");
            else if IS_BIT_SET(board->wk, square) printf("|K");
            else if IS_BIT_SET(board->wq, square) printf("|Q");
            else if IS_BIT_SET(board->bp, square) printf("|p");
            else if IS_BIT_SET(board->bn, square) printf("|n");
            else if IS_BIT_SET(board->bb, square) printf("|b");
            else if IS_BIT_SET(board->br, square) printf("|r");
            else if IS_BIT_SET(board->bk, square) printf("|k");
            else if IS_BIT_SET(board->bq, square) printf("|q");
            else    printf("| ");
        }
        printf("| %d\n", rank+1);
    }
    printf("   a b c d e f g h\n");
}

void clear_board(ChessBoard* board) {
    board->wp = 0ULL;
    board->wn = 0ULL;
    board->wb = 0ULL;
    board->wr = 0ULL;
    board->wq = 0ULL;
    board->wk = 0ULL;
    board->bp = 0ULL;
    board->bn = 0ULL;
    board->bb = 0ULL;
    board->br = 0ULL;
    board->bq = 0ULL;
    board->bk = 0ULL;
}

void set_square(ChessBoard* board, enum PieceType piece, int rank, int file) {
    int square = rank * 8 + file;
    Bitboard mask = 1ULL << square;

    switch (piece) {
        case BLACK_PAWN:   board->bp |= mask; break;
        case BLACK_KNIGHT: board->bn |= mask; break;
        case BLACK_BISHOP: board->bb |= mask; break;
        case BLACK_ROOK:   board->br |= mask; break;
        case BLACK_KING:   board->bk |= mask; break;
        case BLACK_QUEEN:  board->bq |= mask; break;
        case WHITE_PAWN:   board->wp |= mask; break;
        case WHITE_KNIGHT: board->wn |= mask; break;
        case WHITE_BISHOP: board->wb |= mask; break;
        case WHITE_ROOK:   board->wr |= mask; break;
        case WHITE_QUEEN:  board->wq |= mask; break;
        case WHITE_KING:   board->wk |= mask; break;
        default: break;
    }
}

void init_board(ChessBoard* board, char *fen_str) {
    // Clear board so no need to manually set spaces.
    clear_board(board);

    int cur_file = 0;
    int cur_rank = 0;

    for (int str_index = 0; fen_str[str_index] != '\0'; str_index++) {
        // Move up file
        if (fen_str[str_index] == '/') {
            cur_file = 0;
            cur_rank++;
            continue;
        }

        // Add spaces.
        if (fen_str[str_index] >= '0' && fen_str[str_index] <= '9') {
            // Convert to integer using ASCII values.
            int empty_amt = fen_str[str_index] - '0';
            cur_file += empty_amt;
            continue;
        }

        // Add pieces.
        set_square(board, fen_str[str_index], cur_rank, cur_file);
        cur_file++;
    }
}
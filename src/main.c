#include "bitboard.h"

int main() {
    ChessBoard board;

    init_board(&board, START_FEN);
    display_board(&board);
    return 0;
}
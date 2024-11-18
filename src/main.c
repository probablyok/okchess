#include "bitboard.h"

int main() {
    char example_fen[] = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR";
    ChessBoard board;

    init_board(&board, START_FEN);
    display_board(&board);
    return 0;
}
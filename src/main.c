#include "bitboard.h"

int main() {
    ChessBoard board;

    init_board(&board, START_FEN);
    display_board(&board);

    Bitboard occupied = occupied_spaces(&board);
    Bitboard unoccupied = unoccupied_spaces(&board);
    display_bitboard(&occupied);
    display_bitboard(&unoccupied);
    return 0;
}
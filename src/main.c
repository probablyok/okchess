#include "chesslib.h"

int main() {
    char example_fen[] = "rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR";
    int cur_board[8][8];

    init_board(cur_board, START_FEN);
    display_board(cur_board);
    return 0;
}
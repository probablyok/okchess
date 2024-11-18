#include "chesslib.h"

void display_board(int board[8][8]) {
    printf("   a b c d e f g h\n");
    for (int rank = 0; rank <= 7; rank++) {
        printf("%d ", 8 - rank);
        for (int file = 0; file <= 7; file++) {
            printf("|%c", get_char_rep(board[rank][file]));
        }
        printf("| %d\n", 8 - rank);
    }
    printf("   a b c d e f g h\n");
}

void init_board(int board[8][8], char* fen_str) {
    int cur_file = 0;
    int cur_rank = 0;

    for (int str_idx = 0; fen_str[str_idx] != '\0'; str_idx++) {
        // Move up file.
        if (fen_str[str_idx] == '/') {
            cur_rank++;
            cur_file = 0;
            continue;
        }

        // Add spaces.
        if (fen_str[str_idx] >= '0' && fen_str[str_idx] <= '9') {
            // Convert to integer using ASCII values.
            int empty_amt = fen_str[str_idx] - '0';
            for (int empty_idx = 0; empty_idx < empty_amt; empty_idx++) {
                board[cur_rank][cur_file] = NOP;
                cur_file++;
            }
            continue;
        }

        // Add piece.
        int pos_value;
        pos_value = get_binary_rep(fen_str[str_idx]);
        board[cur_rank][cur_file] = pos_value;
        cur_file++;
    }
}

void move_piece(int board[8][8], int to_move[2], int moved_to[2]) {
    board[moved_to[0]][moved_to[1]] = board[to_move[0]][to_move[1]];
    board[to_move[0]][to_move[1]] = NOP;
}

char get_char_rep(int binary_rep) {
    char char_rep;
    switch (binary_rep) {
        // White pieces.
        case W_P:
            char_rep = 'P';
            break;
        case W_N:
            char_rep = 'N';
            break;
        case W_B:
            char_rep = 'B';
            break;
        case W_R:
            char_rep = 'R';
            break;
        case W_Q:
            char_rep = 'Q';
            break;
        case W_K:
            char_rep = 'K';
            break;

        // Black pieces.
        case B_P:
            char_rep = 'p';
            break;
        case B_N:
            char_rep = 'n';
            break;
        case B_B:
            char_rep = 'b';
            break;
        case B_R:
            char_rep = 'r';
            break;
        case B_Q:
            char_rep = 'q';
            break;
        case B_K:
            char_rep = 'k';
            break;

        // No piece
        case NOP:
            char_rep = ' ';
            break;

        // Invalid piece
        default:
            char_rep = '!';
            break;
    }
    return char_rep;
}

int get_binary_rep(char char_rep) {
    int binary_rep;
    switch (char_rep) {
        // Black pieces.
        case 'p':
            binary_rep = B_P;
            break;
        case 'n':
            binary_rep = B_N;
            break;
        case 'b':
            binary_rep = B_B;
            break;
        case 'r':
            binary_rep = B_R;
            break;
        case 'q':
            binary_rep = B_Q;
            break;
        case 'k':
            binary_rep = B_K;
            break;

        // White pieces.
        case 'P':
            binary_rep = W_P;
            break;
        case 'N':
            binary_rep = W_N;
            break;
        case 'B':
            binary_rep = W_B;
            break;
        case 'R':
            binary_rep = W_R;
            break;
        case 'Q':
            binary_rep = W_Q;
            break;
        case 'K':
            binary_rep = W_K;
            break;

        // Invalid piece.
        default:
            binary_rep = NOV;
            break;
    }
    return binary_rep;
}
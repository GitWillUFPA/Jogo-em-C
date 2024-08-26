#include <stdio.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE]);
int checkDraw(char board[SIZE][SIZE]);
void makeMove(char board[SIZE][SIZE], int player);

int main() {
    char board[SIZE][SIZE];
    int currentPlayer = 1;
    int gameOver = 0;

    initializeBoard(board);

    while (!gameOver) {
        printBoard(board);
        makeMove(board, currentPlayer);

        if (checkWin(board)) {
            printBoard(board);
            printf("Jogador %d venceu!\n", currentPlayer);
            gameOver = 1;
        } else if (checkDraw(board)) {
            printBoard(board);
            printf("Empate!\n");
            gameOver = 1;
        } else {
            currentPlayer = (currentPlayer == 1) ? 2 : 1;
        }
    }

    return 0;
}

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---+---+---\n");
    }
    printf("\n");
}

int checkWin(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1;

    return 0;
}

int checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

void makeMove(char board[SIZE][SIZE], int player) {
    int x, y;
    char mark = (player == 1) ? 'X' : 'O';

    while (1) {
        printf("Jogador %d (%c), entre com sua jogada (linha e coluna): ", player, mark);
        scanf("%d %d", &x, &y);

        if (x >= 1 && x <= SIZE && y >= 1 && y <= SIZE && board[x-1][y-1] == ' ') {
            board[x-1][y-1] = mark;
            break;
        } else {
            printf("Jogada inválida! Tente novamente.\n");
        }
    }
}

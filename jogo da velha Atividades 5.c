#include <iostream>
using namespace std;

#define SIZE 3

class TicTacToe {
private:
    char board[SIZE][SIZE];
    int *player1Moves;
    int *player2Moves;
    int moveCount;

    void alocarHist() {
        player1Moves = new int[SIZE * SIZE];
        player2Moves = new int[SIZE * SIZE];
    }

    void cadastrarRegInHist(int player, int position) {
        if (player == 1) {
            player1Moves[moveCount] = position;
        } else {
            player2Moves[moveCount] = position;
        }
        moveCount++;
    }

public:
    TicTacToe() {
        initializeBoard();
        alocarHist();
        moveCount = 0;
    }

    TicTacToe(const TicTacToe &other) {
        initializeBoard();
        moveCount = other.moveCount;
        alocarHist();
        for (int i = 0; i < SIZE * SIZE; i++) {
            player1Moves[i] = other.player1Moves[i];
            player2Moves[i] = other.player2Moves[i];
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = other.board[i][j];
            }
        }
    }

    ~TicTacToe() {
        delete[] player1Moves;
        delete[] player2Moves;
    }

    void playGame() {
        int currentPlayer = 1;
        bool gameOver = false;

        while (!gameOver) {
            printBoard();
            makeMove(currentPlayer);

            if (checkWin()) {
                printBoard();
                cout << "Jogador " << currentPlayer << " venceu!" << endl;
                gameOver = true;
            } else if (checkDraw()) {
                printBoard();
                cout << "Empate!" << endl;
                gameOver = true;
            } else {
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
        }
    }

private:
    void initializeBoard() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                board[i][j] = ' ';
            }
        }
    }

    void printBoard() {
        cout << "\n";
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << " " << board[i][j] << " ";
                if (j < SIZE - 1) cout << "|";
            }
            cout << "\n";
            if (i < SIZE - 1) cout << "---+---+---\n";
        }
        cout << "\n";
    }

    bool checkWin() {
        for (int i = 0; i < SIZE; i++) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
                return true;
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
                return true;
        }
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
            return true;
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
            return true;

        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] == ' ')
                    return false;
            }
        }
        return true;
    }

    void makeMove(int player) {
        int x, y;
        char mark = (player == 1) ? 'X' : 'O';

        while (true) {
            cout << "Jogador " << player << " (" << mark << "), entre com sua jogada (linha e coluna): ";
            cin >> x >> y;

            if (x >= 1 && x <= SIZE && y >= 1 && y <= SIZE && board[x-1][y-1] == ' ') {
                board[x-1][y-1] = mark;
                cadastrarRegInHist(player, (x-1) * SIZE + (y-1));
                break;
            } else {
                cout << "Jogada inválida! Tente novamente." << endl;
            }
        }
    }

    void analyzeMoves() {
        cout << "Análise de jogadas: " << endl;
        cout << "Jogador 1 jogou nas posições: ";
        for (int i = 0; i < moveCount; i++) {
            cout << player1Moves[i] << " ";
        }
        cout << endl;

        cout << "Jogador 2 jogou nas posições: ";
        for (int i = 0; i < moveCount; i++) {
            cout << player2Moves[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    TicTacToe *gamePtr = new TicTacToe();
    gamePtr->playGame();

    delete gamePtr;

    gamePtr = new TicTacToe();
    gamePtr->playGame();

    delete gamePtr;

    return 0;
}

#include <iostream>
#include <fstream> // библиотека для работы с файлами
#include <vector>


using namespace std;

// строковые константы для удобного отображения результата
const string xWon = "X won";
const string oWon = "O won";
const string draw = "Draw";
const string notFinished = "Game has not completed";

ifstream in("/Users/yanametro/Desktop/input"); // путь до входного файла
ofstream out("/Users/yanametro/Desktop/output"); // путь для выходного файла

vector<string> getBoard() {
    vector<string> v(4);
    for (int i = 0; i < 4; ++i) {
        in >> v[i];
    }
    return v;
}

// board -- это одно поле 4х4
string processBoard(const vector<string>& board) {
    vector<int> x_row(4), x_column(4), o_row(4), o_column(4);
    vector<int> x_diag(2), o_diag(2);
    bool is_full = true;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] == '.') {
                is_full = false;
            }
            
            if (board[i][j] == 'X') {
                x_row[i]++;
                x_column[j]++;
            }
            if (board[i][j] == 'O') {
                o_row[i]++;
                o_column[j]++;
            }
            if (board[i][j] == 'T') {
                x_row[i]++;
                x_column[j]++;
                o_row[i]++;
                o_column[j]++;
            }
        }
    }
    
    for (int i = 0; i < 4; ++i) {
        if (board[i][i] == 'X') {
            x_diag[0]++;
        }
        if (board[i][3 - i] == 'X') {
            x_diag[1]++;
        }
        if (board[i][i] == 'O') {
            o_diag[0]++;
        }
        if (board[i][3 - i] == 'O') {
            o_diag[1]++;
        }
        if (board[i][i] == 'T') {
            o_diag[0]++;
            x_diag[0]++;
        }
        if (board[i][3 - i] == 'T') {
            o_diag[1]++;
            x_diag[1]++;
        }
    }
    
    for (int i = 0; i < 4; ++i) {
        if (x_row[i] == 4 || x_column[i] == 4) {
            return xWon;
        }
        
        if (o_row[i] == 4 || o_column[i] == 4) {
            return oWon;
        }
    }
    
    for (int i = 0; i < 2; ++i) {
        if (x_diag[i] == 4) {
            return xWon;
        }
        
        if (o_diag[i] == 4) {
            return oWon;
        }
    }
    
    if (is_full) {
        return draw;
    } else {
        return notFinished;
    }
}

int main() {
    int T;
    in >> T;
    for (int i = 1; i <= T; ++i) {
        vector<string> board = getBoard();
        out << "Case #" << i << ": " << processBoard(board) << "\n";
    }
    
    return 0;
}


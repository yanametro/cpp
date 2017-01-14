#include <iostream>
#include <fstream> // библиотека для работы с файлами
#include <vector>


using namespace std;

// строковые константы для удобного отображения результата
const string xWon = "X won";
const string oWon = "O won";
const string draw = "Draw";
const string notFinished = "Game has not completed";

ifstream in("input"); // путь до входного файла
ofstream out("output"); // путь для выходного файла

vector<string> getBoard() {
    vector<string> v(4);
    for (int i = 0; i < 4; ++i) {
        in >> v[i];
    }
    return v;
}

// board -- это одно поле 4х4
string processBoard(const vector<string>& board) {
    // your code
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


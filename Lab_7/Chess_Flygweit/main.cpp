#include <iostream>
#include <string>
#include "chess.h"
using namespace std;


int main() {
    ChessBoard board;
    string from, to;

    while (true) {
        board.printBoard();
        cout << "Enter move (e.g. E2 E4 or Q to quit): ";
        cin >> from;
        if (from == "Q" || from == "q") break;
        cin >> to;

        auto [fromRow, fromCol] = parsePosition(from);
        auto [toRow, toCol] = parsePosition(to);

        if (fromRow < 0 || fromRow > 7 || toRow < 0 || toRow > 7 ||
            fromCol < 0 || fromCol > 7 || toCol < 0 || toCol > 7) {
            cout << "Invalid move!\n";
            continue;
        }

        board.movePiece(fromRow, fromCol, toRow, toCol);
    }

    return 0;
}
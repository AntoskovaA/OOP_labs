#include <iostream>
#include <string>
#include <cctype>
#include "chess.h"
using namespace std;

ChessPiece::ChessPiece(bool is_white) : isWhite(is_white) {}

string King::getSymbol() {
    return isWhite ? "\033[37m♔\033[0m" : "\033[90m♚\033[0m";
}
King::King(bool isWhite) : ChessPiece(isWhite) {}

std::string Queen::getSymbol() {
    return isWhite ? "\033[37m♕\033[0m" : "\033[90m♛\033[0m";
}

Queen::Queen(bool isWhite) : ChessPiece(isWhite) {}

std::string Rook::getSymbol() {
    return isWhite ? "\033[37m♖\033[0m" : "\033[90m♜\033[0m";
}

Rook::Rook(bool isWhite) : ChessPiece(isWhite) {}

string Bishop::getSymbol() {
    return isWhite ? "\033[37m♗\033[0m" : "\033[90m♝\033[0m";
}

Bishop::Bishop(bool isWhite) : ChessPiece(isWhite) {}

string Knight::getSymbol() {
    return isWhite ? "\033[37m♘\033[0m" : "\033[90m♞\033[0m";
}

Knight::Knight(bool isWhite) : ChessPiece(isWhite) {}

string Pawn::getSymbol() {
    return isWhite ? "\033[37m♙\033[0m" : "\033[90m♟\033[0m";
}

Pawn::Pawn(bool isWhite) : ChessPiece(isWhite) {}

PieceFactory::PieceFactory() {
    pieces[0] = new King(true);
    pieces[1] = new Queen(true);
    pieces[2] = new Rook(true);
    pieces[3] = new Bishop(true);
    pieces[4] = new Knight(true);
    pieces[5] = new Pawn(true);
    pieces[6] = new King(false);
    pieces[7] = new Queen(false);
    pieces[8] = new Rook(false);
    pieces[9] = new Bishop(false);
    pieces[10] = new Knight(false);
    pieces[11] = new Pawn(false);
}

PieceFactory::~PieceFactory() {
    for (int i = 0; i < 12; ++i) {
        delete pieces[i];
    }
}

ChessPiece* PieceFactory::getPiece(const string& type, bool isWhite) {
    if (type == "King") return pieces[isWhite ? 0 : 6];
    else if (type == "Queen") return pieces[isWhite ? 1 : 7];
    else if (type == "Rook") return pieces[isWhite ? 2 : 8];
    else if (type == "Bishop") return pieces[isWhite ? 3 : 9];
    else if (type == "Knight") return pieces[isWhite ? 4 : 10];
    else if (type == "Pawn") return pieces[isWhite ? 5 : 11];
    return nullptr;
}

void ChessBoard::movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    if (board[fromRow][fromCol]) {
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = nullptr;
    }
}

void ChessBoard::printBoard() {
    cout << "  A B C D E F G H\n";
    for (int i = 7; i >= 0; --i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 8; ++j) {
            if (board[i][j])
                cout << board[i][j]->getSymbol() << " ";
            else
                cout << ". ";
        }
        cout << i + 1 << "\n";
    }
    cout << "  A B C D E F G H\n";
}

void ChessBoard::setupBoard() {
        // White
    board[0][0] = factory.getPiece("Rook", true);
    board[0][1] = factory.getPiece("Knight", true);
    board[0][2] = factory.getPiece("Bishop", true);
    board[0][3] = factory.getPiece("Queen", true);
    board[0][4] = factory.getPiece("King", true);
    board[0][5] = factory.getPiece("Bishop", true);
    board[0][6] = factory.getPiece("Knight", true);
    board[0][7] = factory.getPiece("Rook", true);
    for (int i = 0; i < 8; ++i)
        board[1][i] = factory.getPiece("Pawn", true);

        // Black
    board[7][0] = factory.getPiece("Rook", false);
    board[7][1] = factory.getPiece("Knight", false);
    board[7][2] = factory.getPiece("Bishop", false);
    board[7][3] = factory.getPiece("Queen", false);
    board[7][4] = factory.getPiece("King", false);
    board[7][5] = factory.getPiece("Bishop", false);
    board[7][6] = factory.getPiece("Knight", false);
    board[7][7] = factory.getPiece("Rook", false);
    for (int i = 0; i < 8; ++i)
        board[6][i] = factory.getPiece("Pawn", false);

    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            board[i][j] = nullptr;
        }
    }
}
ChessBoard::ChessBoard() {
    setupBoard();
}

pair<int, int> parsePosition(string pos) {
    char col = toupper(pos[0]);
    int row = pos[1] - '1';
    int colIndex = col - 'A';
    return { row, colIndex };
}

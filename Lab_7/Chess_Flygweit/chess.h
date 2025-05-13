#pragma once
#include <string>

class ChessPiece {
protected:
    bool isWhite;

public:
    ChessPiece(bool is_white);
    virtual std::string getSymbol() = 0;
};

class King : public ChessPiece {
public:
    King(bool isWhite);
    std::string getSymbol() override;
};

class Queen : public ChessPiece {
public:
    Queen(bool isWhite);
    std::string getSymbol()override;
};

class Rook : public ChessPiece {
public:
    Rook(bool isWhite);
    std::string getSymbol() override;
};

class Bishop : public ChessPiece {
public:
    Bishop(bool isWhite);
    std::string getSymbol() override;
};

class Knight : public ChessPiece {
public:
    Knight(bool isWhite);
    std::string getSymbol()override;
};

class Pawn : public ChessPiece {
public:
    Pawn(bool isWhite);
    std::string getSymbol() override;
};


class PieceFactory {
    ChessPiece* pieces[12]; 
public:
    PieceFactory();
    ~PieceFactory();
    ChessPiece* getPiece(const std::string& type, bool isWhite);
};

class ChessBoard {
    ChessPiece* board[8][8];
    PieceFactory factory;

public:
    ChessBoard();
    void setupBoard();
    void printBoard();
    void movePiece(int fromRow, int fromCol, int toRow, int toCol);
};

std::pair<int, int> parsePosition(std::string pos);
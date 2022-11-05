#include "board.h"

#include <vector>
#include <iostream>
using std::vector;

Board::Board(vector<vector<int>>& board_data) {
    m = board_data.size();
    n = m > 0 ? board_data[0].size() : 0;
    this->board_data = board_data;
}

vector<vector<int>> Board::next_state() {
    vector<vector<int>> next = {};
    for (int i = 0; i < m; i++) {
        vector<int> row = {};
        for (int j = 0; j < n; j++) {
            row.push_back((this->operator()(i,j) + 1) % 2);
        }
        next.push_back(row);
    }
    return next;
}

int& Board::operator()(int x, int y) {
    return board_data[x][y];
}

std::ostream& operator<<(std::ostream& out, Board& board) {
    // out << "board.m = " << board.m << ", board.n = " << board.n << "\n";
    for (int i = 0; i < board.m; i++) {
        for (int j = 0; j < board.n; j++) {
            out << board(i, j) << " ";
        }
        out << '\n';
    }
    return out;
}

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
    //std::cout << "m = " << m << ", n = " << n << std::endl;
    for (int i = 0; i < m; i++) {
        //std::cout << "i = " << i << std::endl;
        vector<int> row = {};
        for (int j = 0; j < n; j++) {
            //std::cout << "j = " << j << std::endl;
            int next_value = this->operator()(i,j);
            int temp =  ((i>0 &&   j>0)   ? this->operator()(i-1, j-1) : 0) +
                        ((i>0)            ? this->operator()(i-1, j  ) : 0) +
                        ((i>0 &&   j<n-1) ? this->operator()(i-1, j+1) : 0) +
                        ((         j>0 )  ? this->operator()(i  , j-1) : 0) +
                        //
                        ((         j<n-1) ? this->operator()(i  , j+1) : 0) +
                        ((i<m-1 && j>0  ) ? this->operator()(i+1, j-1) : 0) +
                        ((i<m-1         ) ? this->operator()(i+1, j  ) : 0) +
                        ((i<m-1 && j<n-1) ? this->operator()(i+1, j+1) : 0);
            switch (temp) {
                case 2:
                    // do nothing.  With two neighors
                    // dead cell does not become live and
                    // live cell does not die.
                    break;
                case 3:
                    next_value = 1;
                    break;
                default:
                    next_value = 0;
            }
            row.push_back(next_value);
            //row.push_back((this->operator()(i,j) + 1) % 2);
        }
        next.push_back(row);
        //std::cout << "Adding a row!\n";
    }
    return next;
}

int& Board::operator()(int x, int y) {
    return board_data[x][y];
}

// std::ostream& operator<<(std::ostream& out, Board& board) {
//     // out << "board.m = " << board.m << ", board.n = " << board.n << "\n";
//     for (int i = 0; i < board.m; i++) {
//         for (int j = 0; j < board.n; j++) {
//             out << board(i, j) << " ";
//         }
//         out << '\n';
//     }
//     return out;
// }

std::ostream& operator<<(std::ostream& out, Board& board) {
    out << '[';
    for (int i = 0; i < board.m; i++) {
        out << '[';
        for (int j = 0; j < board.n; j++) {
            out << board(i, j);
            if (j < board.n-1)  out << ',';
        }
        out << ']';
    }
    out << ']';
    return out;
}

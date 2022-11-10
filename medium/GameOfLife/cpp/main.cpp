#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

class Board {
public:
    int n;
    int m;

    Board(vector<vector<int>>& board_data);
    vector<vector<int>> next_state();

    void next() {
        this->board_data = this->next_state();
    }

    int& operator()(int x, int y);

public: 
    vector<vector<int>> board_data;
};

std::ostream& operator<<(std::ostream&, Board&);

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
        }
        next.push_back(row);
    }
    return next;
}

int& Board::operator()(int x, int y) {
    return board_data[x][y];
}

std::ostream& operator<<(std::ostream& out, Board& board) {
    out << '[';
    for (int i = 0; i < board.m; i++) {
        out << '[';
        for (int j = 0; j < board.n; j++) {
            out << board(i, j);
            if (j < board.n-1)  out << ',';
        }
        out << ']';
        if (i < board.m-1)  out << ',';
    }
    out << ']';
    return out;
}


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board_data) {
        Board board = Board(board_data);
        //cout << board << endl;
        board.next();
        board_data = board.board_data;
    }
};

int main(int argc, char** argv) {
    auto sol = Solution();

    auto data = vector<vector<int>> { {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
    //auto data = vector<vector<int>> { {1,1},{1,0} };
    sol.gameOfLife(data);
}
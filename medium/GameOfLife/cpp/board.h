#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include <vector>

using std::vector;

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

private: 
    vector<vector<int>> board_data;
};

std::ostream& operator<<(std::ostream&, Board&);
#endif
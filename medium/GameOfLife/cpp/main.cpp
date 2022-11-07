#include <iostream>
#include <vector>

#include "board.h"

using std::cout, std::endl, std::vector;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board_data) {
        Board board = Board(board_data);
        cout << board << endl;
        board.next();
        cout << board << endl;
    }
};

int main(int argc, char** argv) {
    auto sol = Solution();

    //auto data = vector<vector<int>> { {0,1,0},{0,0,1},{1,1,1},{0,0,0} };
    auto data = vector<vector<int>> { {1,1},{1,0} };
    sol.gameOfLife(data);
}
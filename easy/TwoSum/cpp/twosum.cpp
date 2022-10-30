#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	std::unordered_map<int,int> seen = {};
        for (int i=0; i<nums.size(); i++) {
            int value = nums[i];
            int needed = target - value;
            auto search = seen.find(needed);
            if (search != seen.end())
                return vector<int>{i,search->second};
            seen[value] = i;
       };
        return vector<int>{};
    }
};


int main(int argc, char** argv) {
    Solution sol = Solution();
    auto input = vector<int>{2,7,11,15};
    auto answer = sol.twoSum(input, 9);
    std::cout << "ANSWER: [";
    for (int i : answer) {
        std::cout << i << ",";
    }
    std::cout << "]"<< std::endl;

    return(EXIT_SUCCESS);
}

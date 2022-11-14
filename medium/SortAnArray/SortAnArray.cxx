#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using std::cout, std::endl, std::vector, std::string;

void dump(string message, vector<int> nums) {
    cout << message << ": ";
    for (auto elem : nums) {
        cout << elem << " ";
    }
    cout << endl;
}

vector<int> merge(vector<int>& left, vector<int>& right) {
    vector<int> result;
    int i = 0;
    int j = 0;
    const int l = left.size() + right.size();

    while (i + j < l) {
        if (i == left.size())
            result.push_back(right[j++]);
        else if (j == right.size())
            result.push_back(left[i++]);
        else if (left[i] <= right[j])
            result.push_back(left[i++]);
        else
            result.push_back(right[j++]);
    }
    return result;
}

vector<int> sortArray(vector<int>& nums) {
    switch (nums.size()) {
        case 0: case 1:   // base case.  no need to sort a single item list
            return nums;
        case 2:  // not needed, strictly, but it's simple and saves ≈half the recursive calls.
            if (nums[0] > nums[1])
               std::swap(nums[0],nums[1]);
            return nums;
        default:
            auto midpoint = nums.begin() + nums.size()/2;
            auto left  = vector<int>(nums.begin(), midpoint);
            auto right = vector<int>(midpoint++, nums.end());
            auto sortedLeft = sortArray(left);
            auto sortedRight = sortArray(right);
            return merge(sortedLeft, sortedRight);
    }
};

auto operator<<(std::ostream& out, const vector<int>&nums) -> std::ostream& {
    string repr{};
    if (!nums.empty())
        repr = std::accumulate(nums.begin() + 1, nums.end(), std::to_string(nums[0]),
            [](string s, int i) { return s + "," + std::to_string(i); }
        );
    return out << "[" << repr << "]";
}

void test(string name, vector<int>& nums, vector<int>& expected) {
    auto sorted = sortArray(nums);
    auto result = sorted == expected;
    cout << "# ⌄⌄⌄ --------------- test \"" << name << "\": " << ( result ? "✓" : "FAIL");
    if (!result) {
        cout << "\n|           in = " << nums;
        cout << "\n|          out = " << sorted;
        cout << "\n|     expected = " << expected;
        cout << "\n# ^^^ --------------- ";
    };
    cout << endl;
}

auto main() -> int {
    vector<int> input, expected;
    input = {5,2,3,1};     expected = {1,2,3,5};      test("Leetcode Example 1", input, expected);
    input = {5,1,1,2,0,0}; expected = {0,0,1,1,2,5};  test("Leetcode Example 2", input, expected);
    input = {1,3,2};       expected = {1,2,3};        test("Simple", input, expected);
    input = {};            expected = {};             test("Empty" , input, expected);
    input = {1};           expected = {1};            test("Single", input, expected);
    input = {5,4,3,2,1};   expected = {1,2,3,4,5};    test("Odd", input, expected);
    input = {6,5,4,3,2,1}; expected = {1,2,3,4,5,6};  test("Even", input, expected);
    input = {5,1,1,0,0};   expected = {0,0,1,1,5};    test("DuplicateNums", input, expected);
    return (EXIT_SUCCESS);
}
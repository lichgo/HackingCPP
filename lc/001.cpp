class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Save numbers into a vector of pair
        vector<pair<int, int>> v;
        for (int i = 0; i < numbers.size(); ++i)
        	v.push_back(make_pair(numbers[i], i + 1));
    }
};
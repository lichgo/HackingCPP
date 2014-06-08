#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
	return p1.first < p2.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {

    	vector<int> result;

    	if (numbers.empty()) return result;

        // Save numbers into a vector of pair
        vector<pair<int, int> > v;
        for (int i = 0; i < numbers.size(); ++i)
        	v.push_back(make_pair(numbers[i], i + 1));

        // Sort
        sort(v.begin(), v.end(), compare);

        // Search in a loop
        int low = 0; 
        int high = v.size() - 1;
        while (low < high) {
        	int sum = v[low].first + v[high].first;
        	if (sum == target) {
                if (v[low].second < v[high].second) {
                    result.push_back(v[low].second);
                    result.push_back(v[high].second);
                } else {
                    result.push_back(v[high].second);
                    result.push_back(v[low].second);
                }
        		return result;
        	} else if (sum < target) {
        		low++;
        	} else {
        		high--;
        	}
        }

        return result;
    }
};
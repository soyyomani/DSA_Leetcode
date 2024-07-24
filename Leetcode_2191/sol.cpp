#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& map, vector<int>& nums) 
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        vector<pair<int,int>> jumbled_num;
        int n = nums.size();

        // Convert nums to strings, map values, and store mapped value (mv, nums[i])
        for(int i = 0; i < n; i++)
        {
            string s1 = to_string(nums[i]);
            string mv;
            for(char ch : s1)
            {
                mv += '0' + map[ch - '0'];
            }
            int mapped_value = stoi(mv); // Convert string to integer to handle leading zeros
            jumbled_num.emplace_back(mapped_value, nums[i]);
        }

        // Custom comparator for sorting
        auto comp = [](const pair<int,int>& a, const pair<int,int>& b)
        {
            return a.first < b.first; // Compare mapped values
        };

        // Sort the values
        sort(jumbled_num.begin(), jumbled_num.end(), comp);

        vector<int> res;
        for(const auto& val : jumbled_num)
        {
            res.push_back(val.second); // Push original values as per the sorted mapped values
        }
        return res;
    }
};

int main() {
    Solution solution;
    int map_size, nums_size;

    cout << "Enter the size of the map (10 for digits 0-9): ";
    cin >> map_size;

    vector<int> map(map_size);
    cout << "Enter the map values: ";
    for(int i = 0; i < map_size; i++) {
        cin >> map[i];
    }

    cout << "Enter the number of elements in nums: ";
    cin >> nums_size;

    vector<int> nums(nums_size);
    cout << "Enter the nums values: ";
    for(int i = 0; i < nums_size; i++) {
        cin >> nums[i];
    }

    vector<int> sorted_nums = solution.sortJumbled(map, nums);

    cout << "Sorted nums: ";
    for(int num : sorted_nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

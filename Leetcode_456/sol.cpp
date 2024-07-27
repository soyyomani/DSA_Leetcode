#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        int n = nums.size();
        if (n < 3) {
            return false;
        }
        stack<pair<int, int>> st; 
        int min_val = nums[0];
        
        for (int j = 1; j < n; j++) {
            while (!st.empty() && nums[j] >= st.top().second) {
                st.pop();
            }
            
            if (!st.empty() && nums[j] > st.top().first) {
                return true;
            }
            min_val = min(min_val, nums[j]);
            st.push({min_val, nums[j]});
        }
        return false;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    if (solution.find132pattern(nums)) {
        cout << "132 pattern found" << endl;
    } else {
        cout << "132 pattern not found" << endl;
    }
    return 0;
}

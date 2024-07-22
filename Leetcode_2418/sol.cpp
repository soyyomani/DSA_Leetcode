#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL);
        int n = names.size();
        unordered_map<int, string> map;
        vector<string> res;
        for(int i = 0; i < n; i++)
        {
            map[heights[i]] = names[i];  // Mapping the corresponding int and string
        }
        sort(heights.begin(), heights.end(), greater<int>());  // Descending order sorting...
        //example 1:  180,170,165 example 2: 185 155 150

        for (int height : heights)
        {
            res.push_back(map[height]);
        }

        return res;
    }
};

int main() {
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    vector<string> names(n);
    vector<int> heights(n);

    cout << "Enter the names of the people:\n";
    for(int i = 0; i < n; i++) {
        cin >> names[i];
    }

    cout << "Enter the heights of the people:\n";
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    Solution solution;
    vector<string> sortedNames = solution.sortPeople(names, heights);

    cout << "Names sorted by heights in descending order:\n";
    for(const string& name : sortedNames) {
        cout << name << " ";
    }
    cout << endl;

    return 0;
}

//best question i ever encountered//
#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int m = original.size();
        int n = source.length();
        vector<vector<int>> graph(26, vector<int>(26, INT_MAX));

        for (int i = 0; i < 26; i++) {
            graph[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            graph[u][v] = min(graph[u][v], cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (graph[i][k] < INT_MAX && graph[k][j] < INT_MAX) {
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    }
                }
            }
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (source[i] == target[i]) {
                continue;
            }
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            
            if (graph[u][v] == INT_MAX) {
                return -1;
            }
            res += graph[u][v];
        }
        return res;
    }
};

int main() {
    Solution sol;
    string source = "abc";
    string target = "def";
    vector<char> original = {'a', 'b', 'c'};
    vector<char> changed = {'d', 'e', 'f'};
    vector<int> cost = {1, 2, 3};

    long long result = sol.minimumCost(source, target, original, changed, cost);

    if (result == -1) {
        cout << "Conversion is not possible." << endl;
    } else {
        cout << "The minimum cost of conversion is: " << result << endl;
    }

    return 0;
}

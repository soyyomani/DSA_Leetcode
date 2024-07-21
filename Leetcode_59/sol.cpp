#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    static vector<vector<int>>generateMatrix(int n) 
{
        vector<vector<int>> res(n, vector<int>(n));
        int left = 0, top = 0;
        int right = n - 1, bottom = n - 1;
        int val = 1;
        while (top<=bottom && left<=right) 
        {
            for (int j=left;j<=right;j++) 
            {
                res[top][j] = val;
                val += 1;
            }
            top++;
            for (int i=top;i<=bottom;i++) 
            {
                res[i][right] = val;
                val += 1;
            }
            right--;
            if (top<=bottom) 
            {
                for (int j=right;j>=left;j--) 
                {
                    res[bottom][j] = val;
                    val += 1;
                }
                bottom--;
            }
            if (left<=right) 
            {
                for (int i=bottom;i>=top;i--) 
                {
                    res[i][left] = val;
                    val += 1;
                }
                left++;
            }
        }
        return res;
    }
};

int main() {
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    vector<vector<int> > matrix = Solution::generateMatrix(n);

    cout << "Generated " << n << "x" << n << " spiral matrix:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        
        // Left to Right
        for (int i = left; i <= right; i++)
            result.push_back(matrix[top][i]);
        top++;

        // Top to Bottom
        for (int i = top; i <= bottom; i++)
            result.push_back(matrix[i][right]);
        right--;

        // Right to Left
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result.push_back(matrix[bottom][i]);
            bottom--;
        }

        // Bottom to Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result.push_back(matrix[i][left]);
            left++;
        }
    }

    return result;
}

// Driver code
int main() {
    vector<vector<int>> matrix1 = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    vector<int> ans1 = spiralOrder(matrix1);

    cout << "Output: ";
    for (int x : ans1) cout << x << " ";
    cout << endl;

    vector<vector<int>> matrix2 = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    vector<int> ans2 = spiralOrder(matrix2);

    cout << "Output: ";
    for (int x : ans2) cout << x << " ";
    cout << endl;

    return 0;
}
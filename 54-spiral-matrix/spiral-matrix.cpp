class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, down = m - 1;
        int left = 0, right = n - 1;
        int dir = 0;

        vector<int> result;

        while (top <= down && left <= right) {

            if (dir == 0) { // left → right
                for (int i = left; i <= right; i++)
                    result.push_back(matrix[top][i]);
                top++;
            }
            else if (dir == 1) { // top → down
                for (int i = top; i <= down; i++)
                    result.push_back(matrix[i][right]);
                right--;
            }
            else if (dir == 2) { // right → left
                for (int i = right; i >= left; i--)
                    result.push_back(matrix[down][i]);
                down--;
            }
            else if (dir == 3) { // down → top
                for (int i = down; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
            }

            dir = (dir + 1) % 4;
        }

        return result;
    }
};

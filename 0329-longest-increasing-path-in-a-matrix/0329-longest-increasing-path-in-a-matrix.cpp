class Solution {
public:
    vector<vector<int>> matrix;
    vector<vector<int>> memo;
    int R, C;

    int f(int ci, int cj, int fromValue) {
        if (ci < 0 || cj < 0 || ci >= R || cj >= C || matrix[ci][cj] <= fromValue)
            return 0;

        if (memo[ci][cj] != -1)
            return memo[ci][cj];

        return memo[ci][cj] = 1 + max({f(ci - 1, cj, matrix[ci][cj]), f(ci, cj - 1, matrix[ci][cj]),
                                       f(ci, cj + 1, matrix[ci][cj]),
                                       f(ci + 1, cj, matrix[ci][cj])});
    }

public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        this->matrix = matrix;
        R = matrix.size(), C = matrix[0].size();
        memo = vector(R, vector(C, -1));

        int result = 0;

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                result = max(result, f(i, j, -1));

        return result;
    }
    };
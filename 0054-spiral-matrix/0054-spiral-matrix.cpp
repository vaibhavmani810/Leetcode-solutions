class Solution {
public:
    vector<int> answer;
    void dfs(int i,int j,vector<vector<int>>& matrix)
    {
        
		if (j + 1 < matrix[i].size() && matrix[i][j + 1] >= -100 && (i - 1 < 0 || matrix[i - 1][j] == -101)) {

			answer.push_back(matrix[i][j]);
			matrix[i][j] = -101;
			dfs(i, j + 1, matrix);

		} else if (i + 1 < matrix.size() && matrix[i + 1][j] >= -100) {
			
			answer.push_back(matrix[i][j]);
			matrix[i][j] = -101;
			dfs(i + 1, j, matrix);

		} else if (j - 1 < matrix[i].size() && matrix[i][j - 1] >= -100) {
			
			answer.push_back(matrix[i][j]);
			matrix[i][j] = -101;
			dfs(i, j - 1, matrix);

		} else if (i - 1 < matrix.size() && matrix[i - 1][j] >= -100) {
			
			answer.push_back(matrix[i][j]);
			matrix[i][j] = -101;
			dfs(i - 1, j, matrix);

		} else {
			answer.push_back(matrix[i][j]);
			matrix[i][j] = -101;
		}
	
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        dfs(0,0,matrix);
        return answer;
    }
};
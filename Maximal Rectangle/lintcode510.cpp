class Solution {
public:
	/**
	* @param matrix a boolean 2D matrix
	* @return an integer
	*/
	int maximalRectangle(vector<vector<bool> > &matrix) {
		int height = matrix.size(), width = 0;
		if (height) width = matrix[0].size();

		vector<vector<int> > toUp(height);
		
		for (int i = 0; i < height; ++i) {
			vector<int> tmp(width + 5, 0), tmp1(width + 5, 0);
			for (int j = 0; j < width; ++j) {
				if (i) {
					tmp[j] = matrix[i][j] ? toUp[i - 1][j] + 1 : 0;
				}
				else {
					tmp[j] = matrix[i][j] ? 1 : 0;
				}
			}
			toUp[i] = tmp;
		}
		int ans = 0;

		vector<int> toLeft(width + 5, 0), toRight(width + 5, 0);
		for (int i = 0; i < height; ++i) {
			int curLeft = -1, curRight = -1;
			for (int j = 0; j < width; ++j) {
				if (!matrix[i][j]) {
					curLeft = -1;
					toLeft[j] = -1;
				}
				else {
					if (curLeft == -1) curLeft = j;
					toLeft[j] = toLeft[j] ? max(toLeft[j], curLeft) : curLeft;
				}
			}
			for (int j = width - 1; j >= 0; --j) {
				if (!matrix[i][j]) curRight = -1, toRight[j] = -1;
				else {
					if (curRight == -1) curRight = j;
					toRight[j] = toRight[j] ? min(toRight[j], curRight) : curRight;
				}
				ans = max(ans, (toRight[j] - toLeft[j] + 1) * toUp[i][j]);
			}
		}
	
		return ans;
	}
}sol;
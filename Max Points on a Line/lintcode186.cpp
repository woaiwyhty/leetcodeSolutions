class Solution {
public:
	/**
	* @param points an array of point
	* @return an integer
	*/
	int ans = 0;
	
	int maxPoints(vector<Point>& points) {
		// Write your code here
		int sz = points.size();
		if (sz) ans = 1;
		for (int i = 0; i < sz; ++i) {
			map <double, int> cnts;
			int sameX = 1, sameY = 1, sameXY = 1;
			for (int j = 0; j < i; ++j) {
				double k = (double)(points[i].y - points[j].y) / (double)(points[i].x - points[j].x);
				bool flag = 0;
				if (points[i].x - points[j].x == 0) {
					++sameX;
					flag = 1;
				}
				if (points[i].y - points[j].y == 0) {
					++sameY;
					flag = 1;
				}
				if (points[i].y == points[j].y && points[i].x == points[j].x) ++sameXY;
				if(flag) continue;
				cnts[k]++;
			}
			ans = max(ans, max(sameX, sameY));
			ans = max(ans, sameXY);
			for (auto it = cnts.begin(); it != cnts.end(); ++it) {
				ans = max(ans, it->second + sameXY);
			}
		}
		return ans;
	}
}sol;
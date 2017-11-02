class Solution {
public:
	int myAtoi(string str) {
		string s = "";
		int len = str.length(), stPos = 0;
		//checkValid
		long long res = 0;
		int sign = 1; // 1 plus, -1 minus
		for (int i = 0; i < len; ++i) {
			if (str[i] != ' ') {
				s += str[i];
				s = str.substr(i, len - i);
				break;
			}
		}
		len = s.length();
		if (len == 0) return 0;
		if (s[0] == '-') {
			sign = -1;
			stPos = 1;
		}
		else if (s[0] == '+') {
			stPos = 1;
		}
		int cnt = 0; bool zeroFlag = 1;
		for (int i = stPos; i < len; ++i) {
			if (s[i] < '0' || s[i] > '9') break;
			res = res * 10 + s[i] - '0';
			if (s[i] != '0' && zeroFlag == 1) {
				zeroFlag = 0;
			}
			if (!zeroFlag) ++cnt;
			if (cnt >= 10) {
				if (sign == 1 && res >= 2147483648) return INT_MAX;
				if (sign == -1 && res > 2147483648) return  INT_MIN;
			}
		}
		int nRes = res * sign;

		return res * sign;
	}
}sol;
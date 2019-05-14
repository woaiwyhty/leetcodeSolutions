#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    string digitsStr[9] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string digitsStr1[10] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string digitsStr2[8] = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string convertHundred(vector<int> digits, int realValue) {
        while (digits.size() < 3) digits.push_back(0);
        if (!realValue) return "Zero";
        bool leadingZero = true;
        string ans = "";
        for (int i = 2; i >= 0; --i) {
            if (digits[i]) leadingZero = false;
            if (leadingZero && !digits[i]) continue;
            if (!realValue) break;
            if (realValue >= 100) {
                ans += digitsStr[digits[i] - 1] + " Hundred ";
                realValue -= digits[i] * 100;
            } else if (realValue >= 20) {
                ans += digitsStr2[digits[i] - 2] + " ";
                realValue -= digits[i] * 10;
            } else if (realValue >= 10) {
                ans += digitsStr1[realValue - 10] + " ";
                break;
            } else {
                ans += digitsStr[realValue - 1] + " ";
                break;
            }

        }
        return ans.substr(0, ans.length() - 1);
    }
    string convertThousand(vector<int> digits, int realValue) {
        if (realValue < 1000) return convertHundred(digits, realValue);
        while (digits.size() < 5) digits.push_back(0);
        vector<int> thousand(2), hundred(3);
        thousand[1] = digits[4], thousand[0] = digits[3];
        hundred[2] = digits[2], hundred[1] = digits[1], hundred[0] = digits[0];
        int thousandVal = convertToInt(thousand, 2);
        string ans = convertHundred(thousand, thousandVal) + " Thousand ";
        if ((realValue - thousandVal * 1000) == 0) {
            return ans.substr(0, ans.length() - 1);
        }
        ans += convertHundred(hundred, realValue - thousandVal * 1000);
        return ans;
    }

    string convertHundredWithThousand(vector<int> digits, int realValue) {
        if (realValue < 100000) return convertThousand(digits, realValue);
        vector<int> leile(3);
        leile[2] = digits[5], leile[1] = digits[4], leile[0] = digits[3];
        string ans = convertHundred(leile, convertToInt(leile, 3)) + " Thousand";
        digits.erase(digits.begin() + 3, digits.begin() + 6);
        int leftValue = convertToInt(digits, 3);
        if (leftValue == 0) return ans;
        else {
            ans += " " + convertHundred(digits, convertToInt(digits, 3));
        }
        return ans;
    }

    string convertMillion(vector<int> digits, int realValue) {
        if (realValue < 1000000) return convertHundredWithThousand(digits, realValue);
        while (digits.size() < 9) digits.push_back(0);
        vector<int> hundred(3);
        hundred[2] = digits[8], hundred[1] = digits[7], hundred[0] = digits[6];
        string ans = convertHundred(hundred, convertToInt(hundred, 3)) + " Million";
        digits.erase(digits.begin() + 6, digits.begin() + 9);
        int leftValue = convertToInt(digits, 6);
        if (leftValue) {
            ans += " " + convertHundredWithThousand(digits, leftValue);
        }
        return ans;
    }

    string convertBillion(vector<int> digits, int realValue) {
        string ans = digitsStr[digits[9] - 1] + " Billion";
        digits.erase(digits.begin() + 9);
        int leftValue = convertToInt(digits, 9);
        if (leftValue) {
            ans += " " + convertMillion(digits, leftValue);
        }
        return ans;
    }

    int convertToInt(vector<int> digits, int bits) {
        int sz = digits.size(), now = 0, leadingNums = 1;
        bool leadingZero = true;
        for (int i = min(bits, sz) - 1; i >= 0; --i) {
            now = now * 10 + digits[i];
        }
        return now;
    }
public:
    string numberToWords(int num) {
        vector<int> digits;
        int tmpNum = num;
        while (tmpNum) {
            digits.push_back(tmpNum % 10);
            tmpNum /= 10;
        }
        int sz = digits.size();
        if (sz <= 3) {
            return convertHundred(digits, convertToInt(digits, 3));
        } else if (sz <= 5) {
            return convertThousand(digits, convertToInt(digits, 5));
        } else if (sz <= 6) {
            return convertHundredWithThousand(digits, convertToInt(digits, 6));
        } else if (sz <= 9) {
            return convertMillion(digits, convertToInt(digits, 9));
        } else {
            return convertBillion(digits, convertToInt(digits, 10));
        }
        return "";
    }
}solution;

int main() {
    cout << solution.numberToWords(3200348) << endl;
    return 0;
}
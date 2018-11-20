struct items {
    int value;
    int listID;
    items(int x, int y) : value(x), listID(y) { }
};
bool sortAsValue (const items& x, const items& y) {
    if (x.value != y.value) return x.value < y.value;
    return x.listID < y.listID;
}
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        k = nums.size();
        for (int i = 0; i < k; ++i) {
            int len = nums[i].size();
            for (int j = 0; j < len; ++j) {
                if (!j) allNums.push_back(items(nums[i][j], i));
                else {
                    if (nums[i][j] == nums[i][j - 1]) continue;
                    allNums.push_back(items(nums[i][j], i));
                }
            }
        }
        sort(allNums.begin(), allNums.end(), sortAsValue);
        int len = allNums.size();
        for (int i = 0; i < len; ++i) {
            //cout << allNums[i].value << "  ";
            if (!i) next.push_back(i);
            else {
                if (allNums[i].value != allNums[i - 1].value)
                    next.push_back(i);
            }
        }
        //cout << endl;
        int existNums = 0, nextLen = next.size(), ans = 123456789, ansl, ansr;
        bool pending = true;
        vector<int> times(k, 0);
        int l = 0;
        //for (int i = 0; i < nextLen; ++i) cout << next[i] << "  ";
        //cout << endl;
        for (int i = 0; i < nextLen; ++i) {
            if (pending) {
                int limit = i == nextLen - 1 ? len : next[i + 1];
                for (int j = next[i]; j < limit; ++j) {
                    times[allNums[j].listID]++;
                    if (times[allNums[j].listID] == 1) ++existNums;
                }
                if (existNums == k) {
                    pending = false;
                    //cout << allNums[next[l]].value << "  " << allNums[next[i]].value << endl;
                    if (allNums[next[i]].value - allNums[next[l]].value < ans) {
                        ansl = allNums[next[l]].value;
                        ansr = allNums[next[i]].value;
                        ans = ansr - ansl;
                    }
                    while (existNums == k && l < nextLen - 1) {
                        if (allNums[next[i]].value - allNums[next[l]].value < ans) {
                            ansl = allNums[next[l]].value;
                            ansr = allNums[next[i]].value;
                            ans = ansr - ansl;
                        }
                        for (int j = next[l]; j < next[l + 1]; ++j) {
                            times[allNums[j].listID]--;
                            if (!times[allNums[j].listID]) --existNums;
                        }
                        ++l;
                    }
                    if (existNums == k && allNums[next[i]].value - allNums[next[l]].value < ans) {
                        ansl = allNums[next[l]].value;
                        ansr = allNums[next[i]].value;
                        ans = ansr - ansl;
                    }
                    pending = true;
                }
            }
        }
        vector<int> res;
        res.push_back(ansl);
        res.push_back(ansr);
        return res;
    }
private:
    vector<items> allNums;
    vector<int> next;
    int k;
}sol;
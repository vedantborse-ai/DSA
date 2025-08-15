class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int n = s.size();
        int l = 0, maxlen = 0;

        for (int r = 0; r < n; r++) {
            if (mpp.find(s[r]) != mpp.end() && mpp[s[r]] >= l) {
                l = mpp[s[r]] + 1;
            }
            mpp[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};
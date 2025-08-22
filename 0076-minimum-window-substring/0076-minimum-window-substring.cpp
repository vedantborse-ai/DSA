#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256, 0);
        int m = t.size();
        int n = s.size();
        int l = 0, r = 0, sIndex = -1, minlen = INT_MAX, cnt = 0;
        for (char c : t) {
            hash[c]++;
        }

        while (r < n) {
            if (hash[s[r]] > 0) cnt++;
            hash[s[r]]--; 
            while (cnt == m) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sIndex = l;
                }
                hash[s[l]]++; 
                if (hash[s[l]] > 0) cnt--;
                l++; 
            }
            r++;
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minlen);
    }
};
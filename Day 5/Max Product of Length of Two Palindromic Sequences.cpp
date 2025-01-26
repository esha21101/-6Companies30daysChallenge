class Solution {
public:
    int res = 0;

    bool isPalindrome(string& str) {
        int l = 0, r = str.size() - 1;
        while (l < r) {
            if (str[l++] != str[r--]) return false;
        }
        return true;
    }

    void dfs(string& s, int idx, string& s1, string& s2) {
        if (idx == s.size()) {
            if (isPalindrome(s1) && isPalindrome(s2)) {
                res = max(res, (int)s1.size() * (int)s2.size());
            }
            return;
        }

        s1.push_back(s[idx]);
        dfs(s, idx + 1, s1, s2);
        s1.pop_back();

        s2.push_back(s[idx]);
        dfs(s, idx + 1, s1, s2);
        s2.pop_back();

        dfs(s, idx + 1, s1, s2);
    }

    int maxProduct(string s) {
        string s1, s2;
        dfs(s, 0, s1, s2);
        return res;
    }
};

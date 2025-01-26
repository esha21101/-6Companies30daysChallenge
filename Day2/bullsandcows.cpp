class Solution {
public:
    string getHint(string s, string g) {
        int x = 0;
        int n = s.size();
        unordered_map<char, int> s1;
        unordered_map<char, int> g1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == g[i]) {
                x++;
            }
            else {
                s1[s[i]]++;
                g1[g[i]]++;
            }
        }

        int y = 0;
        for (auto i : g1) {
            if (s1[i.first] != 0 && i.second != 0) {
                y += min(s1[i.first], i.second);
            }
        }

        string op = to_string(x) + 'A' + to_string(y) + 'B';

        return op;
    }

        
};
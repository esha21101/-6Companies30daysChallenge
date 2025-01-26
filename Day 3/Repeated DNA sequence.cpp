class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> cnt; 
        vector<string> res; 
        
        
        for (int i = 0; i + 10 <= s.size(); i++) {
            string sub = s.substr(i, 10); 
            cnt[sub]++; 
        }
        
        
        for (const auto& [seq, freq] : cnt) {
            if (freq > 1) res.push_back(seq);
        }
        
        return res;
    }
};
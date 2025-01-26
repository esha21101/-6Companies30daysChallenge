class Solution {
public:
    int firstUniqChar(string s) {
        int sz= s.size();
        unordered_map< char, int> m;
        for(int i=0; i<sz ; i++){
            m[s[i]]++;
           // if(m[s[i]]==1) return i;
        }
        for(int i=0; i<sz ; i++){
            if(m[s[i]]==1) return i;
        }

        // for (int i=0; i<sz; i++){
            
        //             }
        // for( auto &it: m ){
        //     if(it.second<= 1) return it.second;
        // }
        return -1;
    }
};
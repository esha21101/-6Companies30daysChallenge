class Solution {
public:
    map<vector<int>, int> dp;

    int solve(vector<int>& p, vector<vector<int>>& sp, vector<int> need) {
        int n = p.size();
        int minCost = 0;

        
        for (int i = 0; i < n; i++) {
            minCost += need[i] * p[i];
        }

    
        if (dp.find(need) != dp.end()) return dp[need];

       
        for (auto& offer : sp) {
            vector<int> rem = need;
            bool valid = true;

            for (int i = 0; i < n; i++) {
               
                if (offer[i] > need[i]) {
                    valid = false;
                    break;
                }
                rem[i] -= offer[i];
            }

            
            if (valid) {
                minCost = min(minCost, offer[n] + solve(p, sp, rem));
            }
        }

        
        return dp[need] = minCost;
    }

    int shoppingOffers(vector<int>& p, vector<vector<int>>& sp, vector<int>& need) {
        return solve(p, sp, need);
    }
};

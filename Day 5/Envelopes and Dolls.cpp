class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
    
    sort(env.begin(), env.end(), [](vector<int>& a, vector<int>& b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });

  
    vector<int> heights;
    for (auto& e : env) {
        heights.push_back(e[1]);
    }

    
    vector<int> lis;
    for (int h : heights) {
        auto it = lower_bound(lis.begin(), lis.end(), h);
        if (it == lis.end()) {
            lis.push_back(h);
        } else {
            *it = h;
        }
    }

    return lis.size();
}
};
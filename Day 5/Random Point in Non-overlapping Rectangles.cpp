class Solution {
public:
    int n;
    long totalArea;
    vector<vector<int>> rects;
    vector<long> prefixSum;

    Solution(vector<vector<int>>& r) {
        n = r.size();
        totalArea = 0;
        for (auto& rect : r) {
            totalArea += (long)(rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
            prefixSum.push_back(totalArea);
        }
        rects = r;
    }

    vector<int> pick() {
        int randVal = rand() % totalArea;
        int idx = upper_bound(prefixSum.begin(), prefixSum.end(), randVal) - prefixSum.begin();

        int width = rects[idx][2] - rects[idx][0] + 1;
        int height = rects[idx][3] - rects[idx][1] + 1;

        int x = rects[idx][0] + (rand() % width);
        int y = rects[idx][1] + (rand() % height);

        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
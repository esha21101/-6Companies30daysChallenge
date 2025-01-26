class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        string order = "!#$%&*?@^";
        unordered_map<char, int> precedence;

        
        for (int i = 0; i < order.size(); i++) {
            precedence[order[i]] = i;
        }

    
        auto comparator = [&precedence](char a, char b) {
            return precedence[a] < precedence[b];
        };

        sort(nuts, nuts + n, comparator);
        sort(bolts, bolts + n, comparator);
    
    }
};
class Solution {
public:
    long long minimumCost(string src, string tgt, vector<char>& orig, vector<char>& chg, vector<int>& cst) {
        const int inf = 1e9; 
        int graph[26][26];

        for (int i = 0; i < 26; ++i) {
            fill(begin(graph[i]), end(graph[i]), inf);
            graph[i][i] = 0; 
        }

        for (int i = 0; i < orig.size(); ++i) {
            int u = orig[i] - 'a', v = chg[i] - 'a';
            graph[u][v] = min(graph[u][v], cst[i]);
        }

        
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        long long totalCost = 0;
        int n = src.length();

        for (int i = 0; i < n; ++i) {
            int u = src[i] - 'a', v = tgt[i] - 'a';
            if (u != v) {
                if (graph[u][v] == inf) return -1; 
                totalCost += graph[u][v];
            }
        }
        return totalCost;
    }
};

class Solution {
public:
    long long combination(int n, int r) {
        r = max(r, n - r); 
        long long result = 1;

        for (int i = 1; i <= r; ++i) {
            result *= (n - r + i);
            result /= i;
        }
        return result;
    }

    int waysToReachStair(int k) {
        
        if (k == 0 || k == 4) return 2;
        if (k == 1 || k == 2) return 4;

     
        int logVal = ceil(log2(k));
        long long nextPowerOf2 = 1LL << logVal; // 

        long long stepsToPower = nextPowerOf2 - k;

        
        if (stepsToPower < 0 || stepsToPower > logVal + 1)
            return 0;

     
        return combination(logVal + 1, stepsToPower);
    }
};

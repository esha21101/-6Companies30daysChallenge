class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size(), maxLen = 0, i = 1;

        while (i < n) {
            int up = 0, down = 0;

        
            while (i < n && arr[i] > arr[i - 1]) {
                up++;
                i++;
            }

         
            while (i < n && arr[i] < arr[i - 1]) {
                down++;
                i++;
            }

            if (up > 0 && down > 0) {
                maxLen = max(maxLen, up + down + 1);
            }

          
            while (i < n && arr[i] == arr[i - 1]) {
                i++;
            }
        }

        return maxLen;
    }
};

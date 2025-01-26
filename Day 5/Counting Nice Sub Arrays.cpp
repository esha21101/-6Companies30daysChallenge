class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        if (k < 0) return 0; 
        int l = 0, r = 0, oddCount = 0, res = 0;

        while (r < nums.size()) {
            oddCount += nums[r] % 2;

            while (oddCount > k) {
                oddCount -= nums[l] % 2;
                l++;
            }

            
            res += (r - l + 1);
            r++;
        }

        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return countSubarrays(nums, k) - countSubarrays(nums, k - 1);
    }
};

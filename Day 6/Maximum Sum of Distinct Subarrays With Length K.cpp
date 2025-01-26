class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0, maxSum = 0;
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            
            freq[nums[i]]++;
            sum += nums[i];

            if (i >= k) {
                int left = nums[i - k];
                freq[left]--;
                sum -= left;
                if (freq[left] == 0) freq.erase(left);
            }

            if (i >= k - 1 && freq.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        
        int i = n - 1, low = 0, mid = (n + 1) / 2;

        while (i >= 0) {
            if (i % 2 == 1) {
                nums[i] = temp[mid++];
            } else {
                nums[i] = temp[low++];
            }
            i--;
        }
    }
};

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int count = 0, n = nums.size();
        
        
        for (int start = 0; start < n; start++) {
            
            for (int end = start; end < n; end++) {
                bool valid = true; 
                int prev = -1;     
                
                
                for (int idx = 0; idx < n; idx++) {
                    if (idx < start || idx > end) { 
                        if (nums[idx] <= prev) {
                            valid = false;
                            break; 
                        }
                        prev = nums[idx];
                    }
                }
                
                
                if (valid) count++;
            }
        }
        
        return count;
    
    }
};
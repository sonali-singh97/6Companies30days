/* 
Question: Sliding Window Maximum
Link: https://leetcode.com/problems/sliding-window-maximum/
*/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         int n = nums.size();
         deque<int> q;
         vector<int> res;

        for (int i = 0; i < n; i ++){
            
            // delete out of the range indexes
            while(!q.empty() && q.front() <= i-k) q.pop_front();
            
            // delete indexes at which value is less than current value
            while(!q.empty() && nums[q.back()] <= nums[i]) q.pop_back();
            
            q.push_back(i);
            
            if(i >= k-1){
                res.push_back(nums[q.front()]);
            }
            
        }
        
        return res;
    }
};
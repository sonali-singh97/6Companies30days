/*
Question: IPL 2021 - Match Day 2 
Link: https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/#
*/


class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
      
        deque<int> dq;
        vector<int> output;
   
        for (int i = 0; i < n; i ++){
            
            // delete out of the range indexes
            while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
            
            // delete indexes at which value is less than current value
            while(!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
            
            dq.push_back(i);
            
            if(i >= k-1){
                output.push_back(arr[dq.front()]);
            }
            
        }
        
        return output;
    }
};

/*
Time Complexity = O(n) => Every element is added or removed atmost once (2n)
Space : O(k)
*/
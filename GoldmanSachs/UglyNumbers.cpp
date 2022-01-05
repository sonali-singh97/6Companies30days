/**** 
 Question: Find nth Ugly Number
 Link: https://leetcode.com/problems/ugly-number-ii/
 *****/


class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[n];
        ugly[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        int nextMultipleTwo = 2;
        int nextMultipleThree = 3;
        int nextMultipleFive = 5;
        
        for (int i = 1; i < n; i ++){
            ugly[i] = min(nextMultipleTwo, min(nextMultipleThree, nextMultipleFive));
          
            if(ugly[i] == nextMultipleTwo){
                i2++;
                nextMultipleTwo = ugly[i2] * 2;
            }
            if (ugly[i] == nextMultipleThree){
                i3++;
                nextMultipleThree = ugly[i3] * 3;
            }
            if(ugly[i] == nextMultipleFive) {
                i5++;
                nextMultipleFive = ugly[i5] * 5;
            }
        }
        
        return ugly[n-1];
    }
    
    /*****APPROACH****
    Time Complexity: O(n) using DP
    Source: https://youtu.be/78Yx7oLA43s
    
    - Only multiples of 2,3 and 5 are Ugly numbers ( Not all multiples)
    - Make an array of size n to store ugly number
    - Initialize the first multiple of two, three and five with 2, 3 and 5.
    - Initialize i2, i3 and i5 for the index of multiples.
    - For every index
        - Store the min of all three multiples in array
        - Increment the corresponding index and multiple value using dp array.
    ******************/
};
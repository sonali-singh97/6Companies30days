/******
Rectangle Overlap
Link: https://leetcode.com/problems/rectangle-overlap/
******/


class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        // If the rectangles are side by side
        if (rec1[0] >= rec2[2] || rec2[0] >= rec1[2]) return false;
        
        // if one rectangle is present to the top pf other
        if ( rec1[1] >= rec2[3] || rec2[1]  >= rec1[3]) return false;
        
        // In all other cases they will overlap
        return true;
    }
};
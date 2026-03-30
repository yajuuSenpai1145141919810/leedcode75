// 724. Find Pivot Index

// Given an array of integers nums, calculate the pivot index of this array.
// The pivot index is the index where the sum of all the numbers strictly to the left of the index is-
// equal to the sum of all the numbers strictly to the index's right.
// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. 
// This also applies to the right edge of the array.
// Return the leftmost pivot index. If no such index exists, return -1.

// 技巧:全局總和 → 算出右邊 → 檢查平衡 → 更新左邊
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
      
        // 全局總和
        int total=0;
        for(int x:nums) total+=x;

        int left=0,right=0;

        for(int i=0;i<n;i++){
          
            //  算出右邊
            right=total-left-nums[i];
          
            // 檢查平衡
            if(left==right) return i;
          
            // 更新左邊
            left+=nums[i];
        }
        return -1;
    }
};

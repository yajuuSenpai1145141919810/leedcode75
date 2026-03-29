// 283. Move Zeroes
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements
// Note that you must do this in-place without making a copy of the array.\

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;

        // 設一個找0跟找非0的指標
        int f0=0;  // zero
        int fn0=0; // not zero    

        while(fn0<n&&f0<n){
            if(nums[fn0]!=0){
                // 找到非0再去換
                swap(nums[f0],nums[fn0]);
              
                // 因為換完後nums[f0]已經不為0了 因此只要++就好!!!
                f0++;
            }
            fn0++;
        }
    }        
};


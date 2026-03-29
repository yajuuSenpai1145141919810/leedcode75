// 643. Maximum Average Subarray I
// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. 
// Any answer with a calculation error less than 10-5 will be accepted.

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        double result=0;
        double temp=0;
        if(n==k){
            double sum=0;
            for(int x:nums){
                sum+=x;
            }
            return sum/=k;
        }
        for(int i=0;i<n-k;i++){
            temp=nums[i]+nums[i+1]+nums[i+2]+nums[i+3];
            if(temp>result) result=temp;
        }  
        return result/=k;
    }
};

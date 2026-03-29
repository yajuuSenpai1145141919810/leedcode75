// 643. Maximum Average Subarray I
// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. 
// Any answer with a calculation error less than 10-5 will be accepted.


// 很糟糕的寫法
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n=nums.size();

        // 先計算特例
        if(n==k){
            double sum=0;
            for(int x:nums){
                sum+=x;
            }
            return sum/=k;
        }

        // 為了解決負數 所以把第一組設給result
        double temp=0;
        for(int i=0;i<k;i++){
            temp+=nums[i];
        }
        temp/=k;


        double result=temp;
        for(int i=0;i<=n-k;i++){
            double temp=0;
            // 要注意是i+k!!!
            for(int j=i;j<i+k;j++){
                temp+=nums[j];
            }
            temp/=k;
            if(temp>result) result=temp;
        }  
        return result;
    }
};

// 643. Maximum Average Subarray I
// You are given an integer array nums consisting of n elements, and an integer k.

// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. 
// Any answer with a calculation error less than 10-5 will be accepted.

// 正確解法
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        
        // 特例
        if(n==k){
            double sum=0;
            for(int x:nums){
                sum+=x;
            }
            return sum/=k;
        }

        // 先算第一組
        double temp1=0;
        for(int i=0;i<k;i++){
            temp1+=nums[i];
        }

        // 把第一組給結果 後續才好比對
        double result=temp1;

        // 注意是要拿temp1=temp1+.... 如果說全部1,2,3,4,5,k=3, 則第一組是1,2,3 要這樣設才會找2,3,4,下一組才會是3,4,5
        for(int i=0;i<n-k;i++){
            temp1=temp1+nums[i+k]-nums[i];
            if(temp1>result) result=temp1;
        }
        // 最後在去除k就好
        return result/=k;
    }
};









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

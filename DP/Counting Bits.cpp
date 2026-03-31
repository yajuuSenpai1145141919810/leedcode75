// 338. Counting Bits
// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10

class Solution {
public:
    vector<int> countBits(int n) {
        // 偶數：它的二進位最後一位一定是 0。所以 6 (110) 裡面的 1，數量跟 3 (11) 一樣
        // 公式： ans[i] = ans[i / 2]
        // 奇數：它的二進位最後一位一定是 1。
        // 所以 7 (111) 裡面的 1，就是 3 (11) 的數量再加 1。
        // 公式： ans[i] = ans[i / 2] + 1
        vector<int> ans(n+1);

        ans[0]=0;
        for(int i=0;i<n+1;i++){
            if(i%2==0){
                ans[i]=ans[i/2];
            }else{
                // 1 % 2 的結果是 1
                ans[i]=ans[i/2]+1;
            }
        }
        return ans;
    }
    //1=1
    //2=10
    //3=11
    //4=100
    //5=101
    //6=110
    //7=111
    //8=1000

};

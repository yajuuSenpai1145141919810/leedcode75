// 1431. Kids With the Greatest Number of Candies

// There are n kids with candies. You are given an integer array candies, 
// where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, 
// denoting the number of extra candies that you have.
// Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, 
// they will have the greatest number of candies among all the kids, or false otherwise.

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n=candies.size();
        vector<bool> result;

        // find max
        int large=0;
        for(int i=0;i<n;i++){
            if(candies[i]>large){
                large=candies[i];
            }
        }
        for(int j=0;j<n;j++){
            if((candies[j]+extraCandies)>=large){
                // 注意!!如果上面有宣告vector<bool> result(n)的話 這邊就改成result[i]=true;
                result.push_back(true);
            }else{
                result.push_back(false);
            }
        }
    return result;
    }
};

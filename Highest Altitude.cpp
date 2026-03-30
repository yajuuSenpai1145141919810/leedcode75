// 1732. Find the Highest Altitude
// There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. 
// The biker starts his trip on point 0 with altitude equal 0.
// 注意因為他說0也是點 因此結果最低是0!!!!
// You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 
// for all (0 <= i < n). Return the highest altitude of a point.


// 簡化後的寫法
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result=0;
        int current=0;
        for(int x:gain){
          // 注意 x就已經是陣列內的值了 不要再用gain[x]
            current+=x;
            result=max(result,current);
        }
        return result;
    }
};

// 我自己的寫法
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        if(n==0) return 0;

        int result=gain[0];
        int temp=gain[0]; // 用來儲存每輪下來的數值

        for(int i=1;i<n;i++){
            temp+=gain[i];
            if(temp>=result){
                result=temp;
            }
        }
        if(result<0) return 0;
        return result;
    }
};

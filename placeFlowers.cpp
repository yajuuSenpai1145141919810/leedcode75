// 605. Can Place Flowers 媽的 寫了快兩小時
// You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int m=flowerbed.size();
        if(n<=0) return true;
        if (m == 1) return (flowerbed[0] == 0 && n <= 1);
        // 頭
        if(flowerbed[0]==0&&flowerbed[1]==0){
            n--;
            flowerbed[0]=1;
        }
        // 尾巴
        if(flowerbed[m-2]!=1&&flowerbed[m-1]==0){
            n--;
            flowerbed[m-1]=1;
        }
        //中間 注意有三個條件 左中右都要
        for(int i=1;i<(m-1);i++){
            if(flowerbed[i-1]!=1&&flowerbed[i+1]!=1&&flowerbed[i]!=1){
                flowerbed[i]=1;
                n--;  
            }
        }
        if(n>0){
            return false;
        }else{
            return true;
        }

    }
};

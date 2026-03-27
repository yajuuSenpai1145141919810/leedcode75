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

// 另一種寫法 簡單來說就是 陣列 左右額外一格 直接不用檢查 讓他pass
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        for (int i = 0; i < m; i++) {
            // 如果當前位置是 0
            if (flowerbed[i] == 0) {
                // 檢查左邊：如果是第一格 (i==0)，左邊自動算 0；否則看 flowerbed[i-1]
                bool leftEmpty = (i == 0) || (flowerbed[i - 1] == 0);
                
                // 檢查右邊：如果是最後一格 (i==m-1)，右邊自動算 0；否則看 flowerbed[i+1]
                bool rightEmpty = (i == m - 1) || (flowerbed[i + 1] == 0);

                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1; // 種下去
                    n--;              // 剩餘目標減 1
                }
            }
            if (n <= 0) return true; // 提早結束，效能最優
        }
        return n <= 0;
    }
};

// 第三種寫法 
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {

        int m=flowerbed.size();
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        for(int i=1;i<m+1;i++){
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

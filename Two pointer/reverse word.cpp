// 151. Reverse Words in a String

// 簡潔寫法
class Solution {
public:
    string reverseWords(string s) {
    stringstream ss(s);
    string word;   // 暫時存放的位置
    string res=""; // 結果

    // >> 運算子在讀取字串時，會自動跳過所有空白字元
    while(ss>>word){
        if(res==""){
            res=word;
        }else{
            res=word+" "+res;SSSS
        }
    }
    return res;
    }
};

// 都可以用下面的移除辦法
// In-place (原地)
// Reverse words / characters (反轉單字或字元)
// Rotate array / string (旋轉陣列或字串)
// Remove duplicates / specific elements (移除重複或特定元素)

// 標準寫法
class Solution {
public:
    string reverseWords(string s) {
        // 1. 移除多餘空格 (使用快慢雙指針)
        int slow = 0;
        for (int fast = 0; fast < s.size(); ++fast) {
            if (s[fast] != ' ') { // 遇到字母才開始處理
                if (slow != 0) s[slow++] = ' '; // 單字間補一個空格
                while (fast < s.size() && s[fast] != ' ') {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.erase(s.begin() + slow, s.end()); // 砍掉後面多餘的空間

        // 2. 反轉整個字串
        reverse(s.begin(), s.end());

        // 3. 反轉每個單字
        int start = 0;
        for (int end = 0; end <= s.size(); ++end) {
            // 當遇到空格或字串結尾，代表找到一個單字了
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1; // 更新下一個單字的起點
            }
        }

        return s;
    }
};

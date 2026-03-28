// 392. Is Subsequence (兩種寫法)
// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters 
// without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

// Input: s = "abc", t = "ahbgdc"
// Output: true

// 更精簡的寫法 (while寫法比我好 但邏輯是一樣的)
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        
        // 只要任何一個字串走到底就停止
        while (i < s.length() && j < t.length()) {
            // 如果字元匹配，s 的指標才往後移
            if (s[i] == t[j]) {
                i++;
            }
            // 無論是否匹配，t 的指標每次都往後移
            j++;
        }
        
        // 如果 i 走到了 s 的末尾，說明 s 的字元都按順序在 t 中找到了
        return i == s.length();
    }
};

// 他這個子字串不一定要連續 因此想到用雙指標
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.length();// n=3
        int m=t.length();// m=6;

        int p1=0;
        int p2=0;
      
        // 這是重點!!!!!!空字串s可以是t的子字串 但是t不可以是!!!!
        if(n==0) return true;
        if(n!=0&&m==0) return false;

        while(1){
            if(s[p1]==t[p2]){
                p1++;
                p2++;
                if(p1==n){
                    return true;
                }
            }else{
                p2++;
            }
            if(p2==m){
                return false;
            }
        }
        return false;
    }
};

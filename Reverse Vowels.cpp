// 345. Reverse Vowels of a String(三種寫法)
// Given a string s, reverse only all the vowels in the string and return it.
// The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

// Example 1:
// Input: s = "IceCreAm"
// Output: "AceCreIm"
// Explanation:
// The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

class Solution {
public:
    string reverseVowels(string s) {
        int n=s.length();
        string result;
        int left=0;
        int right=n-1;

        string temp="";
        string temp1="";

        if(n==0) return {};
        if(n==1) return s;
        while(left<right){
            if(s[left]=='a'||s[left]=='A'||s[left]=='e'||s[left]=='E'||s[left]=='i'||s[left]=='I'||s[left]=='o'||s[left]=='O'||s[left]=='u'||s[left]=='U'){
                temp=s[left];
            }else{
                left++;
            }
            if(s[right]=='a'||s[right]=='A'||s[right]=='e'||s[right]=='E'||s[right]=='i'||s[right]=='I'||s[right]=='o'||s[right]=='O'||s[right]=='u'||s[right]=='U'){
                temp1=s[right];
            }else{
                right--;
            }
            if((temp!="")&&(temp1!="")){
                swap(s[left],s[right]);
                left++;
                right--;
                temp="";
                temp1="";
            }   
        }
        return s;
    }
};


// 另一種寫法:
while (left < right) {
    if (!isVowel(s[left])) {
        // 左邊不是母音，往右走一步，結束這回合（進入下一次外層 while）
        left++;
    } 
    else if (!isVowel(s[right])) {
        // 左邊是母音了，但右邊不是，右邊往左走一步
        right--;
    } 
    else {
        // 走到這裡，代表 left 和 right 兩邊「剛好」都是母音
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

第三種寫法:
class Solution {
public:
    string reverseVowels(string s) {

        string result;
        
        int left=0;
        int right=s.length()-1;

        string temp="aeiouAEIOU";

        while(left<right){
            while(temp.find(s[left])==string::npos&&left<right){
                left++;
            }
            while(temp.find(s[right])==string::npos&&left<right){
                right--;
            }
            if(left<right){
                swap(s[left],s[right]);
                left++;
                right--;

            }   
        }
        return s;
    }
};



 

// 345. Reverse Vowels of a String
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


 

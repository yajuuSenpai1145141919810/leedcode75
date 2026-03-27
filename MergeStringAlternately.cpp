// 1768. Merge Strings Alternately
// You are given two strings word1 and word2. 
// Merge the strings by adding letters in alternating order, starting with word1. 
// If a string is longer than the other, append the additional letters onto the end of the merged string.
// Return the merged string.

// Input: word1 = "abc", word2 = "pqr"
// Output: "apbqcr"
// Explanation: The merged string will be merged as so:
// word1:  a   b   c
// word2:    p   q   r
// merged: a p b q c r

class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        string result;

        int n=word1.length();
        int m=word2.length();

        if(n==0 && m==0) return {};
        if(n==0) return word2;
        if(m==0) return word1;

        for(int i=0;i<min(n,m);i++){
            result+=word1[i];
            result+=word2[i];
        }
        if(n>m){
            result+=word1.substr(min(n,m));
        }
        if(m>n){
            result+=word2.substr(min(n,m));
        }
        return result;
    }
};

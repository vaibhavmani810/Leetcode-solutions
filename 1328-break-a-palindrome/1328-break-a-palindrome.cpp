class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()<=1)return "";
        int index=-1,i=0;
        int n=palindrome.size();
        while(i<n && palindrome[i]=='a')
        {
            i++;
        }
        if((n%2 && i==(n)/2)||i==n)palindrome[n-1]='b';
        else
            palindrome[i]='a';
        return palindrome;
    }
};
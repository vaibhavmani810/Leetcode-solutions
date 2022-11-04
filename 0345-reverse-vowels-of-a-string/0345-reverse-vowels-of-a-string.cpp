class Solution {
public:
    bool vowel(char k)
    {
            if(k=='a'||k=='e'||k=='i'||k=='o'||k=='u'||k=='A'||k=='E'||k=='I'||k=='O'||k=='U')
            return true;
        return false;
    }
    string reverseVowels(string s) {
      int i=0,j=s.size()-1;
        while(i<j)
        {
            if(vowel(s[i])&&vowel(s[j]))
            {
                swap(s[i],s[j]);
                i++,j--;
            }
            else if(!vowel(s[i]))i++;
            else if(!vowel(s[j]))j--;
        }
        return s;
    }
};
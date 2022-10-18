class Solution {
public:
    string countAndSay(int n) {
         if(n == 1) return "1";
        
        if(n == 2) return "11";
      
      string str = "11";

      for(int j=3;j<=n;++j)
      {

      string temp = "";
      int cnt = 1;
      str += 'x';

     for(int i=1;i<str.length();++i)
     {
       if(str[i] != str[i-1])
       {
           temp += to_string(cnt);
           temp += str[i-1];
           cnt = 1;
       }

       else cnt++;
       
     }
       str = temp;
     
      }

      return str;
    }
};
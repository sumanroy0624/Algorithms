
class Solution {
public:
    vector<int> lps(string patt){
        int n=patt.size();
        vector<int>lps(n,0);
        int pre=0;
        int suf=1;
        while(suf<n){
            if(patt[pre]==patt[suf]){
                lps[suf]=pre+1;
                suf++,pre++;
            }else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }else{
                    pre=lps[pre-1];
                }
            }
        }
        return lps;
    }
    int strStr(string s, string patt) {
        vector<int>psl=lps(patt);
        int i=0;
        int j=0;
        while(i<s.size() && j<patt.size()){
           if(s[i]==patt[j]){
            i++;
            j++;
           }else{
             if(j==0){
                i++;
             }else{
                j=psl[j-1];
             }
           }
           if(j==patt.size())return i-j;
        }
        return -1;
    }
};

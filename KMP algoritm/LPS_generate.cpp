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
};

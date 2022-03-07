
int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        int t[n+1][m+1];
        //initilazitaion
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0||j==0)
                    t[i][j]=0;
            }
        }
        
        // main code
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(text1[i-1]==text2[j-1])
                    t[i][j]=1+t[i-1][j-1];       
                else
                    t[i][j]=max(t[i][j-1],t[i-1][j]);
                
            }
        }
        return t[n][m];
    }

int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        return longestCommonSubsequence( s,  r);
        
    }


class Solution {
public:
    int minInsertions(string s) {
       return s.length()-longestPalindromeSubseq(s);
    }
};

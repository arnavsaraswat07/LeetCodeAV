class Solution {
public:
     int numDistinct(string s, string t) {
        //classic take not take problem
        //we need to count the number of ways so
        //we need to use s to make t
        int i=s.size();
        int j=t.size();
        vector<vector<unsigned long long>>dp(i+1,vector<unsigned long long>(j+1,0));
        for(int i=0;i<=s.size();i++){
            dp[i][0]=1;
        }
        for(int index1=1;index1<=i;index1++){
            for(int index2=1;index2<=j;index2++){
                if(s[index1-1]==t[index2-1]){
                    dp[index1][index2]=dp[index1-1][index2-1]+dp[index1-1][index2];
                }
                else{
                    dp[index1][index2]=dp[index1-1][index2];
                }

            }
        }
        return int(dp[i][j]);
        
    }

};
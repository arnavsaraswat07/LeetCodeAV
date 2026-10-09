class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //aapko segment karna hai
        //word by word
        //hashing until u get a valid word
        //move back and like take or not take thts the game
        //if u take then it cant be taken in another
        //map all the words and see if u can then  get the word

        //for eg dogs and sands if u take s in dogs u cant take it in sands
        int n=s.size();
        unordered_set<string> st;
        vector<bool>dp(n+1,0);
        dp[0]=true;
        for(string s: wordDict){
            st.insert(s);
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && st.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
                
            }
            


        }

        return dp[n];
        
    }
};
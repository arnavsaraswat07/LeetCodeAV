class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        int depth=0;
        for(char c:s){
            if(c=='('){
                if(depth==0){
                    depth++;
                    continue;
                }
                else{
                    ans+=c;
                    depth++;

                }
            }
            else if(c==')'){
                depth--;
                if(depth==0){
                    
                    continue;
                }
                else{
                    ans+=c;
                    

                }

            }
        }
        return ans;
    }
};

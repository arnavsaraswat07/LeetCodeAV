class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int maxcount=0;
        for(char c:s){
            if(c=='('){
                cnt++;
                maxcount=max(cnt,maxcount);
            }
            else if(c==')'){
                cnt--;
            }
            else{
                continue;
            }
        }
        return maxcount;
        
    }
};
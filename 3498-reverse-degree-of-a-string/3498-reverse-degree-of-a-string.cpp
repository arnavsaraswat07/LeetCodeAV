class Solution {
public:
    int reverseDegree(string s) {
        int sum=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            //
            int curr=s[i]-'a';
            int prod=(26-curr)*(i+1);
            sum=sum+prod;
        }
        return sum;
        
    }
};
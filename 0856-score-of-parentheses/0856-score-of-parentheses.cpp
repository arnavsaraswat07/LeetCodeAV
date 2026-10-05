class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for(char c:s){
            if(c=='('){
                st.push(0);
            }
            else{
                int inside=st.top();
                st.pop();
                int current=0;
                if(inside==0){
                    current=1;
                }
                else{
                    current=2*inside;
                }

                st.top()+=current;
            }
        }
        return st.top();
    }
};
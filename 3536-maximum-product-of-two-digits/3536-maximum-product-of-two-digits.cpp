class Solution {
public:
    int maxProduct(int n) {
        string number=to_string(n);
        vector<int>numberarray;
        int m=number.size();
        for(int i=0;i<m;i++){
            numberarray.push_back(number[i]-'0');

        }
        sort(numberarray.begin(),numberarray.end());
        int prod=numberarray[m-1]*numberarray[m-2];
        return prod;
    }
};
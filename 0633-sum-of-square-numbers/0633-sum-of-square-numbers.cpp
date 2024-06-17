class Solution {
public:
    bool judgeSquareSum(int c) {
        long long ans = ceil(sqrt(c));
        bool a = false;
        long long left =0 ;
        long long right = ans;
        while(left <= right) {
            long long temp =(left*left) + (right*right);
            if( temp == c ) return true;
            else if( temp < c)left++;
            else right--;
        }
        
        return a ;
    }
};
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int cnt = 0;
        cout << ans <<endl ;
        for(int i = 0;i<31;i++){
            if(ans & (1 << i)){
                   cout << (1 << i) << endl;
                            cnt++;

            }
        }
        return cnt;
    }
};
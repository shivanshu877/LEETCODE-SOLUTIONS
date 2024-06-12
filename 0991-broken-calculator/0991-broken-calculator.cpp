class Solution {
public:
    int brokenCalc(int st, int tg) {
        int steps = 0;
        while (tg > st) {
            if (tg % 2 == 0) {
                tg /= 2;
            } else {
                tg += 1;
            }
            steps++;
        }
        return steps + (st - tg);
    }
};

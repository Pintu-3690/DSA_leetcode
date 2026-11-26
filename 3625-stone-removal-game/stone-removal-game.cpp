class Solution {
public:
    bool canAliceWin(int n) {
        int pile = n;
        int move = 10;
        bool aliceTurn = true;

        while (pile >= move) {
            pile -= move;
            --move;
            aliceTurn = !aliceTurn;
        }


        return !aliceTurn;
    }
};
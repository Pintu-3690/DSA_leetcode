class Solution {
public:
    int mySqrt(int x) {
        if (x<2)return x;
        long c = x;
        while(c > x/c){
            c = (c + x/c)/2;

        }
         return c;
    }
   
};
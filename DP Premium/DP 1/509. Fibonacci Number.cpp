F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.

class Solution {
public:
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        int a =0, b=1, c;
        for(int i=2;i<=n;i++)
        {
            c = a+b;
            a=b;
            b=c;
        }
        return c;
        
    }
};
You are given an even number of people numPeople that stand around a circle and each person shakes hands with someone else so that there are numPeople / 2 handshakes total.

Return the number of ways these handshakes could occur such that none of the handshakes cross.

Since the answer could be very large, return it modulo 109 + 7.

Input: numPeople = 4
Output: 2
Explanation: There are two ways to do it, the first way is [(1,2),(3,4)] and the second one is [(2,3),(4,1)].


#define N 1000000007
class Solution {
public:
    vector<long long int> sieve(int n){
        vector<long long int> c(n+1);
        c[0]=1;
        c[1] = 1;
        for(int i =2;i<=n;i++){
            for(int j =0;j<i;j++){
                c[i] += c[j]*c[i-j-1];
                c[i]=c[i]%N;
            }
        }
        return c;
    }
    int numberOfWays(int num_people) {
        vector<long long int> c((num_people/2)+1);
        c=sieve(num_people/2);
        return (int)c[num_people/2];
    }
};
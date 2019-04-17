#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int M7 = 1000000007;
ll modularpower(int a,int n){
   
    ll r = 1;
    while(n > 0){
        if(n & 1){
            r *= a;
            r %= M7;
        }
        a=(1LL * a*a) % M7;
        n >>= 1;
    }
    return r;
}

int main(){
    int n,k;
    cin >> n >> k;
    /*
    THINK OF THE PROBLEM AS ARRANGING THE VECTORS IN SUCH A MANNER 
    THAT THEY FORM A POLYGON. THE RESULTANT VECTOR SUM WILL ALWAYS BE 0;
    IF ANY VECTOR(ROD) HAS A LENGTH >K/2 , THE POLYGON WILL NOT BE CONVEX , 
    INFACT THERE WILL BE NO POLYGON. 
    THE PROBABILITY WE REQUIRE IS 1-(WHEN THERE IS A ROD(len)>K/2;
    
    LET THE ROD OF LENGTH >K/2 BE PART OF A CIRCLE OF CIRCUMFERENCE K.
    THE CIRCLE IS DIVIDED INTO N PARTS , AND WE ASSUME THERE IS A PART OF LEN> K/2;
    DRAW A DIAMETER VIA THIS POINT. 
    NOW , THERE ARE N WAYS TO SELECT >K/2;
    ABOVE OR BELOW THE DIAMETER WOULD BE REMAINING N-1 POINTS EACH OF WHICH
    CAN BE SELECTED WITH A PROBABILITY OF 1/2 =(1/2^N-1)
    
    HENCE PROBABILITY OF VECTOR SUM!=0 IS N/2^N-1=P;
    OUR ANS IS 1-P;
    */
    
    ll prob = modularpower(2,n-1);
    prob = (n * modularpower(prob, M7-2)) % M7;
    long long circle= 1 - prob;
    circle+= M7;
    circle%= M7;
    cout << circle <<endl;

    return 0;
}
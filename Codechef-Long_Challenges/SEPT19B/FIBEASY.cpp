#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include<stdio.h>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>
using namespace std;
#define ull unsigned long long int
#define ll long long 

int arr[60]={0, 1, 1, 2, 3, 5, 8, 3, 1, 4, 5, 9, 4, 3, 7, 0, 7, 7, 4, 1, 5, 6, 1, 7, 8, 5, 3, 8, 1, 9, 0, 9, 9, 8, 7, 5, 2, 7, 9, 6, 5, 1, 6, 7, 3, 0, 3, 3, 6, 9, 5, 4, 9, 3, 2, 5, 7, 2, 9, 1};

bool powtwo(ull x)  
{  
    return x && (!(x&(x-1)));  
}  
ull powr(ull base,ull exp)
{
	ull res=1;
	while(exp>0)
	{
		if(exp&1)
			res=res*base;
		exp=exp>>1;
		base=base*base;
	}
 return res;
}
int main()
{
	int mod10[60];
    mod10[0] = 0;
    mod10[1] = 1;
    for (int i=2;i<60;i++)  
        mod10[i] = (mod10[i-2]+mod10[i-1]) % 10;

    int t;
    scanf("%d",&t);
    while(t--){
    	ull fib;
    	cin>>fib;

    	
        //fib|=(fib>>64);
    	fib >>= 1;
        fib |= fib>>32;
        fib |= fib>>16;
        fib |= fib>>8;
        fib |= fib>>4;
        fib |= fib>>2;
        fib |= fib>>1;
        
        int idx=(int)(fib%60);

    	int ans=mod10[idx];
    	printf("%d\n",ans);
    }
}
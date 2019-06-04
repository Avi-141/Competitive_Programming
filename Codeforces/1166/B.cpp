#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long long int lli;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

void sieve(int n, bool primes[]) { 

    for(int i=0;i<=n;i++)
        primes[i] = true;

    for (int p=2; p*p <= n; p++)
        if (primes[p] == true) 
            for (int i=p*p; i <= n; i += p) 
                primes[i] = false; 

}
int main(){

    int k;
    cin >> k;
    int n,m;
    ing flag= 0;
    string str = "";
    char arr[] = { 'a' , 'e' , 'i' , 'o' , 'u' };
    int mov;

    for( int i = 1 ; i <= k ; i++ )
    {
        if( k%i == 0 && i >= 5 && k/i >= 5 )
        {
            n = i;
            m = k/i;
            flag=1;
        }
    }
    if(flag==0)
    {
        cout << -1 << endl;
    }
   else
    {
        mov=0;
        for( int i = 1 ; i<=n; i++ ){
            int row = mov;
            for( int j = 1 ; j<=m ; j++ ){
                str = str + arr[temp];
                row++;
                row=row%5;
            }
            mov++;//mov the pointer to next position .//column wise vowels
            mov=mov%5;
        }
        cout << str << endl;
    }

}
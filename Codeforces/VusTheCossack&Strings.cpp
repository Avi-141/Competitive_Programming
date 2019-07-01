#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
#define For(i,st,en) for(ull   (i) = (ull  )(st); (i) <= (ull  )(en); (i)++)
#define pb push_back
#define bint int64_t
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define pi 3.141592653589793
using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string a, b;
    cin >> a >> b;
    int ans = 0;
    int n = a.size(), m = b.size();
    int fir = count(b.begin(), b.end(), '1');
    int sec = count(a.begin(), a.begin() + m, '1');

    ans = abs(fir - sec) % 2 == 0;

    for (int i = m; i < n; i++) {
        sec += (a[i] - '0') - (a[i - m] - '0');
        ans += abs(sec - fir) % 2 == 0;
    }
    cout << ans;


}
#include <bits/stdc++.h>

using namespace std;

vector<int8_t> mobius(1000001,1);

void calculate_mobius(){
    vector<bool> sieve(mobius.size(),true);
    
    for(long long prime=2; prime < sieve.size(); ++prime){
        if(sieve[prime]){
            //sieving multiples of prime
            for(long long mlt = prime*prime; mlt < sieve.size(); mlt += prime){
                sieve[mlt] = false;
            }
            //negating mobius values
            for(long long mlt = prime; mlt < mobius.size(); mlt += prime){
                mobius[mlt] *= -1;
            }
            //zeroing mobius values for squares
            for(long long mltsqr = prime*prime; mltsqr < mobius.size(); mltsqr += prime*prime){
                mobius[mltsqr] = 0;
            }
        }
    }
}

// Complete the solve function below.
long long solve(long long n) {
    //mobius theorem .
    long long answer = 0;
    for(long long a=2; a*a*a <= n; a++){
        answer -= mobius[a] * (n / (a*a*a));
    }
    return answer;
}

int main()
{
    calculate_mobius();
    
    long long t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}
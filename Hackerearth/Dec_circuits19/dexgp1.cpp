

    #include <bits/stdc++.h>
    using namespace std;
    typedef long long int lli;
     
    vector<lli> primes;
    vector<bool> isPrime;
    void primesSieve(lli n){
    	isPrime.resize(n + 1, true);
    	isPrime[0] = isPrime[1] = false;
    	primes.push_back(2);
    	for(lli i = 4; i <= n; i += 2){
    		isPrime[i] = false;
    	}
    	for(lli i = 3; i <= n; i += 2){
    		if(isPrime[i]){
    			primes.push_back(i);
    			for(lli j = i * i; j <= n; j += 2 * i){
    				isPrime[j] = false;
    			}
    		}
    	}
    }
     
    lli powMod(lli b, lli e, lli m){
    	lli ans = 1;
    	while(e){
    		if(e & 1) ans = (ans * b) % m;
    		e >>= 1;
    		b = (b * b) % m;
    	}
    	return ans;
    }
     
    vector<pair<lli, int>> factorize(lli n){
    	vector<pair<lli, int>> f;
    	for(lli & p : primes){
    		if(p * p > n) break;
    		int pot = 0;
    		while(n % p == 0){
    			pot++;
    			n /= p;
    		}
    		if(pot) f.push_back(make_pair(p, pot));
    	}
    	if(n > 1) f.push_back(make_pair(n, 1));
    	return f;
    }
     
    lli multiplicativeOrder(lli x, lli m){
    	lli order = m - 1;
    	vector<pair<lli, int>> f = factorize(order);
    	for(auto & factor : f){
    		lli p = factor.first;
    		int a = factor.second;
    		order /= pow(p, a);
    		lli tmp = powMod(x, order, m);
    		while(tmp != 1){
    			tmp = powMod(tmp, p, m);
    			order *= p;
    		}
    	}
    	return order;
    }
     
    lli discreteLogarithm(lli a, lli b, lli m){
    	lli order = multiplicativeOrder(a, m);
    	lli n = sqrt(order) + 1;
    	lli a_n = powMod(a, n, m);
    	lli ans = 0;
    	unordered_map<lli, lli> firstHalf;
    	lli current = a_n;
    	for(lli p = 1; p <= n; p++){
    		firstHalf[current] = p;
    		current = (current * a_n) % m;
    	}
    	current = b % m;
    	for(lli q = 0; q <= n; q++){
    		if(firstHalf.count(current)){
    			lli p = firstHalf[current];
    			lli x = n * p - q;
    			return x % order;
    		}
    		current = (current * a) % m;
    	}
    	return -1;
    }
     
    int main(){
    	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    	primesSieve(40000);
    	int t;
    	cin >> t;
    	while(t--){
    		lli r, s, p;
    		cin >> r >> s >> p;
    		lli b = s * (r - 1) + 1;
    		lli ans = discreteLogarithm(r, b, p);
    		if(ans == 0) ans = 1;
    		cout << ans << "\n";
    	}
    	return 0;
    }

Language: C++14

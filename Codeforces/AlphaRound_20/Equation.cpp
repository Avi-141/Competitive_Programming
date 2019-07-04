#include <bits/stdc++.h>
#define ld long double
#define ll long long int
using namespace std;
    ld  x=0,y=0,l=0;
    ll a=0,b,c;
    int main()
    {
    	cin >> a >> b >> c;
    	x=(b*b)-(4*a*c);

    	if(a==0 && b==0 && c==0)
    	{
    		cout << -1; 
    		return 0;
    	}
    	if(a==0 && b==0)
    	{
    		cout << 0;
    		return 0;
    	}
    	cout.precision(6);
            cout << fixed;
    	if(a==0)
    	{
    		x=-c;
    		x/=b;
    		cout << 1 << endl;
    		cout << x;	
    		return 0;
    	}
    	if(x<0)
    	{
    		cout << 0;
    		return 0;
    	}
    	if(x==0)
    	{
    		cout << 1 << endl;
    		x=-b;
    		x/=2*a;
    		cout << x << endl;
    		return 0;
    	}
    	else
    	{
    		cout << 2 << endl;
    		y=-b+sqrt(x);
    		y/=(2*a);
    		l=-b-sqrt(x);
                    l/=(2*a);
    		if(y>l)	
    			swap(y,l);
                    cout << y << endl;
    		cout << l << endl;
    	}
    	return 0;
    }
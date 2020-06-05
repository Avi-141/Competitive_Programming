#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    	cin>>a[i];
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; ++i)
    {
    	if(s.size()!=0)
    	{
    		if(a[i]<a[s.top()])
    			s.push(i);
    		else
    		{
    			while(s.size()!=0 && a[i]>a[s.top()])
    			{
    				b[s.top()]=a[i];
    				s.pop();
    			}
    			s.push(i);
    		}
    	}
    }
    while(s.size()!=0)
    {
    	b[s.top()]=-1;
    	s.pop();
    }
    for(int i=0;i<n;i++)
    	cout<<a[i]<<" "<<b[i]<<endl;
    return 0;
}
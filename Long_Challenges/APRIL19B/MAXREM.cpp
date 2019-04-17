#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
    std::vector<int> v(n);
	for(int i=0;i<n;i++)cin>>v[i];

	std::sort(v.begin(), v.end());
	v.erase(std::unique(v.begin(), v.end()), v.end());
        if(v.size()==1)cout<<0;
        else if(v.size()>1) 
        cout<< *(v.rbegin() + 1)<<endl;

	//for (auto it = v.cbegin(); it != v.cend(); ++it)
	

	return 0;
}
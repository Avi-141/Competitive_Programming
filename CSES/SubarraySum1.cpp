#include<bits/stdc++.h>
using namespace std;
#define ll long long 


int main()
{

 ll n,givenSum;
 cin>>n>>givenSum;
 vector<ll> vec(n);
 for(ll i=0;i<n;i++)
 	cin>>vec[i];

    ll currSum = vec[0];
    ll start=0;
    ll end=0;
    ll tot=0;
    while (end < vec.size())
    {
        if (currSum == givenSum)
        {
           tot++;
        }
        
        if (currSum <= givenSum)
        {
            end++;
            if (end < vec.size())
                currSum = currSum + vec[end];
        }
        else
        {
            currSum = currSum - vec[start];
            start++;
        }
    }
    cout<<tot<<" ";
}

/*Keep on adding elements in current_sum till its less than the given sum.
If it becomes greater than given sum, 
start subtracting elements from the start of the array till its greater than given sum.*/
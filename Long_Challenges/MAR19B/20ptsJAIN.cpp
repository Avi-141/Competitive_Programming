#include<bits/stdc++.h>
using namespace std;

int countCompletePairs(string set1[],int n)
{
    int ans = 0;

    long long s1[n];

    for (int i=0; i<n; i++)
    {
        s1[i] = 0;
        for (int j=0; j<set1[i].length(); j++)
        {
            s1[i] = s1[i] | (1<<(set1[i][j]-'a'));
        }
    }

    long long complete=0;
    complete=complete|(1<<('a'-'a'));
    complete=complete|(1<<('e'-'a'));
    complete=complete|(1<<('i'-'a'));
    complete=complete|(1<<('o'-'a'));
    complete=complete|(1<<('u'-'a'));


    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if ((s1[i] | s1[j]) == complete)
                ans++;
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string set1[n];
        for(int i=0;i<n;i++)
            cin>>set1[i];
        cout<<countCompletePairs(set1,n)<<endl;

    }
}
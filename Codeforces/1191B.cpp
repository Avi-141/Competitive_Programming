#include<bits/stdc++.h>
using namespace std;
#define ll long long 


bool check(string a, string b, string c)
{
    if (a == b && b == c) return true;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    if (a[1] == b[1] && b[1] == c[1])
    {
        if (a[0] + 1 == b[0] && b[0] + 1 == c[0])
            return true;
    }
    return false;
}


int main()
{

    string a, b, c;
    cin >> a >> b >> c;
    if (check(a, b, c))
    {
        cout << "0";
        return 0;
    }
    vector<string> var;
    for (ll  i = 1; i <= 9; i++)
    {
        string s = "";
        s += (char)(i + '0');
        var.push_back(s + "m");
        var.push_back(s + "p");
        var.push_back(s + "s");
    }
    for (string s : var)
    {
        if (check(s, a, b))
        {
            cout << "1";
            return 0;
        }
        if (check(s, a, c))
        {
            cout << "1";
            return 0;
        }
        if (check(s, b, c))
        {
            cout << "1";
            return 0;
        }
    }
    cout << "2";
    return 0;
}
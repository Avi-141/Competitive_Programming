#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mkpa make_pair
#define watch(x) cout << (#x) << " is " << (x) << endl;
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
 
const ll modm = 1e9+7;
// ROUND 638 CODEFORFCES DIV2 

/*I think it would be nice to comment my approach to E and the way i thought about it.

Lets say we have some vectors in a plane, lets define a modular plane as a plane such 
that if we are in [x,y] then 0≤x,y<k, also if the condition doesn't holds then we go to 
[x mod k,y mod k](a positive modular), 
we want to see if we are able to choose some of vectors to reach [x,y] \
such that x+y<k, starting at [r,c]. 
Also each vector is labeled with a number i, 
we cant choose two vectors with the same label, there are n labels at most.

We know that a vector x coordinate plus its y coordinate is equal to k
(each vector means how many reds we chose and how many blues we chose from a ith shrub). 
The problem is not easier, but it can help you understand the logic behind the problem
Also if you start from [r,c], you cant reach [x,y] such that (x+y)≠(r+c)mod k.

r is number of reds modul k and c is number of blues modul k, [x,y] 
is coordinate of a dot or a vector
(coordinates of a vector is the coordinates of the endpoint of the vector 
when its moved to region)


If there are t total berries and r extra red berries, 
there will be (t−r) mod k extra blue berries. 
This is because all the other red berries are already filled in some baskets, 
and if there are many extra blue berries they can fill their own baskets too.
*/

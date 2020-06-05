/*You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. 
You can change the height of a stack by removing and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. 
This means you must remove zero or more cylinders from the 
top of zero or more of the three stacks until they're all the same height, 
then print the height. 
The removals must be performed in such a way as to maximize the height.
An empty stack is still a stack . */

/*Sample input 
5 3 4
3 2 1 1 1
4 3 2
1 1 4 1

output 5*/ 

/*Step I. get the 3 array and reverse them, 
create a new array out of an existing array with each element is sum of all the previous elements. 
eg: [3,2,1,1,1] -> [1,1,1,2,3] -> [1,2,3,5,8]

So the 3 new array formed would be [1,2,3,5,8] [2,5,9] [1,5,6,7]

Step II. Again reverse the array [8,5,3,2,1] [9,5,2] [7,6,5,1]

Step III. Take the smallest array i.e. [9,5,2] traverse the smallest array and search element in the other 2 array -
 if the element is existing in other 2 array, STOP there and return the number.

Eg. Here I start with elem - 9 : Which is not existing in other 2 array.'
' Next I start with elem - 5 : it is existing in other 2 array. */

#include <bits/stdc++.h>
using namespace std;


#define N 100000+10

int a[N];
int b[N];
int c[N];

int main() {
    
    int n1,n2,n3;
    
    cin>>n1>>n2>>n3;
    for(int i = 1; i <= n1; i++)cin>>a[i];
    for(int i = 1; i <= n2; i++)cin>>b[i];
    for(int i = 1; i <= n3; i++)cin>>c[i];

    reverse(a + 1, a + n1 + 1);
    reverse(b + 1, b + n2 + 1);
    reverse(c + 1, c + n3 + 1);

    for(int i = 1; i <= n1; i++) a[i] += a[i - 1];
    for(int i = 1; i <= n2; i++) b[i] += b[i - 1];
    for(int i = 1; i <= n3; i++) c[i] += c[i - 1];

    while(a[n1] != b[n2] || a[n1] != c[n3]) {
        if(a[n1] > b[n2]) n1--;
        if(a[n1] > c[n3]) n1--;
        if(b[n2] > c[n3]) n2--;
        if(a[n1] < b[n2]) n2--;
        if(a[n1] < c[n3]) n3--;
        if(b[n2] < c[n3]) n3--;
    }
    cout << a[n1] << endl;
    return 0;
}

/**
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>

using namespace std;

int n1, n2, n3, a[110000];
int ss[10000001];

void doit(int n) {
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	int sum = 0;
	ss[sum] += 1;
	for (int i = n; i; i--) {
		sum += a[i];
		ss[sum] += 1;
	}
}

int main() {
	memset(ss, 0, sizeof ss);
	scanf("%d%d%d", &n1, &n2, &n3);
	doit(n1);
	doit(n2);
	doit(n3);
	for (int i = 10000000; i >= 0; i--)
		if (ss[i] == 3) {
			printf("%d\n", i);
			return 0;
		}
}**/
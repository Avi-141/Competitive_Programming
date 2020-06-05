/*Find the maximum no.of partitions she can make such that each of her peers gets composite number of chocolates 
because her friends consider composite numbers to be lucky.*/



//python 
/*T = int(input())
for t in range(T):
    n = int(input())
    if n < 12:
        print(-1)
        continue
    if n % 2 == 0:
        if n % 4 == 0:
            print(n // 4)
            continue
        else:
            print((n - 6) // 4 + 1)
            continue
    else:
        k = n - 9
        if k % 4 == 0:
            print(1 + k // 4)
        else:
            print(2 + (k - 6) // 4)
        */


        #include <iostream>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main()
{
	int q;
	cin >> q;
 
	vector <int> v(q);
	for (int i = 0; i < q; i++)
		cin >> v[i];
 
	int temp, parts[12] = {-1, -1, -1, -1, 1, -1, 1, -1, 2, 1, 2, -1};
 
	for (int i = 0; i < q; i++)
	{
		if (v[i] < 12)
			cout << parts[v[i]] << "\n";
 
		else if (v[i] % 2 == 0)
			cout << v[i] / 4 << "\n";
 
		else
			cout << (v[i] - 9) / 4 + 1 << "\n";
	}
 
	return 0;
}
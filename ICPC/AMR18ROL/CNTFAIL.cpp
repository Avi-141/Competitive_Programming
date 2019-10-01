#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include<string.h>
#include <bitset>
#include <iomanip>
#include <climits>
#include <string>
#include <cmath>
using namespace std;

const int inf = 1e6;
int arr[100005];

int main() {

	int test;
	scanf("%d", &test);
	while (test--) {
		int n, minn = inf, mxx = -1;
		int val, cnt1 = 0, cnt2 = 0;
		
		scanf("%d", &n);
		
		for (int i = 0; i < n; ++i) {
			scanf("%d", &val);
			minn = min(minn, val);
			mxx = max(mxx, val);
			arr[i] = val;
		}
		
		for (int i = 0; i < n; ++i) {
			if (arr[i] == minn)
				cnt1++;
			if (arr[i] == mxx)
				cnt2++;
		}
		
		if (mxx - minn > 1) {
			puts("-1");
			continue;
		}
		
		if (mxx - minn == 1) {
			if (mxx != cnt1) {
				puts("-1");
				continue;
			}
			printf("%d\n", n - mxx);
			continue;
		}
		
		if (mxx) {
			if (mxx != n - 1)
				puts("-1");
			else
				puts("0");
		}
		
		else
			printf("%d\n", n);
	}
	return 0;
}


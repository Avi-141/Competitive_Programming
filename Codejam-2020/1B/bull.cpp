#include <bits/stdc++.h>

using namespace std;

const int Lim = 1000000000;

int main() {
	int T, A, B;
	string res;
	cin >> T >> A >> B;
	for (int i=0; i<T; i++) {
		// First, find any point at all that works
		int Xi;
		int Yi;
		int low, high;
		int Xl, Xh, Yl, Yh;
		for (Xi = -7*(Lim/8); Xi < Lim; Xi += Lim/8) {
			for (Yi = -7*(Lim/8); Yi < Lim; Yi += Lim/8) {
				cout << Xi << " " << Yi << endl;
				cin >> res;
				if (res == "CENTER") goto end;
				if (res == "HIT") goto semi;
			}
		}
		semi:
		// Binary search the extend of the board
		low = -Lim-1; high = Xi;
		while (high - low > 1) {
			int mid = (high+low)/2;
			cout << mid << " " << Yi << endl;
			cin >> res;
			if (res == "CENTER") goto end;
			if (res == "HIT") {
				high = mid;
			} else {
				low = mid;
			}
		}
		Xl = low;
		low = Xi; high = Lim+1;
		while (high-low > 1) {
			int mid = (high+low)/2;
			cout << mid << " " << Yi << endl;
			cin >> res;
			if (res == "CENTER") goto end;
			if (res == "HIT") {
				low = mid;
			} else {
				high = mid;
			}
		}
		Xh = high;
		low = -Lim-1; high = Yi;
		while (high-low > 1) {
			int mid = (high+low)/2;
			cout << Xi << " " << mid << endl;
			cin >> res;
			if (res == "CENTER") goto end;
			if (res == "HIT") {
				high = mid;
			} else {
				low = mid;
			}
		}
		Yl = low;
		low = Yi; high = Lim+1;
		while (high-low > 1) {
			int mid = (high+low)/2;
			cout << Xi << " " << mid << endl;
			cin >> res;
			if (res == "CENTER") goto end;
			if (res == "HIT") {
				low = mid;
			} else {
				high = mid;
			}
		}
		Yh = high;
		// Throw dart at center
		cout << (Xl+Xh)/2 << " " << (Yl + Yh)/2 << endl;
		cin >> res;
		end:
		// Do nothing placeholder for finishing round early.
		;
	}
}

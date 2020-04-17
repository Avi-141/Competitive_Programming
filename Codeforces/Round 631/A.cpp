int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif
 
    int tc;
    cin >> tc;
    while (tc--) {
        int n, x;
        cin >> n >> x;
        vector <int> cnt(305);
        int y;
        for (int i = 1; i <= n; i++) {
            cin >> y;
            cnt[y] = 1;
        }
        int cur = 0;
        for (int i = 1; i <= 300; i++) {
            if (!cnt[i]) {
                cur++;
            }
            if (cur > x) {
                cout << i - 1 << '\n';
                break;
            }
        }
    }
}
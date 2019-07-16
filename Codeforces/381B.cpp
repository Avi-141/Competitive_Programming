
    #include <iostream>
    #include <vector>
    #include <algorithm>
     
    using namespace std;
     
    int main() {
        int n;
        cin >> n;
        vector<int> v(n), w(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        sort(v.begin(), v.end());
        w.erase(unique_copy(v.begin(), v.end(), w.begin()), w.end());
        v.erase(set_difference(v.begin(), v.end(), w.begin(), w.end(), v.begin()), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        if (!v.empty() && v.back() == w.back()) v.pop_back();
        cout << w.size() + v.size() << endl << w.front();
        for (int i = 1; i < w.size(); ++i)
            cout << ' ' << w[i];
        for (int i = v.size() - 1; i >= 0; --i)
            cout << ' ' << v[i];
        cout << endl;
        return 0;
    }
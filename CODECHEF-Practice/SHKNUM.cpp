#include<bits/stdc++.h>
using namespace std;

auto precompute_powers() 
{
   set<int> sheokhand;
   for (int i = 0; i <= 30; ++i)
      for (int j = 0; j <= 30; ++j)
         if (i != j) sheokhand.insert (pow (2, i) + pow (2, j));
   return sheokhand;
}
auto calculate(const set<int>& s, int N) {
   if (N < 3) return 3 - N;     
   auto it = s.lower_bound (N);
   if (N == *it) return 0;      
   return min (N - *prev (it), *it - N);//lower or upper bound. better vakue returned.
}

int main ()
{
   auto sheokhand = precompute_powers();
   int t;
   cin >> t;
   while (t--)
   {
      int N; 
      cin >> N;
      cout << calculate(sheokhand, N) << endl;
   }
   return 0;
}  


#include<bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>& a)
{
   int i, score = 0, j, f;
   vector<bool> done(n, false); 

   for (int turn = 0; turn < n; turn++) { // max n turns
      int best_i = -1, best_val = -1;

     
      for (i = 0; i < n; i++) {
         if (!done[i] && a[i] > best_val) {
            best_val = a[i];
            best_i = i;
         }
      }
      if (best_i == -1) break; // all done

      int val = a[best_i];
      score += val;

      
      for (i = 0; i < n; i++) {
         if (!done[i] && (a[i] == val || a[i] == val + 1 || a[i] == val - 1)) {
            done[i] = true;
         }
      }
   }
   cout << score << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    solve(n, a);
}
/*
 * 10130 - SuperSale
 *
 * Looks like Knapsack problem, I'm using the same resolution.
 */

#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int memo[1001][31];
vi prices;
vi weights;
int n;

int dp(int i, int w) {
  if (memo[i][w] != -1)
    return memo[i][w];

  if ((i == n) || (w == 0)) {
    memo[i][w] = 0;
  } else if (weights[i] > w) {
    memo[i][w] = dp(i + 1, w);
  } else {
    memo[i][w] = max(prices[i] + dp(i + 1, w - weights[i]),
                     dp(i + 1, w));
  }

  return memo[i][w];
}

int main() {
  int t, p, w, total, g, mw;

  cin >> t;

  for (int i = 0; i < t; i++) {
    total = 0;

    prices.clear();
    weights.clear();
    memset(memo, -1, sizeof memo);

    cin >> n;

    for (int j = 0; j < n; j++){
      cin >> p;
      cin >> w;

      prices.push_back(p);
      weights.push_back(w);
    }

    cin >> g;

    for (int i = 0; i < g; i++){
      cin >> mw;
      total += dp(0, mw);
    }

    cout << total << endl;
  }
}

/*
 * What is the Median?
 */

#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

int main(){
  int x, median;
  vi arr;

  while (cin >> x){
    arr.push_back(x);

    sort(arr.begin(), arr.end());
    median = arr.size() / 2;

    if (arr.size() % 2 == 0) { // if it's even
      median = (arr[median] + arr[median - 1]) / 2;
    } else {
      median = arr[median];
    }

    cout << median << endl;
  }
  return 0;
}

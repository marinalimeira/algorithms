/*
 * 12207 - That is Your Queue
 */

#include <bits/stdc++.h>
using namespace std;

int main(){
  int c = 1, p = 1, e, begin, cases = 1, n;
  string a;

  while (true) {
    cin >> p;
    cin >> c;

    if (c + p == 0) break;
    list<int> cs;

    p = min(p, c);
    for (int i = 1; i <= p; i++){
      cs.push_back(i);
    }

    cout << "Case " << cases++ << ":" << endl;
    for(int i = 0; i < c; i++){
      cin >> a;
      if (a.compare("N") == 0) {
        begin = *cs.begin();
        cout << begin << endl;
        cs.push_back(begin);
        cs.pop_front();
      } else {
        cin >> e;
        cs.remove(e);
        cs.push_front(e);
      }
    }
  }

  return 0;
}

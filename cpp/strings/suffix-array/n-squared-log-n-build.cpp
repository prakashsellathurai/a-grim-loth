#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;
#define MAXN 65536
#define MAXLG 17
char A[MAXN];
struct entry {
  int nr[2], p;
} L[MAXN];
int P[MAXLG][MAXN], N, i, stp, cnt;
int cmp(struct entry a, struct entry b) {
  return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0)
                            : (a.nr[0] < b.nr[0] ? 1 : 0);
}
int main(void) {
  string A;
  A = "banana";
  for (N = (int)A.length(), i = 0; i < N; i++)
    P[0][i] = A[i] - 'a';
    
  for (stp = 1, cnt = 1; cnt >> 1 < N; stp++, cnt <<= 1) {
    for (i = 0; i < N; i++) {
      L[i].nr[0] = P[stp - 1][i];
      L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
      L[i].p = i;
    }
    sort(L, L + N, cmp);
    for (i = 0; i < N; i++)
      P[stp][L[i].p] =
          i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1]
              ? P[stp][L[i - 1].p]
              : i;
  }
  for (int i = 0; i < (int)A.length()-1; i++) {
    for (int j = 0; j < (int)A.length()-1; j++) {
      cout << P[i][j] << '\t';
    }
    cout << '\n';
  }

  return 0;
}
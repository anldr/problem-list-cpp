/*
 * Visual Studio Code
 * AcWing839.cpp
 * Create By XuChen
 * 2021/06/20 14:23:23
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int h[N], ph[N], hp[N], idx;
void heap_swap (int a, int b) {
    swap(h[a], h[b]);
    swap(hp[a], hp[b]);
    swap(ph[hp[a]], ph[hp[b]]);
}
void down (int u) {
    int t = u;
    if (u * 2 <= idx && h[u * 2] < h[t]) t = u * 2;
    if (u *2 + 1 <= idx && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        heap_swap (u ,t);
        down(t);
    }
    return ;
}
void up (int u) {
    while ( u / 2 > 0 && h[u] < h[u / 2]) {
        heap_swap (u, u / 2);
        u >>= 1;
    }
    return ;
}
int main () {
    int n;
    int m = 0;
    scanf ("%d", &n);
    idx = 0;
    while (n--) {
        char op[3];
        scanf ("%s", op);
        if (op[0] == 'I') {
            int x;
            scanf ("%d", &x);
            m++;
            h[++idx] = x;
            ph[m] = idx;
            hp[idx] = m;
            up(idx);
        } else if (op[0] == 'C') {
            int k, x;
            scanf ("%d%d", &k, &x);
            h[ph[k]] = x;
            down(ph[k]);
            up (ph[k]);
        } else if (op[0] == 'P') {
            printf ("%d\n", h[1]);
        } else if (strlen (op) == 1) {
            int k;
            scanf ("%d", &k);
            int u = ph[k];
            heap_swap(u, idx);
            idx--;
            up(u);
            down(u);
        } else {
            heap_swap(1, idx);
            idx--;
            down(1);
        }
    }
    
    return 0;
}
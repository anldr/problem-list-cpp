/*
 * Visual Studio Code
 * AcWing143.cpp
 * Create By XuChen
 * 2021/06/18 01:19:00
 */
/*
Trie模板题
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 * 31 + 7;
int son[N][2];
int idx;
void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i--) {
        int u = (x >> i) & 1;
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    return ;
}
int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int u = (x >> i) & 1;
        if (!son[p][!u]) p = son[p][u], res = res * 2;
        else p = son[p][!u], res = res * 2 + 1;
    }
    return res;
}
int main() {
    int n;
    scanf("%d", &n);
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        ans = max (ans, query(x));
        insert(x);
    }
    printf("%d\n", ans);
    return 0;
}
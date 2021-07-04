#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
int son[N][31];
int cnt[N];
int idx;
void insert (char* s) {
    int p = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int u = s[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
    return ;
}
int query (char* s) {
    int p = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int u = s[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main () {
    int n;
    scanf ("%d", &n);
    while (n--) {
        char op[3];
        scanf ("%s", op);
        if (op[0] == 'I') {
            char str[N];
            scanf ("%s", str);
            insert(str);
        } else {
            char str[N];
            scanf ("%s", str);
            printf ("%d\n", query(str));
        }
    }
    return 0;
}
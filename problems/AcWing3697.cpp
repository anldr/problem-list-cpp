/*
 * Visual Studio Code
 * AcWing3697.cpp
 * Create By XuChen
 * 2021/06/19 22:41:33
 */
#include <bits/stdc++.h>

using namespace std;

int main () {
    int T;
    scanf ("%d", &T);
    while (T--) {
        int n;
        int num[5007];
        scanf ("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &num[i]);
        }
        int l = 1;
        int mp[5007];
        memset (mp, -1, sizeof mp);
        while (l <= n) {
            if (mp[num[l]] == -1) {
                mp[num[l]] = l;
            } else {
                if (l - mp[num[l]] >= 2) {
                    printf ("YES\n");
                    l = n + 2;
                }
            }
            l++;
        }
        if (l < n + 2) printf ("NO\n");
    }
    return 0;
}
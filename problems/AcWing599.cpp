/*
 * Visual Studio Code
 * AcWing599.cpp
 * Create By XuChen
 * 2021/06/20 12:16:52
 */
// #include <bits/stdc++.h>

// using namespace std;

// const int N = 1e6 + 7;
// int res[N];
// int h[N], v[N];
// int main () {
//     int n;
//     scanf ("%d", &n);
//     for (int i = 1; i <= n; i++) {
//         scanf ("%d %d", &h[i], &v[i]);
//     }
//     int ans = -1;
//     deque<int> q;
//     for (int i = 1; i <= n; i++) {
//         while (q.size() && h[q.back()] <= h[i]) q.pop_back();
//         if (q.size()) res[q.back()] += v[i];
//         q.push_back(i);
//     }
//     q.clear();
//     for (int i = n; i >= 1; i--) {
//         while (q.size() && h[q.back()] <= h[i]) q.pop_back();
//         if (q.size()) res[q.back()] += v[i], ans = max (ans, res[q.back()]);
//         q.push_back(i);
//     }
//     printf ("%d\n", ans);
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
int res[N];
int h[N], v[N];
int main () {
    int n;
    scanf ("%d", &n);
    int ans = -1;
    deque<int> q, p;
    for (int i = 1; i <= n; i++) {
        scanf ("%d %d", &h[i], &v[i]);
        while (q.size() && h[q.back()] <= h[i]) q.pop_back();
        if (q.size()) res[q.back()] += v[i], ans = max (ans, res[q.back()]);
        q.push_back(i);
        while (p.size() && h[p.back()] <= h[i]) res[i] += v[p.back()], p.pop_back(); 
        p.push_back(i);
    }
    printf ("%d\n", ans);
    return 0;
}
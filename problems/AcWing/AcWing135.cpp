// 单调队列、滑动窗口
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+7;
int s[N];
int main() {
    int n,m;
    scanf("%d%d", &n,&m);
    for (int i = 1; i<= n; i++) {
        scanf("%d", &s[i]);
        s[i] += s[i -1];
    }
    int res = -1;
    deque<int> q;
    q.push_back(s[0]);
    for (int i = 1; i <= n; i++) {
        while (q.size() && i-m > q.front()) q.pop_front();
        
        res = max(res, s[i]-s[q.front()]);
        
        while (q.size() && s[q.back()] >= s[i]) q.pop_back();
        q.push_back(i);
    }
    printf("%d\n", res);
    return 0;
}
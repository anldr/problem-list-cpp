#include <bits/stdc++.h>

using namespace std;

long long f[20];
int main () {
    f[0] = 1, f[1] = 1;
    for (int i = 2; i <= 15; i++) f[i] = f[i - 1] * i;
    int n, a[120];
//康托展开
    scanf ("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        int t = 0;
        for (int j = n; j > i; j--)
            if (a[j] < a[i]) t++;
        ans = (ans + t) * (n - i);
    }
    printf("canotr:%lld\n", ans + 1);
	
//逆康托展开
    long long m;
    scanf("%lld", &m);
    m--;
    for (int i = 1; i <= n; i++) a[i] = i;
    for (int j = 1; j < n; j++) {
        printf("%d", a[m / f[n - j] + 1]);
        for (int i = m / f[n - j] + 1; i <= n - j; i++) a[i] = a[i + 1];
        m %= f[n - j];
    }
    printf("%d\n",a[1]);
    return 0;
}

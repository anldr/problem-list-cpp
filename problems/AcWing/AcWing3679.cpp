// 多种构造方法
#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j == i || j - i == 1) {
                    printf("1 ");
                } else if (j == 1 && i == n) {
                    printf("1 ");
                } else {
                    printf("0 ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
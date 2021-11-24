// Wrong answer
#include <bits/stdc++.h>

using namespace std;

const int R = 1e4+7;
const int C = 100;
char mat[R][C];
char matc[C][R];
int r,c;
int ne[C];
void nexxt(char* p, int len) {
    memset(ne, 0, sizeof ne);
    for (int i = 2, j = 0; i <= len; i++) {
        while (j && p[i] != p[j+1]) j = ne[j];
        if (p[i] == p[j+1]) j++;
        ne[i] = j;
    }
}
long long GCD(long long a, long long b) {
    if (!b) return a;
    return GCD(b, a % b);
}
int main () {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        scanf("%s", mat[i] + 1);
    }

    for (int i = 1; i <= c; i++) {
        for (int j = 0; j < r; j++) {
            matc[i-1][j+1] = mat[j][i];
        }
    }


    // for (int i = 0; i < r; i++) {
    //     for (int j = 1; j <= c; j++) {
    //         cout << mat[i][j];
    //     }
    //     cout << endl;
    // }

    // cout << "cccccccc" << endl;
    // for (int i = 0; i < c; i++) {
    //     for (int j = 1; j <= r; j++) {
    //         cout << matc[i][j];
    //     }
    //     cout << endl;
    // }
    

    int ansR = 1;
    for (int i = 0; i < r; i++) {
        nexxt(mat[i], c);
        int res = c;
        for (int j = 2; j <= c; j++) {
            if (j % (j - ne[j]) == 0) {
                res = min(res, j - ne[j]);
            }
        }
        //cout << "R:" << res << endl;
        // lcm
        ansR = ansR * res / GCD (ansR, res);
    }
    int ansC = 1;
    for (int i = 0; i < c; i++) {
        nexxt(matc[i], r);
        int res = r;
        for (int j = 2; j <= r; j++) {
            if (j % (j - ne[j]) == 0) {
                res = min(res, j - ne[j]);
            }
        }
        //cout << "C:" << res << endl;
        // lcm
        ansC = ansC * res / GCD(ansC, res);
    }
    printf("%d\n", ansR * ansC);
    return 0;
}
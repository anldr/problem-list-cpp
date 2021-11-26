/*
 * Visual Studio Code
 * POJ3126.cpp
 * Create By XuChen
 * 2021/11/26 22:51:12
 */
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX_N = 10007;

bool visit[MAX_N];

bool isPrime(int x) {
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int create(int x, int num, int j) {
    int div = 10;
    for (int i = 1; i < x; i++) {
        div = div * 10;
    }

    int front = num / div;
    int back = num % (div / 10);

    if (x == 1) {
        back = 0;
    }

    return (front * 10 + j) * (div / 10) + back;
}

int BFS(int start, int end) {
    queue<pair<int, int> > que;

    que.push(make_pair(start, 0));
    visit[start] = true;

    while (!que.empty()) {
        pair<int, int> value = que.front();
        que.pop();

        if (value.first == end) {
            return value.second;
        }

        // 改变四位数字，然后判断
        for (int i = 1; i <= 4; i++) {
            for (int j = 0; j <= 9; j++) {
                int x = create(i, value.first, j);
                if (x >= 1000 && x <= 9999 && !visit[x] && isPrime(x)) {

                    if (x == end) {
                        return value.second + 1;
                    }

                    visit[x] = true;
                    que.push(make_pair(x, value.second + 1));
                }
            }
        }
    }

    return -1;
}
int main () {
    int T;
    
    scanf("%d", &T);

    while (T--) {
        int start;
        int end;
        scanf("%d%d", &start, &end);

        memset(visit, false, sizeof(visit));

        int result = BFS(start, end);
        if (result == -1) {
            printf("Impossible\n");
        } else {
            printf("%d\n", result);
        }
    }

    return 0;
}
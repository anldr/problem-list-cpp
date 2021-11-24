#include <cstdio>
#include <queue>

using namespace std;

long long BFS(int n) {
    queue<long long> que;

    que.push(1L);

    while (!que.empty()) {
        long long num = que.front();
        que.pop();

        if (num % n == 0) {
            return num;
        }

        que.push(num * 10L);
        que.push(num * 10 + 1L);
    }
    return 0;
}
int main() {
    int n;
    while (~scanf("%d", &n)) {
        if (n == 0) {
             break;
        }

        printf("%lld\n", BFS(n));
    }
    return 0;
}
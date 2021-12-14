/*
 * Visual Studio Code
 * cantorTest.cpp
 * Create By XuChen
 * 2021/12/14 22:31:33
 */
#include <bits/stdc++.h>

using namespace std;

int n = 9;
// int status[] = {2, 3, 4, 1, 5, 0, 7, 6, 8};
int status[] = {0, 1, 2, 3, 4, 5, 6, 8, 7};

int getCantor() {
    int result = 0;
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = n - 1; j > i; j--) {
            if (status[j] < status[i]) {
                t++;
            }
        }
        result += (result + t) * (n - i - 1);
    }
    return result;
}
int main () {
    printf("%d\n", getCantor());
    return 0;
}
#include <iostream>
#include <algorithm>

#define MAX_N 200

using namespace std;

int n, m;
int grid[MAX_N][MAX_N];

int dir[4][2] = {
    {-1, 0},// 상
    {0, 1}, // 우
    {1, 0}, // 하
    {0, -1} // 좌
};

int sumBlock1(int y, int x) {
    int max_sum = 0;

    for (int i = 0; i < 4; i++) {
        int sum = grid[y][x];

        int ny = y + dir[i][0];
        int nx = x + dir[i][1];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        
        sum += grid[ny][nx];

        if (i + 1 == 4) {
            ny = y + dir[0][0];
            nx = x + dir[0][1];
        }
        else {
            ny = y + dir[i + 1][0];
            nx = x + dir[i + 1][1];
        }
        
        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

        sum += grid[ny][nx];

        max_sum = max(sum, max_sum);
    }


    return max_sum;
}

int sumBlock2(int y, int x) {
    int max_sum = 0;

    for (int i = 0; i < 2; i++) {
        int sum = grid[y][x];

        int ny = y + dir[i][0];
        int nx = x + dir[i][1];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        sum += grid[ny][nx];

        ny = y + dir[i + 2][0];
        nx = x + dir[i + 2][1];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        sum += grid[ny][nx];

        max_sum = max(sum, max_sum);

    }


    return max_sum;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    // 1) block 1에서 최댓값 찾기

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            int sum = sumBlock1(y, x);
            result = max(sum, result);
        }
    }
    
    // 2) block 2에서 최댓값 찾기
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            int sum = sumBlock2(y, x);
            result = max(sum, result);
        }
    }

    cout << result;

    return 0;
}
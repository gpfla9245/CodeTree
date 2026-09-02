#include <iostream>
#define MAX_N 100

using namespace std;


int n, m;
int grid[MAX_N][MAX_N];
int seq[MAX_N];

int isHappyNum() {
    int count = 1;
    int max_count = 1;
    
    for (int i = 1; i < n; i++) {
        if (seq[i - 1] == seq[i]) {
            count++;
        }
        else {
            count = 1;
        }
        max_count = max(count, max_count);
    }
    return max_count >= m;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int result = 0;
    
    // 가로
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            seq[j] = grid[i][j];
        }

        if (isHappyNum()) {
            result++;
        }
    }

    // 세로
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            seq[i] = grid[i][j];
        }

        if (isHappyNum()) {
            result++;
        }
    }
    cout << result;


    return 0;
}
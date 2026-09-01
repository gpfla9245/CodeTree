#include <iostream>
#include <algorithm>

using namespace std;

int N;
int grid[20][20];


int main() {
    cin >> N;

    int presum[21][21] = { 0, };

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }


    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            presum[i][j] = grid[i - 1][j - 1] + presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1];
        }

    }



    int max_sum = 0;
    for (int i = 3; i <= N; i++) {
        for (int j = 3; j <= N; j++) {
            int sum = presum[i][j] - presum[i][j - 3] - presum[i - 3][j] + presum[i - 3][j - 3];
            max_sum = max(sum, max_sum);
        }
    }
    cout << max_sum;

    return 0;
}

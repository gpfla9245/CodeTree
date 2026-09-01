#include <iostream>
#define MAX_N 100

using namespace std;


int n, m;
int grid[MAX_N][MAX_N];


//int isHappyNum(int arr[]) {
//    int result = 0;
//    int counting[101] = { 0, };
//
//    for (int i = 0; i < n; i++) {
//        counting[arr[i]] += 1;
//        if (counting[arr[i]] == m)
//            return 1;
//    }
//    return 0;
//}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        int DAT[101] = { 0, };
        int pred = 0;

        for (int j = 0; j < n; j++) {
            int num = grid[i][j];
            if (num != pred) {
                DAT[num] = 1;
                pred = num;
            }
            else {
                DAT[num]++;
                pred = num;
            }
            if (DAT[num] >= m) {
                count++;
                break;
            }

        }

    }

    for (int i = 0; i < n; i++) {
        int DAT[101] = { 0, };
        int pred = 0;

        for (int j = 0; j < n; j++) {
            int num = grid[j][i];
            if (num != pred) {
                DAT[num] = 1;
                pred = num;
            }
            else {
                DAT[num]++;
                pred = num;
            }
            if (DAT[num] >= m) {
                count++;
                break;
            }

        }

    }

    cout << count;


    return 0;
}
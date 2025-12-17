#include<iostream>
#include<vector>
using namespace std;
bool IsNegZero(vector<int>arr) {
    int tag = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            tag = 1;
            break;
        }
        if (arr[i] == 0) {
            tag = 0;
            break;
        }
    }
    if (tag == 0) {
        cout << 0 << " " << 0 << " " << 0;
        return true;
    }
    else if (tag == -1) {
        cout << 0 << " " << arr[0] << " " << arr[arr.size() - 1];
        return true;
    }
    return false;
}

int main() {
    int N = 0;
    cin >> N;
    vector<int>arr;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        arr.push_back(x);
    }
    if (!IsNegZero(arr)) {
        int Sum = 0, Start = arr[0], End = arr[0],
            MaxSum = 0, tmpStart = arr[0];
        for (int i = 0; i < N; i++) {
            Sum += arr[i];
            if (Sum < 0) {
                Sum = 0;
                tmpStart = arr[i + 1];
            }
            if (MaxSum < Sum) {
                End = arr[i];
                MaxSum = Sum;
                Start = tmpStart;
            }
        }
        cout << MaxSum << " " << Start << " " << End;
    }
    return 0;
}
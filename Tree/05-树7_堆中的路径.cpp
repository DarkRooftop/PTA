#include<iostream>
#include<vector>
#include <climits>
using namespace std;

struct HeapNode {
    vector<int>Data;
    int Size;
};
HeapNode* CreatHeap() {
    HeapNode* H = new HeapNode;
    H->Data.push_back(INT_MIN);
    H->Size = 0;
    return H;
}
void InsertHeap(int x, HeapNode* H) {
    H->Data.push_back(0);
    int i = ++(H->Size);
    while (x < H->Data[i / 2]) {
        H->Data[i] = H->Data[i / 2];
        i /= 2;
    }
    H->Data[i] = x;
}
void FindRoad(int x, HeapNode* H) {
    for (int i = x; i >= 1; i /= 2) {
        cout << H->Data[i];
        if (i > 1)
            cout << " ";
    }
    return;
}
int main() {
    int N; cin >> N;
    int M; cin >> M;
    HeapNode* MinHeap = CreatHeap();
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        InsertHeap(x, MinHeap);
    }
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        FindRoad(x, MinHeap);
        if (i != M - 1)cout << endl;
    }
    return 0;
}

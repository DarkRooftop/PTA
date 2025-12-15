#include<iostream>
#include<vector>

#define ElementType int
#define MaxSize 50
using namespace std;

void CreatArray(vector<ElementType>& array) {
    int N;
    cin >> N;
    ElementType x;
    while (N > 0) {
        cin >> x;
        array.push_back(x);
        N--;
    }

}
void QuickSort(vector<ElementType>& array, int L, int R) {
    if (R - L < 1)
        return;
    int SL = L, SR = R;
    int key = array[L];
    while (L <= R) {
        while (L < key)
            L++;
        while (R >= key)
            R--;
        swap(L, R);
    }
    L = key;
    QuickSort(array, SL, L - 1);
    QuickSort(array, R, SR);
}
void QuickSort(vector<ElementType>& array) {
    QuickSort(array, 0, array.size() - 1);
}

void PrintArray(vector<ElementType>& array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i];
        if (i < array.size() - 1)
            cout << " ";
    }
}
int main() {
    vector<int>arr;
    CreatArray(arr);
    QuickSort(arr);
    PrintArray(arr);
    return 0;
}
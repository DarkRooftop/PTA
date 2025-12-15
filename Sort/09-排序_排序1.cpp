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
//三路取中原来这么强！
int MiddleOfThree(vector<ElementType>& array, int L, int R) {
    int mid = L + (R - L) / 2;
    if (array[L] > array[R])
        swap(array[L], array[R]);
    if (array[mid] > array[R])
        swap(array[mid], array[R]);
    if (array[mid] > array[L])
        swap(array[mid], array[L]);
    return L;
}
//初始版本
void QuickSort(vector<ElementType>& array, int L, int R) {
    if (R <= L)
        return;
    int SL = L, SR = R;
    int pivit = MiddleOfThree(array, L, R);
    int key = array[pivit];
    swap(array[pivit], array[L]);
    while (L < R) {
        while (L < R && array[R] >= key) R--;
        if (L < R) {
            swap(array[L], array[R]);
            L++;
        }
        while (L < R && array[L] < key) L++;
        if (L < R) {
            swap(array[L], array[R]);
            R--;
        }
    }
    array[L] = key;
    QuickSort(array, SL, L - 1);
    //L==R这里不用划分了
    QuickSort(array, R + 1, SR);
}
//Hoare划分版本
/*void QuickSort(vector<ElementType>& array, int L, int R) {
    if (R - L + 1 < 1)
        return;
    int i = L - 1, j = R + 1;
    ElementType key = array[L];
    while (true) {
        do {
            i++;
        }while(array[i] < key);
        do {
            j--;
        } while (array[j] > key);
        if (i >= j)break;
        swap(array[i], array[j]);
    }
    QuickSort(array, L, j);
    QuickSort(array, j + 1, R);
}*/
//Lomuto划分版本
/*void QuickSort(vector<ElementType>& array, int L, int R) {
    if (R - L + 1 < 1)
        return;
    ElementType key = array[R];
    int i = L - 1;
    for (int j = L; j <= R - 1; j++) {
        if (array[j] < key) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[R]);
    QuickSort(array, L, i);
    QuickSort(array, i + 2, R);
}*/
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
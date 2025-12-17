#include<iostream>
#include<vector>
using namespace std;
struct ele {
    int val;
    int tag;
};
void Find(vector<ele>& hash, int x, int TSize) {
    int H = x % TSize;
    int pos = H;
    if (hash[H].tag == 0) {
        hash[H].val = x; hash[H].tag = 1;
        cout << pos;
        return;
    }
    for (int i = 1; i <= TSize / 2; i++) {
        pos += i * i;
        if (pos >= TSize) {
            pos %= TSize;
        }
        if (hash[pos].tag == 0) {
            hash[pos].val = x; hash[pos].tag = 1;
            cout << pos;
            return;
        }
        pos = H;
    }
    cout << "-";
    return;
}
int FindPrime(int n) {
    if (n <= 2) return 2;
    for (int i = n;; i++) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            return i;
    }
}
int main() {
    vector<ele>hash;
    int TSize = 0;
    cin >> TSize;
    //TSize->Prime
    TSize = FindPrime(TSize);
    for (int i = 0; i < TSize; i++) {
        ele tmp;
        tmp.val = 0; tmp.tag = 0;
        hash.push_back(tmp);
    }
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        Find(hash, x, TSize);
        if (i < N - 1)
            cout << " ";
    }

    return 0;
}


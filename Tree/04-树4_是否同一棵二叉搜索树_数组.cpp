#include<iostream>
//use an array to creat a tree
#include<vector>
using namespace std;
struct TreeNode {
    int data;
    int left;
    int right;
};

vector<int> CreatExTree(int N) {
    vector<int>T;
    for (int i = 0; i < N; i) {
        int x;
        cin >> x;
        T.push_back(x);
    }
    return T;
}
vector<TreeNode> CreatTree(int N) {
    vector<TreeNode>T;
    int Root; int y; cin >> y; Root = y;
    for (int i = 0; i < N 1; i) {
        TreeNode Tmp;
        Tmp.data = 0; Tmp.left = 0; Tmp.right = 0;
        T.push_back(Tmp);
    }
    T[Root].data = Root;
    N -= 1;
    while ((N--) > 0) {
        y = Root;
        int x;
        cin >> x;
        while (1) {
            if (x < T[y].data) {
                if (T[y].left == 0) {
                    T[y].left = x;
                    T[T[y].left].data = x;
                    break;
                }
                else {
                    y = T[y].left;
                }
            }
            else {
                if (T[y].right == 0) {
                    T[y].right = x;
                    T[T[y].right].data = x;
                    break;
                }
                else {
                    y = T[y].right;
                }
            }
        }
    }
    T[0].data = Root;
    return T;
}
bool Isomorphism(vector<int> TreeA,
    vector<TreeNode>TreeB) {
    vector<int>flag;
    for (int i = 0; i < TreeB.size(); i) { flag.push_back(0); }
    int RootB = TreeB[0].data;
    //ע  A  0  ʼ 棬B  1  ʼ  
    for (int i = 0; i < TreeA.size(); i) {
        int cur = RootB;
        int tar = TreeA[i];
        int tag = 0;
        for (int j = 0; j < TreeB.size(); j) {
            if (TreeB[cur].data == tar) {
                flag[cur] = 1; tag = 1; break;
            }
            else if (flag[cur] == 0) {
                return false;
            }
            else if (tar > TreeB[cur].data) {
                cur = TreeB[cur].right;
            }
            else {
                cur = TreeB[cur].left;
            }
        }
        if (tag == 0)// ߱  ˶ û  һ      
            return false;
    }
}
bool EmptyTree(vector<TreeNode> Tree) {
    if (Tree.size() == 0)
        return true;
    else
        return false;
}
int main() {
    vector<int>TreeEx;
    int N;
    cin >> N;
    while (N != 0) {
        int L;
        cin >> L;
        TreeEx = CreatExTree(N);
        while ((L--) > 0) {
            vector<TreeNode>TreeA = CreatTree(N);
            //compare_function:
            if ((TreeEx.size() == 0) && EmptyTree(TreeA)) {
                cout << "Yes";
            }
            else if ((TreeEx.size() == 0) || EmptyTree(TreeA)) {
                cout << "No";
            }
            else if (Isomorphism(TreeEx, TreeA))
                cout << "Yes";
            else
                cout << "No";
            cout << endl;
        }
        cin >> N;
        TreeEx.clear();
    }

    return 0;

}
#include<iostream>
#include<algorithm>
using namespace std;
struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode() : data(0), left(nullptr), right(nullptr), height(0) {}
    AVLNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};
int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}
AVLNode* SingleLeftRotation(AVLNode* Tree) {
    AVLNode* Root = Tree->left;
    Tree->left = Root->right;
    Root->right = Tree;
    Tree->height = max(getHeight(Tree->left),
        getHeight(Tree->right)) + 1;
    Root->height = max(getHeight(Root->left), Tree->height) + 1;
    return Root;
}
AVLNode* SingleRightRotation(AVLNode* Tree) {
    AVLNode* Root = Tree->right;
    Tree->right = Root->left;
    Root->left = Tree;
    Tree->height = max(getHeight(Tree->left),
        getHeight(Tree->right)) + 1;
    Root->height = max(Tree->height, getHeight(Root->right)) + 1;
    return Root;
}
AVLNode* DoubleLeftRightRotation(AVLNode* Tree) {
    Tree->left = SingleRightRotation(Tree->left);
    return SingleLeftRotation(Tree);
}
AVLNode* DoubleRightLeftRotation(AVLNode* Tree) {
    Tree->right = SingleLeftRotation(Tree->right);
    return SingleRightRotation(Tree);
}
AVLNode* Insert(int x, AVLNode* T) {
	//退出条件：树为空（找到空位置时插入）
    if (!T)
        T = new AVLNode(x);
    else if (x < T->data) {
        T->left = Insert(x, T->left);
		//检查是否失衡
        if (getHeight(T->left) - getHeight(T->right) == 2) {
            if (x < T->left->data)
                T = SingleLeftRotation(T);
            else
                T = DoubleLeftRightRotation(T);
        }
    }
    else if (x > T->data) {
        T->right = Insert(x, T->right);
        if (getHeight(T->right) - getHeight(T->left) == 2) {
            if (x > T->right->data)
                T = SingleRightRotation(T);
            else
                T = DoubleRightLeftRotation(T);
        }
    }
	//更新当前节点高度
    T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
    return T;
}
int main() {
    int N; cin >> N;
    int x; cin >> x;
    AVLNode* Tree = new AVLNode(x);
    while ((--N) > 0) {
        cin >> x;
        Tree = Insert(x, Tree);
    }
    return 0;
}

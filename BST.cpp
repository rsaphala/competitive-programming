#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#define endl '\n'
#define null NULL

using namespace std;
//rebase
struct node {
    int key;
    struct node *left,*right;
};

struct node *newNode(int key){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->left = null;
    temp->right = null;
    temp->key = key;
    return temp;
}

struct node *insert(struct node *node,int key){
    if (node == null) return newNode(key);
    if (key > node->key) node->right = insert(node->right,key);
    else if (key < node->key) node->left = insert(node->left,key);
    return node;
}

void printInorder(struct node*node){
    if (node != null){
        printInorder(node->left);
        cout << node->key << endl;
        printInorder(node->right);
    }
}



int main(){
    struct node *root = null;
    root = insert(root,50);
    insert(root,20);
    insert(root,10);
    insert(root,30);
    printInorder(root);
}
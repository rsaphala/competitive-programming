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

struct Node {
    int key;
    struct Node * next;
};
struct Node * head = NULL;
struct Node * ptr;

void addNode (int key){
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp ->key = key;
    temp->next = null;
    if (!head) {
        head = temp;
        ptr = head;
    }
    else {
        ptr->next = temp;
        ptr = temp;
    } 
}

void popNode(int key){
    Node * temp = head;
    Node * prev = NULL;
    while (temp){
        if (temp->key == key){
            if (!prev) {
                head = temp->next;
                free(temp);
            }
            else if (temp->next == NULL){
                prev->next = NULL;
                free(temp);
            } else {
                prev->next = temp->next;
                free(temp);
            }
        }
        prev = temp;
        temp = temp->next;
    }
}

void printNode(struct Node *root){
    while (root != NULL){
        cout << root->key << " ";
        root = root->next;
    }
    cout <<endl;
}

void reverse(){
    Node * prev = NULL;
    Node * curr = head;
    Node * next;

    while (curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void reverseDouble(){

    Node *temp = NULL;
    Node *curr = head;
    while(curr){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        temp = curr;
        curr = curr->prev;
    }
    head = temp;
}

int main(){
    for (int i = 0;i<20;i++){
        addNode(i);
    }
    popNode(0);
    popNode(7);
    popNode(18);
    popNode(19);
    printNode(head);
    reverse();
    printNode(head);
}

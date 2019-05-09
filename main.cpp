#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    long long data;
    Node* left;
    Node* right;
};
Node *newNode(long long key)
{
    Node* temp = new Node();
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* add(Node* node, long long key)
{
    if(node == NULL) return newNode(key);
    
    if(key < node->data) node->left = add(node->left, key);
    else if(key > node->data) node->right = add(node->right, key);
    return node;
}
void print(Node* root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        print(root->left);
        print(root->right);
    }
}
int main() {
    int N;
    cin >> N;
    Node* root = NULL;
    string name;
    long long key;
    cin >> name >> key;
    root = add(root, key);
    for(int i = 0; i < N-1; ++i)
    {
        cin >> name;
        if(name.compare("add") == 0)
        {   
            cin >> key;
            add(root, key);
        }
        if(name.compare("print") == 0) print(root);
    }
    //print(root);
    return 0;
}

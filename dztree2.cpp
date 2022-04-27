#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef struct tree
{
    int key;
    struct tree* left;
    struct tree* right;

} node;

node* create(int key)
{
    node* root;
    node* tmp = new node();
    tmp->key = key;
    tmp->left = tmp->right = NULL;
    root = tmp;
    return root;
}


node* add(node* root, int key)
{
    node* root2 = root, * root3 = NULL;
    node* tmp = new node();

    tmp->key = key;
    while (root2 != NULL)
    {
        root3 = root2;
        if (key < root2->key)
            root2 = root2->left;
        else
            root2 = root2->right;
    }
    tmp->left = NULL;
    tmp->right = NULL;
    if (key < root3->key) root3->left = tmp;
    else root3->right = tmp;
    return root;
}
void shirina(node* root)
{
    cout << "Обход дерева в ширину:";

    queue <node*> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        node* f = q.front();
        q.pop();

        if (f == NULL)
        {
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << f->key << " ";
            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }
    }
}
void deep(node* t)
{
    cout << "\nОбход дерева в длинну:";
    stack<node*> s;
    s.push(NULL);
    node* tt = t;
    do {
        if (tt != NULL) {
            s.push(tt);
            cout << tt->key << " ";
            tt = tt->left;
        }
        else {
            if (s.top() == NULL) break;
            tt = s.top();
            s.pop();
            tt = tt->right;
        }
    } while (true);
}



int main() {
    node* root1;
    root1 = create(4);
    add(root1, 2);
    add(root1, 236);
    add(root1, 2888);
    add(root1, 0);
    add(root1, 20);
    add(root1, 235);
    shirina(root1);
    deep(root1);
    return 0;
}

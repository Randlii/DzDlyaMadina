#include <iostream>
#include <fstream>
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



int main() {
    fstream F;
    node* root1;
    int kol = 0, fir = 0, tr = 0;
    F.open("txt.txt");
    F >> kol;
    F >> fir;
    root1 = create(fir);
    for (int i = 1; i < kol; i++)
    {
        F >> tr;
        add(root1, tr);
    }
    F.close();
    shirina(root1);
    return 0;
}

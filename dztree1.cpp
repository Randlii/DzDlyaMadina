#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
typedef struct tree
{
int key;
struct tree *left;
struct tree *right;

} node;

node *create(node *root, int key)
{
node *tmp = new node();
tmp -> key = key;
tmp -> left = tmp -> right = NULL;
root = tmp;
return root;
}


node *add(node *root, int key)
{
node *root2 = root, *root3 = NULL;
node *tmp = new node();

tmp -> key = key;
while (root2 != NULL)
{
root3 = root2;
if (key < root2 -> key)
root2 = root2 -> left;
else
root2 = root2 -> right;
}
tmp -> left = NULL;
tmp -> right = NULL;
if (key < root3 -> key) root3 -> left = tmp;
else root3 -> right = tmp;
return root;
}
void korleftright(node* root) 
{
if (root) {
std::cout << root->key << " ";
korleftright(root->left);
korleftright(root->right);
}
}


void leftkorenright(node* root)
{
if (root) {
leftkorenright(root->left);
std::cout << root->key << " ";
leftkorenright(root->right);
}
}

void leftrightkoren(node* root)
{
if (root) {
leftrightkoren(root->left);
leftrightkoren(root->right);
std::cout << root->key << " ";
}
}

int main(){
node * root ;
root= create(root,4);
add(root,2);
add(root,231);
add(root,2888);
add(root,0);
add(root,20);
add(root,231);
std::cout << "Корень-левое-правое\n";
korleftright(root);
std::cout << "\nлевое-правое-корень\n";
leftrightkoren(root);
std::cout << "\nлевое-корень-правое\n";
leftkorenright( root);

return 0;
}

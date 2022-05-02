#include <iostream>

using namespace std;

typedef struct TNode *PNode;
struct TNode {    
    string data;
    PNode left;
    PNode right;
  };

int Priority ( char op )
{
  switch ( op ) {
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    }
  return 100;  
}

int LastOp ( string s )
{
  int i, minPrt, res;
  minPrt = 50;
  res = -1;
  for ( i=0; i<s.size(); i++ )
    if ( Priority(s[i]) <= minPrt ) {
      minPrt = Priority(s[i]);
      res = i;
      }
  return res;
}

PNode MTree ( string s )
{
  int k;
  PNode Tree; 
  Tree = new struct TNode;
  k = LastOp ( s );
  if ( k == -1 ) {
    Tree->data = s;
    Tree->left = NULL;
    Tree->right = NULL;
    }
  else {
    Tree->data = s.substr ( k, 1);    
    Tree->left = MTree ( s.substr(0,k)  );
    Tree->right = MTree ( s.substr(k+1) );
}
  return Tree;
}

int Calc ( PNode Tree )
{
  int n1, n2, res;
  if ( Tree->left == NULL )
    res = atoi(Tree->data.c_str());
  else {
    n1 = Calc ( Tree->left );
    n2 = Calc ( Tree->right );
    switch ( Tree->data[0] ) {
      case '+': res = n1 + n2; break;
      case '-': res = n1 - n2; break;
      case '*': res = n1 * n2; break;
      case '/': res = n1 / n2; break;
      default: res = 99999;
    }    
  }
  return res;
}
void treeprint(PNode tree) {
  if (tree!=NULL) {
    cout << tree->data[0]; 
    treeprint(tree->left); 
    treeprint(tree->right); 
  }
}
void treeprintpost(PNode tree) {
  if (tree!=NULL) { 
    treeprintpost(tree->left); 
    treeprintpost(tree->right); 
    cout << tree->data[0];
  }
}
int main()
{
  PNode Tree1;
  string s;   
  cout << "Введите выражение: \n";
  cin >> s;
  Tree1 = MTree ( s );
  treeprint(Tree1);
  cout << "\n";
  treeprintpost(Tree1);
  cout << "\n" << "отв: " << Calc(Tree1); 
}v

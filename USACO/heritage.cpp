/*
ID: lyronct1
LANG: C++11
TASK: heritage
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <set>
#include <unordered_set>
#include <cmath>
#include <map>
#include <unordered_map>
#include <functional>
#define ull unsigned long long
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp
// ./a.out

struct node{
  char key;
  node *left, *right;
  node (char c) {key = c;}
};
node * generate(string in, string pre){
  if(pre.length()==0){
    node * n = new node(NULL);
    n->left = NULL;
    n->right = NULL;
    return n;
  }

  int pos;
  for(pos=0; pos<in.length() && in[pos] != pre[0]; pos++);

  node * n = new node(pre[0]);
  n->left = generate(in.substr(0, pos), pre.substr(1, pos));
  n->right = generate(in.substr(pos+1), pre.substr(pos+1));
  return n;
}
void printTree(node * root){
  if(root->left != NULL)
    printTree(root->left);
  if(root->right != NULL)
    printTree(root->right);
  if(root->key != NULL)
    printf("%c", root->key);
}
int main(){
  // freopen("in.txt", "r", stdin);
  freopen("heritage.in", "r", stdin);
  freopen("heritage.out", "w", stdout);

  string pre, in;
  cin >> in >> pre;
  node * root = generate(in, pre);
  printTree(root);
  printf("\n");
}
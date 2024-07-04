#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//二叉树节点结构
typedef struct BinaryTreeNode
{
  int val;      //节点值
  int height;   //节点高度
  BinaryTreeNode*  right; //右子节点
  BinaryTreeNode*  left;  //左子节点
}BinaryTreeNode;

//节点的构造函数
BinaryTreeNode* newtreenode(int val){
  BinaryTreeNode* node;
  node = (BinaryTreeNode*) malloc(sizeof(BinaryTreeNode));
  node->val = val;
  node->left = NULL;
  node->right = NULL;
  node->height = 0;
  return node;
}

//层序遍历二叉树：广度优先搜索BFS
//层序遍历的时间复杂度和空间复杂度都是O(n)
//借助队列queue
void levelOrder(BinaryTreeNode* root){
    queue<BinaryTreeNode*> que;
    que.push(root);
    //动态数组，用于存储节点值
    //vector<int> reasult;
    while (!que.empty())
    {
      BinaryTreeNode* node = que.front();  
      que.pop();
      cout<<node->val<<" ";
      if(node->left!= nullptr){
        //cout<<node->left->val<<" ";
        que.push(node->left);
      }
      if(node->right!=nullptr){
        //cout<<node->right->val<<" ";
        que.push(node->right);
      }
    }
    cout<<endl;
    return ;   
}

//前序遍历、中序遍历、后续遍历都属于深度优先遍历depth-first traversal
//前序遍历顺序：根节点->左子树->右子树
void preOrder(BinaryTreeNode* root){
  if(root == nullptr) return;
  cout<<root->val<<",";
  preOrder(root->left);
  preOrder(root->right);
}

//中序遍历: 左子树->根节点->右子树
void inOrder(BinaryTreeNode* root){
  if(root == nullptr) return ;

  inOrder(root->left);
  cout<<root->val<<",";
  inOrder(root->right);
}
//后续遍历:右子树->左子树->根节点
void postOrder(BinaryTreeNode* root){
  if(root == nullptr) return;
  postOrder(root->right);
  postOrder(root->left);
  cout<<root->val<<",";

}
int main(){
  //初始化二叉树
  BinaryTreeNode* n1 = newtreenode(34);
  BinaryTreeNode* n2 = newtreenode(56);
  BinaryTreeNode* n3 = newtreenode(76);
  BinaryTreeNode* n4 = newtreenode(99);
  BinaryTreeNode* n5 = newtreenode(233);
  BinaryTreeNode* n6 = newtreenode(66);

  //设置节点间关系
  n1->left = n2;
  n2->left = n6;
  n1->right = n3;
  n3->right = n4;
  n3->left = n5;

  //层序遍历
  cout<<"层序遍历："<<endl;
  levelOrder(n1);

  cout<<"前序遍历:"<<endl;
  preOrder(n1);
  cout<<endl;

  cout<<"中序遍历: "<<endl;
  inOrder(n1);
  cout<<endl;

  cout<<"后续遍历: "<<endl;
  postOrder(n1);

}
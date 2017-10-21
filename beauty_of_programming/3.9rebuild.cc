#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int v;
};

int findIndex(vector<int> &in,int key)
{
    for(int i=0;i<in.size();i++)
    {
        if(in[i] == key)
        {
            return i;
        }
    }
    return -1;
}

//非递归实现
void rebuild(vector<int> &pre,vector<int> &in,Node ** treeRoot)
{
    if(pre.size() != in.size())
    {
        return ;
    }
    int len =pre.size();

    int curInIn=0;
    int topInIN=0;
    int key;
    stack<Node *> rootNode;

    *treeRoot = new Node{NULL,NULL,pre[0]};
    rootNode.push(*treeRoot);

    int topKey;
    for(int i =1 ;i<len;i++)
    {
        key=pre[i];
        curInIn = findIndex(in,key);
        topInIN = findIndex(in,pre[i]);

        key = rootNode.top()->v;
        if(curInIn < topInIN)
        {
            rootNode.top()->left = new Node{NULL,NULL,key};
            rootNode.push(rootNode.top()->left);
        }else if(curInIn > i)
        {
            while(rootNode.size()>1)
            {
                rootNode.pop();
            }
            rootNode.top()->right=new Node{NULL,NULL,key};
            rootNode.pop();
        }
    }
}


int main()
{
    vector<int> pre{1,2,3,4,5,6};
    vector<int> in{3,2,1,5,4,6};
    Node *tree;

    rebuild(pre,in,&tree);

}
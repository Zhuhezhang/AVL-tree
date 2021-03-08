#ifndef AVLTREE_HEAD_H_
#define AVLTREE_HEAD_H_
#include <iostream>
#include <iomanip>
using namespace std;


//AVL树结点
template <class T>
struct AVLTreeNode
{
    T key;                        //关键字
    int Height;                   //高度
    AVLTreeNode *left;            //左孩子
    AVLTreeNode *right;           //右孩子
    AVLTreeNode(T value,AVLTreeNode *l,AVLTreeNode *r) : key(value),Height(0),left(l),right(r){}
};


//AVL树类
template <class T>
class AVLTree
{
 public:
    AVLTree(); 
    ~AVLTree(); 
    int Height();                 //树的高度
    int Max(int a, int b);        //求a,b中的最大值
    void PreOrder();              //前序遍历
    void InOrder();               //中序遍历
    void PostOrder();             //后序遍历
    AVLTreeNode<T>* Search(T key);//查找AVL树中值为key的结点
    T MinNode();                  //查找最小结点
    T MaxNode();                  //查找最大结点
    void Insert(T key);           //将值为key的结点插入到AVL树中
    void Remove(T key);           //删除值为key的结点
    void Release();               //释放树占用的空间
    void Display();               //凹入法输出显示AVL树
private:
	AVLTreeNode<T> *root;                                  //根结点
    int Height(AVLTreeNode<T>* tree);                      //求树的高度
    void PreOrder(AVLTreeNode<T>* tree) const;             //前序遍历
    void InOrder(AVLTreeNode<T>* tree) const;              //中序遍历
    void PostOrder(AVLTreeNode<T>* tree) const;            //后序遍历
    AVLTreeNode<T>* Search(AVLTreeNode<T>* x,T key) const; //查找AVL树中值为key的结点
    AVLTreeNode<T>* MinNode(AVLTreeNode<T>* tree);         //查找最小结点
    AVLTreeNode<T>* MaxNode(AVLTreeNode<T>* tree);         //查找最大结点
    AVLTreeNode<T>* RotateR(AVLTreeNode<T>* tree);         //LL型：右单旋转
    AVLTreeNode<T>* RotateL(AVLTreeNode<T>* tree);         //RR型：左单旋转
    AVLTreeNode<T>* RotateLR(AVLTreeNode<T>* tree);        //LR型：左右双旋转
    AVLTreeNode<T>* RotateRL(AVLTreeNode<T>* tree);        //RL型：右左双旋转
    AVLTreeNode<T>* Insert(AVLTreeNode<T>* &tree,T key);   //将值为key的结点插入到AVL树中
    AVLTreeNode<T>* Remove(AVLTreeNode<T>* &tree,AVLTreeNode<T>* key);//删除值为key的结点
    void Release(AVLTreeNode<T>* &tree);                   //释放树占用的空间
    void Display(AVLTreeNode<T>* tree,int n);              //凹入法输出显示AVL树，n为打印层数 
};



//构造函数
template <class T>
AVLTree<T>::AVLTree():root(nullptr){}


//析构函数
template <class T>
AVLTree<T>::~AVLTree()
{
    Release(root);
}


//求树的高度
template <class T>
int AVLTree<T>::Height(AVLTreeNode<T>* tree) 
{
    if(tree != nullptr)return tree->Height;
    return 0;
}

template <class T>
int AVLTree<T>::Height() 
{
    return Height(root);
}


//比较两个值的大小
template <class T>
int AVLTree<T>::Max(int a,int b)
{
    return a>b ? a : b;
}


//前序遍历
template <class T>
void AVLTree<T>::PreOrder(AVLTreeNode<T>* tree) const
{
    if(tree != nullptr)
    {
        cout<<tree->key<<" ";
        PreOrder(tree->left);
        PreOrder(tree->right);
    }
}

template <class T>
void AVLTree<T>::PreOrder() 
{
    PreOrder(root);
}


//中序遍历
template <class T>
void AVLTree<T>::InOrder(AVLTreeNode<T>* tree) const
{
    if(tree != nullptr)
    {
        InOrder(tree->left);
        cout<<tree->key<<" ";
        InOrder(tree->right);
    }
}

template <class T>
void AVLTree<T>::InOrder() 
{
    InOrder(root);
}

 
//后序遍历
template <class T>
void AVLTree<T>::PostOrder(AVLTreeNode<T>* tree) const
{
    if(tree != nullptr)
    {
        PostOrder(tree->left);
        PostOrder(tree->right);
        cout<<tree->key<<" ";
    }
}
 
template <class T>
void AVLTree<T>::PostOrder() 
{
    PostOrder(root);
}


//查找AVL树中值为key的结点 
template <class T>
AVLTreeNode<T>* AVLTree<T>::Search(AVLTreeNode<T>* x,T key) const
{
    if(x==nullptr || x->key==key)
        return x;

    if(key < x->key)
        return Search(x->left,key);
    else
        return Search(x->right,key);
}

template <class T>
AVLTreeNode<T>* AVLTree<T>::Search(T key) 
{
    return Search(root,key);
}


//查找最小结点
template <class T>
AVLTreeNode<T>* AVLTree<T>::MinNode(AVLTreeNode<T>* tree)
{
    if(tree == nullptr)
        return nullptr;
    while(tree->left != nullptr)
        tree = tree->left;
    return tree;
}
 
template <class T>
T AVLTree<T>::MinNode()
{
    AVLTreeNode<T> *p = MinNode(root);
    if(p != nullptr)
        return p->key;
}


//查找最大结点
template <class T>
AVLTreeNode<T>* AVLTree<T>::MaxNode(AVLTreeNode<T>* tree)
{
    if(tree == nullptr)
        return nullptr;
    while(tree->right != nullptr)
        tree = tree->right;
    return tree;
}

template <class T>
T AVLTree<T>::MaxNode()
{
    AVLTreeNode<T> *p = MaxNode(root);
    if(p != nullptr)
       return p->key;
}


//LL型：右单旋转
template <class T>
AVLTreeNode<T>* AVLTree<T>::RotateR(AVLTreeNode<T>* tree)
{
    AVLTreeNode<T>* treeL;
    treeL = tree->left;
    tree->left = treeL->right;
    treeL->right = tree;
 
    tree->Height = Max(Height(tree->left),Height(tree->right)) + 1;
    treeL->Height = Max( Height(treeL->left),tree->Height) + 1;
    return treeL;
}


//RR型：左单旋转
template <class T>
AVLTreeNode<T>* AVLTree<T>::RotateL(AVLTreeNode<T>* tree)
{
    AVLTreeNode<T>* treeR;
    treeR = tree->right;
    tree->right = treeR->left;
    treeR->left = tree;

    tree->Height = Max( Height(tree->left),Height(tree->right)) + 1;
    treeR->Height = Max( Height(treeR->right),tree->Height) + 1;
    return treeR;
}


//LR型：左右双旋转
template <class T>
AVLTreeNode<T>* AVLTree<T>::RotateLR(AVLTreeNode<T>* tree)
{
    tree->left = RotateL(tree->left);
    return RotateR(tree);
}
 

//RL型：右左双旋转
template <class T>
AVLTreeNode<T>* AVLTree<T>::RotateRL(AVLTreeNode<T>* tree)
{
    tree->right = RotateR(tree->right);
    return RotateL(tree);
}
 

//将值为key的结点插入到AVL树中
template <class T>
AVLTreeNode<T>* AVLTree<T>::Insert(AVLTreeNode<T>* &tree,T key)
{
    if(tree == nullptr) 
    {                                            //树空则新建节点
        tree = new AVLTreeNode<T>(key,nullptr,nullptr);
        if (tree==nullptr)
        {
            cout<<"AVL树创建错误！"<<endl;
            return nullptr;
        }
    }
    else if(key < tree->key)                     //插入左子树时 
    {
        tree->left = Insert(tree->left,key);     //若AVL树失去平衡，则进行相应的调节
        if (Height(tree->left) - Height(tree->right) == 2)
        {
            if(key < tree->left->key)
                tree = RotateR(tree);            //右单旋 
            else
                tree = RotateLR(tree);           //左右双旋转 
        }
    }
    else if(key > tree->key)                     //插入到右子树时 
    {
        tree->right = Insert(tree->right, key);  //若AVL树失去平衡，则进行相应的调节
        if (Height(tree->right) - Height(tree->left) == 2)
        {
            if(key > tree->right->key)
                tree = RotateL(tree);            //左单旋 
            else
                tree = RotateRL(tree);           //右左双旋转 
        }
    }
    else
    {
        cout<<"添加失败！不允许添加相同的节点！"<<endl;
    }

    tree->Height = Max(Height(tree->left),Height(tree->right)) + 1;
    return tree;                                 //树高度加1
}
 
template <class T>
void AVLTree<T>::Insert(T key)
{
    Insert(root,key);
}


//删除结点key1
template <class T>
AVLTreeNode<T>* AVLTree<T>::Remove(AVLTreeNode<T>* &tree,AVLTreeNode<T>* key1)
{
    if(tree==nullptr)                            //根为空，直接返回nullptr
        return nullptr;
 
    if(key1->key < tree->key)                    //待删除的节点在左子树中
    {
        tree->left = Remove(tree->left,key1);    //若AVL树失去平衡，则进行相应的调节
        if(Height(tree->right) - Height(tree->left) == 2)
        {
            AVLTreeNode<T> *r =  tree->right;
            if (Height(r->left) > Height(r->right))
                tree = RotateRL(tree);
            else
                tree = RotateL(tree);
        }
    }
    else if(key1->key > tree->key)               //待删除的节点在右子树中
    {
        tree->right = Remove(tree->right,key1);  //若AVL树失去平衡，则进行相应的调节
        if(Height(tree->left) - Height(tree->right) == 2)
        {
            AVLTreeNode<T> *l =  tree->left;
            if (Height(l->right) > Height(l->left))
                tree = RotateLR(tree);
            else
                tree = RotateR(tree);
        }
    }
    else                                         //tree是对应要删除的节点
    {                                            //左右孩子都非空
        if((tree->left!=nullptr) && (tree->right!=nullptr))
        {                                        //如果tree的左子树比右子树高
            if (Height(tree->left) > Height(tree->right))
            {
                AVLTreeNode<T>* Max = MaxNode(tree->left);
                tree->key = Max->key;
                tree->left = Remove(tree->left,Max);
            }
            else                                 //如果tree的右子树比左子树高
            {                                    //(即它们相等，或右子树比左子树高1)
                AVLTreeNode<T>* Min = MinNode(tree->right);
                tree->key = Min->key;
                tree->right = Remove(tree->right,Min);
            }
        }
        else                                     //除了左右孩子都非空的其他情况 
        {
            AVLTreeNode<T>* tmp = tree;
            tree = (tree->left!=nullptr) ? tree->left : tree->right;
            delete tmp;
        }
    }

    return tree;
}

template <class T>
void AVLTree<T>::Remove(T key)
{
    AVLTreeNode<T>* tree;
    if((tree = Search(root,key)) != nullptr)
        root = Remove(root,tree);
}
 

//凹入法输出二叉树
template <class T>
void AVLTree<T>::Display(AVLTreeNode<T>* tree,int n)
{                                                //逆时针旋转90°打印二叉树，n为打印的层数，初始值为0
	int i;
	if(tree==nullptr)
	    return;
	Display(tree->right,n+1);                    //遍历打印右子树 
	for(i=0;i<n;i++)
	    cout<<"   ";
	if(n>=0)
	{
		cout<<"---";
		cout<<tree->key<<endl;
	}
	Display(tree->left,n+1);                     //遍历打印左子树 
}

template <class T>
void AVLTree<T>::Display()
{
    if(root != nullptr)
	   Display(root,0);
}


//释放AVL树
template <class T>
void AVLTree<T>::Release(AVLTreeNode<T>* &tree)
{
    if(tree==nullptr)
        return;
    if(tree->left != nullptr)
        Release(tree->left);
    if(tree->right != nullptr)
        Release(tree->right);
    delete tree;
}
 
template <class T>
void AVLTree<T>::Release()
{
    Release(root);
}

#endif

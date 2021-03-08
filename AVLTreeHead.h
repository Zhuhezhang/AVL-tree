#ifndef AVLTREE_HEAD_H_
#define AVLTREE_HEAD_H_
#include <iostream>
#include <iomanip>
using namespace std;


//AVL�����
template <class T>
struct AVLTreeNode
{
    T key;                        //�ؼ���
    int Height;                   //�߶�
    AVLTreeNode *left;            //����
    AVLTreeNode *right;           //�Һ���
    AVLTreeNode(T value,AVLTreeNode *l,AVLTreeNode *r) : key(value),Height(0),left(l),right(r){}
};


//AVL����
template <class T>
class AVLTree
{
 public:
    AVLTree(); 
    ~AVLTree(); 
    int Height();                 //���ĸ߶�
    int Max(int a, int b);        //��a,b�е����ֵ
    void PreOrder();              //ǰ�����
    void InOrder();               //�������
    void PostOrder();             //�������
    AVLTreeNode<T>* Search(T key);//����AVL����ֵΪkey�Ľ��
    T MinNode();                  //������С���
    T MaxNode();                  //���������
    void Insert(T key);           //��ֵΪkey�Ľ����뵽AVL����
    void Remove(T key);           //ɾ��ֵΪkey�Ľ��
    void Release();               //�ͷ���ռ�õĿռ�
    void Display();               //���뷨�����ʾAVL��
private:
	AVLTreeNode<T> *root;                                  //�����
    int Height(AVLTreeNode<T>* tree);                      //�����ĸ߶�
    void PreOrder(AVLTreeNode<T>* tree) const;             //ǰ�����
    void InOrder(AVLTreeNode<T>* tree) const;              //�������
    void PostOrder(AVLTreeNode<T>* tree) const;            //�������
    AVLTreeNode<T>* Search(AVLTreeNode<T>* x,T key) const; //����AVL����ֵΪkey�Ľ��
    AVLTreeNode<T>* MinNode(AVLTreeNode<T>* tree);         //������С���
    AVLTreeNode<T>* MaxNode(AVLTreeNode<T>* tree);         //���������
    AVLTreeNode<T>* RotateR(AVLTreeNode<T>* tree);         //LL�ͣ��ҵ���ת
    AVLTreeNode<T>* RotateL(AVLTreeNode<T>* tree);         //RR�ͣ�����ת
    AVLTreeNode<T>* RotateLR(AVLTreeNode<T>* tree);        //LR�ͣ�����˫��ת
    AVLTreeNode<T>* RotateRL(AVLTreeNode<T>* tree);        //RL�ͣ�����˫��ת
    AVLTreeNode<T>* Insert(AVLTreeNode<T>* &tree,T key);   //��ֵΪkey�Ľ����뵽AVL����
    AVLTreeNode<T>* Remove(AVLTreeNode<T>* &tree,AVLTreeNode<T>* key);//ɾ��ֵΪkey�Ľ��
    void Release(AVLTreeNode<T>* &tree);                   //�ͷ���ռ�õĿռ�
    void Display(AVLTreeNode<T>* tree,int n);              //���뷨�����ʾAVL����nΪ��ӡ���� 
};



//���캯��
template <class T>
AVLTree<T>::AVLTree():root(nullptr){}


//��������
template <class T>
AVLTree<T>::~AVLTree()
{
    Release(root);
}


//�����ĸ߶�
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


//�Ƚ�����ֵ�Ĵ�С
template <class T>
int AVLTree<T>::Max(int a,int b)
{
    return a>b ? a : b;
}


//ǰ�����
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


//�������
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

 
//�������
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


//����AVL����ֵΪkey�Ľ�� 
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


//������С���
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


//���������
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


//LL�ͣ��ҵ���ת
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


//RR�ͣ�����ת
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


//LR�ͣ�����˫��ת
template <class T>
AVLTreeNode<T>* AVLTree<T>::RotateLR(AVLTreeNode<T>* tree)
{
    tree->left = RotateL(tree->left);
    return RotateR(tree);
}
 

//RL�ͣ�����˫��ת
template <class T>
AVLTreeNode<T>* AVLTree<T>::RotateRL(AVLTreeNode<T>* tree)
{
    tree->right = RotateR(tree->right);
    return RotateL(tree);
}
 

//��ֵΪkey�Ľ����뵽AVL����
template <class T>
AVLTreeNode<T>* AVLTree<T>::Insert(AVLTreeNode<T>* &tree,T key)
{
    if(tree == nullptr) 
    {                                            //�������½��ڵ�
        tree = new AVLTreeNode<T>(key,nullptr,nullptr);
        if (tree==nullptr)
        {
            cout<<"AVL����������"<<endl;
            return nullptr;
        }
    }
    else if(key < tree->key)                     //����������ʱ 
    {
        tree->left = Insert(tree->left,key);     //��AVL��ʧȥƽ�⣬�������Ӧ�ĵ���
        if (Height(tree->left) - Height(tree->right) == 2)
        {
            if(key < tree->left->key)
                tree = RotateR(tree);            //�ҵ��� 
            else
                tree = RotateLR(tree);           //����˫��ת 
        }
    }
    else if(key > tree->key)                     //���뵽������ʱ 
    {
        tree->right = Insert(tree->right, key);  //��AVL��ʧȥƽ�⣬�������Ӧ�ĵ���
        if (Height(tree->right) - Height(tree->left) == 2)
        {
            if(key > tree->right->key)
                tree = RotateL(tree);            //���� 
            else
                tree = RotateRL(tree);           //����˫��ת 
        }
    }
    else
    {
        cout<<"���ʧ�ܣ������������ͬ�Ľڵ㣡"<<endl;
    }

    tree->Height = Max(Height(tree->left),Height(tree->right)) + 1;
    return tree;                                 //���߶ȼ�1
}
 
template <class T>
void AVLTree<T>::Insert(T key)
{
    Insert(root,key);
}


//ɾ�����key1
template <class T>
AVLTreeNode<T>* AVLTree<T>::Remove(AVLTreeNode<T>* &tree,AVLTreeNode<T>* key1)
{
    if(tree==nullptr)                            //��Ϊ�գ�ֱ�ӷ���nullptr
        return nullptr;
 
    if(key1->key < tree->key)                    //��ɾ���Ľڵ�����������
    {
        tree->left = Remove(tree->left,key1);    //��AVL��ʧȥƽ�⣬�������Ӧ�ĵ���
        if(Height(tree->right) - Height(tree->left) == 2)
        {
            AVLTreeNode<T> *r =  tree->right;
            if (Height(r->left) > Height(r->right))
                tree = RotateRL(tree);
            else
                tree = RotateL(tree);
        }
    }
    else if(key1->key > tree->key)               //��ɾ���Ľڵ�����������
    {
        tree->right = Remove(tree->right,key1);  //��AVL��ʧȥƽ�⣬�������Ӧ�ĵ���
        if(Height(tree->left) - Height(tree->right) == 2)
        {
            AVLTreeNode<T> *l =  tree->left;
            if (Height(l->right) > Height(l->left))
                tree = RotateLR(tree);
            else
                tree = RotateR(tree);
        }
    }
    else                                         //tree�Ƕ�ӦҪɾ���Ľڵ�
    {                                            //���Һ��Ӷ��ǿ�
        if((tree->left!=nullptr) && (tree->right!=nullptr))
        {                                        //���tree������������������
            if (Height(tree->left) > Height(tree->right))
            {
                AVLTreeNode<T>* Max = MaxNode(tree->left);
                tree->key = Max->key;
                tree->left = Remove(tree->left,Max);
            }
            else                                 //���tree������������������
            {                                    //(��������ȣ�������������������1)
                AVLTreeNode<T>* Min = MinNode(tree->right);
                tree->key = Min->key;
                tree->right = Remove(tree->right,Min);
            }
        }
        else                                     //�������Һ��Ӷ��ǿյ�������� 
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
 

//���뷨���������
template <class T>
void AVLTree<T>::Display(AVLTreeNode<T>* tree,int n)
{                                                //��ʱ����ת90���ӡ��������nΪ��ӡ�Ĳ�������ʼֵΪ0
	int i;
	if(tree==nullptr)
	    return;
	Display(tree->right,n+1);                    //������ӡ������ 
	for(i=0;i<n;i++)
	    cout<<"   ";
	if(n>=0)
	{
		cout<<"---";
		cout<<tree->key<<endl;
	}
	Display(tree->left,n+1);                     //������ӡ������ 
}

template <class T>
void AVLTree<T>::Display()
{
    if(root != nullptr)
	   Display(root,0);
}


//�ͷ�AVL��
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

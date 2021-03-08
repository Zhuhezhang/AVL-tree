#include "AVLTreeHead.h"
#include <iostream> 
using namespace std;

int main()
{   //呃呃，，不想每次运行都输入数据，有需要再改吧 
	int array[] = {3,2,24,4,6,7,16,15,1,12,11,10,9};
	int i;
	AVLTree<int>* tree=new AVLTree<int>();
	cout<<"依次插入: ";
	for(i=0;i<(sizeof(array))/(sizeof(array[0]));i++)
	{
		cout<<array[i]<<" ";
		tree->Insert(array[i]);
	}
	cout<<endl;

	cout<<"前序遍历: "; tree->PreOrder();
    cout<<"\n中序遍历: "; tree->InOrder();
	cout<<"\n后序遍历: "; tree->PostOrder();
	cout<<"\n最小值: "<<tree->MinNode();
	cout<<"\n最大值: "<<tree->MaxNode();
	cout<<"\n凹入法输出AVL树: "<<endl; tree->Display();

	i=12;
	cout<<"删除节点: "<<i;
	tree->Remove(i);
	i=11;
	if(tree->Search(i)==nullptr)
	    cout<<"\n不存在结点："<<i;
	else
	    cout<<"\n存在结点："<<i;
	cout<<endl;

	cout<<"\n前序遍历: "; tree->PreOrder();
	cout<<"\n中序遍历: "; tree->InOrder();
	cout<<"\n后序遍历: "; tree->PostOrder();
	cout<<"\n最小值: "<<tree->MinNode();
	cout<<"\n最大值: "<<tree->MaxNode();
	cout<<"\n凹入法输出AVL树: "<<endl; tree->Display();

	tree->Release();//释放该AVL树
	return 0;
}

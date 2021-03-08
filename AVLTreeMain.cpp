#include "AVLTreeHead.h"
#include <iostream> 
using namespace std;

int main()
{   //������������ÿ�����ж��������ݣ�����Ҫ�ٸİ� 
	int array[] = {3,2,24,4,6,7,16,15,1,12,11,10,9};
	int i;
	AVLTree<int>* tree=new AVLTree<int>();
	cout<<"���β���: ";
	for(i=0;i<(sizeof(array))/(sizeof(array[0]));i++)
	{
		cout<<array[i]<<" ";
		tree->Insert(array[i]);
	}
	cout<<endl;

	cout<<"ǰ�����: "; tree->PreOrder();
    cout<<"\n�������: "; tree->InOrder();
	cout<<"\n�������: "; tree->PostOrder();
	cout<<"\n��Сֵ: "<<tree->MinNode();
	cout<<"\n���ֵ: "<<tree->MaxNode();
	cout<<"\n���뷨���AVL��: "<<endl; tree->Display();

	i=12;
	cout<<"ɾ���ڵ�: "<<i;
	tree->Remove(i);
	i=11;
	if(tree->Search(i)==nullptr)
	    cout<<"\n�����ڽ�㣺"<<i;
	else
	    cout<<"\n���ڽ�㣺"<<i;
	cout<<endl;

	cout<<"\nǰ�����: "; tree->PreOrder();
	cout<<"\n�������: "; tree->InOrder();
	cout<<"\n�������: "; tree->PostOrder();
	cout<<"\n��Сֵ: "<<tree->MinNode();
	cout<<"\n���ֵ: "<<tree->MaxNode();
	cout<<"\n���뷨���AVL��: "<<endl; tree->Display();

	tree->Release();//�ͷŸ�AVL��
	return 0;
}

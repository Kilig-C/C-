/*
ADT ����tree��
Data 
������һ�����������ɿ��������ɡ����н�������ͬ�������ͼ���ι�ϵ��
Operation
InitTree(*T)�����ɿ���T��
DestroyTree(*T)��������T��
CreateTree(*T,Definition)����definition�и��������Ķ�������������
ClearTree(*T)������T���ڣ�����T��Ϊ������
TreeEmpty(T)����TΪ����������true�����򷵻�false��
TreeDepth(T)������T����ȡ�
Root(T)������T�ĸ���㡣
Value(T,cur_e)��cur_e����T��һ����㣬���ش˽���ֵ��
Assign(T,cur_e,value)������T�Ľ��cur_e��ֵΪvalue��
Parent(T,cur_e)����cur_e����T�ķǸ���㣬�򷵻�����˫�ף����򷵻ؿա�
LeftChild(T,cur_e)����cur_e����T�ķ�Ҷ��㣬���򷵻����������ӣ����򷵻ؿա�
RightSlibling(T,cur_e)����cur_e�����ֵܣ��򷵻��������ֵܣ����򷵻ؿա�
InsertChild(*T,*p,i,c)������pָ����T��ĳ����㣬iΪ��ָ���p�Ķȼ���1��
�ǿ���c��T���ཻ���������Ϊ����cΪ��T��pָ���ĵ�i��������
DeleteChild(*T,*p,i)������pָ����T��ĳ����㣬iΪ��ָ���p�Ķȣ��������Ϊɾ��T��p��ָ���ĵ�i��������

endADT


*/
#include<stdio.h>

//����˫�ױ�ʾ�����ṹ����
#define MAX_TREE_SIZE 100  //�������Ĵ�С 
typedef int TElemType; //�������������ͣ��˴���λ����

typedef struct PTNode //���ṹ
{
	TElemType data; //�������
	int parent; //˫��λ��
}PTNode;

typedef struct //���ṹ
{
	PTNode nodes[MAX_TREE_SIZE]; //�������
	int r, n; //����λ�úͽ����
}PTree;


//���ĺ��ӱ�ʾ���ṹ����
#define MAX_TREE_SIZE 100  //�������Ĵ�С 
typedef int TElemType; //�������������ͣ��˴���λ����

typedef struct CTNNode //���ӽ��
{
	int child;
	struct CTNode *next;
}*ChildPtr;
typedef struct //��ͷ�ṹ
{
	TElemType data;
	ChildPtr firstchild;
}CTBox;
typedef struct //���ṹ
{
	CTBox nodes[MAX_TREE_SIZE]; //�������
	int r, n; //����λ�úͽ����
}CTree;

//���ĺ����ֵܱ�ʾ���ṹ����
typedef struct CSNode
{
	TElemType data;
	struct CSNode *firstchild, *rightsib;
}CSNode,*CSTree;




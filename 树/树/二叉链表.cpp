#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//树的双亲表示法结点结构定义
#define MAX_TREE_SIZE 100  //结点数组的大小 
typedef int TElemType; //根结点的数据类型，此处定位整型

//二叉树的二叉链表结点结构定义
typedef struct BiTNode //结点结构
{
	TElemType data; //结点数据
	struct BiTNode *lchild, *rchild; //左右孩子指针
}BiTNode,*BiTree;

//二叉树的前序遍历递归算法
void PreOrderTraverse(BiTree T)
{
	if (T == NULL) //判断树是否为空
	{
		return; //如果树为空，直接返回，不执行后续操作
	}
	printf("%c", T->data); //显示结点数据，可以更改为其他对结点的操作
	PreOrderTraverse(T->lchild); //再先序遍历左子树
	PreOrderTraverse(T->rchild); //最后先序遍历右子树
}

//二叉树的中序遍历递归算法
void InOrderTraverse(BiTree T)
{
	if (T == NULL) //判断树是否为空
	{
		return; //如果树为空，直接返回，不执行后续操作
	}
	InOrderTraverse(T->lchild); //中序遍历左子树
	printf("%c", T->data); //显示结点数据，可以更改为其他对结点的操作
	InOrderTraverse(T->rchild); //最后中序遍历右子树
}

//二叉树的后序遍历递归算法
void PostOrderTraverse(BiTree T)
{
	if (T == NULL) //判断树是否为空
	{
		return; //如果树为空，直接返回，不执行后续操作
	}
	PostOrderTraverse(T->lchild); //先后序遍历左子树
	PostOrderTraverse(T->rchild); //再后序遍历右子树
	printf("%c", T->data); //显示结点数据，也可以更改为其他对结点操作
}

//按前序输入二叉树中结点的值（一个字符）
// # 表示空树，构造二叉链表表示二叉树T
void CreateBiTree(BiTree *T)
{
	TElemType ch;
	scanf("%c", &ch);
	if (ch == '#')
	{
		*T = NULL;
	}
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if (!*T)
		{
			/*
				OVERFLOW为math.h中的一个宏定义，其值为3。
			含义为运算过程中出现了上溢，
			即运算结果超出了运算变量所能存储的范围。
				exit(OVERFLOW)的含义就是，退出程序，
			并返回OVERFLOW的值给主调进程。其标准的使用范围为:
			当程序运算出现上溢时，退出程序并报错给主调进程。 
			*/
			exit(OVERFLOW);
		}
		(*T)->data = ch; //生成根结点
		CreateBiTree(&(*T)->lchild); //构造左子树
		CreateBiTree(&(*T)->rchild); //构造右子树
	}
}




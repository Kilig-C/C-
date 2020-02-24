#define TRUE 1
#define FALSE 0
typedef int Status; //创建子函数返回类型 
/* 当二叉排序树T中不存在关键字等于 key 的数据元素时，*/
/* 插入 key 并返回 TRUE ,否則返回 FALSE */
Status InsertBST(BiTree *T,int key)
{
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p))	/* 查找不成功 */
	{
		s = (BiTree)malloc(sizeof (BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
		{
			*T = s;	/* 插入 s 为新的根结点 */
		}
		else if (key < p->data)
		{
			p->lchild = s; /* 插入 s 为左孩子 */
		}
		else
		{
			p->rchild = s; /* 插入 s 为右孩子 */
		}
		return TRUE;
	}
	else
		return FALSE;	/* 树中已有关键字相同的结点，不再插入 */
}
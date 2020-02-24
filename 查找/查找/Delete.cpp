typedef int Status; //创建子函数返回类型 
/*从二叉排序树中删除结点P,并重接它的左或右子树。*/
Status	Delete(BiTree *p)
{
	BiTree q, s;
	if ((*p)->rchild = NULL)	/* 右子树空则只需重接它的左子树 */
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if ((*p)->lchild == NULL)	/* 只需重接它的右子树 */
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else /* 左右子树均不空 */
	{
		q = *p;
		s = (*p)->lchild;
		while(s->rchild) /* 转左，然后向右到尽头（找待测结点的前驱）*/
		{
			q = s;
			s - s->rchild;
		}
		(*p)->data = s->data;	/* s 指向被删结点的直接前驱 */
		if (q != *p)
		{
			q->rchild = s->lchild;	/* 重接 q 的右子树 */
		}
		else
		{
			q->lchilds = s->lchild;	/* 重接 q 的左子树 */
		}
		free(s);
	}
	return TRUE;
}

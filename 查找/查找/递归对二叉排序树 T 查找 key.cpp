typedef int Status; //创建子函数返回类型 
/* 若二叉排序树T中存在关键字等于 key 的数据元素时，则删除该数据元素结点，*/
/* 并返回 TRUE ;否則返回 FALSE */
Status DeleteBST(BiTree *T, int key)
{
	if(!*T) /* 不存在关键字等于 key 的数据元素 */
	{
		return FALSE;
	}
	else
	{
		if(key == (*T)->data) /* 找到关键字等于 key 的数据元素 */
		{
			return Delete(T);
		}
		else if(key < (*T)->data)
		{
			return DeleteBST(&(*T)->lchild, key);
		}
		else 
		{
			return DeleteBST(&(*T)->rchild, key);
		}
	}
}

typedef int Status; //�����Ӻ����������� 
/* ������������T�д��ڹؼ��ֵ��� key ������Ԫ��ʱ����ɾ��������Ԫ�ؽ�㣬*/
/* ������ TRUE ;��t���� FALSE */
Status DeleteBST(BiTree *T, int key)
{
	if(!*T) /* �����ڹؼ��ֵ��� key ������Ԫ�� */
	{
		return FALSE;
	}
	else
	{
		if(key == (*T)->data) /* �ҵ��ؼ��ֵ��� key ������Ԫ�� */
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

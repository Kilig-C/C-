#define TRUE 1
#define FALSE 0
typedef int Status; //�����Ӻ����������� 
/* �ݹ���Ҷ��������� T ���Ƿ���� key , ָ�� f ָ�� T ��˫�ף����ʼ����ֵΪNULL */
/* �����ҳɹ�����ָ�� p ָ�������Ԫ�ؽ�㣬������ TRUE */
/* ����ָ�� p ָ�����·���Ϸ��ʵ����һ����㲢���� FALSE */
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
	if (!T)	/* ���Ҳ��ɹ� */
	{
		*p = f;
		return FALSE;
	}
	else if (key == T->data)	/* ���ҳɹ� */
	{
		*p = T;
		return TRUE;
	}
	else if (key < T->data)
	{
		return SearchBST(T->lchild , key, T, p); /*���������������� */
	}
	else
	{
		return SearchBST(T->rchild, key, T, p); /*���������������� */
	}
}







/* �������Ķ���������ṹ���� */
typedef struct BiTNode	/* ���ṹ */
{
	int data;	/* ������� */
	struct BiTNode *lchild, *rchild; /* ���Һ���ָ�� */
} BiTNode, *BiTree;



#define TRUE 1
#define FALSE 0
typedef int Status; //�����Ӻ����������� 
/* ������������T�в����ڹؼ��ֵ��� key ������Ԫ��ʱ��*/
/* ���� key ������ TRUE ,��t���� FALSE */
Status InsertBST(BiTree *T,int key)
{
	BiTree p, s;
	if (!SearchBST(*T, key, NULL, &p))	/* ���Ҳ��ɹ� */
	{
		s = (BiTree)malloc(sizeof (BiTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
		{
			*T = s;	/* ���� s Ϊ�µĸ���� */
		}
		else if (key < p->data)
		{
			p->lchild = s; /* ���� s Ϊ���� */
		}
		else
		{
			p->rchild = s; /* ���� s Ϊ�Һ��� */
		}
		return TRUE;
	}
	else
		return FALSE;	/* �������йؼ�����ͬ�Ľ�㣬���ٲ��� */
}
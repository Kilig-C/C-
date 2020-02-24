#define LH +1	/* ��� */
#define EH 0	/* �ȸ� */
#define RH -1	/* �Ҹ� */
/* ����ָ�� T ��ָ���Ϊ���Ķ���������ƽ����ת���� */
/* ���㷨����ʱ��ָ�� T ָ���µĸ���� */
void LeftBalance(BiTree *T)
{
	BiTree L, Lr;
	L = (*T)->lchild;	/* L ָ�� T ������������� */
	switch (L->bf)
	{
		/* ��� T ����������ƽ��ȣ�������Ӧƽ�⴦�� */
	case LH:	/* �½������� T �����ӵ��������ϣ�Ҫ������������ */
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH:	/* �½������� T �����ӵ��������ϣ�Ҫ��˫������ */
		Lr = L->rchild;	/*	Lr ָ�� T �����ӵ��������� */
		switch (Lr->bf) /* �޸� T �������ӵ�ƽ������ */
		{
		case LH: 
			(*T)->bf = RH;
			L->bf = EH;
			break;
		case EH:	
			(*T)->bf = L->bf = EH;
			break;
		case RH:	
			(*T)->bf = EH;
			L->bf = LH;
			break;
		}
		Lr->bf = EH;
		L_Rotate(&(*T)->lchild);	/* �� T ��������������ƽ�⴦�� */
		R_Rotate(T);	/* �� T ������ƽ�⴦�� */
	}
}

							/* �������Ķ���������ṹ���� */
			typedef struct	BiTNode	 /* ���ṹ */
			{
				int data;	/* ������� */
				int bf;		/* ����ƽ������ */
				struct BiTNode *lchild, *rchild;	/* ���Һ���ָ�� */
			} BiTNode, *BiTree;

			/* ���� p Ϊ���Ķ����������� ���� ����*/
			/* ����֮�� p ָ���µ�������㣬����ת����֮ǰ���������ĸ���� */
			void R_Rotate(BiTree *P)
			{
				BiTree L;
				L = (*P)->lchild;			/*	L ָ�� P ������������� */
				(*P)->lchild = L->rchild;	/* L ���������ҽ�Ϊ P �������� */
				L->rchild = (*P);
				*P = L;						/* P ָ���µĸ���� */
			}


			/* ���� P Ϊ���Ķ����������� ���� ����*/
			/* ����֮�� P ָ���µ�������㣬����ת����֮ǰ���������ĸ���� 0 */
			void L_Rotate(BiTree *P)
			{
				BiTree R;
				R = (*P)->rchild;			/* R ָ��P�������������*/
				(*P)->rchild = R->lchild;	/* R ���������ҽ�Ϊ P ��������*/
				R->lchild = (*P);
				*P = R;						/* P ָ���µĸ����*/
			}

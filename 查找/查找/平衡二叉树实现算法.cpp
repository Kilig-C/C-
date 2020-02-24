#define LH +1	/* 左高 */
#define EH 0	/* 等高 */
#define RH -1	/* 右高 */
/* 对以指针 T 所指结点为根的二叉树作左平衡旋转处理 */
/* 本算法结束时，指针 T 指向新的根结点 */
void LeftBalance(BiTree *T)
{
	BiTree L, Lr;
	L = (*T)->lchild;	/* L 指向 T 的左子树根结点 */
	switch (L->bf)
	{
		/* 检查 T 的左子树的平衡度，并作相应平衡处理 */
	case LH:	/* 新结点插入在 T 的左孩子的左子树上，要作单右旋处理 */
		(*T)->bf = L->bf = EH;
		R_Rotate(T);
		break;
	case RH:	/* 新结点插入在 T 的左孩子的右子树上，要作双旋处理 */
		Lr = L->rchild;	/*	Lr 指向 T 的左孩子的右子树根 */
		switch (Lr->bf) /* 修改 T 及其左孩子的平衡因子 */
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
		L_Rotate(&(*T)->lchild);	/* 对 T 的左子树作左旋平衡处理 */
		R_Rotate(T);	/* 对 T 作右旋平衡处理 */
	}
}

							/* 二叉树的二叉链表结点结构定义 */
			typedef struct	BiTNode	 /* 结点结构 */
			{
				int data;	/* 结点数据 */
				int bf;		/* 结点的平衡因子 */
				struct BiTNode *lchild, *rchild;	/* 左右孩子指针 */
			} BiTNode, *BiTree;

			/* 对以 p 为根的二叉排序树作 右旋 处理，*/
			/* 处理之后 p 指向新的树根结点，即旋转处理之前的左子树的根结点 */
			void R_Rotate(BiTree *P)
			{
				BiTree L;
				L = (*P)->lchild;			/*	L 指向 P 的左子树根结点 */
				(*P)->lchild = L->rchild;	/* L 的右子树挂接为 P 的左子树 */
				L->rchild = (*P);
				*P = L;						/* P 指向新的根结点 */
			}


			/* 对以 P 为根的二叉排序树作 左旋 处理，*/
			/* 处理之后 P 指向新的树根结点，即旋转处理之前的右子树的根结点 0 */
			void L_Rotate(BiTree *P)
			{
				BiTree R;
				R = (*P)->rchild;			/* R 指向P的右子树根结点*/
				(*P)->rchild = R->lchild;	/* R 的左子树挂接为 P 的右子树*/
				R->lchild = (*P);
				*P = R;						/* P 指向新的根结点*/
			}

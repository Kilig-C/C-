typedef int Status; //�����Ӻ����������� 
/*�Ӷ�����������ɾ�����P,���ؽ����������������*/
Status	Delete(BiTree *p)
{
	BiTree q, s;
	if ((*p)->rchild = NULL)	/* ����������ֻ���ؽ����������� */
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if ((*p)->lchild == NULL)	/* ֻ���ؽ����������� */
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else /* �������������� */
	{
		q = *p;
		s = (*p)->lchild;
		while(s->rchild) /* ת��Ȼ�����ҵ���ͷ���Ҵ������ǰ����*/
		{
			q = s;
			s - s->rchild;
		}
		(*p)->data = s->data;	/* s ָ��ɾ����ֱ��ǰ�� */
		if (q != *p)
		{
			q->rchild = s->lchild;	/* �ؽ� q �������� */
		}
		else
		{
			q->lchilds = s->lchild;	/* �ؽ� q �������� */
		}
		free(s);
	}
	return TRUE;
}

#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12	/* ����ɢ�б�Ϊ����ĳ��� */
#define NULLKEY -32768 
typedef struct 
{
	int *elem;	/* ����Ԫ�ش洢��ַ����̬�������� */
	int count; /* ��ǰ����Ԫ�ظ��� */
}HashTable;
int m = 0;	/* ɢ�б����ȫ�ֱ��� */

#define OK 1
#define HASHSIZE 12	/* ����ɢ�б�Ϊ����ĳ��� */
#define NULLKEY - 32768
typedef int Status; 
/* ��ʼ��ɢ�б� */
Status InitHashTable(HashTable *H)
{
	int i; m = HASHSIZE;
	H->count = m;
	H->elem = (int *)malloc(m*sizeof (int)); 
	for (i = 0; i < m; i++)
	{
		H->elem[i] = NULLKEY;
	}
	return OK;
}


/* ɢ�к��� */ 
int Hash ( int key )
{
	return key % m;	/* ���������� */
}


/* ����ؼ��ֽ�ɢ�б� */
void InsertHash(HashTable *H, int key)
{
	int addr = Hash(key);	/* ��ɢ�е�ַ */
	while (H->elem[addr] != NULLKEY)	/* �����Ϊ�գ����ͻ */
	{
		addr = (addr + 1) % m;	/*���Ŷ�ַ��������̽��*/
	}
	H->elem[addr] = key;	/* ֱ���п�λ�����ؼ��� */
}

/* ɢ�б���ҹؼ��� */
Status SearchHash(HashTable H, int key, int *addr)
{
	*addr = Hash(key);	/* ��ɢ�е�ַ */
	while (H.elem[*addr] != key)	/* �����Ϊ�գ����ͻ */
	{
		*addr = (*addr + 1) % m;	/* ���Ŷ�ַ��������̽�� */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key))
		{
			/* ���ѭ���ص�ԭ�� */
			return UNSUCCESS;	/* ��˵���ؼ��ֲ����� */
		}
	}
	return SUCCESS;
}
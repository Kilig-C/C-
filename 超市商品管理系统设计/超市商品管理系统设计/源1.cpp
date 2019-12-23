#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <conio.h>//��getch();���û�����ĳ���ַ�ʱ�������Զ���ȡ�����谴�س���

using namespace std;

//��Ʒ��
class Goods
{
public:
	Goods() { } //���캯��
	int kind;
	char name[20];//����
	char Id[20];//���
	char manufacturers[20];//�������� 
	char brand[10];//Ʒ��
	float buyprice;  //�����ۣ�
	float saleprice; //�����ۣ�
	int amount;  //���������
	int amount1; //�ۻ�������
	int profit;  //������
	Goods * Next; //��Ʒ���ָ��
	//��Ʒ��Ϣ��¼��
	void InputAll()
	{
		InputName();  //������Ʒ������
		InputKind();  //����
		InputID();    //��Ʒ�ı��
		InputOther(); // ������Ϣ����
	}
	//ѡ������
	void InputKind()
	{
		cout << "\t��ѡ�����ࣺ";   
		cin >> kind;
	}
	//������Ʒ������
	void InputName()
	{
		cout << "\t��������Ʒ�����ƣ�";  
		cin >> name;
	}
	//������Ʒ�ı��
	void InputID()
	{
		cout << "\t��������Ʒ�ı�ţ�";  
		cin >> Id;
	}
	//���������
	void InputBuyprice()
	{
		cout << "\t����������ۣ�"; 
		cin >> buyprice;
	}
	//�����۳���
	void InputSaleprice()
	{
		cout << "\t�������۳��ۣ�"; 
		cin >> saleprice;
	}
	//ʣ����Ʒ����
	void InputAmount()
	{
		cout << "\t������ʣ����Ʒ������"; 
		cin >> amount;
	}
	//���뾻����
	void InputProfit()
	{
		cout << "\t�����뾻����"; 
		cin >> profit;
	}
	//������������
	void InputManufacturers()
	{
		cout << "\t�������������ң�"; 
		cin >> manufacturers;
	}
	//����������Ʒ��
	void Inputbrand()
	{
		cout << "\t������������Ʒ�ƣ�"; 
		cin >> brand;
	}
	//������Ϣ����
	void InputOther()
	{
		cout << "\t����������ۣ�"; 
		cin >> buyprice;
		cout << "\t�������۳��ۣ�"; 
		cin >> saleprice;
		cout << "\t��������������"; 
		cin >> amount;
		cout << "\t�������������ң�"; 
		cin >> manufacturers;
		cout << "\t������������Ʒ�ƣ�"; 
		cin >> brand;
		profit = 0;
	}
	//������Ķ��������ļ�
	void ReadFile(istream & in) 
	{
		in >> kind >> name >> Id >> buyprice >> saleprice >> amount >> manufacturers >> brand >> profit;
	}
	//�����Ʒ��Ϣ
	void Show()
	{
		cout << "����:" << kind << endl;
		cout << "��Ʒ��: " << name << endl;
		cout << "���: " << Id << endl;
		cout << "������ " << buyprice << endl;
		cout << "�۳��� " << saleprice << endl;
		cout << "�����: " << amount << endl;
		cout << "������" << profit << endl;
		cout << "��������: " << manufacturers << endl;
		cout << "������Ʒ��: " << brand << endl << endl << endl;
	}
};
//Goodsmessage��
class Goodsmessage : public Goods            
{
public:
	Goodsmessage();
	~Goodsmessage();
	void showMenu(int n);
	void Find();
	void Save();
	void ModifyItem();
	void RemoveItem();
	void Swap(Goods *, Goods *);
	void Paixu();
	void Saleprice();
	int ListCount();
	void Display()
	{
		system("cls"); //�������Ļ������
		i = 0;
		for (Goods * p = Head->Next; p != End; p = p->Next)
		{
			p->Show();
			i++;
		}
		cout << "����" << i << "����Ʒ" << "\n" << endl;
		cout << "���������ַ�����������";
		getch();
	}
	//�Ӽ���������Ʒ��Ϣ �����Ʒ��Ϣ
	void AddItem()
	{
		system("cls"); //�������Ļ������
		End->InputName(); //
		showMenu(1);
		End->InputKind();
		do
		{
			End->InputID();
		} while (FindID(End->Id));
		End->InputOther();

		End->Next = new Goods;
		End = End->Next;
		cout << "��ӳɹ�!" << endl;
		Save();
		cout << "���������ַ�����������";
		getch();
	}
private:
	Goods * Head, *End;
	int i;
	ifstream in;
	ofstream out;
	Goods *FindItem(char * name)
	{
		for (Goods * p = Head; p->Next != End; p = p->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
		if (!strcmp(p->Next->name, name))return p;
		return NULL;
	}
	Goods *FindID(char * Id)
	{
		for (Goods * p = Head; p->Next != End; p = p->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
		if (!strcmp(p->Next->Id, Id))return p;
		return NULL;
	}
	/*Goods *Findkind(int * kind)
	{
	for(Goods * p=Head;p->Next!=End;p=p->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
	if(!strcmp(p->Next->kind,kind))return p;
	return NULL;
	}*/
	Goods *Findmanufacturers(char * manufacturers)
	{
		for (Goods * p = Head; p->Next != End; p = p->Next)//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
		if (!strcmp(p->Next->manufacturers, manufacturers))return p;
		return NULL;
	}
};
//���캯��
Goodsmessage::Goodsmessage()                 
{
	Head = new Goods;
	Head->Next = new Goods;
	End = Head->Next;
	in.open("supermarket.txt");
	if (!in)
		cout << "����Ʒ��Ϣ�����Ƚ�����" << endl; //��ʾ��Ϣ
	else
	{
		while (!in.eof())
		{
			End->ReadFile(in);
			if (End->name[0] == '\0')break;
			End->Next = new Goods;
			End = End->Next;
		}
		in.close();
		cout << "\n\t\t\t\t\t��ȡ��Ʒ��Ϣ�ɹ�!" << "\n" << endl; //��ʾ��Ϣ
	}
}
//��������
Goodsmessage::~Goodsmessage()               
{
	//Save();
	for (Goods * temp; Head->Next != End;)
	{
		temp = Head->Next;
		Head->Next = Head->Next->Next;
		delete temp;
	}
	delete Head, End;
}
//�˵�
void Goodsmessage::showMenu(int n)//�˵�      
{
	switch (n)
	{
	case 1:
	{
			  cout << "\t+-----------------------------------------------------------+\n"
				  <<  "\t|    1. ʳƷ      2. ��ױƷ      3. ����Ʒ      4. ����     |\n"
				  <<  "\t+-----------------------------------------------------------+\n" << endl;
			  break; }
	case 2:
	{
			  system("cls"); //�������Ļ������
			  cout << "\t\t+-----------------  �� �� �� Ʒ �� �� ϵ  ͳ  -------------------+" << endl;
			  cout << "\t\t|                             1.��ӳ�����Ʒ                     |" << endl;
			  cout << "\t\t|                             2.��ʾ������Ʒ                     |" << endl;
			  cout << "\t\t|                             3.��ѯͳ����Ʒ                     |" << endl;
			  cout << "\t\t|                             4.�޸ĳ�����Ʒ                     |" << endl;
			  cout << "\t\t|                             5.ɾ��������Ʒ                     |" << endl;
			  cout << "\t\t|                             6.��������Ʒ                     |" << endl;
			  cout << "\t\t|                             7.�۳�������Ʒ                     |" << endl;
			  cout << "\t\t|                             8.������Ʒ��Ϣ                     |" << endl;
			  cout << "\t\t|                             0.��ȫ�˳�ϵͳ                     |" << endl;
			  cout << "\t\t+----------------------------------------------------------------+" << endl;
			  cout << "\t\t\n\t\t\t\t  ��ѡ��(1-8)��" << endl;
			  break; }
	case 3:
	{
			  system("cls"); //�������Ļ������
			  cout << "\n\t\t+-------------------------------+" << endl;
			  cout << "\t\t|\t 1.����Ʒ������\t|" << endl;
			  cout << "\t\t|\t 2.����Ʒ���Ʋ���\t|" << endl;
			  cout << "\t\t|\t 3.���������Ҳ���\t|" << endl;
			  cout << "\t\t+-------------------------------+\n��ѡ��(1-3)��";
			  break;
	}
	case 4:
	{
			  system("cls");  //�������Ļ������
			  cout << "\t+---------------------------------------------------------------+" << endl;
			  cout << "\t|   1. �޸���Ʒ��      2. �޸ı��           3. ��������\t|" << endl;
			  cout << "\t|   4. �޸�Ʒ��        5. �޸��۳���         6. �޸Ľ�����\t|" << endl;
			  cout << "\t|   7. �޸Ŀ����      8. �޸����           9. �޸�ȫ��\t|" << endl;
		      cout << "\t+---------------------------------------------------------------+" << endl;
			  cout << "\t\t\n\t\t\t\t  ��ѡ��(1-9)��" << endl;
			  break;
	}
	case 5:
	{
			  system("cls");  //�������Ļ������
			  cout << "\n\t+-----------------------------------------------------------------------+" << endl;
			  cout << "\t|   1. ������������        2. �����������       3. ��������������\t|" << endl;
		      cout << "\t+-----------------------------------------------------------------------+" << endl;
			  cout << "\t\t\n\t\t  ��ѡ��(1-3)��" << endl;
			  break;
	}
	}
}
//���Һ���
void Goodsmessage::Find()       
{
	system("cls");
	char kind[20], name[20], manufacturers[10];
	int x;
	Goods * p = NULL;
	showMenu(3);
	cin >> x;
	switch (x)
	{
		/* case 1:{cout<<"\t\t������Ҫ���ҵ���Ʒ�����";cin>>kind;
		if(p=Findkind(kind))
		{
		p->Next->Show();
		cout<<"���������ַ�����������";
		getch();
		}
		else
		{
		cout<<"\t\t�ü�¼�����ڣ�"<<'\n'<<endl;
		cout<<"���������ַ�����������";
		getch();
		}
		}break;*/
	case 2:{cout << "\t\t������Ҫ���ҵ���Ʒ�����ƣ�"; cin >> name;
		if (p = FindItem(name))
		{
			p->Next->Show();
			cout << "���������ַ�����������";
			getch();
		}
		else
		{
			cout << "\t\t�ü�¼�����ڣ�" << '\n' << endl;
			cout << "���������ַ�����������";
			getch();
		}
	}break;
	case 3:
	{
			  cout << "\t\t������Ҫ���ҵ���Ʒ���������ң�"; cin >> manufacturers;
			  if (p = Findmanufacturers(manufacturers))
			  {
				  p->Next->Show();
				  cout << "���������ַ�����������";
				  getch();
			  }
			  else
			  {
				  cout << "\t\t�ü�¼�����ڣ�" << '\n' << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
	}break;
	}
}
//�޸���Ʒ��Ϣ
void Goodsmessage::ModifyItem()         
{

	showMenu(4);
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
				  p->Next->InputName();
				  cout << "�޸ĳɹ���" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  else
			  {
				  cout << "\t\tû���ҵ�����Ҫ����Ʒ!" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  break;
	}
	case 2:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
				  p->Next->InputKind();
				  cout << "�޸ĳɹ���" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  else
			  {
				  cout << "\t\tû���ҵ�����Ҫ����Ʒ!" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  break;
	}
	case 3:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
				  p->Next->InputID();
				  cout << "�޸ĳɹ���" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  else
			  {
				  cout << "\t\tû���ҵ�����Ҫ����Ʒ!" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  break;
	}
	case 4:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
				  p->Next->InputBuyprice();
				  cout << "�޸ĳɹ���" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  else
			  {
				  cout << "\t\tû���ҵ�����Ҫ����Ʒ!" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  break;
	}
	case 5:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
				  p->Next->InputSaleprice();
				  cout << "�޸ĳɹ���" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  else
			  {
				  cout << "\t\tû���ҵ�����Ҫ����Ʒ!" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  break;
	}
	case 6:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
				  p->Next->InputAmount();
				  cout << "�޸ĳɹ���" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  else
			  {
				  cout << "\t\tû���ҵ�����Ҫ����Ʒ!" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  break;
	}
	case 7:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
				  p->Next->InputProfit();
				  cout << "�޸ĳɹ���" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  else
			  {
				  cout << "\t\tû���ҵ�����Ҫ����Ʒ!" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  break;
	}
	case 8:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
				  p->Next->Inputbrand();
				  cout << "�޸ĳɹ���" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  else
			  {
				  cout << "\t\tû���ҵ�����Ҫ����Ʒ!" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  break;
	}
	case 9:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
				  p->Next->Inputbrand();
				  cout << "�޸ĳɹ���" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  else
			  {
				  cout << "\t\tû���ҵ�����Ҫ����Ʒ!" << endl;
				  cout << "���������ַ�����������";
				  getch();
			  }
			  break;
	}
	case 10:
	{
			   char Id[20];
			   Goods * p = NULL;
			   cout << "\t\t������Ҫ�޸ĵ���Ʒ�ı��:"; cin >> Id;
			   if (p = FindID(Id))
			   {
				   cout << "\t\t���ҵ���Ʒ����Ϣ���������µ���Ϣ!" << endl;
				   p->Next->InputAll();
				   cout << "�޸ĳɹ���" << endl;
				   cout << "���������ַ�����������";
				   getch();
			   }
			   else
			   {
				   cout << "\t\tû���ҵ�����Ҫ����Ʒ!" << endl;
				   cout << "���������ַ�����������";
				   getch();
			   }
	}
	}
}
//ɾ����Ʒ��Ϣ
void Goodsmessage::RemoveItem()          
{
	system("cls");
	char Id[20];
	Goods * p = NULL, *temp = NULL;
	cout << "\t\t������Ҫɾ������Ʒ�ı��:" << endl; cin >> Id;
	if (p = FindID(Id))
	{
		temp = p->Next;
		p->Next = p->Next->Next;
		delete temp;
		cout << "\t\tɾ���ɹ�!" << endl;
		cout << "���������ַ�����������";
		getch();
	}
	else
	{
		cout << "\t\t����Ʒ������!" << endl;
		cout << "���������ַ�����������";
		getch();
	}
}
//�۳���Ʒ
void Goodsmessage::Saleprice()           
{
	system("cls");
	char kind[20]; char name[20]; int i;
	Goods * p = NULL;
	Goods * temp = NULL;
	cout << "\t\t������Ҫ�۳�����Ʒ����������:" << endl; cin >> kind; cin >> name;
	cout << "\t\t������Ҫ���������:" << endl; cin >> i;

	if (p = FindItem(name))
	{
		cout << "��Ʒ��ϢΪ:" << endl;

		if (p->Next->amount>i)
		{
			p->Next->amount -= i;
			p->Next->amount1 += i;
			p->Next->profit += i*(p->Next->saleprice - p->Next->buyprice);
			cout << "��Ʒ�۳��ɹ�!" << "\n";
			cout << "�۳���Ʒ����: " << name << "\t" << "����: " << i << "\n";
			cout << "\n";
			cout << "�۳�����Ʒ��Ϣ: " << endl;

			p->Next->Show();
			Save();
			cout << "���������ַ�����������";
			getch();

		}
		else
		{
			cout << "��Ʒ�������������ܹ���" << endl;
			cout << "���������ַ�����������";
			getch();
			Saleprice();
		}

	}
	else
	{
		cout << "�޴�����Ʒ�����ܹ���" << endl;
		cout << "���������ַ�����������";
		getch();
		showMenu(2);
	}

}
//����������Ʒ������
void Goodsmessage::Swap(Goods *p1, Goods *p2)        
{
	Goods *temp = new Goods;
	strcpy(temp->name, p1->name);
	temp->kind = p1->kind;
	strcpy(temp->Id, p1->Id);
	strcpy(temp->manufacturers, p1->manufacturers);
	temp->saleprice = p1->saleprice;
	temp->buyprice = p1->buyprice;
	temp->amount = p1->amount;
	temp->profit = p1->profit;
	strcpy(temp->brand, p1->brand);

	strcpy(p1->name, p2->name);
	p1->kind = p2->kind;
	strcpy(p1->Id, p2->Id);
	strcpy(p1->manufacturers, p2->manufacturers);
	p1->saleprice = p2->saleprice;
	p1->buyprice = p2->buyprice;
	p1->amount = p2->amount;
	p1->profit = p2->profit;
	strcpy(p1->brand, p2->brand);

	strcpy(p2->name, temp->name);
	p2->kind = temp->kind;
	strcpy(p2->Id, temp->Id);
	strcpy(p2->manufacturers, temp->manufacturers);
	p2->saleprice = temp->saleprice;
	p2->buyprice = temp->buyprice;
	p2->amount = temp->amount;
	p2->profit = temp->profit;
	strcpy(p2->brand, temp->brand);
}
//ͳ�Ƶ�ǰ����ļ�¼����������һ������
int Goodsmessage::ListCount()       
{
	if (!Head)
		return 0;
	int n = 0;
	for (Goods * p = Head->Next; p != End; p = p->Next)
	{
		n++;
	}
	return n;
}
//������Ʒ
void Goodsmessage::Paixu()       
{
	showMenu(5);
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
	{
			  system("cls");
			  cout << "\t\t������..." << endl;
			  cout << "\n";
			  Goods *p = NULL, *p1 = NULL, *k = NULL;
			  int n = Goodsmessage::ListCount();
			  if (n<2)
				  return;
			  for (p = Head->Next; p != End; p = p->Next)
			  for (k = p->Next; k != End; k = k->Next)
			  {
				  if (p->buyprice>k->buyprice)
				  {
					  Goodsmessage::Swap(p, k);
				  }
			  }
			  Display();
			  out.open("������.txt");
			  for (Goods *q = Head->Next; q != End; q = q->Next)
				  out << q->name << "\t" << q->kind << "\t" << q->Id << "\t" << q->buyprice << "\t" << q->saleprice << "\t" << q->amount << "\t" << q->manufacturers << "\t" << q->brand << "\t" << q->profit << '\n';
			  out.close();
			  cout << "������Ϣ�ɹ�" << endl;
			  cout << "������ɣ�" << endl;
			  getch();
			  return;
	}
	case 2:
	{
			  system("cls");
			  cout << "\t\t������..." << endl;
			  cout << "\n";
			  Goods *p = NULL, *p1 = NULL, *k = NULL;
			  int n = Goodsmessage::ListCount();
			  if (n<2)
				  return;
			  for (p = Head->Next; p != End; p = p->Next)
			  for (k = p->Next; k != End; k = k->Next)
			  {
				  if (p->amount>k->amount)
				  {
					  Goodsmessage::Swap(p, k);
				  }
			  }
			  Display();
			  out.open("�����.txt");
			  for (Goods *q = Head->Next; q != End; q = q->Next)
				  out << q->name << "\t" << q->kind << "\t" << q->Id << "\t" << q->buyprice << "\t" << q->saleprice << "\t" << q->amount << "\t" << q->manufacturers << "\t" << q->brand << "\t" << q->profit << '\n';
			  out.close();
			  cout << "������Ϣ�ɹ�" << endl;
			  cout << "������ɣ�" << endl;
			  getch();
			  return;
	}
	case 3:
	{
			  system("cls");
			  cout << "\t\t������..." << endl;
			  cout << "\n";
			  Goods *p = NULL, *p1 = NULL, *k = NULL;
			  int n = Goodsmessage::ListCount();
			  if (n<2)
				  return;
			  for (p = Head->Next; p != End; p = p->Next)
			  for (k = p->Next; k != End; k = k->Next)
			  {
				  if (p->profit>k->profit)
				  {
					  Goodsmessage::Swap(p, k);
				  }
			  }
			  Display();
			  out.open("��������.txt");
			  for (Goods *q = Head->Next; q != End; q = q->Next)
				  out << q->name << "\t" << q->kind << "\t" << q->Id << "\t" << q->buyprice << "\t" << q->saleprice << "\t" << q->amount << "\t" << q->manufacturers << "\t" << q->brand << "\t" << q->profit << '\n';
			  out.close();
			  cout << "������Ϣ�ɹ�" << endl;
			  cout << "������ɣ�" << endl;
			  getch();
			  return;
	}
	}
}

//��Ʒ��Ϣ���浽�ļ�����
void Goodsmessage::Save()       
{
	out.open("supermarket.txt");
	for (Goods *p = Head->Next; p != End; p = p->Next)
		out << p->name << "\t" << p->kind << "\t" << p->Id << "\t" << p->buyprice << "\t" << p->saleprice << "\t" << p->amount << "\t" << p->manufacturers << "\t" << p->brand << "\t" << p->profit << '\n';

	out.close();
	cout << "��Ʒ��Ϣ���̳ɹ�" << endl;
}

int main()
{
	//�����ʼ������
	for (int i = 0; i < 3; i++)
	{
		cout << "\t\t\t\t+----------------------------------------+" << endl;
	}
	cout << "\t\t\t\t| \t��ӭ���볬����Ʒ����ϵͳ\t |" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "\t\t\t\t+----------------------------------------+" << endl;
	}
	Goodsmessage Grade; //������Grade����ù������ �乹������᷵����Ӧ����ʾ��Ϣ
	cout << "\n\t\t\t\t\t������������������"; //�����ʾ��Ϣ
	getchar(); //�����뻺������ȡ����һ���س���
	int x; //�˱����������湦��ѡ���ֵ
	bool quit = false; //�˱�������ȷ���Ƿ��˳�ϵͳ ��Ϊtrueʱ �˳�ϵͳ
	while (!quit)
	{
		Grade.showMenu(2); //������Grade�Ĳ˵������е�2 Ҳ���ǲ�������
		cin >> x; //����x  ��Ҫѡ��Ĺ��ܶ�Ӧ������ ������x��
		switch (x)
		{
		case 0:{quit = true; break; }        //��ȫ�˳�ϵͳ
		case 1:{Grade.AddItem(); break; }    //��ӳ�����Ʒ
		case 2:{Grade.Display(); break; }    //��ʾ������Ʒ
		case 3:{Grade.Find(); break; }       //��ѯͳ����Ʒ
		case 4:{Grade.ModifyItem(); break; } //�޸ĳ�����Ʒ
		case 5:{Grade.RemoveItem(); break; } //ɾ����Ʒ
		case 6:{Grade.Paixu(); break; }      //��������Ʒ
		case 7:{Grade.Saleprice(); break; }  //���۳�����Ʒ
		case 8:{Grade.Save(); break; }       //������Ʒ��Ϣ
		}
	}
	return 0;
}
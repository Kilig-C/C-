#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <conio.h>//��getch();���û�����ĳ���ַ�ʱ�������Զ���ȡ�����谴�س���

using namespace std;

//��Ʒ��
class Goods
{
public:
	Goods() { } //���캯��
	int kind;//����
	char name[20];//����
	char Id[20];//���
	char manufacturers[20];//�������� 
	char brand[10];//Ʒ��
	float buyprice;  //�����ۣ�
	float saleprice; //�����ۣ�
	int amount;  //���������
	int amount1; //�ۻ�������
	int profit=0;  //������
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
		bool b = true; //����������ַ�Χ���Ϸ�ʱ��������ѭ��
		cout << "\t��ѡ�����ࣺ";
		do
		{
			cin >> kind;
			if (kind > 0 && kind <= 4)
			{
				b = false; //������ֹѭ��
			}
			if (b) //Ϊtrue����
			{
				cout << "\t����������Ų��Ϸ������������룺";
				fflush(stdin); //��ջ�����
			}
		} while (b); //Ϊ��ʱ��ֹѭ��
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
		do
		{
			cin >> buyprice;
			if (buyprice <= 0)
			{
				cout << "\t��������ֲ��Ϸ������������룺";
			}
		} while (buyprice <= 0);
	}
	//�����۳���
	void InputSaleprice()
	{
		cout << "\t�������۳��ۣ�";
		do
		{
			cin >> saleprice;
			if (saleprice <= 0)
			{
				cout << "\t��������ֲ��Ϸ������������룺";
			}
		} while (saleprice <= 0);
	}
	//ʣ����Ʒ����
	void InputAmount()
	{
		cout << "\t������ʣ����Ʒ������"; 
		do
		{
			cin >> amount;
			if (amount <= 0)
			{
				cout << "\t��������ֲ��Ϸ������������룺";
			}
		} while (amount <= 0);
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
		do
		{
			cin >> buyprice;
			if (buyprice <= 0)
			{
				cout << "\t��������ֲ��Ϸ������������룺";
				fflush(stdin); //��ջ�����
			}
		} while (buyprice <= 0);
		cout << "\t�������۳��ۣ�"; 
		do
		{
			cin >> saleprice;
			if (saleprice <= 0)
			{
				cout << "\t��������ֲ��Ϸ������������룺";
				fflush(stdin); //��ջ�����
			}
		} while (saleprice <= 0);
		cout << "\t��������������";
		do
		{
			cin >> amount;
			if (amount <= 0)
			{
				cout << "\t��������ֲ��Ϸ������������룺";
			}
		} while (amount <= 0);
		cout << "\t�������������ң�"; 
		cin >> manufacturers;
		cout << "\t������������Ʒ�ƣ�"; 
		cin >> brand;
		//ÿ����Ʒ������
		profit = saleprice - buyprice;
	}
	//������Ķ��������ļ�
	void ReadFile(istream & in) 
	{
		in >> kind >> name >> Id >> buyprice >> saleprice >> amount >> manufacturers >> brand >> profit;
	}
	//�����Ʒ��Ϣ
	void Show1()
	{
		cout << endl << endl;
		cout << setw(12) << "����" << setw(12) << "��Ʒ��" << setw(12) << "���" << setw(12) << "������";
		cout << setw(12) << "�۳���" << setw(12) << "�����" << setw(12) << "������" << setw(16) << "��������";
		cout << setw(16) << "������Ʒ��" << endl;
	}
	void Show2()
	{
		cout << setw(12) << kind<< setw(12) << name << setw(12) << Id << setw(12) << buyprice;
		cout << setw(12) << saleprice << setw(12) << amount << setw(12) << profit << setw(16) << manufacturers;
		cout << setw(16) << brand << endl;
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
	//��ʾ������Ʒ
	void Display()
	{
		system("cls"); //�������Ļ������
		int j = 0;
		i = 0; //�˴�������¼��Ʒ����
		//����Ʒ��Ϣȫ����ʾ����
		for (Goods * p = Head->Next; p != End; p = p->Next)
		{
			if(j==0)
			{
				p->Show1(); //��ʾ��Ʒ��Ϣ
				j = 1;
			}
			p->Show2(); //��ʾ��Ʒ��Ϣ
			i++;
		}
		cout << "\n\n\t���� " << i << " ����Ʒ" << "\n" << endl;
		cout << "\n\t���������ַ���������ѯ......";
		getch();
	}
	//�Ӽ���������Ʒ��Ϣ �����Ʒ��Ϣ
	void AddItem()
	{
		system("cls"); //�������Ļ������
		End->InputName(); //���ú���������Ʒ������
		showMenu(1); //���ò˵�������ѡ��1
		End->InputKind(); //���ú�������ѡ�������
		do
		{
			End->InputID();
			if (FindID(End->Id))
			{
				cout << "\t�ñ���Ѿ����ڣ�" << endl;
			}
		} while (FindID(End->Id)); //�����жϱ���Ƿ��Ѿ�����
		End->InputOther(); //������Ϣ������
		End->Next = new Goods; //����һ���½��
		End = End->Next; //���һ�����û�д洢��Ϣ �����´��������Ĳ�Ʒ��Ϣ
		cout << "\t��ӳɹ�!" << endl;
		Save(); //�洢��Ϣ
		cout << "\t���������ַ�����������";
		getch();
	}
private:
	Goods * Head, *End;
	int i;
	ifstream in;
	ofstream out;
	//ƥ������
	Goods *FindItem(char * name) 
	{
		//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
		for (Goods * p = Head; p->Next != End; p = p->Next)
		{
			if (!strcmp(p->Next->name, name))
			{
				return p;
			}
		}
		return NULL;
	}
	//ƥ����
	Goods *FindID(char * Id) 
	{
		//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
		for (Goods * p = Head; p->Next != End; p = p->Next)
		{
			//���ID��ͬ�򷵻�0  !0Ϊ�� 
			if (!strcmp(p->Next->Id, Id)) 
			{
				return p;
			}
		}
		return NULL;
	}
	//ƥ���Ʒ����
	Goods *Findkind(int kind)
	{
		//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
		for (Goods * p = Head; p->Next != End; p = p->Next)
		{
			if (p->Next->kind == kind)
			{
				return p;
			}
		}
		return NULL;
	}
	//ƥ��ɲ�����
	Goods *Findmanufacturers(char * manufacturers) 
	{
		//ƥ��ɹ��򷵻���һ��ָ�룬���ɹ��ͷ��ؿ�
		for (Goods * p = Head; p->Next != End; p = p->Next)
		{
			if (!strcmp(p->Next->manufacturers, manufacturers))
			{
				return p;
			}
		}
		return NULL;
	}
};
//���캯��
Goodsmessage::Goodsmessage()                 
{
	Head = new Goods;
	Head->Next = new Goods;
	End = Head->Next;
	in.open("������Ʒ����.txt");
	if (!in)
		cout << "����Ʒ��Ϣ�����Ƚ�����" << endl; //��ʾ��Ϣ
	else
	{
		//�������Ա��������0��ʱ��
		//��һֱִ����while�������ڵ����
		//һֱ����������ֵ���ֹͣ
		//Ȼ��ͼ���ִ���������
		while (!in.eof())
		{
			End->ReadFile(in);
			if (End->name[0] == '\0')
			{
				break; //����ѭ��
			}
			//if (in.fail()) break;
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
	Save();
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
			  cout << "\t\t\n\t\t\t\t  ��ѡ��(1-8)�� ";
			  break; }
	case 3:
	{
			  system("cls"); //�������Ļ������
			  cout << "\n\t\t+-------------------------------+" << endl;
			  cout << "\t\t|\t 1.����Ʒ�������\t|" << endl;
			  cout << "\t\t|\t 2.����Ʒ���Ʋ���\t|" << endl;
			  cout << "\t\t|\t 3.���������Ҳ���\t|" << endl;
			  cout << "\t\t+-------------------------------+\n��ѡ��(1-3)��";
			  break;
	}
	case 4:
	{
			  //system("cls");  //�������Ļ������
			  cout << "\t+---------------------------------------------------------------+" << endl;
			  cout << "\t|   1. �޸���Ʒ��      2. �޸ı��           3. ��������\t|" << endl;
			  cout << "\t|   4. �޸�Ʒ��        5. �޸��۳���         6. �޸Ľ�����\t|" << endl;
			  cout << "\t|   7. �޸Ŀ����      8. �޸�����                      \t|" << endl;
		      cout << "\t+---------------------------------------------------------------+" << endl;
			  cout << "\n\t  ��ѡ��Ҫ�޸ĵ���Ϣ�ı��(1-8)�� ";
			  break;
	}
	case 5:
	{
			  system("cls");  //�������Ļ������
			  cout << "\n\t+-----------------------------------------------------------------------+" << endl;
			  cout << "\t|   1. ������������        2. �����������       3. ������������\t|" << endl;
		      cout << "\t+-----------------------------------------------------------------------+" << endl;
			  cout << "\t\t\n\t\t  ��ѡ��(1-3)�� ";
			  break;
	}
	}
}
//���Һ���
void Goodsmessage::Find()       
{
	system("cls"); //�����Ļ
	char name[20], manufacturers[20];
	int kind;
	int x,j;
	Goods * p = NULL;
	showMenu(3); //�������� �˵�������3
	cin >> x; //����ѡ��Ĳ��ҷ�ʽ�ı��
	while (x <= 0 || x > 3)
	{
		cout << "��������ֲ��Ϸ���������ѡ��1-3����";
		cin >> x;
	}
	switch (x)
	{
		case 1:
		{
				  j = 0;
				  cout<<"������Ҫ���ҵ���Ʒ�����ࣺ";
				  cin>>kind;
				  if (p = Findkind(kind))
				  {
					  p->Next->Show1();
					  p->Next->Show2();
					  j++;
					  for (p=p->Next; p->Next != End; p = p->Next)
					  {
						  if (p->Next->kind == kind)
						  {
							  p->Next->Show2();
							  j++;
						  }
					  }
					  cout << "һ����" << j << "������" << endl;
				  }
				  else
				  {
					  cout << "�ü�¼�����ڣ�" << '\n' << endl;
				  }
				  cout << "\n\n���������ַ�����������......";
				  getch();
		}break;
		case 2:
		{
			  cout << "������Ҫ���ҵ���Ʒ�����ƣ�"; 
			  cin >> name;
			  if (p = FindItem(name))
			  {
				  j = 0;
				  p->Next->Show1();
				  p->Next->Show2();
				  j++;
				  for (p = p->Next; p->Next != End; p = p->Next)
				  {
					  if (!strcmp(p->Next->name, name))
					  {
						  p->Next->Show2();
						  j++;
					  }
				  }
				  cout << "һ����" << j << "������" << endl;
			  }
			  else
			  {
				  cout << "�ü�¼�����ڣ�" << '\n' << endl;
			  }
			  cout << "\n\n���������ַ�����������......";
			  getch();
		}break;
		case 3:
		{
			  cout << "������Ҫ���ҵ���Ʒ���������ң�"; 
			  cin >> manufacturers;
			  if (p = Findmanufacturers(manufacturers))
			  {
				  j = 0;
				  p->Next->Show1();
				  p->Next->Show2();
				  j++;
				  for (p = p->Next; p->Next != End; p = p->Next)
				  {
					  if (!strcmp(p->Next->manufacturers, manufacturers))
					  {
						  p->Next->Show2();
						  j++;
					  }
				  }
				  cout << "һ����" << j << "������" << endl;
			  }
			  else
			  {
				  cout << "�ü�¼�����ڣ�" << '\n' << endl;
			  }
			  cout << "\n\n���������ַ�����������......";
			  getch();
		}break;
	}
}
//�޸���Ʒ��Ϣ
void Goodsmessage::ModifyItem()         
{
	system("cls");
	char kind[20]; char name[20]; int i;
	Goods * p = NULL;
	Goods * temp = NULL;
	cout << "������Ҫ�޸ĵ���Ʒ�����ࣺ";
	cin >> kind;
	cout << "������Ҫ�޸ĵ���Ʒ�����ƣ�";
	cin >> name;
	if (p = FindItem(name)) //������Ʒ�Ƿ����
	{
		//��Ʒ���ڽ�������Ĳ���
		cout << "����Ʒ����\n��Ϣ������ʾ��";
		p->Next->Show1();
		p->Next->Show2();
		cout << endl;
		showMenu(4); //���ò˵������е�4
		int x;
		cin >> x;//����ѡ����
		while (x <= 0 || x > 8)
		{
			cout << "��������ֲ��Ϸ���������ѡ��1-8����";
			cin >> x;
		}
		switch (x)
		{
		case 1://�޸ĵ���Ʒ������
			p->Next->InputName();
			break;
		case 2://�޸ı��
			p->Next->InputID();
			break;
		case 3://��������
			 p->Next->InputManufacturers();
			 break;
		case 4://�޸ĵ���Ʒ��Ʒ��
			p->Next->Inputbrand();
			break;
		case 5://�޸ĵ���Ʒ���۳���
			p->Next->InputSaleprice();
			p->Next->profit = p->Next->saleprice - p->Next->buyprice;
			break;
		case 6://�޸ĵ���Ʒ�Ľ�����
			p->Next->InputBuyprice();
			p->Next->profit = p->Next->saleprice - p->Next->buyprice;
			break;
		case 7://�޸ĵ���Ʒ�Ŀ����
			p->Next->InputAmount(); 
			break;
		case 8://�޸ĵ���Ʒ������
			p->Next->InputKind(); 
			break;
		}
		cout << "�޸ĳɹ���" << endl;
		cout << "���Ҫ���޸ĵ���Ϣ���浽�ı��ļ��У���ִ�����˵��Ĺ���8��" << endl;
		cout << "\n\n���������ַ�����������......";
		getch();
	}
	else
	{
		cout << "�޴�����Ʒ���޷��޸���Ϣ��" << endl;
		cout << "\n\n���������ַ�����������......";
		getch();
		showMenu(2);
	}

}
//ɾ����Ʒ��Ϣ
void Goodsmessage::RemoveItem()          
{
	system("cls"); //�����Ļ
	char Id[20];
	Goods * p = NULL, *temp = NULL;
	cout << "\t������Ҫɾ������Ʒ�ı�ţ�  " ;
	cin >> Id;
	if (p = FindID(Id))
	{
		temp = p->Next;
		p->Next = p->Next->Next;
		delete temp;
		cout << "\tɾ���ɹ�!" << endl;
		cout << "\n���Ҫ��ɾ�������ݴ��ı��ļ���Ҳɾ������ִ�����˵��Ĺ���8��";
		cout << "\n���������ַ�����������......";
		getch();
	}
	else
	{
		cout << "\t����Ʒ������!" << endl;
		cout << "\n\n���������ַ�����������......";
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
	cout << "������Ҫ�۳�����Ʒ�����ࣺ"; 
	cin >> kind; 
	cout << "������Ҫ�۳�����Ʒ�����ƣ�";
	cin >> name;
	if (p = FindItem(name)) //������Ʒ�Ƿ����
	{
		cout << "������Ҫ�����������";
		cin >> i;
		if (p->Next->amount >= i)
		{
			p->Next->amount -= i;
			p->Next->amount1 += i;
			p->Next->profit += i*(p->Next->saleprice - p->Next->buyprice);
			cout << "\n��Ʒ�۳��ɹ�!" << "\n";
			cout << "�۳���Ʒ����: " << name << "\t" << "����: " << i << endl << endl;
			cout << "�۳�����Ʒ��Ϣ: " << endl;
			p->Next->Show1();
			p->Next->Show2();
			cout << endl;
			Save();
			cout << "\n\n���������ַ�����������......";
			getch();

		}
		else
		{
			cout << "��Ʒ�������������ܹ���" << endl;
			cout << "\n\n���������ַ�����������......";
			getch();
			Saleprice();
		}

	}
	else
	{
		cout << "�޴�����Ʒ�����ܹ���" << endl;
		cout << "\n\n���������ַ�����������......";
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
	system("cls"); //�����Ļ
	showMenu(5);
	int x;
	cin >> x;
	while (x <= 0 || x > 3)
	{
		cout << "��������ֲ��Ϸ���������ѡ��1-3����";
		cin >> x;
	}
	switch (x)
	{
	case 1://������������
	{
			  cout << "\t������..." << endl << endl;
			  Goods *p = NULL, *p1 = NULL, *k = NULL;
			  int n = Goodsmessage::ListCount();//ͳ�Ƶ�ǰ����ļ�¼����������һ������
			  if (n < 2) 
			  {
				  return; //˵��ֻ��һ�����ݻ���û������ �Ͳ���������
			  }
			  for (p = Head->Next; p != End; p = p->Next)
			  {
				  for (k = p->Next; k != End; k = k->Next)
				  {
					  if (p->buyprice > k->buyprice) //���۵͵���ǰ��
					  {
						  Goodsmessage::Swap(p, k);
					  }
				  }
			  }
			  out.open("������.txt");
			  for (Goods *q = Head->Next; q != End; q = q->Next)
			  {
				  out << q->name << "\t" << q->kind << "\t" << q->Id << "\t" << q->buyprice << "\t" << q->saleprice << "\t" << q->amount << "\t" << q->manufacturers << "\t" << q->brand << "\t" << q->profit << '\n';
			  }
			  out.close();
			  cout << "\n������ɣ�" << endl;
			  cout << "������Ϣ�ɹ�" << endl;
			  getch();
			  return;
	}
	case 2://�����������
	{
			  cout << "\t������..." << endl << endl;
			  Goods *p = NULL, *p1 = NULL, *k = NULL;
			  int n = Goodsmessage::ListCount();
			  if (n<2)
			  {
				  return;
			  }
			  for (p = Head->Next; p != End; p = p->Next)
			  {
				  for (k = p->Next; k != End; k = k->Next)
				  {
					  if (p->amount > k->amount)//����ٵ���ǰ��
					  {
						  Goodsmessage::Swap(p, k);
					  }
				  }
			  }
			  out.open("�����.txt");
			  for (Goods *q = Head->Next; q != End; q = q->Next)
			  {
				  out << q->name << "\t" << q->kind << "\t" << q->Id << "\t" << q->buyprice << "\t" << q->saleprice << "\t" << q->amount << "\t" << q->manufacturers << "\t" << q->brand << "\t" << q->profit << '\n';
			  } 
			  out.close();
			  cout << "\n������ɣ�" << endl;
			  cout << "������Ϣ�ɹ�" << endl;
			  getch();
			  return;
	}
	case 3://������������
	{
			  cout << "\t������..." << endl << endl;
			  Goods *p = NULL, *p1 = NULL, *k = NULL;
			  int n = Goodsmessage::ListCount();
			  if (n<2)
			  {
				  return;
			  } 
			  for (p = Head->Next; p != End; p = p->Next)
			  {
				  for (k = p->Next; k != End; k = k->Next)
				  {
					  if (p->profit < k->profit) //��������ǰ��
					  {
						  Goodsmessage::Swap(p, k);
					  }
				  }
			  }
			  out.open("������.txt");
			  for (Goods *q = Head->Next; q != End; q = q->Next)
			  {
				  out << q->name << "\t" << q->kind << "\t" << q->Id << "\t" << q->buyprice << "\t" << q->saleprice << "\t" << q->amount << "\t" << q->manufacturers << "\t" << q->brand << "\t" << q->profit << '\n';
			  }
			  out.close();
			  cout << "\n������ɣ�" << endl;
			  cout << "������Ϣ�ɹ�" << endl;
			  getch();
			  return;
	}
	}
}
//��Ʒ��Ϣ���浽�ļ�����
void Goodsmessage::Save()       
{
	out.open("������Ʒ����.txt"); //���ļ�
	for (Goods *p = Head->Next; p != End; p = p->Next)
	{
		out << p->kind << "\t" << p->name << "\t" << p->Id << "\t" << p->buyprice << "\t" << p->saleprice << "\t" << p->amount << "\t" << p->manufacturers << "\t" << p->brand << "\t" << p->profit << '\n';
	}
	out.close(); //�ر��ļ�
	cout << "\t��Ʒ��Ϣ���̳ɹ�" << endl;
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
	getch(); //�����뻺������ȡ����һ���س���
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
		case 8:{Grade.Save(); getch(); break; }  //������Ʒ��Ϣ
		}
		if(quit==true)
		{
			cout << "�԰�ȫ�˳����밴������رմ��ڣ�";
			//getch();
		}
	}
	return 0;
}
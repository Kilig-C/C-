/*
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
	Goods() {} //���캯��
	//ÿ����Ʒ����������Ϣ�� ��Ʒ���� �۸� ����� ��������  Ʒ��
	int kind; //��Ʒ����
	char name[20];//����
	char Id[20];//���
	char manufacturers[20];//�������� 
	char brand[10];//Ʒ��
	float buyprice;  //�����ۣ�
	float saleprice; //�����ۣ�
	int amount;  //���������
	int amount1; //�ۻ�������
	int profit;  //������
	Goods * Next;
	//��Ʒ��Ϣ��¼��
	void InputAll()
	{
		InputName();  //������Ʒ������
		InputKind();  //����
		InputID();    //��Ʒ�ı��
		InputOther(); // ������Ϣ����
	}
	//����
	void InputKind() 
	{
		cout << "\t\t��ѡ�����ࣺ";   cin >> kind;
	}
	//��Ʒ������
	void InputName() 
	{
		cout << "\t\t��������Ʒ�����ƣ�";  cin >> name;
	}
	//��Ʒ�ı��
	void InputID() 
	{
		cout << "\t\t��������Ʒ�ı�ţ�";  cin >> Id;
	}
	//������
	void InputBuyprice() 
	{
		cout << "\t\t����������ۣ�"; cin >> buyprice;
	}
	//�۳���
	void InputSaleprice() 
	{
		cout << "\t\t�������۳��ۣ�"; cin >> saleprice;
	}
	//ʣ����Ʒ����
	void InputAmount() 
	{
		cout << "\t\t������ʣ����Ʒ������"; cin >> amount;
	}
	//������
	void InputProfit() 
	{
		cout << "\t\t�����뾻����"; cin >> profit;
	}
	//��������
	void InputManufacturers() 
	{
		cout << "\t\t�������������ң�"; cin >> manufacturers;
	}
	//������Ʒ��
	void Inputbrand() 
	{
		cout << "\t\t������������Ʒ�ƣ�"; cin >> brand;
	}
	void InputOther()
	{
		cout << "\t\t����������ۣ�"; cin >> buyprice;
		cout << "\t\t�������۳��ۣ�"; cin >> saleprice;
		cout << "\t\t��������������"; cin >> amount;
		cout << "\t\t�������������ң�"; cin >> manufacturers;
		cout << "\t\t������������Ʒ�ƣ�"; cin >> brand;
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
		cout << "����:" << kind << endl << "��Ʒ��: " << name << endl << "���: " << Id << endl << "������ " << buyprice << endl << "�۳��� " << saleprice << endl << "�����: " <<
			amount << endl << "������" << profit << endl << "��������: " << manufacturers << endl << "������Ʒ��: " << brand << endl << endl << endl;
	}
};
*/

// ��Ʒ��ΪʳƷ  ��ױƷ ����Ʒ ����
//ÿ����Ʒ����������Ϣ�� ��Ʒ���� �۸� ����� ��������  Ʒ��
//��Ҫ��ɶ���Ʒ������  ͳ��  �򵥹���


/*
���۹��ܣ�
������Ʒʱ�������������������Ʒ���ƣ��ڿ���в��Ҹ���Ʒ�������Ϣ
����п�棬�����빺������� û���������� 
�����治��������ʾ��Ϣ  ��������
*/

//��ӹ��ܣ���Ҫ�����Ʒ��Ϣ����ӡ�


//��ѯ���ܣ��ɰ���Ʒ�����Ʒ���ơ��������ҽ��в�ѯ��
//��������Ӧ��Ϣ���������ѯ����Ϣ���������ڸü�¼������ʾ���ü�¼�����ڣ�����


//�޸Ĺ��ܣ��ɸ��ݲ�ѯ�������Ӧ�ļ�¼�����޸ġ�


//ɾ�����ܣ���Ҫ�����Ʒ��Ϣ��ɾ������������Ʒ���������Ҫɾ������Ʒ���ƣ�
//���ݲ�ѯ���ɾ������Ʒ�ļ�¼���������Ʒ������Ʒ���У�����ʾ������Ʒ�����ڡ���

//ͳ�ƹ��ܡ�
//�����ǰ�����������Ʒ����������ϸ��Ϣ���ɰ���Ʒ�ļ۸񡢿������
//�������ҽ���ͳ�ƣ����ͳ����Ϣʱ��Ҫ���Ӵ�С�������򣨰�����ͳ��ʱ���⣩��


//��Ʒ��Ϣ���̣�����ǰ�����е���Ʒ��Ϣ�����ļ��С�

//������Ϣ�����ļ��н���Ʒ��Ϣ�������


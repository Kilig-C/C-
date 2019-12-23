#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <conio.h>//用getch();当用户按下某个字符时，函数自动读取，无需按回车。

using namespace std;

//商品类
class Goods
{
public:
	Goods() { } //构造函数
	int kind;
	char name[20];//名字
	char Id[20];//编号
	char manufacturers[20];//生产厂家 
	char brand[10];//品牌
	float buyprice;  //进货价；
	float saleprice; //卖出价；
	int amount;  //存货数量；
	int amount1; //售货数量；
	int profit;  //净利润；
	Goods * Next; //商品类的指针
	//产品信息的录入
	void InputAll()
	{
		InputName();  //输入商品的名称
		InputKind();  //种类
		InputID();    //商品的编号
		InputOther(); // 其他信息输入
	}
	//选择种类
	void InputKind()
	{
		cout << "\t请选择种类：";   
		cin >> kind;
	}
	//输入商品的名称
	void InputName()
	{
		cout << "\t请输入商品的名称：";  
		cin >> name;
	}
	//输入商品的编号
	void InputID()
	{
		cout << "\t请输入商品的编号：";  
		cin >> Id;
	}
	//输入进货价
	void InputBuyprice()
	{
		cout << "\t请输入进货价："; 
		cin >> buyprice;
	}
	//输入售出价
	void InputSaleprice()
	{
		cout << "\t请输入售出价："; 
		cin >> saleprice;
	}
	//剩余商品数量
	void InputAmount()
	{
		cout << "\t请输入剩余商品数量："; 
		cin >> amount;
	}
	//输入净利润
	void InputProfit()
	{
		cout << "\t请输入净利润："; 
		cin >> profit;
	}
	//输入生产厂家
	void InputManufacturers()
	{
		cout << "\t请输入生产厂家："; 
		cin >> manufacturers;
	}
	//输入生产商品牌
	void Inputbrand()
	{
		cout << "\t请输入生产商品牌："; 
		cin >> brand;
	}
	//其它信息输入
	void InputOther()
	{
		cout << "\t请输入进货价："; 
		cin >> buyprice;
		cout << "\t请输入售出价："; 
		cin >> saleprice;
		cout << "\t请输入存货数量："; 
		cin >> amount;
		cout << "\t请输入生产厂家："; 
		cin >> manufacturers;
		cout << "\t请输入生产商品牌："; 
		cin >> brand;
		profit = 0;
	}
	//将输入的东西存入文件
	void ReadFile(istream & in) 
	{
		in >> kind >> name >> Id >> buyprice >> saleprice >> amount >> manufacturers >> brand >> profit;
	}
	//输出商品信息
	void Show()
	{
		cout << "种类:" << kind << endl;
		cout << "商品名: " << name << endl;
		cout << "编号: " << Id << endl;
		cout << "进货价 " << buyprice << endl;
		cout << "售出价 " << saleprice << endl;
		cout << "库存量: " << amount << endl;
		cout << "净利润：" << profit << endl;
		cout << "生产厂家: " << manufacturers << endl;
		cout << "生产商品牌: " << brand << endl << endl << endl;
	}
};
//Goodsmessage类
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
		system("cls"); //起清除屏幕的作用
		i = 0;
		for (Goods * p = Head->Next; p != End; p = p->Next)
		{
			p->Show();
			i++;
		}
		cout << "共有" << i << "个商品" << "\n" << endl;
		cout << "输入任意字符！继续……";
		getch();
	}
	//从键盘输入商品信息 添加商品信息
	void AddItem()
	{
		system("cls"); //起清除屏幕的作用
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
		cout << "添加成功!" << endl;
		Save();
		cout << "输入任意字符！继续……";
		getch();
	}
private:
	Goods * Head, *End;
	int i;
	ifstream in;
	ofstream out;
	Goods *FindItem(char * name)
	{
		for (Goods * p = Head; p->Next != End; p = p->Next)//匹配成功则返回上一个指针，不成功就返回空
		if (!strcmp(p->Next->name, name))return p;
		return NULL;
	}
	Goods *FindID(char * Id)
	{
		for (Goods * p = Head; p->Next != End; p = p->Next)//匹配成功则返回上一个指针，不成功就返回空
		if (!strcmp(p->Next->Id, Id))return p;
		return NULL;
	}
	/*Goods *Findkind(int * kind)
	{
	for(Goods * p=Head;p->Next!=End;p=p->Next)//匹配成功则返回上一个指针，不成功就返回空
	if(!strcmp(p->Next->kind,kind))return p;
	return NULL;
	}*/
	Goods *Findmanufacturers(char * manufacturers)
	{
		for (Goods * p = Head; p->Next != End; p = p->Next)//匹配成功则返回上一个指针，不成功就返回空
		if (!strcmp(p->Next->manufacturers, manufacturers))return p;
		return NULL;
	}
};
//构造函数
Goodsmessage::Goodsmessage()                 
{
	Head = new Goods;
	Head->Next = new Goods;
	End = Head->Next;
	in.open("supermarket.txt");
	if (!in)
		cout << "无商品信息，请先进货。" << endl; //提示信息
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
		cout << "\n\t\t\t\t\t读取商品信息成功!" << "\n" << endl; //提示信息
	}
}
//析构函数
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
//菜单
void Goodsmessage::showMenu(int n)//菜单      
{
	switch (n)
	{
	case 1:
	{
			  cout << "\t+-----------------------------------------------------------+\n"
				  <<  "\t|    1. 食品      2. 化妆品      3. 日用品      4. 饮料     |\n"
				  <<  "\t+-----------------------------------------------------------+\n" << endl;
			  break; }
	case 2:
	{
			  system("cls"); //起清除屏幕的作用
			  cout << "\t\t+-----------------  超 市 商 品 管 理 系  统  -------------------+" << endl;
			  cout << "\t\t|                             1.添加超市商品                     |" << endl;
			  cout << "\t\t|                             2.显示超市商品                     |" << endl;
			  cout << "\t\t|                             3.查询统计商品                     |" << endl;
			  cout << "\t\t|                             4.修改超市商品                     |" << endl;
			  cout << "\t\t|                             5.删除超市商品                     |" << endl;
			  cout << "\t\t|                             6.排序超市商品                     |" << endl;
			  cout << "\t\t|                             7.售出超市商品                     |" << endl;
			  cout << "\t\t|                             8.保存商品信息                     |" << endl;
			  cout << "\t\t|                             0.安全退出系统                     |" << endl;
			  cout << "\t\t+----------------------------------------------------------------+" << endl;
			  cout << "\t\t\n\t\t\t\t  请选择(1-8)：" << endl;
			  break; }
	case 3:
	{
			  system("cls"); //起清除屏幕的作用
			  cout << "\n\t\t+-------------------------------+" << endl;
			  cout << "\t\t|\t 1.按商品类别查找\t|" << endl;
			  cout << "\t\t|\t 2.按商品名称查找\t|" << endl;
			  cout << "\t\t|\t 3.按生产厂家查找\t|" << endl;
			  cout << "\t\t+-------------------------------+\n请选择(1-3)：";
			  break;
	}
	case 4:
	{
			  system("cls");  //起清除屏幕的作用
			  cout << "\t+---------------------------------------------------------------+" << endl;
			  cout << "\t|   1. 修改商品名      2. 修改编号           3. 生产厂家\t|" << endl;
			  cout << "\t|   4. 修改品牌        5. 修改售出价         6. 修改进货价\t|" << endl;
			  cout << "\t|   7. 修改库存量      8. 修改类别           9. 修改全部\t|" << endl;
		      cout << "\t+---------------------------------------------------------------+" << endl;
			  cout << "\t\t\n\t\t\t\t  请选择(1-9)：" << endl;
			  break;
	}
	case 5:
	{
			  system("cls");  //起清除屏幕的作用
			  cout << "\n\t+-----------------------------------------------------------------------+" << endl;
			  cout << "\t|   1. 按进货价排序        2. 按库存量排序       3. 按生产厂家排序\t|" << endl;
		      cout << "\t+-----------------------------------------------------------------------+" << endl;
			  cout << "\t\t\n\t\t  请选择(1-3)：" << endl;
			  break;
	}
	}
}
//查找函数
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
		/* case 1:{cout<<"\t\t请输入要查找的商品的类别：";cin>>kind;
		if(p=Findkind(kind))
		{
		p->Next->Show();
		cout<<"输入任意字符！继续……";
		getch();
		}
		else
		{
		cout<<"\t\t该记录不存在！"<<'\n'<<endl;
		cout<<"输入任意字符！继续……";
		getch();
		}
		}break;*/
	case 2:{cout << "\t\t请输入要查找的商品的名称："; cin >> name;
		if (p = FindItem(name))
		{
			p->Next->Show();
			cout << "输入任意字符！继续……";
			getch();
		}
		else
		{
			cout << "\t\t该记录不存在！" << '\n' << endl;
			cout << "输入任意字符！继续……";
			getch();
		}
	}break;
	case 3:
	{
			  cout << "\t\t请输入要查找的商品的生产厂家："; cin >> manufacturers;
			  if (p = Findmanufacturers(manufacturers))
			  {
				  p->Next->Show();
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  else
			  {
				  cout << "\t\t该记录不存在！" << '\n' << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
	}break;
	}
}
//修改商品信息
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
			  cout << "\t\t请输入要修改的商品的编号:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t已找到商品的信息，请输入新的信息!" << endl;
				  p->Next->InputName();
				  cout << "修改成功！" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  else
			  {
				  cout << "\t\t没有找到您需要的商品!" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  break;
	}
	case 2:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t请输入要修改的商品的编号:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t已找到商品的信息，请输入新的信息!" << endl;
				  p->Next->InputKind();
				  cout << "修改成功！" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  else
			  {
				  cout << "\t\t没有找到您需要的商品!" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  break;
	}
	case 3:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t请输入要修改的商品的编号:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t已找到商品的信息，请输入新的信息!" << endl;
				  p->Next->InputID();
				  cout << "修改成功！" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  else
			  {
				  cout << "\t\t没有找到您需要的商品!" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  break;
	}
	case 4:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t请输入要修改的商品的编号:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t已找到商品的信息，请输入新的信息!" << endl;
				  p->Next->InputBuyprice();
				  cout << "修改成功！" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  else
			  {
				  cout << "\t\t没有找到您需要的商品!" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  break;
	}
	case 5:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t请输入要修改的商品的编号:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t已找到商品的信息，请输入新的信息!" << endl;
				  p->Next->InputSaleprice();
				  cout << "修改成功！" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  else
			  {
				  cout << "\t\t没有找到您需要的商品!" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  break;
	}
	case 6:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t请输入要修改的商品的编号:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t已找到商品的信息，请输入新的信息!" << endl;
				  p->Next->InputAmount();
				  cout << "修改成功！" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  else
			  {
				  cout << "\t\t没有找到您需要的商品!" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  break;
	}
	case 7:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t请输入要修改的商品的编号:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t已找到商品的信息，请输入新的信息!" << endl;
				  p->Next->InputProfit();
				  cout << "修改成功！" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  else
			  {
				  cout << "\t\t没有找到您需要的商品!" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  break;
	}
	case 8:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t请输入要修改的商品的编号:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t已找到商品的信息，请输入新的信息!" << endl;
				  p->Next->Inputbrand();
				  cout << "修改成功！" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  else
			  {
				  cout << "\t\t没有找到您需要的商品!" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  break;
	}
	case 9:
	{
			  char Id[20];
			  Goods * p = NULL;
			  cout << "\t\t请输入要修改的商品的编号:"; cin >> Id;
			  if (p = FindID(Id))
			  {
				  cout << "\t\t已找到商品的信息，请输入新的信息!" << endl;
				  p->Next->Inputbrand();
				  cout << "修改成功！" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  else
			  {
				  cout << "\t\t没有找到您需要的商品!" << endl;
				  cout << "输入任意字符！继续……";
				  getch();
			  }
			  break;
	}
	case 10:
	{
			   char Id[20];
			   Goods * p = NULL;
			   cout << "\t\t请输入要修改的商品的编号:"; cin >> Id;
			   if (p = FindID(Id))
			   {
				   cout << "\t\t已找到商品的信息，请输入新的信息!" << endl;
				   p->Next->InputAll();
				   cout << "修改成功！" << endl;
				   cout << "输入任意字符！继续……";
				   getch();
			   }
			   else
			   {
				   cout << "\t\t没有找到您需要的商品!" << endl;
				   cout << "输入任意字符！继续……";
				   getch();
			   }
	}
	}
}
//删除商品信息
void Goodsmessage::RemoveItem()          
{
	system("cls");
	char Id[20];
	Goods * p = NULL, *temp = NULL;
	cout << "\t\t请输入要删除的商品的编号:" << endl; cin >> Id;
	if (p = FindID(Id))
	{
		temp = p->Next;
		p->Next = p->Next->Next;
		delete temp;
		cout << "\t\t删除成功!" << endl;
		cout << "输入任意字符！继续……";
		getch();
	}
	else
	{
		cout << "\t\t该商品不存在!" << endl;
		cout << "输入任意字符！继续……";
		getch();
	}
}
//售出商品
void Goodsmessage::Saleprice()           
{
	system("cls");
	char kind[20]; char name[20]; int i;
	Goods * p = NULL;
	Goods * temp = NULL;
	cout << "\t\t请输入要售出的商品的类别和名称:" << endl; cin >> kind; cin >> name;
	cout << "\t\t请输入要购买的数量:" << endl; cin >> i;

	if (p = FindItem(name))
	{
		cout << "商品信息为:" << endl;

		if (p->Next->amount>i)
		{
			p->Next->amount -= i;
			p->Next->amount1 += i;
			p->Next->profit += i*(p->Next->saleprice - p->Next->buyprice);
			cout << "商品售出成功!" << "\n";
			cout << "售出商品名称: " << name << "\t" << "数量: " << i << "\n";
			cout << "\n";
			cout << "售出后商品信息: " << endl;

			p->Next->Show();
			Save();
			cout << "输入任意字符！继续……";
			getch();

		}
		else
		{
			cout << "商品数量不够，不能购买" << endl;
			cout << "输入任意字符！继续……";
			getch();
			Saleprice();
		}

	}
	else
	{
		cout << "无此种商品，不能购买" << endl;
		cout << "输入任意字符！继续……";
		getch();
		showMenu(2);
	}

}
//交换两个商品的数据
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
//统计当前链表的记录总数，返回一个整数
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
//排序商品
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
			  cout << "\t\t排序中..." << endl;
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
			  out.open("进货价.txt");
			  for (Goods *q = Head->Next; q != End; q = q->Next)
				  out << q->name << "\t" << q->kind << "\t" << q->Id << "\t" << q->buyprice << "\t" << q->saleprice << "\t" << q->amount << "\t" << q->manufacturers << "\t" << q->brand << "\t" << q->profit << '\n';
			  out.close();
			  cout << "保存信息成功" << endl;
			  cout << "排序完成！" << endl;
			  getch();
			  return;
	}
	case 2:
	{
			  system("cls");
			  cout << "\t\t排序中..." << endl;
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
			  out.open("库存量.txt");
			  for (Goods *q = Head->Next; q != End; q = q->Next)
				  out << q->name << "\t" << q->kind << "\t" << q->Id << "\t" << q->buyprice << "\t" << q->saleprice << "\t" << q->amount << "\t" << q->manufacturers << "\t" << q->brand << "\t" << q->profit << '\n';
			  out.close();
			  cout << "保存信息成功" << endl;
			  cout << "排序完成！" << endl;
			  getch();
			  return;
	}
	case 3:
	{
			  system("cls");
			  cout << "\t\t排序中..." << endl;
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
			  out.open("生产厂家.txt");
			  for (Goods *q = Head->Next; q != End; q = q->Next)
				  out << q->name << "\t" << q->kind << "\t" << q->Id << "\t" << q->buyprice << "\t" << q->saleprice << "\t" << q->amount << "\t" << q->manufacturers << "\t" << q->brand << "\t" << q->profit << '\n';
			  out.close();
			  cout << "保存信息成功" << endl;
			  cout << "排序完成！" << endl;
			  getch();
			  return;
	}
	}
}

//商品信息保存到文件函数
void Goodsmessage::Save()       
{
	out.open("supermarket.txt");
	for (Goods *p = Head->Next; p != End; p = p->Next)
		out << p->name << "\t" << p->kind << "\t" << p->Id << "\t" << p->buyprice << "\t" << p->saleprice << "\t" << p->amount << "\t" << p->manufacturers << "\t" << p->brand << "\t" << p->profit << '\n';

	out.close();
	cout << "商品信息存盘成功" << endl;
}

int main()
{
	//程序初始化界面
	for (int i = 0; i < 3; i++)
	{
		cout << "\t\t\t\t+----------------------------------------+" << endl;
	}
	cout << "\t\t\t\t| \t欢迎进入超市商品管理系统\t |" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "\t\t\t\t+----------------------------------------+" << endl;
	}
	Goodsmessage Grade; //创建类Grade会调用构造参数 其构造参数会返回相应的提示信息
	cout << "\n\t\t\t\t\t按任意键进入操作界面"; //输出提示信息
	getchar(); //从输入缓冲区读取吸收一个回车键
	int x; //此变量用来保存功能选择的值
	bool quit = false; //此变量用来确定是否退出系统 当为true时 退出系统
	while (!quit)
	{
		Grade.showMenu(2); //调用类Grade的菜单函数中的2 也就是操作界面
		cin >> x; //输入x  将要选择的功能对应的数字 保存在x中
		switch (x)
		{
		case 0:{quit = true; break; }        //安全退出系统
		case 1:{Grade.AddItem(); break; }    //添加超市商品
		case 2:{Grade.Display(); break; }    //显示超市商品
		case 3:{Grade.Find(); break; }       //查询统计商品
		case 4:{Grade.ModifyItem(); break; } //修改超市商品
		case 5:{Grade.RemoveItem(); break; } //删除商品
		case 6:{Grade.Paixu(); break; }      //排序超市商品
		case 7:{Grade.Saleprice(); break; }  //出售超市商品
		case 8:{Grade.Save(); break; }       //保存商品信息
		}
	}
	return 0;
}
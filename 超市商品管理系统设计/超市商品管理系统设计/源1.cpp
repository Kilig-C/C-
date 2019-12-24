#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <conio.h>//用getch();当用户按下某个字符时，函数自动读取，无需按回车。

using namespace std;

//商品类
class Goods
{
public:
	Goods() { } //构造函数
	int kind;//种类
	char name[20];//名字
	char Id[20];//编号
	char manufacturers[20];//生产厂家 
	char brand[10];//品牌
	float buyprice;  //进货价；
	float saleprice; //卖出价；
	int amount;  //存货数量；
	int amount1; //售货数量；
	int profit=0;  //净利润；
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
		bool b = true; //当输入的数字范围不合法时用来继续循环
		cout << "\t请选择种类：";
		do
		{
			cin >> kind;
			if (kind > 0 && kind <= 4)
			{
				b = false; //用来终止循环
			}
			if (b) //为true进入
			{
				cout << "\t输入的种类编号不合法，请重新输入：";
				fflush(stdin); //清空缓存区
			}
		} while (b); //为假时终止循环
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
		do
		{
			cin >> buyprice;
			if (buyprice <= 0)
			{
				cout << "\t输入的数字不合法，请重新输入：";
			}
		} while (buyprice <= 0);
	}
	//输入售出价
	void InputSaleprice()
	{
		cout << "\t请输入售出价：";
		do
		{
			cin >> saleprice;
			if (saleprice <= 0)
			{
				cout << "\t输入的数字不合法，请重新输入：";
			}
		} while (saleprice <= 0);
	}
	//剩余商品数量
	void InputAmount()
	{
		cout << "\t请输入剩余商品数量："; 
		do
		{
			cin >> amount;
			if (amount <= 0)
			{
				cout << "\t输入的数字不合法，请重新输入：";
			}
		} while (amount <= 0);
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
		do
		{
			cin >> buyprice;
			if (buyprice <= 0)
			{
				cout << "\t输入的数字不合法，请重新输入：";
				fflush(stdin); //清空缓存区
			}
		} while (buyprice <= 0);
		cout << "\t请输入售出价："; 
		do
		{
			cin >> saleprice;
			if (saleprice <= 0)
			{
				cout << "\t输入的数字不合法，请重新输入：";
				fflush(stdin); //清空缓存区
			}
		} while (saleprice <= 0);
		cout << "\t请输入存货数量：";
		do
		{
			cin >> amount;
			if (amount <= 0)
			{
				cout << "\t输入的数字不合法，请重新输入：";
			}
		} while (amount <= 0);
		cout << "\t请输入生产厂家："; 
		cin >> manufacturers;
		cout << "\t请输入生产商品牌："; 
		cin >> brand;
		//每件商品净利润
		profit = saleprice - buyprice;
	}
	//将输入的东西存入文件
	void ReadFile(istream & in) 
	{
		in >> kind >> name >> Id >> buyprice >> saleprice >> amount >> manufacturers >> brand >> profit;
	}
	//输出商品信息
	void Show1()
	{
		cout << endl << endl;
		cout << setw(12) << "种类" << setw(12) << "商品名" << setw(12) << "编号" << setw(12) << "进货价";
		cout << setw(12) << "售出价" << setw(12) << "库存量" << setw(12) << "净利润" << setw(16) << "生产厂家";
		cout << setw(16) << "生产商品牌" << endl;
	}
	void Show2()
	{
		cout << setw(12) << kind<< setw(12) << name << setw(12) << Id << setw(12) << buyprice;
		cout << setw(12) << saleprice << setw(12) << amount << setw(12) << profit << setw(16) << manufacturers;
		cout << setw(16) << brand << endl;
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
	//显示超市商品
	void Display()
	{
		system("cls"); //起清除屏幕的作用
		int j = 0;
		i = 0; //此处用来记录商品个数
		//将商品信息全部显示出来
		for (Goods * p = Head->Next; p != End; p = p->Next)
		{
			if(j==0)
			{
				p->Show1(); //显示商品信息
				j = 1;
			}
			p->Show2(); //显示商品信息
			i++;
		}
		cout << "\n\n\t共有 " << i << " 种商品" << "\n" << endl;
		cout << "\n\t输入任意字符，结束查询......";
		getch();
	}
	//从键盘输入商品信息 添加商品信息
	void AddItem()
	{
		system("cls"); //起清除屏幕的作用
		End->InputName(); //调用函数输入商品的名称
		showMenu(1); //调用菜单函数的选项1
		End->InputKind(); //调用函数输入选择的种类
		do
		{
			End->InputID();
			if (FindID(End->Id))
			{
				cout << "\t该编号已经存在！" << endl;
			}
		} while (FindID(End->Id)); //用来判断编号是否已经存在
		End->InputOther(); //其他信息的输入
		End->Next = new Goods; //创建一个新结点
		End = End->Next; //最后一个结点没有存储信息 用来下次添加另外的产品信息
		cout << "\t添加成功!" << endl;
		Save(); //存储信息
		cout << "\t输入任意字符！继续……";
		getch();
	}
private:
	Goods * Head, *End;
	int i;
	ifstream in;
	ofstream out;
	//匹配名称
	Goods *FindItem(char * name) 
	{
		//匹配成功则返回上一个指针，不成功就返回空
		for (Goods * p = Head; p->Next != End; p = p->Next)
		{
			if (!strcmp(p->Next->name, name))
			{
				return p;
			}
		}
		return NULL;
	}
	//匹配编号
	Goods *FindID(char * Id) 
	{
		//匹配成功则返回上一个指针，不成功就返回空
		for (Goods * p = Head; p->Next != End; p = p->Next)
		{
			//如果ID相同则返回0  !0为真 
			if (!strcmp(p->Next->Id, Id)) 
			{
				return p;
			}
		}
		return NULL;
	}
	//匹配产品种类
	Goods *Findkind(int kind)
	{
		//匹配成功则返回上一个指针，不成功就返回空
		for (Goods * p = Head; p->Next != End; p = p->Next)
		{
			if (p->Next->kind == kind)
			{
				return p;
			}
		}
		return NULL;
	}
	//匹配成产厂家
	Goods *Findmanufacturers(char * manufacturers) 
	{
		//匹配成功则返回上一个指针，不成功就返回空
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
//构造函数
Goodsmessage::Goodsmessage()                 
{
	Head = new Goods;
	Head->Next = new Goods;
	End = Head->Next;
	in.open("超市商品档案.txt");
	if (!in)
		cout << "无商品信息，请先进货。" << endl; //提示信息
	else
	{
		//当这个成员函数返回0的时候
		//就一直执行你while大括号内的语句
		//一直到返回其他值后才停止
		//然后就继续执行其他语句
		while (!in.eof())
		{
			End->ReadFile(in);
			if (End->name[0] == '\0')
			{
				break; //跳出循环
			}
			//if (in.fail()) break;
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
	Save();
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
			  cout << "\t\t\n\t\t\t\t  请选择(1-8)： ";
			  break; }
	case 3:
	{
			  system("cls"); //起清除屏幕的作用
			  cout << "\n\t\t+-------------------------------+" << endl;
			  cout << "\t\t|\t 1.按商品种类查找\t|" << endl;
			  cout << "\t\t|\t 2.按商品名称查找\t|" << endl;
			  cout << "\t\t|\t 3.按生产厂家查找\t|" << endl;
			  cout << "\t\t+-------------------------------+\n请选择(1-3)：";
			  break;
	}
	case 4:
	{
			  //system("cls");  //起清除屏幕的作用
			  cout << "\t+---------------------------------------------------------------+" << endl;
			  cout << "\t|   1. 修改商品名      2. 修改编号           3. 生产厂家\t|" << endl;
			  cout << "\t|   4. 修改品牌        5. 修改售出价         6. 修改进货价\t|" << endl;
			  cout << "\t|   7. 修改库存量      8. 修改种类                      \t|" << endl;
		      cout << "\t+---------------------------------------------------------------+" << endl;
			  cout << "\n\t  请选择要修改的信息的编号(1-8)： ";
			  break;
	}
	case 5:
	{
			  system("cls");  //起清除屏幕的作用
			  cout << "\n\t+-----------------------------------------------------------------------+" << endl;
			  cout << "\t|   1. 按进货价排序        2. 按库存量排序       3. 按净利润排序\t|" << endl;
		      cout << "\t+-----------------------------------------------------------------------+" << endl;
			  cout << "\t\t\n\t\t  请选择(1-3)： ";
			  break;
	}
	}
}
//查找函数
void Goodsmessage::Find()       
{
	system("cls"); //清除屏幕
	char name[20], manufacturers[20];
	int kind;
	int x,j;
	Goods * p = NULL;
	showMenu(3); //函数调用 菜单函数的3
	cin >> x; //输入选择的查找方式的编号
	while (x <= 0 || x > 3)
	{
		cout << "输入的数字不合法！请重新选择（1-3）：";
		cin >> x;
	}
	switch (x)
	{
		case 1:
		{
				  j = 0;
				  cout<<"请输入要查找的商品的种类：";
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
					  cout << "一共有" << j << "条数据" << endl;
				  }
				  else
				  {
					  cout << "该记录不存在！" << '\n' << endl;
				  }
				  cout << "\n\n输入任意字符，继续程序......";
				  getch();
		}break;
		case 2:
		{
			  cout << "请输入要查找的商品的名称："; 
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
				  cout << "一共有" << j << "条数据" << endl;
			  }
			  else
			  {
				  cout << "该记录不存在！" << '\n' << endl;
			  }
			  cout << "\n\n输入任意字符，继续程序......";
			  getch();
		}break;
		case 3:
		{
			  cout << "请输入要查找的商品的生产厂家："; 
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
				  cout << "一共有" << j << "条数据" << endl;
			  }
			  else
			  {
				  cout << "该记录不存在！" << '\n' << endl;
			  }
			  cout << "\n\n输入任意字符，继续程序......";
			  getch();
		}break;
	}
}
//修改商品信息
void Goodsmessage::ModifyItem()         
{
	system("cls");
	char kind[20]; char name[20]; int i;
	Goods * p = NULL;
	Goods * temp = NULL;
	cout << "请输入要修改的商品的种类：";
	cin >> kind;
	cout << "请输入要修改的商品的名称：";
	cin >> name;
	if (p = FindItem(name)) //看此商品是否存在
	{
		//商品存在进行下面的操作
		cout << "该商品存在\n信息如下所示：";
		p->Next->Show1();
		p->Next->Show2();
		cout << endl;
		showMenu(4); //调用菜单函数中的4
		int x;
		cin >> x;//输入选择编号
		while (x <= 0 || x > 8)
		{
			cout << "输入的数字不合法！请重新选择（1-8）：";
			cin >> x;
		}
		switch (x)
		{
		case 1://修改的商品的名称
			p->Next->InputName();
			break;
		case 2://修改编号
			p->Next->InputID();
			break;
		case 3://生产厂家
			 p->Next->InputManufacturers();
			 break;
		case 4://修改的商品的品牌
			p->Next->Inputbrand();
			break;
		case 5://修改的商品的售出价
			p->Next->InputSaleprice();
			p->Next->profit = p->Next->saleprice - p->Next->buyprice;
			break;
		case 6://修改的商品的进货价
			p->Next->InputBuyprice();
			p->Next->profit = p->Next->saleprice - p->Next->buyprice;
			break;
		case 7://修改的商品的库存量
			p->Next->InputAmount(); 
			break;
		case 8://修改的商品的种类
			p->Next->InputKind(); 
			break;
		}
		cout << "修改成功！" << endl;
		cout << "如果要将修改的信息保存到文本文件中，请执行主菜单的功能8！" << endl;
		cout << "\n\n输入任意字符，继续程序......";
		getch();
	}
	else
	{
		cout << "无此种商品，无法修改信息！" << endl;
		cout << "\n\n输入任意字符，继续程序......";
		getch();
		showMenu(2);
	}

}
//删除商品信息
void Goodsmessage::RemoveItem()          
{
	system("cls"); //清除屏幕
	char Id[20];
	Goods * p = NULL, *temp = NULL;
	cout << "\t请输入要删除的商品的编号：  " ;
	cin >> Id;
	if (p = FindID(Id))
	{
		temp = p->Next;
		p->Next = p->Next->Next;
		delete temp;
		cout << "\t删除成功!" << endl;
		cout << "\n如果要将删除的数据从文本文件中也删除，请执行主菜单的功能8！";
		cout << "\n输入任意字符，继续程序......";
		getch();
	}
	else
	{
		cout << "\t该商品不存在!" << endl;
		cout << "\n\n输入任意字符，继续程序......";
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
	cout << "请输入要售出的商品的种类："; 
	cin >> kind; 
	cout << "请输入要售出的商品的名称：";
	cin >> name;
	if (p = FindItem(name)) //看此商品是否存在
	{
		cout << "请输入要购买的数量：";
		cin >> i;
		if (p->Next->amount >= i)
		{
			p->Next->amount -= i;
			p->Next->amount1 += i;
			p->Next->profit += i*(p->Next->saleprice - p->Next->buyprice);
			cout << "\n商品售出成功!" << "\n";
			cout << "售出商品名称: " << name << "\t" << "数量: " << i << endl << endl;
			cout << "售出后商品信息: " << endl;
			p->Next->Show1();
			p->Next->Show2();
			cout << endl;
			Save();
			cout << "\n\n输入任意字符，继续程序......";
			getch();

		}
		else
		{
			cout << "商品数量不够，不能购买" << endl;
			cout << "\n\n输入任意字符，继续程序......";
			getch();
			Saleprice();
		}

	}
	else
	{
		cout << "无此种商品，不能购买" << endl;
		cout << "\n\n输入任意字符，继续程序......";
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
	system("cls"); //清除屏幕
	showMenu(5);
	int x;
	cin >> x;
	while (x <= 0 || x > 3)
	{
		cout << "输入的数字不合法！请重新选择（1-3）：";
		cin >> x;
	}
	switch (x)
	{
	case 1://按进货价排序
	{
			  cout << "\t排序中..." << endl << endl;
			  Goods *p = NULL, *p1 = NULL, *k = NULL;
			  int n = Goodsmessage::ListCount();//统计当前链表的记录总数，返回一个整数
			  if (n < 2) 
			  {
				  return; //说明只有一条数据或者没有数据 就不用排序了
			  }
			  for (p = Head->Next; p != End; p = p->Next)
			  {
				  for (k = p->Next; k != End; k = k->Next)
				  {
					  if (p->buyprice > k->buyprice) //进价低的在前面
					  {
						  Goodsmessage::Swap(p, k);
					  }
				  }
			  }
			  out.open("进货价.txt");
			  for (Goods *q = Head->Next; q != End; q = q->Next)
			  {
				  out << q->name << "\t" << q->kind << "\t" << q->Id << "\t" << q->buyprice << "\t" << q->saleprice << "\t" << q->amount << "\t" << q->manufacturers << "\t" << q->brand << "\t" << q->profit << '\n';
			  }
			  out.close();
			  cout << "\n排序完成！" << endl;
			  cout << "保存信息成功" << endl;
			  getch();
			  return;
	}
	case 2://按库存量排序
	{
			  cout << "\t排序中..." << endl << endl;
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
					  if (p->amount > k->amount)//库存少的在前面
					  {
						  Goodsmessage::Swap(p, k);
					  }
				  }
			  }
			  out.open("库存量.txt");
			  for (Goods *q = Head->Next; q != End; q = q->Next)
			  {
				  out << q->name << "\t" << q->kind << "\t" << q->Id << "\t" << q->buyprice << "\t" << q->saleprice << "\t" << q->amount << "\t" << q->manufacturers << "\t" << q->brand << "\t" << q->profit << '\n';
			  } 
			  out.close();
			  cout << "\n排序完成！" << endl;
			  cout << "保存信息成功" << endl;
			  getch();
			  return;
	}
	case 3://按净利润排序
	{
			  cout << "\t排序中..." << endl << endl;
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
					  if (p->profit < k->profit) //利润多的在前面
					  {
						  Goodsmessage::Swap(p, k);
					  }
				  }
			  }
			  out.open("净利润.txt");
			  for (Goods *q = Head->Next; q != End; q = q->Next)
			  {
				  out << q->name << "\t" << q->kind << "\t" << q->Id << "\t" << q->buyprice << "\t" << q->saleprice << "\t" << q->amount << "\t" << q->manufacturers << "\t" << q->brand << "\t" << q->profit << '\n';
			  }
			  out.close();
			  cout << "\n排序完成！" << endl;
			  cout << "保存信息成功" << endl;
			  getch();
			  return;
	}
	}
}
//商品信息保存到文件函数
void Goodsmessage::Save()       
{
	out.open("超市商品档案.txt"); //打开文件
	for (Goods *p = Head->Next; p != End; p = p->Next)
	{
		out << p->kind << "\t" << p->name << "\t" << p->Id << "\t" << p->buyprice << "\t" << p->saleprice << "\t" << p->amount << "\t" << p->manufacturers << "\t" << p->brand << "\t" << p->profit << '\n';
	}
	out.close(); //关闭文件
	cout << "\t商品信息存盘成功" << endl;
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
	getch(); //从输入缓冲区读取吸收一个回车键
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
		case 8:{Grade.Save(); getch(); break; }  //保存商品信息
		}
		if(quit==true)
		{
			cout << "以安全退出，请按任意键关闭窗口！";
			//getch();
		}
	}
	return 0;
}
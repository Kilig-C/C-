/*
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
	Goods() {} //构造函数
	//每种商品都包含的信息有 商品名称 价格 库存量 生产厂家  品牌
	int kind; //商品种类
	char name[20];//名字
	char Id[20];//编号
	char manufacturers[20];//生产厂家 
	char brand[10];//品牌
	float buyprice;  //进货价；
	float saleprice; //卖出价；
	int amount;  //存货数量；
	int amount1; //售货数量；
	int profit;  //净利润；
	Goods * Next;
	//产品信息的录入
	void InputAll()
	{
		InputName();  //输入商品的名称
		InputKind();  //种类
		InputID();    //商品的编号
		InputOther(); // 其他信息输入
	}
	//种类
	void InputKind() 
	{
		cout << "\t\t请选择种类：";   cin >> kind;
	}
	//商品的名称
	void InputName() 
	{
		cout << "\t\t请输入商品的名称：";  cin >> name;
	}
	//商品的编号
	void InputID() 
	{
		cout << "\t\t请输入商品的编号：";  cin >> Id;
	}
	//进货价
	void InputBuyprice() 
	{
		cout << "\t\t请输入进货价："; cin >> buyprice;
	}
	//售出价
	void InputSaleprice() 
	{
		cout << "\t\t请输入售出价："; cin >> saleprice;
	}
	//剩余商品数量
	void InputAmount() 
	{
		cout << "\t\t请输入剩余商品数量："; cin >> amount;
	}
	//净利润
	void InputProfit() 
	{
		cout << "\t\t请输入净利润："; cin >> profit;
	}
	//生产厂家
	void InputManufacturers() 
	{
		cout << "\t\t请输入生产厂家："; cin >> manufacturers;
	}
	//生产商品牌
	void Inputbrand() 
	{
		cout << "\t\t请输入生产商品牌："; cin >> brand;
	}
	void InputOther()
	{
		cout << "\t\t请输入进货价："; cin >> buyprice;
		cout << "\t\t请输入售出价："; cin >> saleprice;
		cout << "\t\t请输入存货数量："; cin >> amount;
		cout << "\t\t请输入生产厂家："; cin >> manufacturers;
		cout << "\t\t请输入生产商品牌："; cin >> brand;
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
		cout << "种类:" << kind << endl << "商品名: " << name << endl << "编号: " << Id << endl << "进货价 " << buyprice << endl << "售出价 " << saleprice << endl << "库存量: " <<
			amount << endl << "净利润：" << profit << endl << "生产厂家: " << manufacturers << endl << "生产商品牌: " << brand << endl << endl << endl;
	}
};
*/

// 商品分为食品  化妆品 日用品 饮料
//每种商品都包含的信息有 商品名称 价格 库存量 生产厂家  品牌
//主要完成对商品的销售  统计  简单管理


/*
销售功能：
购买商品时，先输入类别，在输入商品名称，在库存中查找该商品的相关信息
如果有库存，则输入购买的数量 没有则不能输入 
如果库存不够给出提示信息  结束购买
*/

//添加功能：主要完成商品信息的添加。


//查询功能：可按商品类别、商品名称、生产厂家进行查询。
//若存在相应信息，输出所查询的信息，若不存在该记录，则提示“该记录不存在！”。


//修改功能：可根据查询结果对相应的记录进行修改。


//删除功能：主要完成商品信息的删除。先输入商品类别，再输入要删除的商品名称，
//根据查询结果删除该物品的记录，如果该商品不在物品库中，则提示“该商品不存在”。

//统计功能。
//输出当前库存中所有商品的总数及详细信息；可按商品的价格、库存量、
//生产厂家进行统计，输出统计信息时，要按从大到小进行排序（按厂家统计时除外）。


//商品信息存盘：将当前程序中的商品信息存入文件中。

//读出信息：从文件中将商品信息读入程序。


#include<iostream>
using namespace std;
#define MAX 1000

//1.建立菜单页面
void showMenu()
{
	cout << "*********************************" << endl;
	cout << "******    1,添加联系人     ******" << endl;
	cout << "******    2,显示联系人     ******" << endl;
	cout << "******    3,删除联系人     ******" << endl;
	cout << "******    4,查找联系人     ******" << endl;
	cout << "******    5,修改联系人     ******" << endl;
	cout << "******    6,清空联系人     ******" << endl;
	cout << "******    0,退出通讯录     ******" << endl;
	cout << "*********************************" << endl;
}

//创建联系人结构体
struct Person
{
	//姓名
	string m_Name;
	//性别 1 男 2 女
	int m_Sex;
	//年龄
	int m_Age;
	//电话
	string m_Phone;
	//地址
	string m_Addr;
};
//创建通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录联系人个数
	int m_Size;
	
};
//添加联系人
void addPerson(struct Addressbooks* abs)
{
	//1,先判断通讯录是否已满,如果满了就不能再添加了
	if (abs->m_Size == MAX) {
		cout << "通讯录已满,无法再添加!" << endl;
		return;
	}
	else {
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名:  " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别:  " << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{
			//设置死循环,只有输入1或者2才能退出循环
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误,请重新输入" << endl;
		}

		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//电话
		cout << "请输入联系电话" << endl;
		cout << "电话号应为7位或者11位" << endl;
		string phone;
		while (true) {
			cin >> phone;
			if (phone.length() == 11 || phone.length() == 7) {
				abs->personArray[abs->m_Size].m_Phone = phone;
				break;
			}
			cout << "请输入合法的中国大陆手机号" << endl;
		}

		//地址
		cout << "请输入联系人地址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		abs->m_Size++;
		cout << "添加联系人信息成功" << endl;

		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}

}
void showPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == 0) {
		cout << "当前通讯录为空" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "  姓名:  " << abs->personArray[i].m_Name << "\t";
			cout << "  性别:  " << (abs->personArray[i].m_Sex == 1 ? "男":"女" )<< "\t";
			cout << "  年龄:  " << abs->personArray[i].m_Age << "\t";
			cout << "  电话:  " << abs->personArray[i].m_Phone << "\t";
			cout << "  地址:  " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");//按任意键继续
	system("cls");//清屏操作
}

//检测联系人是否存在
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name) {
			return i;//查找到联系人,把下标返回
		}
	}
	return -1;
}
//封装删除函数
void deletePerson(Addressbooks* abs)
{
	cout << "请输入你要删除的联系人:" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	//ret == -1 查无此人
	//ret != -1 查有此人
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			//把后一个人的信息覆盖掉查的人,即可实现删除
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//封装查找联系人函数
void findPerson(Addressbooks* abs)
{
	cout << "请输入你要查找的联系人:  " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "  姓名:  " << abs->personArray[ret].m_Name << "\t";
		cout << "  性别:  " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "  年龄:  " << abs->personArray[ret].m_Age << "\t";
		cout << "  电话:  " << abs->personArray[ret].m_Phone << "\t";
		cout << "  地址:  " << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "没有找到此联系人" << endl;
	}
	system("pause");
	system("cls");
}
//封装修改联系人信息
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入你要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//姓名
		string name;
		cout << "请输入修改后的姓名: " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		cout << "请输入修改后的性别:  " << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{
			//设置死循环,只有输入1或者2才能退出循环
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误,请重新输入" << endl;
		}
		//年龄
		cout << "请输入修改后的年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//电话
		cout << "请输入修改后的联系电话" << endl;
		cout << "电话号应为7位或者11位" << endl;
		string phone;
		while (true) {
			cin >> phone;
			if (phone.length() == 11 || phone.length() == 7) {
				abs->personArray[ret].m_Phone = phone;
				break;
			}
			cout << "请输入合法的中国大陆手机号" << endl;
		}

		//地址
		cout << "请输入修改后的联系人地址" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "修改联系人信息成功" << endl;


	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//封装清空通讯录操作函数
void emptyPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "成功清空通讯录" << endl;
	system("pause");
	system("cls");
}
int main()
{		//创建通讯录结构体变量
		Addressbooks abs;
		//初始化通讯录中当前人员个数
		abs.m_Size = 0;
	while (true)
	{
		int select = 0;
		//菜单调用函数
		showMenu();
		cout << "请输入你要进行的操作:" << endl;
		cin >> select;
		switch (select)
		{
		case 1:			//1,添加联系人
			addPerson(&abs);
			break;
		case 2:			//2, 显示联系人
			showPerson(&abs);
			break;
		case 3:			//3,删除联系人
			//进行测试可不可以找到人:
		/* {
			cout << "请输入你想要删除的联系人:" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1) {
				cout << "查无此人" << endl;
			}
			else {
				cout << "查有此人" << endl;
			}
		}*/
			deletePerson(&abs);
			break;
		case 4:			//4,查找联系人
			findPerson(&abs);
			break;
		case 5:			//5,修改联系人
			modifyPerson(&abs);
			break;
		case 6:			//6, 清空联系人
		{
			cout << "请再次确认你是否需要清空通讯录" << endl;
			cout << "确认请按1,退出请按任意键" << endl;
			int Confirm;
			cin >> Confirm;
			if (Confirm == 1) {
				emptyPerson(&abs);
			}
			else {
				cout << "已经退出清空通讯录程序" << endl;
				system("pause");
				system("cls");
			}

		}
			break;
		case 0:			//0,退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}
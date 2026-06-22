#include<iostream>
using namespace std;
#include<string>
#include<limits>
#define MAX 100
//设计联系人结构体
struct person
{
	string m_name;
	int m_sex = 0;
	int m_age = 0;
	string m_phone;
	string m_add;
};

//设计通讯录的结构体
struct addressbooks
{
	//通讯录中保存的联系人数组
	struct person personArray[MAX];
	//通讯录中记录的联系人个数
	int m_size;
};

//1，添加联系人
void addperson(addressbooks* a)
{
	//判断通讯录是否已满
	if (a->m_size == MAX)
	{
		cout << "通讯录已满" << endl;
		return;
	}
	else 
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		a->personArray[a->m_size].m_name = name;

		cout << "请输入性别" << endl;
		cout << " 1--男" << endl;
		cout << " 2--女" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				a->personArray[a->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
			cin.clear();//清除输入错误的状态
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//清除输入错误的内容
		}

		cout << "请输入年龄" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				a->personArray[a->m_size].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
			cin.clear();//清除输入错误的状态
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//清除输入错误的内容
		}

		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;
		a->personArray[a->m_size].m_phone = phone;

		cout << "请输入家庭住址" << endl;
		string add;
		cin >> add;
		a->personArray[a->m_size].m_add = add;

		a->m_size++;//更新通讯录人数

		system("pause");
		system("cls");
	}
}

//2,显示所有联系人
void showperson(const addressbooks * a)
{
	//判断人数是否为0
	if (a->m_size == 0)
	{
		cout << "空" << endl;
	}
	else
	{
		for (int i = 0; i < a->m_size; i++)
		{
			cout << "姓名： " << a->personArray[i].m_name << endl;
			cout << "性别： " << (a->personArray[i].m_sex == 1 ? "男" :"女") << endl;
			cout << "年龄： " << a->personArray[i].m_age<< endl;
			cout << "电话： " << a->personArray[i].m_phone << endl;
			cout << "住址： " << a->personArray[i].m_add << endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在
int exist(const addressbooks * a, const string& name)
{
	for (int i = 0; i < a->m_size; i++)
	{
		if (a->personArray[i].m_name == name)
		{
			return i;
		}
	}
	return -1;//如果遍历没有找到，返回-1
}

//3,删除指定联系人
void deleteperson(addressbooks * a)
{ 
	cout << "输入你要删除的联系人" << endl;
	string name;
	cin >> name;
	int r = exist(a, name);

	if(r != -1)
	{
		for (int i = r; i < a->m_size; i++)
		{
			//数据前移
            a->personArray[i] = a->personArray[i + 1];
            a->m_size--;//更新人数
		}
		
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//4,查找指定联系人信息
void findperson(const addressbooks * a)
{
	cout << " 输入联系人" << endl;
	string name;
	cin >> name;

int r = exist(a, name);
	if (r != -1)
	{
		cout << "姓名： " << a->personArray[r].m_name << endl;
		cout << "性别： " << (a->personArray[r].m_sex == 1 ? "男" :"女") << endl;
		cout << "年龄： " << a->personArray[r].m_age << endl;
		cout << "电话： " << a->personArray[r].m_phone << endl;
		cout << "住址： " << a->personArray[r].m_add << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//5,修改联系人信息
/*void modifyperson(addressbooks* a)
{
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;

	int r = exist(a, name);

	if (r != -1)
	{
		string newname;
		cout << "newname:  " << endl;
		cin >> name;
		a->personArray[r].m_name = newname;


		cout << "sex:  " << endl;
		cout << "1--- 男" << endl;
		cout << "2--- 女" << endl;
		int sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				a->personArray[a->m_size].m_sex = sex;
				break;
			}
		}

		int age;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 150)
			{
				a->personArray[a->m_size].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
			cin.clear();//清除输入错误的状态
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//清除输入错误的内容
		}


		cout << "telephone number:  " << endl;
		string phone;
		cin >> phone;
		a->personArray[r].m_phone = phone;


		cout << "address:  " << endl;
		string add;
		cin >> add;
		a->personArray[r].m_add = add;

		cout << "修改成功" << endl;
	}
	system("pause");
	system("cls");
}*/

// 5. 修改联系人信息（支持选择性修改）
void modifyperson(addressbooks* a) {
	if (a->m_size == 0) {
		cout << "通讯录为空，无法修改！" << endl;
		system("pause");
		system("cls");
		return;
	}

	string name;
	cout << "请输入要修改的联系人姓名：";
	cin >> name;

	int index = exist(a, name);  // 查找联系人是否存在
	if (index == -1) {
		cout << "查无此人！" << endl;
		system("pause");
		system("cls");
		return;
	}

	// 显示当前信息
	cout << "\n当前联系人信息：" << endl;
	cout << "姓名：" << a->personArray[index].m_name << endl;
	cout << "性别：" << (a->personArray[index].m_sex == 1 ? "男" : "女") << endl;
	cout << "年龄：" << a->personArray[index].m_age << endl;
	cout << "电话：" << a->personArray[index].m_phone << endl;
	cout << "住址：" << a->personArray[index].m_add << endl;

	// 修改菜单
	int choice = -1;
	while (true) {
		cout << "\n请选择要修改的字段：" << endl;
		cout << "1. 姓名" << endl;
		cout << "2. 性别" << endl;
		cout << "3. 年龄" << endl;
		cout << "4. 电话" << endl;
		cout << "5. 住址" << endl;
		cout << "0. 退出修改（不保存改动）" << endl;
		cout << "请输入编号：";
		cin >> choice;

		switch (choice) {
		case 1: {  // 修改姓名
			string newName;
			cout << "原姓名：" << a->personArray[index].m_name << "，新姓名：";
			cin >> newName;
			a->personArray[index].m_name = newName;
			cout << "姓名修改成功！" << endl;
			break;
		}
		case 2: {  // 修改性别
			int sex;
			cout << "原性别：" << (a->personArray[index].m_sex == 1 ? "男" : "女") << endl;
			cout << "新性别（1-男，2-女）：";
			while (true) {
				cin >> sex;
				if (sex == 1 || sex == 2) {
					a->personArray[index].m_sex = sex;
					break;
				}
				cout << "输入无效，请重新输入（1 或 2）：";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "性别修改成功！" << endl;
			break;
		}
		case 3: {  // 修改年龄
			int age;
			cout << "原年龄：" << a->personArray[index].m_age << "，新年龄（1-120）：";
			while (true) {
				cin >> age;
				if (age >= 1 && age <= 120) {
					a->personArray[index].m_age = age;
					break;
				}
				cout << "年龄范围 1~120，请重新输入：";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "年龄修改成功！" << endl;
			break;
		}
		case 4: {  // 修改电话
			string phone;
			cout << "原电话：" << a->personArray[index].m_phone << "，新电话：";
			cin >> phone;
			a->personArray[index].m_phone = phone;
			cout << "电话修改成功！" << endl;
			break;
		}
		case 5: {  // 修改住址
			string add;
			cout << "原住址：" << a->personArray[index].m_add << "，新住址：";
			cin >> add;
			a->personArray[index].m_add = add;
			cout << "住址修改成功！" << endl;
			break;
		}
		case 0:
			cout << "放弃修改，已退出。" << endl;
			system("pause");
			system("cls");
			return;  // 直接退出函数，不保存任何改动
		default:
			cout << "输入无效，请输入 0~5 之间的数字！" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}

		// 修改完一项后，询问是否继续修改
		if (choice >= 1 && choice <= 5) {
			char cont;
			cout << "是否继续修改其他字段？(y/n)：";
			cin >> cont;
			if (cont != 'y' && cont != 'Y') {
				break;  // 退出修改循环
			}
		}
	}

	cout << "修改操作完成！" << endl;
	system("pause");
	system("cls");
}

//6,清空联系人
void cleanperson(addressbooks* a)
{
	a->m_size = 0;
	cout << "已清空" << endl;
	system("pause");
	system("cls");
}

//菜单界面
void menu()
{
	cout << "1,添加联系人" << endl;
	cout << "2,显示联系人" << endl;
	cout << "3,删除联系人" << endl;
	cout << "4,查找联系人" << endl;
	cout << "5,修改联系人" << endl;
	cout << "6,清空联系人" << endl;
	cout << "0,退出联系人" << endl;
}
int main()
{
	//创建结构体变量
	addressbooks a;
	//初始化通讯录当前人员个数
	a.m_size = 0;
	
	int select = 0;

	while (true)
	{
		//菜单调用
		menu();

		cin >> select;
		switch (select)
		{
		case 1:
			addperson(&a);//地址传递，修饰实参
			break;
		case 2:
			showperson(&a);
			break;
		case 3:
			deleteperson(&a);
			break;
		case 4:
			findperson(&a);
			break;
		case 5:
			modifyperson(&a);
			break;
		case 6:
			cleanperson(&a);
			break;
		case 0:
			cout << "再见" << endl;
			return 0;
		default:
			cout << "输入无效，请重新输入" << endl;
			cin.clear();//清除输入错误的状态
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("pause");
			system("cls");
			break;
		}
	}
    return 0;
}
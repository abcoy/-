#include"addressbook.h"
using namespace std;

int  main() {
	
	showMenu();
	int choice;
	int index;
	cout << "请输入你想要选择的功能: ";
	cin >> choice;
	vector<Person>allperson;
	while (1)
	{
		if (0 <= choice && choice <= 10)
		{
			switch (choice)
			{
			case 0:ExiteProgramer(allperson); break;
			case 1:AddPerson(allperson); break;
			case 2:PrinallPeople(allperson); break;
			case 3:delete_a_person(allperson); break;
			case 4:index = Find(allperson); allperson[index].Print(); break;
			case 5:change_a_person(allperson); break;
			case 6:Clearaddressbook(allperson); break;
			case 7:ReadPerson(allperson); break;
			case 8:CallaPerson(); break;
			case 9:Sort(allperson); break;
			case 10:Output_info_befor(allperson); break;
			}
		}
		cout << "请输入你想要选择的功能:  ";
		cin >> choice;
	}
	
	return 0;
}

/*vector<Person>allperson;
	Person p("C++", 1, 19, "19147019624", "ssssssss");
	allperson.push_back(p);
	for (int i = 0; i < 3; i++)
	{
		Person p("C++"+i, 1, i + 19, "19147019624", "ssssssss");
		allperson.push_back(p);
	}
	auto ptr = remove(allperson.begin(), allperson.end(), p);
	allperson.erase(ptr, allperson.end());
	for (auto x : allperson)
		x.Print();*/

//int main(void)
//{
//	while (1)
//	{
//		ReadAcquire8("123123123211");
//		/*Beep(440, 1000);*/
//		Sleep(1000);//放慢程序运行的速度
//	}
//}


//#include<iostream>
//using namespace std;
//#include<string>
//#define MAX 1000
//
//
//// 设计联系人结构体
//struct Person
//{
//	// 姓名
//	string m_Name;
//	// 性别  1:男  2:女
//	int m_sex;
//	// 年龄
//	int m_age;
//	// 电话
//	string m_Phone;
//	// 住址
//	string m_Addr;
//};
//
//struct Addressbooks
//{
//	// 通讯录中保存的联系人数组
//	struct Person personArray[MAX];
//
//	// 通讯录中当前记录联系人个数
//	int m_size;
//};
//
//
//// 1.菜单页面
//void showMenu()
//{
//	cout << "*****************************" << endl;
//	cout << "*****	 1:添加联系人	*****" << endl;
//	cout << "*****	 2:显示联系人	*****" << endl;
//	cout << "*****	 3:删除联系人	*****" << endl;
//	cout << "*****	 4:查找联系人	*****" << endl;
//	cout << "*****	 5:修改联系人	*****" << endl;
//	cout << "*****	 6:清空联系人	*****" << endl;
//	cout << "*****	 0:退出通讯录	*****" << endl;
//	cout << "*****************************" << endl;
//}
//
//// 2.添加联系人
//void addPerson(Addressbooks* abs)
//{
//	// 判断通讯录是否已满
//	if (abs->m_size == MAX)
//	{
//		cout << "通讯录已满，无法添加" << endl;
//		return;
//	}
//	else
//	{
//		// 姓名
//		string name;
//		cout << "请输入姓名：" << endl;
//		cin >> name;
//		abs->personArray[abs->m_size].m_Name = name;
//
//		// 性别
//		cout << "请输入性别（1:男  2:女）：" << endl;
//		int sex = 0;
//
//		while (true)
//		{
//			cin >> sex;
//			if (sex == 1 || sex == 2)
//			{
//				abs->personArray[abs->m_size].m_sex = sex;
//				break;
//			}
//			cout << "输入有误，请重新输入" << endl;
//		}
//
//		// 年龄
//		int age;
//		cout << "请输入年龄：" << endl;
//		while (true)
//		{
//			cin >> age;
//			if (age >= 0 && age <= 120)
//			{
//				abs->personArray[abs->m_size].m_age = age;
//				break;
//			}
//			cout << "输入有误，请重新输入" << endl;
//		}
//
//		// 电话
//		string phone;
//		cout << "请输入电话：" << endl;
//		cin >> phone;
//		abs->personArray[abs->m_size].m_Phone = phone;
//
//		// 地址
//		string address;
//		cout << "请输入地址：" << endl;
//		cin >> address;
//		abs->personArray[abs->m_size].m_Addr = address;
//
//		// 更新通讯录人数
//		abs->m_size++;
//
//		cout << "添加成功" << endl;
//
//		system("pause");	// 按下任意键继续
//		system("cls");		// 清屏
//	}
//}
//
//// 显示联系人
//void showPerson(Addressbooks* abs)
//{
//	// 判断通讯录中人数是否为0
//	if (abs->m_size == 0)
//	{
//		cout << "通讯录为空" << endl;
//		return;
//	}
//	else
//	{
//		for (int i = 0; i < abs->m_size; i++)
//		{
//			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
//			cout << "性别(1:男  2:女)：" << (abs->personArray[i].m_sex == 1 ? "男" : "女") << "\t";
//			cout << "年龄：" << abs->personArray[i].m_age << "\t";
//			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
//			cout << "地址" << abs->personArray[i].m_Addr << endl;
//		}
//	}
//	system("pause");
//	system("cls");
//}
//
//// 检测联系人是否存在，存在返回编号，不存在返回-1
//int isExit(Addressbooks* abs, string name)
//{
//	for (int i = 0; i < abs->m_size; i++)
//	{
//		if (abs->personArray[i].m_Name == name)
//		{
//			return i;
//		}
//
//	}
//	return -1;
//}
//
//// 删除指定联系人
//void deletePerson(Addressbooks* abs)
//{
//	cout << "请输入删除联系人姓名：" << endl;
//	string name;
//	cin >> name;
//
//	int judge;
//	judge = isExit(abs, name);
//	if (judge == -1)
//	{
//		cout << "查无此人" << endl;
//	}
//	else
//	{
//		// 数据前移
//		for (int i = judge; i < abs->m_size; i++)
//		{
//			abs->personArray[i] = abs->personArray[i + 1];
//		}
//		abs->m_size--;
//		cout << "删除成功" << endl;
//	}
//	system("pause");
//	system("cls");
//}
//
//// 查找指定联系人
//void findPerson(Addressbooks* abs)
//{
//	cout << "请输入查找的联系人姓名：" << endl;
//	string name;
//	cin >> name;
//
//	int judge;
//	judge = isExit(abs, name);
//	if (judge == -1)
//	{
//		cout << "查无此人" << endl;
//	}
//	else
//	{
//		cout << "姓名：" << abs->personArray[judge].m_Name << endl;
//		cout << "性别(1:男  2:女)：" << (abs->personArray[judge].m_sex == 1 ? "男" : "女") << endl;
//		cout << "年龄：" << abs->personArray[judge].m_age << endl;
//		cout << "电话：" << abs->personArray[judge].m_Phone << endl;
//		cout << "地址" << abs->personArray[judge].m_Addr << endl;
//	}
//	system("pause");
//	system("cls");
//}
//
//// 更改指定联系人
//void modifyPerson(Addressbooks* abs)
//{
//	cout << "请输入更改的联系人姓名：" << endl;
//	string name;
//	cin >> name;
//
//	int judge;
//	judge = isExit(abs, name);
//	if (judge == -1)
//	{
//		cout << "查无此人" << endl;
//	}
//	else
//	{
//		while (true)
//		{
//			cout << "姓名：" << abs->personArray[judge].m_Name << endl;
//			cout << "性别(1:男  2:女)：" << (abs->personArray[judge].m_sex == 1 ? "男" : "女") << endl;
//			cout << "年龄：" << abs->personArray[judge].m_age << endl;
//			cout << "电话：" << abs->personArray[judge].m_Phone << endl;
//			cout << "地址" << abs->personArray[judge].m_Addr << "\n" << endl;
//
//			cout << "请输入要修改的内容\n1:姓名\t2:性别\t3:年龄\t4:电话\t5:地址\t0:退出" << endl;
//			int rev;
//			cin >> rev;
//			switch (rev)
//			{
//			case 1:
//			{
//				cout << "请输入更改后的姓名" << endl;
//				string new_name;
//				cin >> new_name;
//				abs->personArray[judge].m_Name = new_name;
//				break;
//			}
//			case 2:
//			{
//				cout << "请输入更改后的性别" << endl;
//				int new_sex;
//				while (true)
//				{
//					cin >> new_sex;
//					if (new_sex == 1 || new_sex == 2)
//					{
//						abs->personArray[judge].m_sex = new_sex;
//						break;
//					}
//					cout << "输入有误，请重新输入" << endl;
//				}
//				break;
//			}
//			case 3:
//			{
//				int new_age;
//				cout << "请输入更改后的年龄：" << endl;
//				while (true)
//				{
//					cin >> new_age;
//					if (new_age >= 0 && new_age <= 120)
//					{
//						abs->personArray[judge].m_age = new_age;
//						break;
//					}
//					cout << "输入有误，请重新输入" << endl;
//				}
//				break;
//			}
//			case 4:
//			{
//				string new_phone;
//				cout << "请输入更改后的电话：" << endl;
//				cin >> new_phone;
//				abs->personArray[judge].m_Phone = new_phone;
//				break;
//			}
//			case 5:
//			{
//				// 地址
//				string new_address;
//				cout << "请输入地址：" << endl;
//				cin >> new_address;
//				abs->personArray[judge].m_Addr = new_address;
//				break;
//			}
//			case 0:
//			{
//				cout << "修改完成" << endl;
//				system("pause");
//				system("cls");
//				return;
//			}
//			default:
//				break;
//			}
//
//			system("pause");
//			system("cls");
//		}
//	}
//}
//
//
//// 清空所有联系人
//void cleanPerson(Addressbooks* abs)
//{
//	cout << "是否确认清空，确认请按1，返回请按0" << endl;
//	int nub;
//	cin >> nub;
//	while (true)
//	{
//		if (nub == 1)
//		{
//			abs->m_size = 0;
//			cout << "所有联系人已清空" << endl;
//			system("pause");
//			system("cls");
//			return;
//		}
//		else if (nub == 0)
//		{
//			cout << "返回主菜单" << endl;
//			system("pause");
//			system("cls");
//			return;
//		}
//		else
//		{
//			cout << "请重新输入，确认请按1，返回请按0" << endl;
//			cin >> nub;
//		}
//	}
//}
//
//
//int main()
//{
//	// 创建通讯录结构体变量
//	Addressbooks abs;
//	// 初始化通讯录中当前人员个数
//	abs.m_size = 0;
//
//
//	int select = 0;		// 用户选择变量
//
//	while (true)
//	{
//		showMenu();
//
//		cin >> select;
//
//		switch (select)
//		{
//		case 1:		// 添加联系人
//			addPerson(&abs);
//			break;
//		case 2:		// 显示联系人
//			showPerson(&abs);
//			break;
//		case 3:		// 删除联系人
//			deletePerson(&abs);
//			break;
//		case 4:		// 查找联系人
//			findPerson(&abs);
//			break;
//		case 5:		// 修改联系人
//			modifyPerson(&abs);
//			break;
//		case 6:		// 清空联系人
//			cleanPerson(&abs);
//			break;
//		case 0:		// 退出通讯录
//		{
//			cout << "欢迎下次使用" << endl;
//			system("pause");
//			return 0;
//		}
//		default:
//			break;
//		}
//	}
//}
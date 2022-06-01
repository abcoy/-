//		system("pause");	// 按下任意键继续
//		system("cls");		// 清屏
#include"addressbook.h"
#include<cstring>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string>
Person::Person():m_Age(0),m_Sex(false)
{
	m_Name = m_Phone = m_Addr = nullptr;
	
}
Person::Person(const char* name, bool sex, int age, const char* phone, const char* addr):m_Sex(sex),m_Age(age)
{
	m_Name = new char[strlen(name) + 1];
	strcpy_s(m_Name, strlen(name) + 1, name);
	m_Phone = new char[strlen(phone) + 1];
	strcpy_s(m_Phone, strlen(phone) + 1, phone);
	m_Addr = new char[strlen(addr) + 1];
	strcpy_s(m_Addr, strlen(addr) + 1, addr);
}
Person::Person(const Person& p):m_Age(p.m_Age),m_Sex(p.m_Sex)
{
	m_Name = new char[strlen(p.m_Name) + 1];
	m_Phone = new char[strlen(p.m_Phone) + 1];
	m_Addr = new char[strlen(p.m_Addr) + 1];
	strcpy_s(m_Name, strlen(p.m_Name)+1, p.m_Name);
	strcpy_s(m_Phone, strlen(p.m_Phone) + 1, p.m_Phone);
	strcpy_s(m_Addr, strlen(p.m_Addr)+1, p.m_Addr);
}
Person::~Person()
{
	if (m_Name!=nullptr)
		delete []m_Name;
	if (m_Phone!=nullptr)
		delete []m_Phone;
	if (m_Addr!=nullptr)
		delete []m_Addr;
}
void Person::ResetName()
{
	cout << "请输入名字: ";
	cin >> m_Name;
}
void Person::ResetSex()
{
	string sex;
	cout << "请输入性别:";
	cin >> sex;
	if (sex == "男")
		m_Sex = false;
	else
		m_Sex = true;
}
void Person::ResetAge()
{
	cout << "请输入年龄: ";
	cin >> m_Age;
}
void Person::ResetPhone()
{
	cout << "请输入电话: ";
	cin >> m_Phone;
}
void Person::ResetAddr()
{
	cout << "请输入地址: ";
	cin >> m_Addr;
}
void Person::Print()const
{
	cout << "\n姓名: " << m_Name << endl;
	cout << "性别: ";
	if (m_Sex)
	{
		cout << "女\n";
	}
	else
	{
		cout << "男\n";
	}
	cout << "年龄: " << m_Age << endl;
	cout << "电话: " << m_Phone << endl;
	cout << "住址: " << m_Addr << endl;
}
const char* Person::GetName()const
{
	return m_Name;
}
const char* Person::GetPhone()const
{
	return m_Phone;
}
const char* Person::GetAddr()const
{
	return m_Addr;
}
int Person::GetAge()const
{
	return m_Age;
}
bool Person::GetSex()const
{
	return m_Sex;
}
bool Person::operator==(const Person& p)
{
	return strcmp(m_Name, p.m_Name)==0;
}
void Person::operator=(const Person& p)
{
	if (!m_Addr)
	{
		delete[]m_Addr;
		delete[]m_Name;
		delete[]m_Phone;
	}
	m_Addr = new char[strlen(p.m_Addr) + 1];
	strcpy_s(m_Addr, strlen(p.m_Addr) + 1, p.m_Addr);
	m_Name = new char[strlen(p.m_Name) + 1];
	strcpy_s(m_Name, strlen(p.m_Name) + 1, p.m_Name);
	m_Phone = new char[strlen(p.m_Phone) + 1];
	strcpy_s(m_Phone, strlen(p.m_Phone) + 1, p.m_Phone);
	m_Age = p.m_Age;
	m_Sex = p.m_Sex;
	
}
istream& operator>>(istream& is,  Person& p)
{
	if (!p.m_Name)
		delete []p.m_Name;
	if (!p.m_Addr)
		delete []p.m_Addr;
	if (!p.m_Phone)
		delete[]p.m_Phone;
	string temp;
	cout << "请输入姓名: ";
	is >> temp;
	p.m_Name = new char[strlen(temp.c_str()) + 1];
	strcpy_s(p.m_Name, strlen(temp.c_str()) + 1, temp.c_str());
	string sex;
	cout << "请输入性别:";
	is >> sex;
	if (sex == "男")
		p.m_Sex = false;
	else
		p.m_Sex = true;
	cout << "请输入年龄: ";
	is >> p.m_Age;
	cout << "请输入电话: ";
	is >> temp;
	p.m_Phone = new char[strlen(temp.c_str()) + 1];
	strcpy_s(p.m_Phone, strlen(temp.c_str()) + 1, temp.c_str());
	cout << "请输入地址: ";
	is >> temp;
	p.m_Addr = new char[strlen(temp.c_str()) + 1];
	strcpy_s(p.m_Addr, strlen(temp.c_str()) + 1, temp.c_str());
	return is;
}
ostream& operator<<(ostream& os, const Person& p)
{
	os << p.m_Name << "\t";
	if (p.m_Sex)
	{
		cout << "女\t";
	}
	else  
		cout << "男\t";
	cout << p.m_Age << "\t\t" << p.m_Phone << "\t" << p.m_Addr;
	return os;
 }


//朗读函数
void  MSSSpeak(LPCTSTR speakContent)// speakContent为LPCTSTR型的字符串,调用此函数即可将文字转为语音
{
	ISpVoice* pVoice = NULL;


	//初始化COM接口


	if (FAILED(::CoInitialize(NULL)))
		MessageBox(NULL, (LPCWSTR)L"COM接口初始化失败！", (LPCWSTR)L"提示", MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2);


	//获取SpVoice接口


	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);




	if (SUCCEEDED(hr))
	{
		pVoice->SetVolume((USHORT)100); //设置音量，范围是 0 -100
		pVoice->SetRate(0); //设置速度，范围是 -10 - 10
		hr = pVoice->Speak(speakContent, 0, NULL);

		pVoice->Release();

		pVoice = NULL;
	}


	//释放com资源
	::CoUninitialize();
}
//string转换车wstring  
std::wstring  StringToWString(const std::string& s)
{
	std::wstring wszStr;


	int nLength = MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, NULL, NULL);
	wszStr.resize(nLength);
	LPWSTR lpwszStr = new wchar_t[nLength];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), -1, lpwszStr, nLength);
	wszStr = lpwszStr;
	delete[] lpwszStr;
	return wszStr;
}
void read(string temp) {

	wstring a = StringToWString(temp);
	LPCWSTR str = a.c_str();
	MSSSpeak(str);
	/*cout << "";*///在这里朗读就结束了
}
////
// //
// 
// 1.菜单页面
void showMenu()
{
	system("color 0D");//设置控制为黑底紫字
	read("你好,我是cortana,通讯录语音助手,让我来帮助你");
	cout << "*****************************" << endl;
	cout << "*****	 0:退出通讯录	*****" << endl;
	cout << "*****	 1:添加联系人	*****" << endl;
	cout << "*****	 2:显示联系人	*****" << endl;
	cout << "*****	 3:删除联系人	*****" << endl;
	cout << "*****	 4:查找联系人	*****" << endl;
	cout << "*****	 5:修改联系人	*****" << endl;
	cout << "*****	 6:清空联系人	*****" << endl;
	cout << "*****	 7:朗读联系人	*****" << endl;
	cout << "*****	 8:拨打联系人	*****" << endl;//模拟拨打联系人
	cout << "*****	 9:排序联系人	*****" << endl;
	cout << "*****	10:查看已有联系人 ***" << endl;
	cout << "*****************************" << endl;
	read("输入你想要选择的功能");
}
void AddPerson(vector<Person>&allperson)
{
	read("请问你想添加多少人");
	cout << "请输入添加多少人: ";
	int numbers;
	cin >> numbers;
	cout << "请输入信息: \n";
	for (int i = 0; i < numbers; i++)
	{
		Person _people;
		cin >> _people;
		allperson.push_back(_people);
		if(i!=numbers-1)  
		cout << "输入下一个人的信息: \n";
	}
	
}


int Find(const vector<Person>&allperson)
{
	int choice;
	cout << "\n1.姓名\t2.电话\t3.地址\n";
	cin >> choice;
	int index = -1;
	while (1)
	{
		if (0 < choice && choice < 3)
		{
			switch (choice)
			{
			case 1:index =  find_By_Name(allperson); break;
			case 2:index =  find_By_Phone(allperson); break;
			case 3:index =  find_By_Addr(allperson); break;
			}
			break;
		}
		cout << "输入错误请重新输入: ";
		cin >> choice;
	}
	return index;
}
int find_By_Name(const vector<Person>& allperson)
{
	cout << "请输入要查找的名字: ";
	string name;
	cin >> name;
	for (int i = 0; i < allperson.size(); i++)
	{
		if (strcmp(name.c_str(), allperson[i].GetName()) == 0)
			return i;
	}
	return -1;
}
int find_By_Phone(const vector<Person>& allperson)
{
	cout << "请输入要查找的电话: ";
	string phone;
	cin >> phone;
	for (int i = 0; i < allperson.size(); i++)
	{
		if (strcmp(phone.c_str(), allperson[i].GetPhone()) == 0)
			return i;
	}
	return -1;
}
int find_By_Addr(const vector<Person>& allperson)
{
	cout << "请输入要查找的地址: ";
	string addr;
	cin >> addr;
	for (int i = 0; i < allperson.size(); i++)
	{
		if (strcmp(addr.c_str(), allperson[i].GetAddr()) == 0)
			return i;
	}
	return -1;
}
void delete_a_person(vector<Person>&allPerson)
{
	read("请选择你要按什么查找要删除的人: ");
	cout << "请选择你要按什么查找要删除的人: ";
	int index = Find(allPerson);
	if (index == -1)
	{
		cout << "没有找到该人!\n";
		read("没有找到该人");
		return;
	}
	else
	{
		string temp;
		read("是否删除该联系人？");
		cout << "是否删除该联系人？\n";
		cin >> temp;
		if (temp == "是" || temp == "要" || temp == "可以");
		{
			auto ptr = remove(allPerson.begin(), allPerson.end(), allPerson[index]);//remover 返回一个移除元素以后的尾迭代器
			allPerson.pop_back();
			read("删除成功!");
			cout << "删除成功!\n";
		}
	}
}
void changePart(Person& p)
{
	cout << "1.姓名\t2.性别\t3.年龄\n";
	cout << "4.电话\t5.地址\t\n";
	cout << "请问你要修改什么: ";
	int choice;
	cin >> choice;
	while (1)
	{
		if (0 < choice && choice < 6)
		{
			switch (choice)
			{
			case 1:p.ResetName(); break;
			case 2:p.ResetSex(); break;
			case 3:p.ResetAge(); break;
			case 4:p.ResetPhone(); break;
			case 5:p.ResetAddr(); break;
			}
			break;
		}
		cout << "输入错误请重新输入: ";
		cin >> choice;
	}
}
void changeAll(Person& p)
{
	cin >> p;
}
void change_a_person(vector<Person>& allperson)
{
	read("请选择你要按什么查找要修改的人: ");
	cout << "请选择你要按什么查找要修改的人: ";
	int index = Find(allperson);
	if (index == -1)
	{
		cout << "没有找到该人!\n";
		read("没有找到该人");
		return;
	}
	else
	{
		cout << "你想修改整体还是局部(1:整体|2:局部):  ";
		int choice;
		cin >> choice;
		while (1)
		{
			if (choice == 1)
			{
				changeAll(allperson[index]);
				break;
			}
			else if (choice == 2)
			{
				changePart(allperson[index]);
				break;
			}
			else
			{
				cout << "输入错误,请重新输入: ";
				cin >> choice;
			}
		}
	}
	read("修改成功!");
	cout << ("修改成功!\n");
}
void Clearaddressbook(vector<Person>& allperson)
{
	read("是否真的删除所有联系人?");
	read("一旦删除将无法恢复");
	cout << "是否真的删除所搜联系人?\n";
	cout << "一旦删除将无法恢复\n";
	string choice;
	cin >> choice;
	if (choice == "是")
	{
		
		for (int i = 0; i < allperson.size(); i++)
		{
			allperson.pop_back();
		}
		read("删除完毕!");
		cout << "删除完毕!\n";
	}
	else
	{
		read("好的,已经退出删除程序!");
		cout << "已经退出删除程序!\n";
	}
}
void PrinallPeople(const vector<Person>& allperson)
{
	if (allperson.size() == 0)
	{
		read("没有信息可以显示");
		cout << "没有信息可以显示\n";
		return;
	}
	cout << "姓 名\t" << "性 别\t" << "年 龄\t\t" << "电   话\t\t" << "住  址\n";
	for (int i = 0; i < allperson.size(); i++)
	{
		cout << allperson[i] << endl;
	}
}
void ReadPerson(const vector<Person>& allperson)
{
	
	for (int i = 0; i < allperson.size(); i++)
	{
		
		read("姓名");
		read(allperson[i].GetName());
		read("性别");
		if (allperson[i].GetSex())
			read("女");
		else
			read("男");
		read("年龄");
		string  age = to_string(allperson[i].GetAge());
		read(age.c_str());
		read("电话 ");
		read(allperson[i].GetPhone());
		read("住址");
		read(allperson[i].GetAddr());
		Sleep(1000);
	}
}
void CallaPerson()//模拟打电话无人接听
{
	cout << "请输入你要拨打的电话或者姓名:  ";
	string temp;
	cin >> temp;
	int i = 0;
	read("正在拨打 ");
	read(temp.c_str());
	while (i < 10)
	{
		Beep(440, 1250);
		Sleep(1000);
		i++;
	}
	i = 0;
	while (i < 2)
	{
		read("您好,您所拨打的电话暂时无人接听，请稍后再拨");
		read("The number you dialed can't be connected for the moment, please redial later");
		Sleep(500);
		i++;
	}
}
int choice;//作为选择switch
bool cmp(const Person& p1, const Person& p2)
{

	while (1)
	{
		if (choice > 0 && choice < 5)
		{
			switch (choice)
			{
			case 1:return strcmp(p1.GetName(), p2.GetName())<0; break;
			case 2:return  p1.GetAge() > p2.GetAge(); break;
			case 3:return strcmp(p1.GetPhone(), p2.GetPhone()) < 0; break;
			case 4:return strcmp(p1.GetAddr(), p2.GetAddr()) < 0; break;
			}
			break;
		}
		cout << "输入错误请重新输入: ";
		cin >> choice;
	}
}
void Sort(vector<Person>& allperson)
{
	cout << "你想以什么方式进行排序?\n";
	read("你想以什么方式进行排序?");
	cout << "1.姓名\t2.年龄\t3.电话\t4.地址\n";
	cout << "请输入你的选择: ";
	cin >> choice;
	sort(allperson.begin(), allperson.end(), cmp);
}
bool Out_of_Info = false;
void Input_info_to_file(const vector<Person>& allperson)
{
	
	
	if (!Out_of_Info)//如果把文件里面的信息读出来了则要判断是追加还是不追加
	{
		ofstream fout("addressbook.txt", ios_base::out|ios_base::app);
		if (!fout.is_open())
		{
			read("尝试打开文件失败！");
			cout << "尝试打开文件失败！";
			return;
		}
		for (int i = 0; i < allperson.size(); i++)
		{
			fout << allperson[i].GetName() << "\t";
			if (allperson[i].GetSex())
			{
				fout << "女\t";
			}
			else
			{
				fout << "男\t";
			}
			fout << allperson[i].GetAge() << "\t";
			fout << allperson[i].GetPhone() << "\t";
			fout << allperson[i].GetAddr() << '\n';
		}
		read("已将全部信息输入文件");
		cout << "已将全部信息输入文件\n";
		fout.close();
	}
	else
	{
		ofstream fout("addressbook.txt", ios_base::out);
		if (!fout.is_open())
		{
			read("尝试打开文件失败！");
			cout << "尝试打开文件失败！";
			return;
		}
		for (int i = 0; i < allperson.size(); i++)
		{
			fout << allperson[i].GetName() << "\t";
			if (allperson[i].GetSex())
			{
				fout << "女\t";
			}
			else
			{
				fout << "男\t";
			}
			fout << allperson[i].GetAge() << "\t";
			fout << allperson[i].GetPhone() << "\t";
			fout << allperson[i].GetAddr() << '\n';
		}
		read("已将全部信息输入文件");
		cout << "已将全部信息输入文件\n";
		fout.close();
	}

	
}
//这个BUG再跟老师讨论一下交作业之前
void Output_info_befor(vector<Person>& allperson)
{
	ifstream fin("addressbook.txt", ios_base::in|ios_base::app);
	if (!fin.is_open())
	{
		read("尝试打开文件失败！");
		cout << "打开文件失败!\n";
		return;
	}
	char Buffer_Name[10];//作为缓冲区从文件里面读出内容放在这
	char Buffer_Phone[13];
	char Buffer_Addr[20];
	char Buffer_sex[4];
	int Age;
	bool Sex = false;
	while (!fin.eof())
	{

		fin >> Buffer_Name >> Buffer_sex>>Age>>Buffer_Phone>>Buffer_Addr;
		if (strcmp(Buffer_sex,"男")==0)
			Sex = false;
		else
			Sex = true;
		allperson.push_back(Person(Buffer_Name, Sex, Age, Buffer_Phone, Buffer_Addr));
	}
	cout << "文件内的信息如下: \n";
	allperson.pop_back();//有一个BUG不知道在哪里怎么改所以只能这样弥补错误,allperson里面总是多出一个容器对象那我就把他扔掉
	PrinallPeople(allperson);
	fin.close();
	Out_of_Info = true;
}
void ExiteProgramer(vector<Person>& allperson)
{
	read("是否保存信息？");
	cout << "是否保存信息: ";
	string temp;
	cin >> temp;
	if (temp == "是"||temp=="要"||temp == "可以")
	{
		Input_info_to_file(allperson);
	}
	read("正在退出程序,请稍等");
	read("我是cortana，通讯录语音助手");
	read("期待我们下次再见!");
	exit(0);
}


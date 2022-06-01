#include<iostream>
#include <sapi.h> //导入语音头文件
#include <string>
#include<vector>
#include <time.h>
#pragma comment(lib,"sapi.lib") //导入语音头文件库
using namespace std;
class Person
{
private:
	//姓名
	char* m_Name;
	//性别
	bool m_Sex;
	//年龄
	int m_Age;
	//电话
	char* m_Phone;
	//住址
	char* m_Addr;
public:
	Person();
	Person(const char* name, bool sex, int age, const char* phone, const char* addr);
	Person(const Person& p);
	~Person();
	void ResetName();
	void ResetSex();
	void ResetAge();
	void ResetPhone();
	void ResetAddr();
	void Print()const;
	const char* GetName()const;
	const char* GetPhone()const;
	const char* GetAddr()const;
	int GetAge()const;
	bool GetSex()const;
	bool operator==(const Person& p);
	void operator=(const Person& p);
	friend istream& operator>>(istream& is,  Person& p);
	friend ostream& operator<<(ostream& os, const Person& p);
};
//语音播报
void  MSSSpeak(LPCTSTR speakContent);
std::wstring  StringToWString(const std::string& s);
void read(string temp);
//菜单
void showMenu();
void ReadPerson(const vector<Person>& allperson);
void AddPerson(vector<Person>&);
void PrinallPeople(const vector<Person>&);
int find_By_Name(const vector<Person>&);
int find_By_Phone(const vector<Person>&);
int find_By_Addr(const vector<Person>&);
int Find(const vector<Person>&);
void delete_a_person(vector<Person>&);
void change_a_person( vector<Person>& allperson);
void changePart(Person&);
void changeAll(Person&);
void Clearaddressbook(vector<Person>& allperson);
void CallaPerson();//模拟打电话
bool cmp(const Person& p1, const Person& p2);//作为sort的一个比较函数参数
void Sort(vector<Person>& allperson);//排序函数
void Input_info_to_file(const vector<Person>& allperson);//将信息输入进入文件
void Output_info_befor(vector<Person>& allperson);//将信息从文件中读出
void ExiteProgramer(vector<Person>&allperson);//退出程序
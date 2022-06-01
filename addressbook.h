#include<iostream>
#include <sapi.h> //��������ͷ�ļ�
#include <string>
#include<vector>
#include <time.h>
#pragma comment(lib,"sapi.lib") //��������ͷ�ļ���
using namespace std;
class Person
{
private:
	//����
	char* m_Name;
	//�Ա�
	bool m_Sex;
	//����
	int m_Age;
	//�绰
	char* m_Phone;
	//סַ
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
//��������
void  MSSSpeak(LPCTSTR speakContent);
std::wstring  StringToWString(const std::string& s);
void read(string temp);
//�˵�
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
void CallaPerson();//ģ���绰
bool cmp(const Person& p1, const Person& p2);//��Ϊsort��һ���ȽϺ�������
void Sort(vector<Person>& allperson);//������
void Input_info_to_file(const vector<Person>& allperson);//����Ϣ��������ļ�
void Output_info_befor(vector<Person>& allperson);//����Ϣ���ļ��ж���
void ExiteProgramer(vector<Person>&allperson);//�˳�����
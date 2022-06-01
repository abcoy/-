//		system("pause");	// �������������
//		system("cls");		// ����
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
	cout << "����������: ";
	cin >> m_Name;
}
void Person::ResetSex()
{
	string sex;
	cout << "�������Ա�:";
	cin >> sex;
	if (sex == "��")
		m_Sex = false;
	else
		m_Sex = true;
}
void Person::ResetAge()
{
	cout << "����������: ";
	cin >> m_Age;
}
void Person::ResetPhone()
{
	cout << "������绰: ";
	cin >> m_Phone;
}
void Person::ResetAddr()
{
	cout << "�������ַ: ";
	cin >> m_Addr;
}
void Person::Print()const
{
	cout << "\n����: " << m_Name << endl;
	cout << "�Ա�: ";
	if (m_Sex)
	{
		cout << "Ů\n";
	}
	else
	{
		cout << "��\n";
	}
	cout << "����: " << m_Age << endl;
	cout << "�绰: " << m_Phone << endl;
	cout << "סַ: " << m_Addr << endl;
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
	cout << "����������: ";
	is >> temp;
	p.m_Name = new char[strlen(temp.c_str()) + 1];
	strcpy_s(p.m_Name, strlen(temp.c_str()) + 1, temp.c_str());
	string sex;
	cout << "�������Ա�:";
	is >> sex;
	if (sex == "��")
		p.m_Sex = false;
	else
		p.m_Sex = true;
	cout << "����������: ";
	is >> p.m_Age;
	cout << "������绰: ";
	is >> temp;
	p.m_Phone = new char[strlen(temp.c_str()) + 1];
	strcpy_s(p.m_Phone, strlen(temp.c_str()) + 1, temp.c_str());
	cout << "�������ַ: ";
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
		cout << "Ů\t";
	}
	else  
		cout << "��\t";
	cout << p.m_Age << "\t\t" << p.m_Phone << "\t" << p.m_Addr;
	return os;
 }


//�ʶ�����
void  MSSSpeak(LPCTSTR speakContent)// speakContentΪLPCTSTR�͵��ַ���,���ô˺������ɽ�����תΪ����
{
	ISpVoice* pVoice = NULL;


	//��ʼ��COM�ӿ�


	if (FAILED(::CoInitialize(NULL)))
		MessageBox(NULL, (LPCWSTR)L"COM�ӿڳ�ʼ��ʧ�ܣ�", (LPCWSTR)L"��ʾ", MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2);


	//��ȡSpVoice�ӿ�


	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);




	if (SUCCEEDED(hr))
	{
		pVoice->SetVolume((USHORT)100); //������������Χ�� 0 -100
		pVoice->SetRate(0); //�����ٶȣ���Χ�� -10 - 10
		hr = pVoice->Speak(speakContent, 0, NULL);

		pVoice->Release();

		pVoice = NULL;
	}


	//�ͷ�com��Դ
	::CoUninitialize();
}
//stringת����wstring  
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
	/*cout << "";*///�������ʶ��ͽ�����
}
////
// //
// 
// 1.�˵�ҳ��
void showMenu()
{
	system("color 0D");//���ÿ���Ϊ�ڵ�����
	read("���,����cortana,ͨѶ¼��������,������������");
	cout << "*****************************" << endl;
	cout << "*****	 0:�˳�ͨѶ¼	*****" << endl;
	cout << "*****	 1:�����ϵ��	*****" << endl;
	cout << "*****	 2:��ʾ��ϵ��	*****" << endl;
	cout << "*****	 3:ɾ����ϵ��	*****" << endl;
	cout << "*****	 4:������ϵ��	*****" << endl;
	cout << "*****	 5:�޸���ϵ��	*****" << endl;
	cout << "*****	 6:�����ϵ��	*****" << endl;
	cout << "*****	 7:�ʶ���ϵ��	*****" << endl;
	cout << "*****	 8:������ϵ��	*****" << endl;//ģ�Ⲧ����ϵ��
	cout << "*****	 9:������ϵ��	*****" << endl;
	cout << "*****	10:�鿴������ϵ�� ***" << endl;
	cout << "*****************************" << endl;
	read("��������Ҫѡ��Ĺ���");
}
void AddPerson(vector<Person>&allperson)
{
	read("����������Ӷ�����");
	cout << "��������Ӷ�����: ";
	int numbers;
	cin >> numbers;
	cout << "��������Ϣ: \n";
	for (int i = 0; i < numbers; i++)
	{
		Person _people;
		cin >> _people;
		allperson.push_back(_people);
		if(i!=numbers-1)  
		cout << "������һ���˵���Ϣ: \n";
	}
	
}


int Find(const vector<Person>&allperson)
{
	int choice;
	cout << "\n1.����\t2.�绰\t3.��ַ\n";
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
		cout << "�����������������: ";
		cin >> choice;
	}
	return index;
}
int find_By_Name(const vector<Person>& allperson)
{
	cout << "������Ҫ���ҵ�����: ";
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
	cout << "������Ҫ���ҵĵ绰: ";
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
	cout << "������Ҫ���ҵĵ�ַ: ";
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
	read("��ѡ����Ҫ��ʲô����Ҫɾ������: ");
	cout << "��ѡ����Ҫ��ʲô����Ҫɾ������: ";
	int index = Find(allPerson);
	if (index == -1)
	{
		cout << "û���ҵ�����!\n";
		read("û���ҵ�����");
		return;
	}
	else
	{
		string temp;
		read("�Ƿ�ɾ������ϵ�ˣ�");
		cout << "�Ƿ�ɾ������ϵ�ˣ�\n";
		cin >> temp;
		if (temp == "��" || temp == "Ҫ" || temp == "����");
		{
			auto ptr = remove(allPerson.begin(), allPerson.end(), allPerson[index]);//remover ����һ���Ƴ�Ԫ���Ժ��β������
			allPerson.pop_back();
			read("ɾ���ɹ�!");
			cout << "ɾ���ɹ�!\n";
		}
	}
}
void changePart(Person& p)
{
	cout << "1.����\t2.�Ա�\t3.����\n";
	cout << "4.�绰\t5.��ַ\t\n";
	cout << "������Ҫ�޸�ʲô: ";
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
		cout << "�����������������: ";
		cin >> choice;
	}
}
void changeAll(Person& p)
{
	cin >> p;
}
void change_a_person(vector<Person>& allperson)
{
	read("��ѡ����Ҫ��ʲô����Ҫ�޸ĵ���: ");
	cout << "��ѡ����Ҫ��ʲô����Ҫ�޸ĵ���: ";
	int index = Find(allperson);
	if (index == -1)
	{
		cout << "û���ҵ�����!\n";
		read("û���ҵ�����");
		return;
	}
	else
	{
		cout << "�����޸����廹�Ǿֲ�(1:����|2:�ֲ�):  ";
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
				cout << "�������,����������: ";
				cin >> choice;
			}
		}
	}
	read("�޸ĳɹ�!");
	cout << ("�޸ĳɹ�!\n");
}
void Clearaddressbook(vector<Person>& allperson)
{
	read("�Ƿ����ɾ��������ϵ��?");
	read("һ��ɾ�����޷��ָ�");
	cout << "�Ƿ����ɾ��������ϵ��?\n";
	cout << "һ��ɾ�����޷��ָ�\n";
	string choice;
	cin >> choice;
	if (choice == "��")
	{
		
		for (int i = 0; i < allperson.size(); i++)
		{
			allperson.pop_back();
		}
		read("ɾ�����!");
		cout << "ɾ�����!\n";
	}
	else
	{
		read("�õ�,�Ѿ��˳�ɾ������!");
		cout << "�Ѿ��˳�ɾ������!\n";
	}
}
void PrinallPeople(const vector<Person>& allperson)
{
	if (allperson.size() == 0)
	{
		read("û����Ϣ������ʾ");
		cout << "û����Ϣ������ʾ\n";
		return;
	}
	cout << "�� ��\t" << "�� ��\t" << "�� ��\t\t" << "��   ��\t\t" << "ס  ַ\n";
	for (int i = 0; i < allperson.size(); i++)
	{
		cout << allperson[i] << endl;
	}
}
void ReadPerson(const vector<Person>& allperson)
{
	
	for (int i = 0; i < allperson.size(); i++)
	{
		
		read("����");
		read(allperson[i].GetName());
		read("�Ա�");
		if (allperson[i].GetSex())
			read("Ů");
		else
			read("��");
		read("����");
		string  age = to_string(allperson[i].GetAge());
		read(age.c_str());
		read("�绰 ");
		read(allperson[i].GetPhone());
		read("סַ");
		read(allperson[i].GetAddr());
		Sleep(1000);
	}
}
void CallaPerson()//ģ���绰���˽���
{
	cout << "��������Ҫ����ĵ绰��������:  ";
	string temp;
	cin >> temp;
	int i = 0;
	read("���ڲ��� ");
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
		read("����,��������ĵ绰��ʱ���˽��������Ժ��ٲ�");
		read("The number you dialed can't be connected for the moment, please redial later");
		Sleep(500);
		i++;
	}
}
int choice;//��Ϊѡ��switch
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
		cout << "�����������������: ";
		cin >> choice;
	}
}
void Sort(vector<Person>& allperson)
{
	cout << "������ʲô��ʽ��������?\n";
	read("������ʲô��ʽ��������?");
	cout << "1.����\t2.����\t3.�绰\t4.��ַ\n";
	cout << "���������ѡ��: ";
	cin >> choice;
	sort(allperson.begin(), allperson.end(), cmp);
}
bool Out_of_Info = false;
void Input_info_to_file(const vector<Person>& allperson)
{
	
	
	if (!Out_of_Info)//������ļ��������Ϣ����������Ҫ�ж���׷�ӻ��ǲ�׷��
	{
		ofstream fout("addressbook.txt", ios_base::out|ios_base::app);
		if (!fout.is_open())
		{
			read("���Դ��ļ�ʧ�ܣ�");
			cout << "���Դ��ļ�ʧ�ܣ�";
			return;
		}
		for (int i = 0; i < allperson.size(); i++)
		{
			fout << allperson[i].GetName() << "\t";
			if (allperson[i].GetSex())
			{
				fout << "Ů\t";
			}
			else
			{
				fout << "��\t";
			}
			fout << allperson[i].GetAge() << "\t";
			fout << allperson[i].GetPhone() << "\t";
			fout << allperson[i].GetAddr() << '\n';
		}
		read("�ѽ�ȫ����Ϣ�����ļ�");
		cout << "�ѽ�ȫ����Ϣ�����ļ�\n";
		fout.close();
	}
	else
	{
		ofstream fout("addressbook.txt", ios_base::out);
		if (!fout.is_open())
		{
			read("���Դ��ļ�ʧ�ܣ�");
			cout << "���Դ��ļ�ʧ�ܣ�";
			return;
		}
		for (int i = 0; i < allperson.size(); i++)
		{
			fout << allperson[i].GetName() << "\t";
			if (allperson[i].GetSex())
			{
				fout << "Ů\t";
			}
			else
			{
				fout << "��\t";
			}
			fout << allperson[i].GetAge() << "\t";
			fout << allperson[i].GetPhone() << "\t";
			fout << allperson[i].GetAddr() << '\n';
		}
		read("�ѽ�ȫ����Ϣ�����ļ�");
		cout << "�ѽ�ȫ����Ϣ�����ļ�\n";
		fout.close();
	}

	
}
//���BUG�ٸ���ʦ����һ�½���ҵ֮ǰ
void Output_info_befor(vector<Person>& allperson)
{
	ifstream fin("addressbook.txt", ios_base::in|ios_base::app);
	if (!fin.is_open())
	{
		read("���Դ��ļ�ʧ�ܣ�");
		cout << "���ļ�ʧ��!\n";
		return;
	}
	char Buffer_Name[10];//��Ϊ���������ļ�����������ݷ�����
	char Buffer_Phone[13];
	char Buffer_Addr[20];
	char Buffer_sex[4];
	int Age;
	bool Sex = false;
	while (!fin.eof())
	{

		fin >> Buffer_Name >> Buffer_sex>>Age>>Buffer_Phone>>Buffer_Addr;
		if (strcmp(Buffer_sex,"��")==0)
			Sex = false;
		else
			Sex = true;
		allperson.push_back(Person(Buffer_Name, Sex, Age, Buffer_Phone, Buffer_Addr));
	}
	cout << "�ļ��ڵ���Ϣ����: \n";
	allperson.pop_back();//��һ��BUG��֪����������ô������ֻ�������ֲ�����,allperson�������Ƕ��һ�������������ҾͰ����ӵ�
	PrinallPeople(allperson);
	fin.close();
	Out_of_Info = true;
}
void ExiteProgramer(vector<Person>& allperson)
{
	read("�Ƿ񱣴���Ϣ��");
	cout << "�Ƿ񱣴���Ϣ: ";
	string temp;
	cin >> temp;
	if (temp == "��"||temp=="Ҫ"||temp == "����")
	{
		Input_info_to_file(allperson);
	}
	read("�����˳�����,���Ե�");
	read("����cortana��ͨѶ¼��������");
	read("�ڴ������´��ټ�!");
	exit(0);
}


#include"addressbook.h"
using namespace std;

int  main() {
	
	showMenu();
	int choice;
	int index;
	cout << "����������Ҫѡ��Ĺ���: ";
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
		cout << "����������Ҫѡ��Ĺ���:  ";
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
//		Sleep(1000);//�����������е��ٶ�
//	}
//}


//#include<iostream>
//using namespace std;
//#include<string>
//#define MAX 1000
//
//
//// �����ϵ�˽ṹ��
//struct Person
//{
//	// ����
//	string m_Name;
//	// �Ա�  1:��  2:Ů
//	int m_sex;
//	// ����
//	int m_age;
//	// �绰
//	string m_Phone;
//	// סַ
//	string m_Addr;
//};
//
//struct Addressbooks
//{
//	// ͨѶ¼�б������ϵ������
//	struct Person personArray[MAX];
//
//	// ͨѶ¼�е�ǰ��¼��ϵ�˸���
//	int m_size;
//};
//
//
//// 1.�˵�ҳ��
//void showMenu()
//{
//	cout << "*****************************" << endl;
//	cout << "*****	 1:�����ϵ��	*****" << endl;
//	cout << "*****	 2:��ʾ��ϵ��	*****" << endl;
//	cout << "*****	 3:ɾ����ϵ��	*****" << endl;
//	cout << "*****	 4:������ϵ��	*****" << endl;
//	cout << "*****	 5:�޸���ϵ��	*****" << endl;
//	cout << "*****	 6:�����ϵ��	*****" << endl;
//	cout << "*****	 0:�˳�ͨѶ¼	*****" << endl;
//	cout << "*****************************" << endl;
//}
//
//// 2.�����ϵ��
//void addPerson(Addressbooks* abs)
//{
//	// �ж�ͨѶ¼�Ƿ�����
//	if (abs->m_size == MAX)
//	{
//		cout << "ͨѶ¼�������޷����" << endl;
//		return;
//	}
//	else
//	{
//		// ����
//		string name;
//		cout << "������������" << endl;
//		cin >> name;
//		abs->personArray[abs->m_size].m_Name = name;
//
//		// �Ա�
//		cout << "�������Ա�1:��  2:Ů����" << endl;
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
//			cout << "������������������" << endl;
//		}
//
//		// ����
//		int age;
//		cout << "���������䣺" << endl;
//		while (true)
//		{
//			cin >> age;
//			if (age >= 0 && age <= 120)
//			{
//				abs->personArray[abs->m_size].m_age = age;
//				break;
//			}
//			cout << "������������������" << endl;
//		}
//
//		// �绰
//		string phone;
//		cout << "������绰��" << endl;
//		cin >> phone;
//		abs->personArray[abs->m_size].m_Phone = phone;
//
//		// ��ַ
//		string address;
//		cout << "�������ַ��" << endl;
//		cin >> address;
//		abs->personArray[abs->m_size].m_Addr = address;
//
//		// ����ͨѶ¼����
//		abs->m_size++;
//
//		cout << "��ӳɹ�" << endl;
//
//		system("pause");	// �������������
//		system("cls");		// ����
//	}
//}
//
//// ��ʾ��ϵ��
//void showPerson(Addressbooks* abs)
//{
//	// �ж�ͨѶ¼�������Ƿ�Ϊ0
//	if (abs->m_size == 0)
//	{
//		cout << "ͨѶ¼Ϊ��" << endl;
//		return;
//	}
//	else
//	{
//		for (int i = 0; i < abs->m_size; i++)
//		{
//			cout << "������" << abs->personArray[i].m_Name << "\t";
//			cout << "�Ա�(1:��  2:Ů)��" << (abs->personArray[i].m_sex == 1 ? "��" : "Ů") << "\t";
//			cout << "���䣺" << abs->personArray[i].m_age << "\t";
//			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
//			cout << "��ַ" << abs->personArray[i].m_Addr << endl;
//		}
//	}
//	system("pause");
//	system("cls");
//}
//
//// �����ϵ���Ƿ���ڣ����ڷ��ر�ţ������ڷ���-1
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
//// ɾ��ָ����ϵ��
//void deletePerson(Addressbooks* abs)
//{
//	cout << "������ɾ����ϵ��������" << endl;
//	string name;
//	cin >> name;
//
//	int judge;
//	judge = isExit(abs, name);
//	if (judge == -1)
//	{
//		cout << "���޴���" << endl;
//	}
//	else
//	{
//		// ����ǰ��
//		for (int i = judge; i < abs->m_size; i++)
//		{
//			abs->personArray[i] = abs->personArray[i + 1];
//		}
//		abs->m_size--;
//		cout << "ɾ���ɹ�" << endl;
//	}
//	system("pause");
//	system("cls");
//}
//
//// ����ָ����ϵ��
//void findPerson(Addressbooks* abs)
//{
//	cout << "��������ҵ���ϵ��������" << endl;
//	string name;
//	cin >> name;
//
//	int judge;
//	judge = isExit(abs, name);
//	if (judge == -1)
//	{
//		cout << "���޴���" << endl;
//	}
//	else
//	{
//		cout << "������" << abs->personArray[judge].m_Name << endl;
//		cout << "�Ա�(1:��  2:Ů)��" << (abs->personArray[judge].m_sex == 1 ? "��" : "Ů") << endl;
//		cout << "���䣺" << abs->personArray[judge].m_age << endl;
//		cout << "�绰��" << abs->personArray[judge].m_Phone << endl;
//		cout << "��ַ" << abs->personArray[judge].m_Addr << endl;
//	}
//	system("pause");
//	system("cls");
//}
//
//// ����ָ����ϵ��
//void modifyPerson(Addressbooks* abs)
//{
//	cout << "��������ĵ���ϵ��������" << endl;
//	string name;
//	cin >> name;
//
//	int judge;
//	judge = isExit(abs, name);
//	if (judge == -1)
//	{
//		cout << "���޴���" << endl;
//	}
//	else
//	{
//		while (true)
//		{
//			cout << "������" << abs->personArray[judge].m_Name << endl;
//			cout << "�Ա�(1:��  2:Ů)��" << (abs->personArray[judge].m_sex == 1 ? "��" : "Ů") << endl;
//			cout << "���䣺" << abs->personArray[judge].m_age << endl;
//			cout << "�绰��" << abs->personArray[judge].m_Phone << endl;
//			cout << "��ַ" << abs->personArray[judge].m_Addr << "\n" << endl;
//
//			cout << "������Ҫ�޸ĵ�����\n1:����\t2:�Ա�\t3:����\t4:�绰\t5:��ַ\t0:�˳�" << endl;
//			int rev;
//			cin >> rev;
//			switch (rev)
//			{
//			case 1:
//			{
//				cout << "��������ĺ������" << endl;
//				string new_name;
//				cin >> new_name;
//				abs->personArray[judge].m_Name = new_name;
//				break;
//			}
//			case 2:
//			{
//				cout << "��������ĺ���Ա�" << endl;
//				int new_sex;
//				while (true)
//				{
//					cin >> new_sex;
//					if (new_sex == 1 || new_sex == 2)
//					{
//						abs->personArray[judge].m_sex = new_sex;
//						break;
//					}
//					cout << "������������������" << endl;
//				}
//				break;
//			}
//			case 3:
//			{
//				int new_age;
//				cout << "��������ĺ�����䣺" << endl;
//				while (true)
//				{
//					cin >> new_age;
//					if (new_age >= 0 && new_age <= 120)
//					{
//						abs->personArray[judge].m_age = new_age;
//						break;
//					}
//					cout << "������������������" << endl;
//				}
//				break;
//			}
//			case 4:
//			{
//				string new_phone;
//				cout << "��������ĺ�ĵ绰��" << endl;
//				cin >> new_phone;
//				abs->personArray[judge].m_Phone = new_phone;
//				break;
//			}
//			case 5:
//			{
//				// ��ַ
//				string new_address;
//				cout << "�������ַ��" << endl;
//				cin >> new_address;
//				abs->personArray[judge].m_Addr = new_address;
//				break;
//			}
//			case 0:
//			{
//				cout << "�޸����" << endl;
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
//// ���������ϵ��
//void cleanPerson(Addressbooks* abs)
//{
//	cout << "�Ƿ�ȷ����գ�ȷ���밴1�������밴0" << endl;
//	int nub;
//	cin >> nub;
//	while (true)
//	{
//		if (nub == 1)
//		{
//			abs->m_size = 0;
//			cout << "������ϵ�������" << endl;
//			system("pause");
//			system("cls");
//			return;
//		}
//		else if (nub == 0)
//		{
//			cout << "�������˵�" << endl;
//			system("pause");
//			system("cls");
//			return;
//		}
//		else
//		{
//			cout << "���������룬ȷ���밴1�������밴0" << endl;
//			cin >> nub;
//		}
//	}
//}
//
//
//int main()
//{
//	// ����ͨѶ¼�ṹ�����
//	Addressbooks abs;
//	// ��ʼ��ͨѶ¼�е�ǰ��Ա����
//	abs.m_size = 0;
//
//
//	int select = 0;		// �û�ѡ�����
//
//	while (true)
//	{
//		showMenu();
//
//		cin >> select;
//
//		switch (select)
//		{
//		case 1:		// �����ϵ��
//			addPerson(&abs);
//			break;
//		case 2:		// ��ʾ��ϵ��
//			showPerson(&abs);
//			break;
//		case 3:		// ɾ����ϵ��
//			deletePerson(&abs);
//			break;
//		case 4:		// ������ϵ��
//			findPerson(&abs);
//			break;
//		case 5:		// �޸���ϵ��
//			modifyPerson(&abs);
//			break;
//		case 6:		// �����ϵ��
//			cleanPerson(&abs);
//			break;
//		case 0:		// �˳�ͨѶ¼
//		{
//			cout << "��ӭ�´�ʹ��" << endl;
//			system("pause");
//			return 0;
//		}
//		default:
//			break;
//		}
//	}
//}
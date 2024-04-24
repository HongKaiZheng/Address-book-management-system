#include<iostream>
using namespace std;
#define MAX 1000

//1.�����˵�ҳ��
void showMenu()
{
	cout << "*********************************" << endl;
	cout << "******    1,�����ϵ��     ******" << endl;
	cout << "******    2,��ʾ��ϵ��     ******" << endl;
	cout << "******    3,ɾ����ϵ��     ******" << endl;
	cout << "******    4,������ϵ��     ******" << endl;
	cout << "******    5,�޸���ϵ��     ******" << endl;
	cout << "******    6,�����ϵ��     ******" << endl;
	cout << "******    0,�˳�ͨѶ¼     ******" << endl;
	cout << "*********************************" << endl;
}

//������ϵ�˽ṹ��
struct Person
{
	//����
	string m_Name;
	//�Ա� 1 �� 2 Ů
	int m_Sex;
	//����
	int m_Age;
	//�绰
	string m_Phone;
	//��ַ
	string m_Addr;
};
//����ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
	
};
//�����ϵ��
void addPerson(struct Addressbooks* abs)
{
	//1,���ж�ͨѶ¼�Ƿ�����,������˾Ͳ����������
	if (abs->m_Size == MAX) {
		cout << "ͨѶ¼����,�޷������!" << endl;
		return;
	}
	else {
		//��Ӿ�����ϵ��

		//����
		string name;
		cout << "����������:  " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�:  " << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true)
		{
			//������ѭ��,ֻ������1����2�����˳�ѭ��
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "��������,����������" << endl;
		}

		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//�绰
		cout << "��������ϵ�绰" << endl;
		cout << "�绰��ӦΪ7λ����11λ" << endl;
		string phone;
		while (true) {
			cin >> phone;
			if (phone.length() == 11 || phone.length() == 7) {
				abs->personArray[abs->m_Size].m_Phone = phone;
				break;
			}
			cout << "������Ϸ����й���½�ֻ���" << endl;
		}

		//��ַ
		cout << "��������ϵ�˵�ַ" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		abs->m_Size++;
		cout << "�����ϵ����Ϣ�ɹ�" << endl;

		system("pause");//�밴���������
		system("cls");//��������
	}

}
void showPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == 0) {
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "  ����:  " << abs->personArray[i].m_Name << "\t";
			cout << "  �Ա�:  " << (abs->personArray[i].m_Sex == 1 ? "��":"Ů" )<< "\t";
			cout << "  ����:  " << abs->personArray[i].m_Age << "\t";
			cout << "  �绰:  " << abs->personArray[i].m_Phone << "\t";
			cout << "  ��ַ:  " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");//�����������
	system("cls");//��������
}

//�����ϵ���Ƿ����
int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name) {
			return i;//���ҵ���ϵ��,���±귵��
		}
	}
	return -1;
}
//��װɾ������
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��:" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	//ret == -1 ���޴���
	//ret != -1 ���д���
	if (ret != -1) {
		for (int i = ret; i < abs->m_Size; i++) {
			//�Ѻ�һ���˵���Ϣ���ǵ������,����ʵ��ɾ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//��װ������ϵ�˺���
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��:  " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		cout << "  ����:  " << abs->personArray[ret].m_Name << "\t";
		cout << "  �Ա�:  " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "  ����:  " << abs->personArray[ret].m_Age << "\t";
		cout << "  �绰:  " << abs->personArray[ret].m_Phone << "\t";
		cout << "  ��ַ:  " << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "û���ҵ�����ϵ��" << endl;
	}
	system("pause");
	system("cls");
}
//��װ�޸���ϵ����Ϣ
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//����
		string name;
		cout << "�������޸ĺ������: " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		cout << "�������޸ĺ���Ա�:  " << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true)
		{
			//������ѭ��,ֻ������1����2�����˳�ѭ��
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "��������,����������" << endl;
		}
		//����
		cout << "�������޸ĺ������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		//�绰
		cout << "�������޸ĺ����ϵ�绰" << endl;
		cout << "�绰��ӦΪ7λ����11λ" << endl;
		string phone;
		while (true) {
			cin >> phone;
			if (phone.length() == 11 || phone.length() == 7) {
				abs->personArray[ret].m_Phone = phone;
				break;
			}
			cout << "������Ϸ����й���½�ֻ���" << endl;
		}

		//��ַ
		cout << "�������޸ĺ����ϵ�˵�ַ" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "�޸���ϵ����Ϣ�ɹ�" << endl;


	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//��װ���ͨѶ¼��������
void emptyPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "�ɹ����ͨѶ¼" << endl;
	system("pause");
	system("cls");
}
int main()
{		//����ͨѶ¼�ṹ�����
		Addressbooks abs;
		//��ʼ��ͨѶ¼�е�ǰ��Ա����
		abs.m_Size = 0;
	while (true)
	{
		int select = 0;
		//�˵����ú���
		showMenu();
		cout << "��������Ҫ���еĲ���:" << endl;
		cin >> select;
		switch (select)
		{
		case 1:			//1,�����ϵ��
			addPerson(&abs);
			break;
		case 2:			//2, ��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:			//3,ɾ����ϵ��
			//���в��Կɲ������ҵ���:
		/* {
			cout << "����������Ҫɾ������ϵ��:" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1) {
				cout << "���޴���" << endl;
			}
			else {
				cout << "���д���" << endl;
			}
		}*/
			deletePerson(&abs);
			break;
		case 4:			//4,������ϵ��
			findPerson(&abs);
			break;
		case 5:			//5,�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6:			//6, �����ϵ��
		{
			cout << "���ٴ�ȷ�����Ƿ���Ҫ���ͨѶ¼" << endl;
			cout << "ȷ���밴1,�˳��밴�����" << endl;
			int Confirm;
			cin >> Confirm;
			if (Confirm == 1) {
				emptyPerson(&abs);
			}
			else {
				cout << "�Ѿ��˳����ͨѶ¼����" << endl;
				system("pause");
				system("cls");
			}

		}
			break;
		case 0:			//0,�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
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
#include <iostream>
using namespace std;
class student
{
	char* name;
	char* email;
	int age;
public:
	student()
	{
		name = nullptr;
		age = 0;
		cout << "default";
	}
	student(const char* n, int a, const char* b)
	{
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		age = a;
		email = new char[strlen(b) + 1];
		strcpy_s(email, strlen(b) + 1, b);
		cout << "by params";
	}
	void input()
	{
		char buff[20];
		cout << "Enter name ==>";
		cin >> buff;
		if (name != nullptr)
		{
			cout << "delete..." << name << "\n";
			delete[] name;

		}
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);
		cout << "Enter age ==>";
		cin >> age;
		cout << "Enter email ==>";
		cin >> buff;
		if (email != nullptr)
		{
			cout << "delete..." << email << "\n";
			delete[] email;

		}
		email = new char[strlen(buff) + 1];
		strcpy_s(email, strlen(buff) + 1, buff);
	}
	void print()
	{
		cout << "Name:" << name << "\tAge:" << age << "\temail:" << email << endl;
	}

	~student()
	{
		delete[] email;
		delete[] name;
		cout << "destructor\n";
	}
};
int main()
{
	student obj1;
	student obj2("oleg", 20, "mail@com.com");
	obj2.print();
	obj2.input();
	obj2.print();


}


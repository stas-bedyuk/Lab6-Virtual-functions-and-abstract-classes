
// 3 sem lab 6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>

using namespace std;

class B
{
private:
	int id;
protected:
	char name[40];
public:
	B(const char* s1, int i) : id(i)
	{
		strcpy(name, s1);
	}
	B()  {};
	virtual ~B() {};
	virtual void see()
	{
		cout << "\n\nName: " << name;
		cout << "\n\nID: " << id;
	}
	virtual void cout1()
	{
		int i;
		for ( i = 0; i < 40; i++)
		{
			if (name[i] == '\0') break;
	    }
		cout << "\n\nCout of symbols in name: " << i;
	}
};

 class P1 :  public B
{
private:
	char company[20];
protected:
	int salary;
public:
	P1(int i, const char* s1, const char* s, int j) : B(s1, i)
	{
		strcpy(company, s);
		salary = j;
	}
	P1() {};
	~P1() {};
	void see()
	{
		cout << "\n\nName: " << name;
		cout << "\n\nCompany: " << company;
		cout << "\n\nSalary: " << salary;

	}
	void cout1()
	{
		int i;
		for (i = 0; i < 40; i++)
		{
			if (company[i] == '\0') break;
		}
		cout << "\n\nCout of symbols in company: " << i;
	}
	void search(char *t)
	{
		char a[20];
		for (int i = 0; i < 20; i++)
		{
			a[i] = toupper(company[i]);
		}
		if (strcmp(t, a) == 0)
		{
			see();
			cout << "\n\n*******************";
		}
	}
};

class P11 : public P1
{
private:
	int experience;
protected:
	char post[20];
public:
	P11() {};
	P11(int i, const char* s1, const char* s, int j, const char* h, int a) : P1(i, s1, s, j)
	{
		strcpy(post, h);
		experience = a;
	}
	~P11() {};
	void see()
	{
		cout << "\n\nName: " << name;
		cout << "\n\nPost: " << post;
		cout << "\n\nExperience: " << experience;
		cout << "\n\nSalary: " << salary;

	}
	void cout1()
	{
		int i;
		for (i = 0; i < 40; i++)
		{
			if (post[i] == '\0') break;
		}
		cout << "\n\nCout of symbols in post: " << i;
	}
};
class P2 : public B
{
private:
	char division[20];
protected:
	int number_of_unit;
public:
	P2(int i, const char* s1, const char* s, int j) : B(s1, i)
	{
		strcpy(division, s);
		number_of_unit = j;
	}
	P2() {};
	~P2() {};
	void see()
	{
		cout << "\n\nName: " << name;
		cout << "\n\nDivision: " << division;
		cout << "\n\nNumber of unit: " << number_of_unit;

	}
	void cout1()
	{
		int i;
		for (i = 0; i < 40; i++)
		{
			if (division[i] == '\0') break;
		}
		cout << "\n\nCout of symbols in division: " << i;
	}
};

int main()
{
	B** ptr = new B*[6];
	P1** ptr1 = new P1 * [4];
	char name1[40];
	char company1[20];
	cout << "\n\n_____OBJ1_____\n\nEnter the name of employee: ";
	cin.getline(name1,40);
	B* a = new B(name1,1);


	cout << "\n\n_____OBJ2_____\n\nEnter the name of company: ";
	cin.getline(company1, 20);
	cout << "\nEnter the name of employee: ";  ///1
	cin.getline(name1, 40);
	P1* b = new P1(1, name1, company1,5000);

	cout << "\n\n_____OBJ3_____\n\nEnter the name of company: ";
	cin.getline(company1, 20);                  ////2
	cout << "\nEnter the name of employee: ";
	cin.getline(name1, 40);
	P1* bb = new P1(2, name1, company1, 1000);

	cout << "\n\n_____OBJ4_____\n\nEnter the name of company: ";
	cin.getline(company1, 20);
	cout << "\nEnter the name of employee: ";  ///3
	cin.getline(name1, 40);
	P1* bbb = new P1(3, name1, company1, 3500);

	cout << "\n\n_____OBJ5_____\n\nEnter the name of employee: ";
	cin.getline(name1, 40);
	B* c = new P2(1, name1,"Tankisty", 3);
	cout << "\n\n_____OBJ6_____\n\nEnter the name of employee: ";
	cin.getline(name1, 40);
	cout << "\nEnter the name of company: ";
	cin.getline(company1, 20);
	P1* d = new P11(1, name1, company1, 5000,"programmer-general",3);
	ptr[0] = b; 	ptr[1] = bb; 	ptr[2] = bbb; 	ptr[3] = a; ptr[4] = c; ptr[5] = d;
	ptr1[0] = b; ptr1[1] = bb; ptr1[2] = bbb; ptr1[3] = d;
	ptr[0]->see();
	ptr[0]->cout1();
	cout << "\n------------------";
	ptr[1]->see();
	ptr[1]->cout1();
	cout << "\n------------------";
	ptr[2]->see();
	ptr[2]->cout1();
	cout << "\n------------------";
	ptr[3]->see();
	ptr[3]->cout1();
	cout << "\n------------------";
	ptr[4]->see();
	ptr[4]->cout1();
	cout << "\n------------------";
	ptr[5]->see();
	ptr[5]->cout1();
	cout << "\n------------------";

	char t[20];
	char s[20];
	cout << "\n\nEnter the name of company: ";
	cin.getline(t, 20);
	for (int i = 0; i < 20; i++) 
	{
		s[i]=toupper(t[i]);
	}
	cout << endl << s;
	for (int i = 0; i < 4; i++)
	{
		ptr1[i]->search(s);
	}
	delete a;
	delete b;
	delete c;
	delete d;
	//for (int i = 0; i <4; i++)
    //delete[] ptr[i];
	delete[] ptr;
	delete[] ptr1;
	return 0;
}

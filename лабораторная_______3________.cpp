#define _CRT_SECURE_NO_WARNINGS // для  копировавния строк из фйала
#include <iostream>
#include <string.h>      // для strcmp
#include <stdlib.h>
#include <algorithm>    // для sort
#include <fstream>      // лля работы с файлами
#include <iomanip>      // для setw(n)   left  rigth - выравнивание столбика 

using namespace std;

class prepod;
class fio;
class database;

class Fio
{
	friend bool operator==(Fio& d, const prepod& p);
	friend bool operator==(prepod& d, const prepod& p);
	friend ostream& operator<<(ostream& s, const prepod& p);
	friend database;
	friend prepod;
	
private:
	char* fam;
	char* name;
	char* otchestvo;
	Fio()
	{
		fam = new char[100];  // выделение памяти на массив символов
		name = new char[100];
		otchestvo = new char[100];

	}
	~Fio()
	{
		delete[] fam;
		delete[] name;
		delete[] otchestvo;
	}
};
class prepod

{
	friend database;
public:
	Fio fio;
	int department;	                        // кафедра
	int academic_title;	                    //  ученое звание
	char* subject;                          // предмет

	//static int ct;                        // счетчик существующих объектов класса

	prepod()                                 //конструктор  для пустого человечка
	{

		department = 0;
		academic_title = 0;

		subject = new char[100];
		strcpy(subject, "incognito");

		fio.fam = new char[100];
		strcpy(fio.fam, "incognito");

		fio.name = new char[100];
		strcpy(fio.name, "incognito");

		fio.otchestvo = new char[100];
		strcpy(fio.otchestvo, "incognito");


	}
	prepod(int vDE, double vSA,const char* strsubjeckt, const char* strfam, const char* strname, const char* strotchestvo) //еще один коструктор  для перегрузки
	{
		department = vDE;
		academic_title = vSA;
		strcpy(subject, strsubjeckt);
		strcpy(fio.fam, strfam);
		strcpy(fio.name, strname);
		strcpy(fio.otchestvo, strotchestvo);

	}
	~prepod()                                                                 //деструктор для подчистки памяти (кучи)
	{
		delete[] subject;
	}

	friend ostream& operator<<(ostream& s, const prepod& p);

	void Print()                                                             //проверка кострукторов
	{
		cout << "\ndepartment: " << department;
		cout << "\nsalary:     " << academic_title;
		cout << "\nsubject:    " << academic_title;
		cout << "\nfam:        " << fio.fam;
		cout << "\nname:       " << fio.name;
		cout << "\notchestvo:  " << fio.otchestvo;
		cout << "\n----------------------\n";
	}


};
class database
{


	prepod* array;
	int n;
public:
	database()
	{
		const int countMax = 100;
		array = new prepod[countMax];  //создание динамического массива (new выделяет память,указывает на нее)

		n = 0;
	}
	~database()
	{
		delete[] array;
	}


	void input_worker()
	{
		{
			//array[n].fio.fam = new char[100];  // выделение памяти на массив символов
			//array[n].fio.name = new char[100];
			//array[n].fio.otchestvo = new char[100];

			bool flag_department = 1;
			while (flag_department)
			{
				cout << "information[" << n << "].department = ";
				cin >> array[n].department;
				if ((cin.fail()) || (array[n].department < 0)) //если вводимое число не типа int или отрицательное 
				{
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "U  AAAAA (-_-)/\n";
				}
				else
					flag_department = 0;
			}

			bool flag_academic_title = 1;
			while (flag_academic_title)
			{
				cout << "information[" << n << "].academic_title = ";
				cin >> array[n].academic_title;
				if ((cin.fail()) || (array[n].academic_title < 0)) //если вводимое число не типа int или отрицательное 
				{
					cin.clear();
					cin.ignore(32767, '\n');
					cout << "AAAAA (0_o)/ \n";
				}
				else
					flag_academic_title = 0;
			}
			cout << "information[" << n << "].subject = ";
			cin >> array[n].subject;
			cout << "information[" << n << "].fam = ";
			cin >> array[n].fio.fam;
			cout << "information[" << n << "].name = ";
			cin >> array[n].fio.name;
			cout << "information[" << n << "].otchestvo = ";
			cin >> array[n].fio.otchestvo;
			cout << "\n";
		}
		n++;
	}
	void output_worker()
	{
		if (0 == n)
			cout << "NOT INFORMATION\n";
		else
		{
			cout << "\nINFORMATION ABOUT ALL WORKERS\n";
			cout << "depertment"
				<< "         " << "academic_title"
				<< "         " << "subject"
				<< "                " << "fam"
				<< "               " << "name"
				<< "              " << "otchestvo"
			    << endl;
			for (int i = 0; i < n; i++)
			{
				cout << array[i];
			}
		}
		cout << "\n";
	}


	void search_subject()
	{
		char* subject = new char[100];
		cout << "ENTER SUBJECT: ";
		cin >> subject;


		cout << "============\n";
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			//f = (person == array[i]);
			//cout << f <<'\n' << '\n';
			if (strcmp(subject,array[i].subject) == 0)
			{
				sum++;
				cout << "\n";
				cout << "INFORMATION\n";
				cout << "\n";
				cout << "fam: " << array[i].fio.fam << "\n";
				cout << "name: " << array[i].fio.name << "\n";
				cout << "otchestvo: " << array[i].fio.otchestvo << "\n";
				cout << "department: " << array[i].department << "\n";
				cout << "academic_title: " << array[i].academic_title << "\n";
				cout << "subject: " << array[i].subject << "\n";
				cout << "\n";

			}
		}
		cout << "Found " << sum << "\n";
	}
	void search_department()
	
	{
		int department_person;
		cout << "ENTER DEPARTMENT: ";
		cin >> department_person;
		

		cout << "============\n";
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			//f = (person == array[i]);
			//cout << f <<'\n' << '\n';
			if (department_person == array[i].department)
			{
				sum++;
				cout << "\n";
				cout << "INFORMATION\n";
				cout << "\n";
				cout << "fam: " << array[i].fio.fam << "\n";
				cout << "name: " << array[i].fio.name << "\n";
				cout << "otchestvo: " << array[i].fio.otchestvo << "\n";
				cout << "department: " << array[i].department << "\n";
				cout << "academic_title: " << array[i].academic_title << "\n";
				cout << "subject: " << array[i].subject << "\n";
				cout << "\n";

			}
		}
		cout << "Found " << sum << "\n";
	}
	
	void search_fam()
	{
		Fio person;
		cout << "ENTER FAM: ";
		cin >> person.fam;
		cout << "ENTER NAME: ";
		cin >> person.name ;
		cout << "ENTER OTCHESTVO: ";
		cin >> person.otchestvo;

		cout << "============\n";
		int sum = 0;
		int f;
		for (int i = 0; i < n; i++)
		{
			

			if (person == array[i])
			{
				sum++;
				cout << "\n";
				cout << "INFORMATION\n";
				cout << "\n";
				cout << "fam: " << array[i].fio.fam << "\n";
				cout << "name: " << array[i].fio.name << "\n";
				cout << "otchestvo: " << array[i].fio.otchestvo << "\n";
				cout << "department: " << array[i].department << "\n";
				cout << "academic_title: " << array[i].academic_title << "\n";
				cout << "subject: " << array[i].subject << "\n";
				cout << "\n";

			}
		}
		cout << "Found " << sum << "\n";
	}
	void load_data(const char* file_name_count, const char* file_name_data)
	{
		ifstream fin;
		fin.open(file_name_count);
		if (!fin.is_open())
		{
			cout << "ERROR\n";
		}
		else
		{
			cout << "count open" << endl;
			string inp;
			inp = " ";
			fin >> inp;
			n = atoi(inp.c_str());
			//масив дин количество каунт
		}
		fin.close();


		ifstream file_in;
		file_in.open(file_name_data);
		if (!file_in.is_open())
		{
			cout << "ERROR\n";
		}
		else
		{
			cout << "myFile open" << endl;
			string inp;
			inp = " ";

			for (int g = 0; g < n; g++)
			{
				inp = ""; // чтобы в конце не дублировалась строка
				file_in >> inp;
				//cout << inp << endl;
				array[g].department = atoi(inp.c_str());// из string  в  int
				/*if (0 == array[g].department)
					return -1;*/
				inp = "";
				file_in >> inp;
				//cout << inp << endl;
				array[g].academic_title = (double)atof(inp.c_str());
				/*if (0 == array[g].academic_title)
					return -1;*/

				inp = "";
				file_in >> inp;
				//cout << inp << endl;
				array[g].subject = new char[100];        // выделение памяти на массив символов
				strcpy(array[g].subject, inp.c_str());

				inp = "";
				file_in >> inp;
				//cout << inp << endl;
				array[g].fio.fam = new char[100];        // выделение памяти на массив символов
				strcpy(array[g].fio.fam, inp.c_str());

				inp = "";
				file_in >> inp;
				//cout << inp << endl;
				array[g].fio.name = new char[100];        // выделение памяти на массив символов
				strcpy(array[g].fio.name, inp.c_str());

				inp = "";
				file_in >> inp;
				//cout << inp << endl;
				array[g].fio.otchestvo = new char[100];        // выделение памяти на массив символов
				strcpy(array[g].fio.otchestvo, inp.c_str());
			}
		}

		file_in.close();
		/*return n;*/
	}
	void end(const char* file_name_data, const char* file_name_count)
	{

		//cout = file_out для файла
	   // ofstream::appчтобы сохранялись дданные и не стиралисьпри новом запуске
	   // создается  myFile типа txt 
		ofstream file_out;
		file_out.open(file_name_data);

		if (!file_out.is_open())
		{
			cout << "error" << endl;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{

				file_out << array[i].department << '\n';
				file_out << array[i].academic_title << '\n';
				file_out << array[i].subject << "\n";
				file_out << array[i].fio.fam << '\n';
				file_out << array[i].fio.name << '\n';
				file_out << array[i].fio.otchestvo << '\n';

			}
		}
		file_out.close();

		ofstream fout;                       //отдельно для количества сотрудников
		fout.open(file_name_count);

		if (!fout.is_open())
			cout << "error_count" << endl;
		else
		{
			fout << n << '\n';
		}
		fout.close();
	}

};

ostream& operator<<(ostream& s, const prepod& p)
{
	s << "  " << left << setw(17) << p.department
		<< setw(23) << p.academic_title
		<< setw(23) << p.subject
		<< setw(18) << p.fio.fam
		<< setw(18) << p.fio.name
		<< setw(10) << p.fio.otchestvo<<'\n';
	return s;
}

bool operator==(Fio& d, const prepod& p)
{	
	if ((strcmp(d.fam, p.fio.fam) == 0) && (strcmp(d.name, p.fio.name) == 0) && (strcmp(d.otchestvo, p.fio.otchestvo) == 0))
		return true;
	else
	{
		//cout << "eror" << '\n';
		return false;
	}
}

int main()
{
	database ddd;

	ofstream f;                                   //для создания файла если их не существовало
	f.open("myFile.txt", ios::app);
	f.close();
	ofstream fi;
	fi.open("count.txt", ios::app);
	fi.close();


	ddd.load_data("count.txt", "myFile.txt");
	int menu = 6;
	do
	{
		cout << " ------------------------------------------ \n";
		cout << "|write information about prepod  -> type 0 |\n";
		cout << "|search prepod (subject)         -> type 1 |\n";
		cout << "|search prepod (department)      -> type 2 |\n";
		cout << "|search prepod (fam)             -> type 3 |\n";
		cout << "|information about all workers   -> type 4 |\n";
		cout << "|clear                           -> type 5 |\n";
		cout << "|exist                           -> type 6 |\n";
		cout << " ------------------------------------------ \n";
		cout << endl;
		cout << "enter number:";

		cin >> menu;
		if ((cin.fail()) || (menu < 0) || (menu > 6)) //если вводимое число не типа int или отрицательное 
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "ERROR AHAHAHAAAH  SIDI DUMAY ....(^ w ^)\n";
			continue;
		}
		switch (menu)
		{
		case 0:
		{
			ddd.input_worker();                 // ввод структур
			break;
		}
		case 1:
		{
			ddd.search_subject();               // сортировка по окладу
			break;
		}
		case 2:
		{
			ddd.search_department();           // сoртировка по отделу             
			break;
		}
		case 3:
		{
			ddd.search_fam();                // поиск по фамилии           
			break;
		}
		case 4:
		{
			ddd.output_worker();              // вывод  записанных структур    
			break;
		}
		case 5:
		{
			system("cls");
			break;
		}
		default:
		{
			break;
		}

		}
	} while (menu != 6);

	ddd.end("myFile.txt", "count.txt");
	return 0;

}




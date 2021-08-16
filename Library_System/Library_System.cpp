#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
#define size1 10
#define size_book 100
#define size_user 100
struct Book
{
	int ID;
	string Name;
	int Quantity;
	int Quatity_id_borrow = 0;

};
struct User
{
	int ID;
	string Name;
	int a[size1];
	int num_b = 0;
};

Book book[size_book];
int num_b = 0;
User user[size_user];
int num_u = 0;

void Library_System();
void Menu();
int Choice();
void add_book();
void print_book_by_ID();
bool compare_ID(Book&, Book&);
bool compare_Name(Book&, Book&);
void print_book_by_Name();
void add_user();
void user_borrow_book();
void user_return_book();
void Print_users();
void print_who_borrowed_book_by_name();
void search_book_by_prefix_name();
int main()
{
	Library_System();
}

void Library_System()
{
	int quit = 0;
	Menu();
	do
	{
		switch (Choice())
		{
		case 1:
			add_book();
			break;
		case 2:
			search_book_by_prefix_name();
			break;
		case 3:
			print_who_borrowed_book_by_name();
			break;
		case 4:
			print_book_by_ID();
			break;
		case 5:
			print_book_by_Name();
			break;
		case 6:
			add_user();
			break;
		case 7:
			user_borrow_book();
			break;
		case 8:
			user_return_book();
			break;
		case 9:
			Print_users();
			break;
		case 10:
			quit = 1;
			break;
		}

	} while (quit == 0);
}
void Menu()
{
	cout << "Library Menu : \n";
	cout << "1) add_book\n";
	cout << "2) search_booka_by_prefix_name\n";
	cout << "3) print_who_borrowed_book_by_name\n";
	cout << "4) print_Library_by_ID\n";
	cout << "5) print_Library_by_Name\n";
	cout << "6) add_user\n";
	cout << "7) user_borrow_book\n";
	cout << "8) user_return_book\n";
	cout << "9) print_user\n";
	cout << "10) Exit \n";
}
int Choice()
{
	int choose, quit = 0;

	cout << "Enter your menu choice [1 - 10]: ";
	cin >> choose;

	cout << endl;
	do
	{
		if (choose >= 1 && choose <= 10)
		{
			return choose;
		}
		else
		{
			cout << "Out of Rang !!\n";
			cout << "Please Enter your menu choice[1 - 10]: ";
			cin >> choose;
			cout << endl;
		}
	} while (quit == 0);
	
	return choose;
}
void add_book()
{
	cout << "\nEnter ID book : ";
	cin >> book[num_b].ID;
	cout << "Enter Name book : ";
	cin >> book[num_b].Name;
	cout << "Enter Quantity book : ";
	cin >> book[num_b].Quantity;
	num_b++;
	cout << endl;
}
bool compare_ID(Book& a1, Book& a2)
{
	if (a1.ID < a2.ID)
		return 1;
	return 0;
}
bool compare_Name(Book& a1, Book& a2)
{
	if (a1.Name < a2.Name)
		return 1;
	return 0;
}
void print_book_by_ID()
{

	if (num_b == 0)
	{
		cout << "NO book to disply \n";
	}
	else
	{
		sort(book, book + num_b, compare_ID);
		for (int i = 0; i < num_b; i++)
		{
			cout << "ID : " << book[i].ID << " Name : " << book[i].Name << " total_quantity = " << book[i].Quantity << " total_quantity_borrowed = " << book[i].Quatity_id_borrow << endl;
		}
	}
	cout << endl;
}
void print_book_by_Name()
{
	if (num_b == 0)
	{
		cout << "NO book to disply \n";
	}
	else
	{
		sort(book, book + num_b, compare_Name);
		for (int i = 0; i < num_b; i++)
		{
			cout << "ID : " << book[i].ID << " Name : " << book[i].Name << " total_quantity = " << book[i].Quantity << " total_quantity_borrowed = " << book[i].Quatity_id_borrow << endl;
		}
	}
	cout << endl;
}
void add_user()
{

	cout << "Enter data of user :\n";
	cout << "Enter ID of user : ";
	cin >> user[num_u].ID;
	cout << "Enter Name of user : ";
	cin >> user[num_u].Name;
	num_u++;
	cout << endl;
}
void user_borrow_book()
{
	string name_user, name_book;


	cout << "Enetr Name of user : ";
	cin >> name_user;

	cout << "Enetr Name of book : ";
	cin >> name_book;
	cout << endl;
	bool ok_user = false, ok_book = false;;
	int index_user, index_book;
	for (int i = 0; i < num_u; i++)
	{
		if (name_user == user[i].Name)
		{
			ok_user = true;
			index_user = i;
			break;
		}
	}

	for (int i = 0; i < num_b; i++)
	{
		if (name_book == book[i].Name)
		{
			ok_book = true;
			index_book = i;
			break;
		}
	}




	if (ok_user == false)
	{
		cout << "Not found user of this Name : " << name_user << endl;
	}
	else if (ok_book == false)
	{
		cout << "Not found book of this Name : " << name_book << endl;
	}
	else
	{
		if (book[index_book].Quatity_id_borrow == book[index_book].Quantity)
		{
			cout << "this book is'nt avaliable " << endl;
		}
		else
		{
			book[index_book].Quatity_id_borrow++;
			user[index_user].a[user[index_user].num_b++] = book[index_book].ID;
			cout << endl;
		}

	}
	cout << endl;
}
void user_return_book()
{
	string name_user, name_book;


	cout << "Enetr Name of user : ";
	cin >> name_user;

	cout << "Enetr Name of book : ";
	cin >> name_book;

	cout << endl;

	bool ok_user = false, ok_book = false;;
	int index_user, index_book;

	for (int i = 0; i < num_u; i++)
	{
		if (name_user == user[i].Name)
		{
			ok_user = true;
			index_user = i;
			break;
		}
	}

	for (int i = 0; i < num_b; i++)
	{
		if (name_book == book[i].Name)
		{
			ok_book = true;
			index_book = i;
			break;
		}
	}

	if (ok_user == false)
	{
		cout << "Not found user of this Name : " << name_user << endl;
	}
	else if (ok_book == false)
	{
		cout << "Not found book of this Name : " << name_book << endl;
	}
	else
	{
		bool x = false;
		int ind_id = 0;
		for (int i = 0; i < user[index_user].num_b; i++)
		{
			if (book[index_book].ID == user[index_user].a[i])
			{
				x = true;
				ind_id = i;
				break;
			}
		}


		if (user[index_user].num_b == 0)
		{
			cout << "this user do'nt borrow any books " << endl;
		}
		else if (x == false)
		{
			cout << "this user do'nt borrow this book " << endl;
		}
		else
		{
			if (ind_id == 0)
			{
				user[index_user].num_b--;
			}
			else if (ind_id == ((user[index_user].num_b) - 1))
			{
				user[index_user].num_b--;
			}
			else
			{

				for (int i = ind_id; i < user[index_user].num_b - 1; i++)
				{
					user[index_user].a[i] = user[index_user].a[i + 1];
				}
				user[index_user].num_b--;
			}
			user[index_user].num_b;
			book[index_book].Quatity_id_borrow--;
			cout << endl;
		}

	}
	cout << endl;
}
void Print_users()
{
	cout << endl;
	if (num_u == 0)
	{
		cout << "NO user to disply \n";
	}
	else
	{

		for (int i = 0; i < num_u; i++)
		{
			cout << "user name : " << user[i].Name;
			cout << "  user ID : " << user[i].ID;
			cout << "  borrowed_book_IDS : ";
			for (int j = 0; j < user[i].num_b; j++)
			{
				cout << user[i].a[j];
			}
			cout << endl;
		}
	}
	cout << endl;

}
void print_who_borrowed_book_by_name()
{
	string s;
	cout << "Enter Book Name : ";
	cin >> s;
	bool x = false;
	int ind;
	for (int i = 0; i < num_b; i++)
	{
		if (s == book[i].Name)
		{
			ind = i;
			x = true;
			break;
		}
	}
	cout << endl;

	if (x == false)
	{
		cout << "This book is'nt found in library\n";
	}
	else
	{
		bool ok = false;
		int ind2;
		for (int i = 0; i < num_u; i++)
		{
			for (int j = 0; j < user[i].num_b; j++)
			{
				if (user[i].a[j] == book[ind].ID)
				{
					cout << user[i].Name << endl;
					ok = true;
				}

			}

		}
		cout << endl;
		if (ok == false)
		{
			cout << "this user was'nt borrowed this book \n\n";
		}
		cout << endl;
	}


}
void search_book_by_prefix_name()
{
	string s;
	bool x = false;
	int c = 0;
	int a[100];

	cout << "Enter Book prefixe Name : ";
	cin >> s;


	for (int i = 0; i < num_b; i++)
	{
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == book[i].Name[j])
			{
				c++;
				x = true;
			}
			if (c == s.size())
			{
				cout << book[i].Name << endl;
				c = 0;
			}
		}
	}


	if (x == false)
	{
		cout << "There is not book by this prefixe name \n\n";
	}

	cout << endl;
}
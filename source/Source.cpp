#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
const char filename[] = "c:\\file\\file.dat";

class Date;


class Date
{
private:
	int year;
	int month;
	int day;
	string item;
	int price;
public:
	Date()
	{
		year = 0;
		month = 0;
		day = 0;
		item = "";
		price = 0;
	}
	
	Date(int a, int b, int c, string d, int e)
	{
		year = a;
		month = b;
		day = c;
		item = d;
		price = e;
	}
	void setDate(int a, int b, int c, string d, int e)
	{
		year = a;
		month = b;
		day = c;
		item = d;
		price = e;
	}
	int getyear()
	{
		return year;
	}
	int getmonth()
	{
		return month;
	}
	int getday()
	{
		return day;
	}
	string getitem()
	{
		return item;
	}
	int getprice()
	{
		return price;
	}
	void setitem(string a)
	{
		item = a;
	}
	void setyear()
	{
		cout << "�п�J�~��(��J0����):";
		cin >> year;
	}
	void setmonth()
	{
		cout << "�п�J���(��J0����):";
		cin >> month;
	}
	void setday()
	{
		cout << "�п�J���(��J����):";
		cin >> day;
	}
	void setitem()
	{
		cout << "�п�J���ئW��(��J0����):";
		cin >> item;
	}
	void setprice()
	{
		cout << "�п�J����(��J0����):";
		cin >> price;
	}
	friend istream & operator >> (istream& in, Date& obj);
	friend ostream & operator << (ostream& out, Date& obj);


	void welcome()
	{
		char option = 0;
		int repeat = 1;
		string str;

		cout << "�w��ϥΥ��O�b�{��\n";
		while (repeat)
		{
			cout << "1.�O�b 2.����r�d�b 3.���O�d�b : ";
			cin >> option;
			switch (option)
			{
			case '1':
				write();
				repeat = wel_re();
				break;
			case '2':
				cout << "\n�п�J����r : ";
				cin >> str;
				read(str);
				repeat = wel_re();
				break;
			case '3':
				total(search_ymd());
				repeat = wel_re();
				break;
			default:
				cout << "\n�L�Ŀ�J\n\n";
				break;
			}
		}
	}

	int  wel_re()
	{
		char repeat = '3';
		cout << "\n�аݭn�A�ϥΥ��{����?\n";
		while (repeat == '3')
		{
			cout << "1.�n 2.���n : ";
			cin >> repeat;
			switch (repeat)
			{
			case '1':
				repeat = '1';
				break;
			case '2':
				repeat = '0';
				cout << "\n�w��A���ϥ�!\n\n";
				break;
			default:
				repeat = '3';
				cout << "�L�Ŀ�J\n\n";
				break;
			}
		}
		if (repeat == '1')
			return 1;
		if (repeat == '0')
			return 0;
	}
	void write()
	{
		char question;
		Date form;
		ofstream filePtr;
		filePtr.open(filename, ios::app);
		if (!filePtr)
		{
			cout << "�ɮ׶}�ҿ��~!\n";
			system("pause");
			exit(EXIT_FAILURE);
		}
		else
		{
			while (1)
			{
				form = search_ymdip();

				if (form.item == "fail")
				{
					break;
				}
				else
				{
					cout << form;
					cout << "�O�_��J���T(Y/N)? :";
					cin >> question;
				}
				if (question == 'Y' || question == 'y')
					filePtr.write((char*)&form, sizeof(form));
				else
					cout << "�P�_����J���~�A�Э��s��J�C\n";
			}
		}
		filePtr.close();
	}
	void read(string search)
	{
		ifstream filePtr;
		string str;
		filePtr.open(filename, ios::binary | ios::in);
		if (!filePtr)
		{
			cout << "�}�ҿ�J�ɿ��~!\n";
			system("pause");
			exit(EXIT_FAILURE);
		}
		else
		{

			while (!filePtr.eof())
			{

				filePtr.read((char*)this, sizeof(*this));

				if (filePtr.eof())
					break;
				if (search == inttostr(year) || search == inttostr(month) || search == inttostr(day) || search == inttostr(price) || search == item)
					cout << *this;

			}
		}
		filePtr.close();
	}
	string inttostr(int data)
	{
		string temp_str;
		string str;
		int temp;
		int conv_time = 0;
		temp = data;
		int minus = 0;
		if (temp < 0)
		{
			minus = 1;
			temp = abs(temp);
		}
		while (temp>0)
		{
			temp_str += temp % 10 + '0';
			temp = temp / 10;
			conv_time++;
		}

		if (minus == 0)
		{
			for (int i = 0; i < conv_time; i++)
			{
				str += temp_str.substr(conv_time - i - 1, 1);
			}
		}
		else
		{
			str += '-';
			for (int i = 0; i < conv_time; i++)
			{
				str += temp_str.substr(conv_time - i - 1, 1);
			}
		}
		return str;
	}

	Date search_ymdip()
	{
		Date search;
		
		int key_ok = 0;
		while (1)
		{
			search.setyear();
			if (search.getyear() == 0)
			{
				key_ok = 0;
				break;
			}
			else
			{
				key_ok = 1;
			}

			search.setmonth();
			if (search.getmonth() == 0)
			{
				key_ok = 0;
				break;
			}
			else
			{
				key_ok = 1;
			}

			search.setday();
			if (search.getday() == 0)
			{
				key_ok = 0;
				break;
			}
			else
			{
				key_ok = 1;
			}

			search.setitem();
			if (search.getitem() == "0")
			{
				key_ok = 0;
				break;
			}
			else
			{
				key_ok = 1;
			}

			search.setprice();
			if (search.getprice() == 0)
			{
				key_ok = 0;
				break;
			}
			else
			{
				key_ok = 1;
			}

			if (key_ok == 1)
				break;
		}
		if (key_ok == 0)
			search.item = "fail";
		return search;
	}

	Date search_ymd()
	{
		Date search;
			int key_ok = 0;
		while (1)
		{
			search.setyear();
			if (search.getyear() == 0)
			{
				key_ok = 0;
				break;
			}
			else
				key_ok = 1;

			search.setmonth();
			if (search.getmonth() == 0)
			{
				key_ok = 0;
				break;
			}
			else
				key_ok = 1;

			search.setday();
			if (search.getday() == 0)
			{
				key_ok = 0;
				break;
			}
			else
				key_ok = 1;
			if (key_ok == 1)
			{
				break;
			}
		}
		if (key_ok == 0)
			search.item = "fail";
		return search;
	}


	void total(Date search) 
	{

		Date total;
		ifstream filePtr;
		int count = 0;
		filePtr.open(filename, ios::binary | ios::in);

		if (!filePtr)
		{
			cout << "�}�ҿ�J�ɿ��~!\n";
			system("pause");
			exit(EXIT_FAILURE);
		}
		else
		{

			while (!filePtr.eof())
			{

				filePtr.read((char*)this, sizeof(*this));

				if (filePtr.eof())
					break;
				if ((search.year == year) && (search.month == month) && (search.day == day))
				{
					count++;
					total.year = year;
					total.month = month;
					total.day = day;
					total.price += price;
					cout << *this;
				}
			}
			if (count == 0)
			{
				cout << "�d�L���";
			}
			else
			{
				total.item = "���O�[�`";
				cout << total;
			}
		}
		filePtr.close();
	}
	~Date()
	{

	}
};
istream & operator >> (istream& in, Date& obj)
{
	cout << "�п�J���: ";
	in >> obj.year >> obj.month >> obj.day;
	return in;
}
ostream & operator << (ostream& out, Date& obj)
{
	out << obj.year << "/" << obj.month << "/" << obj.day << "\t" << obj.item << "\t" << obj.price << "\n";
	return out;

}




int main()
{
	Date a;
	a.welcome();
	system("pause");
	return 0;
}
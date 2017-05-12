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
		cout << "請輸入年分(輸入0結束):";
		cin >> year;
	}
	void setmonth()
	{
		cout << "請輸入月分(輸入0結束):";
		cin >> month;
	}
	void setday()
	{
		cout << "請輸入日期(輸入結束):";
		cin >> day;
	}
	void setitem()
	{
		cout << "請輸入項目名稱(輸入0結束):";
		cin >> item;
	}
	void setprice()
	{
		cout << "請輸入價錢(輸入0結束):";
		cin >> price;
	}
	friend istream & operator >> (istream& in, Date& obj);
	friend ostream & operator << (ostream& out, Date& obj);


	void welcome()
	{
		char option = 0;
		int repeat = 1;
		string str;

		cout << "歡迎使用本記帳程式\n";
		while (repeat)
		{
			cout << "1.記帳 2.關鍵字查帳 3.日花費查帳 : ";
			cin >> option;
			switch (option)
			{
			case '1':
				write();
				repeat = wel_re();
				break;
			case '2':
				cout << "\n請輸入關鍵字 : ";
				cin >> str;
				read(str);
				repeat = wel_re();
				break;
			case '3':
				total(search_ymd());
				repeat = wel_re();
				break;
			default:
				cout << "\n無效輸入\n\n";
				break;
			}
		}
	}

	int  wel_re()
	{
		char repeat = '3';
		cout << "\n請問要再使用本程式嗎?\n";
		while (repeat == '3')
		{
			cout << "1.要 2.不要 : ";
			cin >> repeat;
			switch (repeat)
			{
			case '1':
				repeat = '1';
				break;
			case '2':
				repeat = '0';
				cout << "\n歡迎再次使用!\n\n";
				break;
			default:
				repeat = '3';
				cout << "無效輸入\n\n";
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
			cout << "檔案開啟錯誤!\n";
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
					cout << "是否輸入正確(Y/N)? :";
					cin >> question;
				}
				if (question == 'Y' || question == 'y')
					filePtr.write((char*)&form, sizeof(form));
				else
					cout << "判斷為輸入錯誤，請重新輸入。\n";
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
			cout << "開啟輸入檔錯誤!\n";
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
			cout << "開啟輸入檔錯誤!\n";
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
				cout << "查無資料";
			}
			else
			{
				total.item = "日花費加總";
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
	cout << "請輸入日期: ";
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
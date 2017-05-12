#include <iostream>
#include <cstring>;

using namespace std;

class Date
{
private:
	double year;
	string item;
public:
	Date()
	{
		year = 0;
		item = "";
	}
	void setYear(int y)
	{
		year = y;
	}
	void setItem(string i)
	{
		item = i;
	}
	double getYear()
	{
		return year;
	}
	string getItem()
	{
		return item;
	}
	int search(string searchKey)
	{
		if(item == searchKey || dtos(year) == searchKey)
			return 1;
		else
			return 0;
	}
};

void write()
{
	Date temp;
	double year;
	string item;
	cin >> year;
	cin >> item;
	temp.setYear(year);
	temp.setItem(item);
	fwrite(&temp);
}

void read()
{
	Date temp;
	string searchKey;
	cin >> searchKey;
	while(eof)
	{
		fread(&temp);
		if(temp.search(searchKey))
		{
			cout << temp;
		}
	}
	
}
int main(void)
{
	write(form);
	read();
} 

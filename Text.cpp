#include "Text.h"
using namespace std;
Text::Text()
{
	columns = 0;
	rows = 0;
	ypos = 0;
	CONSOLE_SCREEN_BUFFER_INFO csbi;   									//member of windows.h 
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);  //gets the buffer size of the console window; the number of chars per column, row, etc
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;				 //column number of left subtractred from right equals number of columns per window 
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

string Text::replace(string s, char c, char d)
{
	//first char is char you want to replace, second is char to replace it with
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == c)
		{
			s[i] == d;
		}
	}
	return s;
}

string Text::remove(string s, char c)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == c)
		{
			std::remove(std::begin(s), std::end(s), c);
		}
	}
	return s;
}

void Text::trim()
//banner trimming 
{
	for (int i = 0; i < columns; i++)
	{
		cout << "~";
	}
	cout << "\n";
}

void Text::trim(char c)
{
	for (int i = 0; i < columns; i++)
	{
		cout << c;
	}
	cout << "\n";
}

void Text::middle()
{
	int half = (columns / 2);
	for (int i = 0; i < half; i++)
	{
		cout << " ";
	}
}
void Text::middle(int n)
{
	int half = (columns / 2) - n;
	for (int i = 0; i < half; i++)
	{
		cout << " ";
	}
}

string Text::pad(string s)
{
	s = " " + s + " ";
	return s;
}

string Text::pad(string s, char c)
{
	s = c + s + c;
	return s;
}

void Text::clear()
{
	//from https://stackoverflow.com/questions/17335816/clear-screen-using-c "the best way to do it"
	cout << "\033[2J\033[1;1H";
}

void Text::banner()
{
	string BCPA = "**BCPA TICKET PURCHASER** \n";
	trim();
	middle(BCPA.size() / 2);
	cout << BCPA;
	trim();
}

void Text::banner(string t)
{
	string BCPA = "**" + t + "** \n";
	trim();
	middle(BCPA.size() / 2);
	cout << BCPA;
	trim();
}



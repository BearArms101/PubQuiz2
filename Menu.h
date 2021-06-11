#pragma once
#include <string>
using namespace std;


class Menu
{
private:
	string name;
	int selection, category;

public:
	Menu();
	~Menu();
	void Setup();
	string Display();


};

#pragma once
#include <string>
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
//Question Class: pulls questions from file, formats them into plain language, iterates each into a vector which goes into a vector
class Question
{
private:
	string line;
	ifstream read;
	istream *readptr = &read;
	string question, category, type, difficulty, ans1, ans2, ans3, ans4, _str;
	int corrAns, nolines, count;
	vector<string> v;
	vector<string>* ptrv;
	vector<vector<string>> *ptrquestionlist;
	vector<vector<string>> questionlist;



public:
	string Format(string);
	vector<vector<string>> getQuestion();
	void ReadFile();
	void Store(Question*);
	void Output();
	Question();
	~Question();
};


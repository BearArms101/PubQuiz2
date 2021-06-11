#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <unordered_map>
#include "Question.h"
#include "BT.h"
#include "Text.h"
#undef max
#include <limits>

using namespace std;
class QuizMaster
{
private:
	//vector<vector<int>> questionlist; 
	vector<string> currentround;
	vector<vector<string>> questionlist;

	Question question;
	BT tree;
	Text cnslText;

	string cat, typ, dif, q, a1, a2, a3, a4;
	int count, input, corr, inco;
	int* ptrcount;

	unordered_map<string, int> numpairs;
	unordered_map<int, int> correctanswer;
	string aryQuestions[4];

	queue <int> queue;

	struct Node
	{
		int key;
		Node* left;
		Node* right;
	};
protected:


public:
	void Display();
	void Prepare();
	void Randomiser();
	QuizMaster();
	~QuizMaster();
};


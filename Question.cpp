#include "Question.h"

//bad name really. originally was going to be insantiated for each question, but found it preferable to just make a big vector
//the Store() method would have been more appropriate in QuizMaster, but I created very light documentation for myself and suffered for it. 

Question::Question() 
{
	//originally wanted to call the format method while initialising my vars, but couldn't find a way to keep the file stream open each call
	corrAns = 0;
	category, type, difficulty, question, ans1, ans2, ans3, ans4 = "";
	nolines = 0;
	count = 0;
	vector<string> v;
	vector<vector<string>> questionlist;
	vector<vector<string>>* ptrquestionlist = &questionlist;
	ptrv = &v;
}

Question::~Question() {
	corrAns = 0;
	question, ans1, ans2, ans3, ans4 = "";
}

void Question::ReadFile()
{
	read.open("Questions2.txt", ifstream::in);
	if (read.is_open() != true)
	{
		cout << "Failed to open file. Please try again.";
		cin.ignore();
	}
	do 
	{
		category = Format(category);
		type = Format(type);
		difficulty = Format(difficulty);
		question = Format(question);
		ans1 = Format(ans1);
		ans2 = Format(ans2);
		ans3 = Format(ans3);
		ans4 = Format(ans4);
		Store(this);
	} while (read.eof() != true);

	//Output();
	read.close();
	
}

void Question::Store(Question *q)
{
	v.clear();
	v.push_back(q->category);
	v.push_back(q->type);
	v.push_back(q->difficulty);
	v.push_back(q->question);
	v.push_back(q->ans1);
	v.push_back(q->ans2);
	v.push_back(q->ans3);
	v.push_back(q->ans4);
	questionlist.push_back(v);


}
string Question::Format(string s)
{
	//notes: category, type, difficulty, question, correct, [incorrects]
	getline(*readptr, s, ','); //comma is our delimiter, not whitespace
	s.erase(std::remove_if(s.begin(), s.end(), [](char c)
		//remove characters from our line
		{
			return c == '"' || c == '{' || c == '}'
				|| c == '[' || c == ']';
		}),
		s.end());

	for (int i = 0; i <= s.length(); i++)
		//add a white space after colons
	{
		if (s[i] == ':')
		{
			s.insert(++i, " ");
		}
		else if (s[i] == '*')
		{
			// is placeholder for commas in questions
			replace(s.begin(), s.end(), '*', ',');
			s.insert(++i, " ");
		}
	}
	return s;

}

vector<vector<string>> Question::getQuestion()
{
	return questionlist;
	
}

void Question::Output()
{
	//for debugging 
	cout << " cat:" << category << " ty:" << type << " di:" << difficulty << " qu:" << question << " 1:" << ans1 << " 2:" << ans2 << " 3:" << ans3 << " 4:" << ans4 << "\n";
}
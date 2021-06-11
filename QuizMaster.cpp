#include "QuizMaster.h"




QuizMaster::QuizMaster()
{
	cat, typ, dif, q, a1, a2, a3, a4 = " ";
	count, corr, inco = 0;
	ptrcount = &count;
	vector<string> currentround;
	vector<vector<string>> questionlist;
	
	struct Node
	{
		int key;
		Node* left;
		Node* right;
	};


}

QuizMaster::~QuizMaster()
{

}
void QuizMaster::Display()
{
	for (int i = 0; i <= 4; i++)
	{
		Prepare();
		cnslText.clear();
		cnslText.banner("PUB QUIZ");
		cout << cat << typ << dif << "\nRound " << *ptrcount << ": " << q << "\nPlease input an answer using the number keys: ";
		cout << "\n\n";

		for (int i = 0; i < 4; i++)
		{
			//question output
			cout << queue.front() << aryQuestions[i] << "\t";
			queue.pop();
		}
		bool flag = false;
		do
		{
			cin >> input;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (input == 1 || 2 || 3 || 4)
			{
				flag = true;
				cin.clear();
			}
			else if (input == 9)
			{
				exit;
			}
			else
			{
				cout << "Please make a valid selection between 1 and 4. There is no exit input, you must complete the quiz.";
				cin.clear();
			}
		} while (flag != true);

		//cout << numpairs[a1];
		if (input == numpairs[a1])
		{
			corr++;
			cout << "HOLE IN ONE! THAT IS CORRECT!";
		}
		else
		{
			inco++;
			cout << "A MISERABLE ATTEMPT. THAT IS INCORRECT!";
		}
		cin.get();
	}
	cout << "TOTAL CORRECT: " << corr << ". TOTAL INCORRECT: " << inco << ".";

	
}

void QuizMaster::Prepare()
{
	//responsible for dumping randomly chosen questions in vars, mainly as it's easier to type. Waste of memory.

	question.ReadFile(); 
	int row = rand() % (59 - 0 + 1);

	//would have been much more efficient to create the vector within this class, below is semi redudant code
	cat = question.getQuestion()[row][0] + " ";
	typ = question.getQuestion()[row][1] + " ";
	dif = question.getQuestion()[row][2] + " ";
	q = question.getQuestion()[row][3] + " ";
	a1 = cnslText.pad(question.getQuestion()[row][4]); //pad adds whitespace either side of str
	a2 = cnslText.pad(question.getQuestion()[row][5]);
	a3 = cnslText.pad(question.getQuestion()[row][6]);
	a4 = cnslText.pad(question.getQuestion()[row][7]);

	numpairs[q] = *ptrcount;
	Randomiser();

	//store our questions in an array to iterate through later

	count++;
}

void QuizMaster::Randomiser()
//responsible for assigning random question numbers for mapping to answers/question
//the map is used to check for correct answers by checking against ints instead of strings. Char would have been better as it is smaller size.

//hoped to populate a tree with a int range (1-4) and remove nodes of numbers that I allocated to answer strings. 
{

	int r = rand() % (4 - 1 + 1);
	switch (r)
		//our objective with the switch is to randomise the questions and push them into a queue, so they can 
		//... still be outputted in numerical order 
	{
	case 1:
		queue.push(numpairs[a1] = 1);
		queue.push(numpairs[a2] = 2);
		queue.push(numpairs[a3] = 3);
		queue.push(numpairs[a4] = 4);
		aryQuestions[0] = a1;
		aryQuestions[1] = a2;
		aryQuestions[2] = a3;
		aryQuestions[3] = a4;
		break;
	case 2:
		queue.push(numpairs[a4] = 1);
		queue.push(numpairs[a1] = 2);
		queue.push(numpairs[a2] = 3);
		queue.push(numpairs[a3] = 4);
		aryQuestions[1] = a1;
		aryQuestions[2] = a2;
		aryQuestions[3] = a3;
		aryQuestions[0] = a4;
		break;
	case 3:
		queue.push(numpairs[a3] = 1);
		queue.push(numpairs[a4] = 2);
		queue.push(numpairs[a1] = 3);
		queue.push(numpairs[a2] = 4);
		aryQuestions[2] = a1;
		aryQuestions[3] = a2;
		aryQuestions[0] = a3;
		aryQuestions[1] = a4;
		break;
	case 4:
		queue.push(numpairs[a2] = 1);
		queue.push(numpairs[a3] = 2);
		queue.push(numpairs[a4] = 3);
		queue.push(numpairs[a1] = 4);
		aryQuestions[3] = a1;
		aryQuestions[0] = a2;
		aryQuestions[1] = a3;
		aryQuestions[2] = a4;
		break;
	default:
		queue.push(numpairs[a1] = 1);
		queue.push(numpairs[a2] = 2);
		queue.push(numpairs[a3] = 3);
		queue.push(numpairs[a4] = 4);
		aryQuestions[0] = a1;
		aryQuestions[1] = a2;
		aryQuestions[2] = a3;
		aryQuestions[3] = a4;
		break;
	}
	/*Node* root = NULL;
	for (int i = 1; i <= 6; i++)
	{
		tree.Insert(root, i);
	} */
}


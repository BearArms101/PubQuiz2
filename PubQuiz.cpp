#include <iostream>
#include "Question.h"
#include "QuizMaster.h"
#include "BT.h"



// Pub Quiz 
// Creator: Alex Wood 02/06/21
// Small program that is focused on using data structures and learning how things work

int main()
{   
    BT tree;
    tree.Run();
    cin.get();
    Question test;
    Question test2;
    QuizMaster test3;
    //test3.Prepare();
    test3.Display();
    //test.Output();
    std::cout << "\nEnd";
    cin.get();
}

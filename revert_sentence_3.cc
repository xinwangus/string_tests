//
// A program to revert the words in a sentence.
// For example:
//     People in Pittsburgh love football
//        becomes 
//     football love Pittsburgh in People   
// better than version 1
//	This is a recursive idea
// other ideas:
//	to use a stack of strings
// 

#include <iostream>
#include <string>

using namespace std;

string
revert_sentence(const string& input_s)
{
	int p1 = input_s.find(" ");
	if (p1 == string::npos) return input_s;
	int p2 = input_s.find_first_not_of(" ", p1); // <<<< find from position p1
	if (p2 == string::npos) { return input_s; }

	// <<<< recursive
	return move(revert_sentence(input_s.substr(p2))) +  // p2 to the end
               move(input_s.substr(p1, (p2-p1))) + // space
               move(input_s.substr(0, p1)); // first part
}

int
main () 
{
	while (1) {
		cout << endl << "Please input a sentence: " << endl;

		string input_s;
		std::getline(cin, input_s); // getline(), cin, val

		cout << endl << "Transformed Sentence: " << endl;
		cout << revert_sentence(input_s) << endl;
	}
}


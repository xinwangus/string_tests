//
// A program to revert the words in a sentence.
// For example:
//     People in Pittsburgh love football
//        becomes 
//     football love Pittsburgh in People   
// better than version 1
// other ideas:
//	to use a stack of strings
// 

#include <iostream>
#include <string>

using namespace std;

string
revert_sentence(string& input_s)
{
	int p1 = input_s.find(" ");
	if (p1 == string::npos) { return input_s; }
	int p2 = input_s.find_first_not_of(" ", p1); // <<<< find from position, find_first_nof_of()
	if (p2 == string::npos) { return input_s; }
	string s = input_s.substr(p2);
	string ret = revert_sentence(s);
	// <<<< recursive
	return move(ret) + 
               move(input_s.substr(p1, (p2-p1))) + 
               move(input_s.substr(0, p1));
}

int
main () 
{
	while (1) {
		cout << endl << "Please input a sentence: " << endl;

		string input_s;
		std::getline(cin, input_s); // getline()

		cout << endl << "Transformed Sentence: " << endl;
		cout << revert_sentence(input_s) << endl;
	}
}


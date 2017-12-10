//
// A program to revert the words in a sentence.
// For example:
//     People in Pittsburgh love football
//        becomes 
//     football love Pittsburgh in People   
// 

#include <iostream>
#include <string>

using namespace std;

// l, r are the starting and stop positions
// of the word inside "s", that we want to
// revert.
void
revert_word (string& s, int l, int r)
{
	int i = 0;
	int len = r - l + 1;
	while (i < len/2) {
		char temp = s[l + i];
		s[l + i] = s[r - i];
		s[r - i] = temp;
		i++;
	}
}

void
revert_sentence (string& input_s)
{
	int len = input_s.length();
        int l = 0;
        int r = 0;
	bool done = false;

	// first revert every word
	while (!done) {
		// find starting point of next word.
		while (input_s[l] == ' ' && l < len) {
			l++;
		}
		// find stopping point of this word.
		r = l;
		while (input_s[r] != ' ' && r < len) {
			r++;
		}
		
		revert_word(input_s, l, (r - 1));

		// prepare for the next word.
		l = r;

		if (r >= len - 1) {
			done = true;
		}
	}

	// then revert the whole sentence
	revert_word(input_s, 0, (len - 1));
}

int
main () 
{
	while (1) {
		string input_s;
		cout << endl << "Please input a sentence: " << endl;

		std::getline(cin, input_s);

		cout << endl << ">>> Original Sentence: " << endl;
		cout << input_s << endl;

		revert_sentence(input_s);

		cout << endl << "<<< Transformed Sentence: " << endl;
		cout << input_s << endl;
	}
}


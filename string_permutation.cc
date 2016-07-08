#include <string>
#include <iostream>
#include <deque>
#include <assert.h>

using namespace std;

void
permutation(const char* str, unsigned int len, deque<string>& out)
{
	if ((str == 0) || (len == 0)) {
		return;
	}

	char head = str[0];
	if (len == 1) {
		assert(out.empty());
		assert(str);
		string tmp(&head, len);
		out.push_back(tmp);
		// cout << "Pushed " << tmp << endl; 
		return;
	}

	// call recursively.
	permutation((str+1), (len-1), out);
	// out now has all permutations for the rest of string.

	// Post-processing.
	// take all out, one by one, and do the insert.
	int s = out.size();
	for (int i = 0; i < s; i++) {
		string tmp = out.front();
		out.pop_front();
		// cout << "Poped " << tmp << endl; 

		string tmp2;
		// insert to all possible slots.
		for (int j = 0; j < tmp.size(); j++) {
			tmp2 = tmp;
			tmp2.insert(j, &head, 1);	
			out.push_back(tmp2);
			// cout << "Pushed " << tmp2 << endl; 
		}

		// last string is to append to the end.
		string last = tmp.append(&head, 1);
		out.push_back(last);
		// cout << "Pushed Last " << last << endl; 
	}
	// out now has all permutations for the string, str.
}

void
permutation(string& s, deque<string>& out)
{
	permutation(s.c_str(), s.size(), out);
}

int
main()
{
	string test("abcdef");
	deque<string> out;

	permutation(test, out);
	while (!out.empty()) {
		cout << out.front() << endl;
		out.pop_front();
	}
}

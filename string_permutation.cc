/* g++ -std=c++11 */

#include <string>
#include <iostream>
#include <deque>
#include <assert.h>

using namespace std;

void
permutation_recursive(const char* str, unsigned int len, deque<string>& out)
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
	permutation_recursive((str+1), (len-1), out);
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
permutation_recursive(string& s, deque<string>& out)
{
	permutation_recursive(s.c_str(), s.size(), out);
}


/* this is a much better solution, avoids recursive calls */
void
permutation_iterative(string& s, deque<string>& out)
{
	if (s.size() == 0) { return; }
	
	for (auto itr = s.begin(); itr != s.end(); ++itr) {
		if (itr == s.begin()) {
			assert(out.empty());
			out.push_back(string(&(*itr), 1));
			continue;
		}

		// need to save off, as the out.size()
		// will change.
		int out_size = out.size();

		for (int j = 0; j < out_size; j++) {
			string tmp = out.front();
			out.pop_front();

			string tmp2;
			for (int k = 0; k < tmp.size(); k++) {
				tmp2 = tmp;
				out.push_back(tmp2.insert(k, &(*itr), 1));
			}

			tmp2 = tmp;
			out.push_back(tmp2.append(&(*itr), 1));
		}	
		// Loop invariant:
		// by now "out" has all permutations of the string 
		// from beginning to the current itr position.
	}	
}

int
main()
{
	string test("abcdef");
	deque<string> out;

	//permutation_recursive(test, out);
	permutation_iterative(test, out);

	auto it = out.begin();
	while (it != out.end()) {
		cout << *it++ << endl;
	}
}

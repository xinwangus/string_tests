#include <string>
#include <iostream>

using namespace std;

void longest_sub (const string& m, const string& n, string& ret)
{
	const string* s = (m.size() > n.size())? &n : &m; // use pointer, use const!
	const string* b = (m.size() <= n.size())? &n : &m;

	if (b->find(*s) != string::npos) {
		ret = *s;
		return;
	}

	string ret_1;
	string ret_2;
	longest_sub(*b, s->substr(0, s->size() -1), ret_1);
	longest_sub(*b, s->substr(1, s->size() -1), ret_2);
	ret = (ret_1.size() > ret_2.size())? move(ret_1) : move(ret_2);
}

int main()
{
	string s1("I love something so badly!");
	string s2("We need to something soon");

	string ret;
	longest_sub(s2, s1, ret);
	cout << "Longest common sub string of " << endl
             << "\t" << s1 << endl
             << "and" << endl
             << "\t" << s2 << endl
             << "is" << endl
             << "\t \"" << ret << "\"" << endl;
	return 0;
}


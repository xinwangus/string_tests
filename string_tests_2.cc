/*
 * Last updated Jan 2021
 */
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//
// return the logest substr that has at most 
// k different characters.
//
// do it in O(N) way.
//

string 
longest_substr (string& in, unsigned int k)
{
	if (k == 0) { return "";}
	
	// hash table to track how many times
	// any uniq char appears.
	unordered_map<char, int> ht;

	// a and b are start and stop (1 over) of the range
	// two cursors moving forward, b first, then a.
	unsigned int a = 0;
	unsigned int b = 0;

	// the max so far
	unsigned int max_a = 0;
	unsigned int max_b = 0;

	while (b < in.size()) {
		// move b first and grow as much as can
		while ((ht.size() <= k) && (b < in.size())) {
			ht[in[b++]]++;
		}

		if ((b - a) > (max_b - max_a)) {
			max_a = a;
			max_b = b;
		}

		// move a and shrink the tracking hash table
		while (ht.size() > k) {
			ht[in[a]]--;
			if (ht[in[a]] == 0) {
				ht.erase(in[a]);
			}
			a++;
		}
	}
	// b is 1 over so that we were k+1, so need to -1
	// but how about b reached the end? then no need -1
	return in.substr(max_a, (max_b - max_a - 1));
}

int
main()
{
	string str1("cudshfifhvcbdsjaclas");
	cout << longest_substr(str1, 5) << endl;

	string str2("CudshFifhvcbDdsjaclas");
	cout << longest_substr(str2, 5) << endl;
}



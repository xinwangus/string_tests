#include <iostream>
#include <string>

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
	
	int char_count = 0;
	int ref_count[256] =  {0};

	unsigned int a = 0;
	unsigned int b = 0;
	unsigned int ai = 0;
	unsigned int bi = 0;
	unsigned int max_a = 0;
	unsigned int max_b = 0;

	while (b < in.size()) {
		do {
			bi = in[b] - 'A';
			if (ref_count[bi] == 0) {
				// new char.
				ref_count[bi] = 1;
				char_count++;
			} else {
				ref_count[bi]++;
			}		
			b++;
			if (b >= in.size()) break;
		} while (char_count <= k);

		if ((b - a) > (max_b - max_a)) {
			max_a = a;
			max_b = b;
		}

		do {
			ai = in[a] - 'A';
			if (ref_count[ai] == 1) {
				ref_count[ai] = 0;
				char_count--;
			} else {
				ref_count[ai]--;
			}		
			a++;
			if (a == b) break;
		} while (char_count > k);
	}
	// b was one position over, so do -1.
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



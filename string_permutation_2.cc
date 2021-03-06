// 
// C++ program to print all 
// permutations with duplicates allowed 
// from a string
// Much cleaner than the first version
// swap-recursive-backtrack
//
#include <stdlib.h> 
#include <string>
#include <iostream>

using namespace std; 

void permute(string& a, int l, int r) 
{ 
	if (l == r) {
		cout << a << endl;  // could save off as well
                                    // this prints out the whole string
	} else { 
		for (int i = l; i <= r; i++) 
		{ 
			swap(a[l], a[i]); 
			// recursion
			permute(a, l+1, r); 
			//backtrack, important!
			swap(a[l], a[i]); 
		} 
	} 
} 

int main() 
{ 
	string str = "abcdef"; 
	int n = str.size(); 
	permute(str, 0, n-1); 
	return 0; 
} 



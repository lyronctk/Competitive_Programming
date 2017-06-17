#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ main.cpp
// ./a.out

int main(){
	ifstream f1("f1.txt"); ifstream f2("f2.txt");

	bool equal = true;
	string s1, s2;
	for(int i=1; !f1.eof(); i++){
		getline(f1, s1);
		getline(f2, s2);

		if(s1 != s2){
			equal = false;
			cout << "Files are not identical (at line #" << i << ")" << endl;
			cout << "f1: " << s1 << endl << "f2: " << s2 << endl << endl;
		}
	}
	if(equal)
		cout << "Files are identical!" << endl;
}
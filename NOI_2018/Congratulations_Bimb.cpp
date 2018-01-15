#include <iostream>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp

const string SUBJECTS[] = {"Art", "English", "Handwriting", "History", "Math", "P.E.", "Phonics", "Reading", "Religion", "Science/Health", "Spelling", "Vocabulary"};
const string QUARTERS[] = {"1ST", "2ND", "3RD", "4TH"};

string getLetterGrade(int gr) {
	if(gr >= 97) return "A+";
	if(gr >= 93) return "A";
	if(gr >= 90) return "A-";
	if(gr >= 87) return "B+";
	if(gr >= 83) return "B";
	if(gr >= 80) return "B-";
	if(gr >= 77) return "C+";
	if(gr >= 73) return "C";
	if(gr >= 70) return "C-";
	if(gr >= 67) return "D+";
	if(gr >= 63) return "D";
	if(gr >= 60) return "D-";
	return "F";
}

int main() {
	freopen("in.txt", "r", stdin);
	
	int c; scanf("%d", &c);
	for(int i=0; i<c; i++) {
		int q, t; scanf("%d\n%d", &q, &t);
		cout << "CONGRATULATIONS BIMB!" << endl << QUARTERS[q-1]
			 << " QUARTER GRADES" << endl;
		for(int j=0; j<12; j++) {
			int gr; scanf("%d", &gr);
			if(gr >= t) cout << SUBJECTS[j] << ": " << getLetterGrade(gr) << endl;
		}
	}
}
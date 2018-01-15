#include <iostream>
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp

bool marked[10];
int main() {
	// freopen("in.txt", "r", stdin);
	
	int n; scanf("%d", &n);
	for(int i=0; i<n; i++) {
		fill(marked, marked+10, true);
		for(int j=0; j<9; j++) {
			int dig; scanf("%d", &dig);
			marked[dig] = false;
		}
		for(int j=0; j<10; j++) if(marked[j]) printf("%d", j);
	}
	printf("\n");
}
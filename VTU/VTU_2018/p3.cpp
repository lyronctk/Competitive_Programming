#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool marked[110];
int main() {
  int n, y; scanf("%d %d", &n, &y);

  int k;
  for(int i=0; i<y; i++) {
     scanf("%d", &k); marked[k] = 1;
  }

  int ctr=0;
  for(int i=0; i<n; i++)
    if(marked[i]) ctr++;
    else printf("%d\n", i);
  printf("Mario got %d of the dangerous obstacles.\n", ctr);
}

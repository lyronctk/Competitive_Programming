#include <vector>
#include <iostream>
using namespace std;

struct PCL { int up, left, down, right; };
const int dR[] = {0, 0, -1, 1}, dC[] = {-1, 1, 0, 0};

char grid[20+1][20+1];
bool visited[20+1][20+1];
void dfs(int r, int c, char color, int up, int left, int down, int right) {
    if(r<up || r>down || c<left || c>right || visited[r][c] || grid[r][c] != color) return;
    visited[r][c] = true;
    for(int i=0; i<4; i++) dfs(r+dR[i], c+dC[i], color, up, left, down, right);
}

int nRegions[26+1];
bool validPCL(int up, int left, int down, int right) {
    for(int i=0; i<26+1; i++) nRegions[i] = 0;
    for(int i=up; i<=down; i++) for(int j=left; j<=right; j++) visited[i][j] = false;

    int nColors=0;
    for(int i=up; i<=down; i++)
        for(int j=left; j<=right; j++)
            if(!visited[i][j]) {
                nColors += (nRegions[grid[i][j]-'A'] == 0);
                nRegions[grid[i][j]-'A']++;
                dfs(i, j, grid[i][j], up, left, down, right);
            }

    bool cond1=false, cond2=false;
    for(int i=0; i<26+1; i++) {
        if(nRegions[i] == 1) cond1 = true;
        if(nRegions[i] > 1) cond2 = true;
    }
    return (nColors == 2 && cond1 && cond2);
}

vector<PCL> v;
bool insidePCL(int x) {
    for(int i=0; i<v.size(); i++) 
        if(i!=x && v[i].up <= v[x].up && v[i].left <= v[x].left 
                && v[i].down >= v[x].down && v[i].right >= v[x].right)
            return true;
    return false;
}

int main() {
    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);

    int N; scanf("%d", &N);
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf(" %c", &grid[i][j]);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k=i; k<N; k++)
                for(int l=j; l<N; l++)
                    if(validPCL(i, j, k, l))
                        v.push_back({i, j, k, l});

    int ctr=0;
    for(int i=0; i<v.size(); i++) ctr += !insidePCL(i);
    printf("%d\n", ctr);

    return 0;
}
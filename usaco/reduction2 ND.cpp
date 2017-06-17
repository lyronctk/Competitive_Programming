#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <map>
using namespace std;

struct Point{
    int x, y;
};

Point pointsX[50001], pointsY[50001], pick[12];
map<Point,bool> m;
int cmprX(Point p1, Point p2){
    return p1.x > p2.x || (p1.x == p2.x && p1.y>p2.y);
}
int cmprY(Point p1, Point p2){
    return p1.y > p2.y || (p1.x == p2.x && p1.y>p2.y);
}

int minArea = INT_MAX, N;
void generate(){
    for(int i=0; i<N; i++){
        if(pointsX[i].x < )
    }
}

int present(Point p, int x){
    for(int i=0; i<x; i++){
        if(pick[i].x == p.x && pick[i].y == p.y)
            return 1;
    }
    return 0;
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        Point p;
        scanf("%d %d", &p.x, &p.y);
        pointsX[i] = p;
        pointsY[i] = p;
    }
    
    sort(pointsX, pointsX+N, cmprX);
    sort(pointsY, pointsY+N, cmprY);
    
    for(int i=0; i<3; i++)
        pick[i] = pointsX[i];  //maxX
    for(int i=0; i<3; i++)
        if( !present(pointsX[N-i-1], 3) )
            pick[i+3] = pointsX[N-i-1]; //minX
    for(int i=0; i<3; i++)
        if( !present(pointsY[i], 6) )
            pick[i+6] = pointsY[i]; //maxY
    for(int i=0; i<3; i++)
        if( !present(pointsY[N-i-1], 9) )
            pick[i+9] = pointsY[N-i-1]; //minY
    
    for(int i=0; i<12; i++)
        for(int j=i+1; j<12; j++)
            for(int k=j+1; k<12; k++){
                m[pick[i]] = true;
                m[pick[j]] = true;
                m[pick[k]] = true;
                generate();
                m[pick[i]] = false;
                m[pick[j]] = false;
                m[pick[k]] = false;
            }
    
    printf("%d\n", minArea);
}
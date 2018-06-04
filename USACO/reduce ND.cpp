#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct Point{
    int x, y;
};

Point points[50001], maxX[4], minX[4], maxY[4], minY[4];
int cmprX(Point p1, Point p2){
    return p1.x > p2.x || (p1.x == p2.x && p1.y>p2.y);
}
int cmprY(Point p1, Point p2){
    return p1.y > p2.y || (p1.x == p2.x && p1.y>p2.y);
}

int minArea = INT_MAX, N;
void calculate(int minXp, int maxXp, int minYp, int maxYp){
    Point minXv = minX[minXp+1];
    Point maxXv = maxX[maxXp+1];
    Point minYv = minY[minYp+1];
    Point maxYv = maxY[maxYp+1];
    
    int counter = 0;
    for(int i=0; i<N; i++){
        if(points[i].x < minXv.x || points[i].x > maxXv.x || points[i].y < minYv.y || points[i].y > maxYv.y)
            counter++;
//        printf("%d\n", counter);
        if(counter > 3)
            return;
    }
    minArea = min(minArea, (maxXv.x-minXv.x)*(maxYv.y-minYv.y));
}

int main(){
    freopen("/Users/lyronctk/Desktop/usaco/usaco/in.txt", "r", stdin);
    
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        Point p;
        scanf("%d %d", &p.x, &p.y);
        points[i] = p;
    }
    
    
    sort(points, points+N, cmprX);
    for(int i=0; i<4; i++){
        maxX[i].x = points[i].x;
        maxX[i].y = points[i].y;
        minX[i].x = points[N-i-1].x;
        minX[i].y = points[N-i-1].y;
    }
    
    sort(points, points+N, cmprY);
    for(int i=0; i<4; i++){
        maxY[i].x = points[i].x;
        maxY[i].y = points[i].y;
        minY[i].x = points[N-i-1].x;
        minY[i].y = points[N-i-1].y;
    }
    
//    for(int i=0; i<4; i++)
//        printf("(%d, %d) ", maxX[i].x, maxX[i].y);
//    printf("\n");
//    for(int i=0; i<4; i++)
//        printf("(%d, %d) ", maxY[i].x, maxY[i].y);
//    printf("\n");
//    for(int i=0; i<4; i++)
//        printf("(%d, %d) ", minX[i].x, minX[i].y);
//    printf("\n");
//    for(int i=0; i<4; i++)
//        printf("(%d, %d) ", minY[i].x, minY[i].y);
//    printf("\n");
    
    for(int i=0; i<3; i++)
        for(int j=0; j+i<3; j++)
            for(int k=0; k+j+i<3; k++)
                for(int a=0; a+k+j+i<3; a++){
                    calculate(i, j, k, a);
                }
    printf("%d", minArea);
}

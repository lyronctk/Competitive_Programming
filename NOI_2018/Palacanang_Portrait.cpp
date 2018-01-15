#include <iostream>
#include <math.h> 
using namespace std;
// clang++ -std=c++11 -stdlib=libc++ general.cpp

double calcCost(double diagonal, double p, double d) {
	return 0.5*diagonal*diagonal*p + 2*sqrt(2)*diagonal*d;
}

int main() {
	freopen("in.txt", "r", stdin);
	
	int t; scanf("%d", &t);
	for(int i=0; i<t; i++) {
		double x0, y0, x2, y2, p, b; 
		scanf("%lf %lf %lf %lf\n%lf %lf", &x0, &y0, &x2, &y2, &p, &b);
		printf("%.10f ", calcCost(sqrt((x0-x2)*(x0-x2)+(y0-y2)*(y0-y2)), p, b)); 
		
		double x1 = (x0+x2+y0-y2)/2, y1 = (y0+y2+x2-x0)/2;
		double x3 = (x0+x2+y2-y0)/2, y3 = (y0+y2+x0-x2)/2;
		printf("%.10f %.10f %.10f %.10f\n", x1, y1, x3, y3);
	}
}
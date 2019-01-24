#include <bits/stdc++.h>
using namespace std;

int main() {
	int pointsInsideCircle=0,totalPoints=0;
	float x,y;
	
	while(pointsInsideCircle<=2000000)
	{
	    x = (float)(rand()%10)/10;
	    y = (float)(rand()%10)/10;
	    
	    if((x*x + y*y) <= 1.0)
	        pointsInsideCircle+=1;
	    
	    totalPoints+=1;
	}
	
	float pi = (float)(4 * pointsInsideCircle)/totalPoints;
	cout<<pi;
	return 0;
}
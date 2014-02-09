/*

As Valentine's Day is fast approaching, Dodo plans to take his girlfriend, Becky on a surprise date today itself. However, being overloaded with work Becky asks for Dodo's help. Her Math assignment is as follows : given the coordinates of the centre of the circle and a point on its circumference, find if the given point (x, y) lies inside or on the circle or not. Being poor in Math, Dodo asks you to help him. 

Input:
The first line contains T, the number of test cases. T test cases follow. Each test case consists of 3 lines :
1st line contains the coordinates of the center of the circle
2nd line contains the coordinates of the point on the circumference of the circle
3rd line contains the coordinates of the point (x, y) whose position wrt has to be determined 

Output:
Output T lines either YES if the given point lies inside the circle or on its circumference, NO otherwise. 

Constraints:
1 <= T <= 1000
The coordinates of the points are integers in the range [-5000, 5000] 

Sample Input:
2
0 0
3 3
2 2
5 5
9 9
9 9


Sample Output:
YES
YES


Solution : 

	For a point to lie on or within a circle , the distance between the point and the center of the circle has to be equal to or less than the radius of the circle. Therefore find the radius r , distance d between center and the arbitary point and compare the two .
Conversely , it is sufficient to compare the values r^2 and d^2 , therefore avoiding using the sqrt function .	
Distance between two points can be found using the formula : d^2 = (x1 - x2)^2 + (y1 - y2)^2

*/



// CODE


#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	int t ;

	cin>>t;

	while(t-->0)	// Iterating through all the test cases
	{
		int x , y , h  , k ;		// Centre of the circle (h,k) ; Point on the circumfurence (x,y)

		cin>>h>>k>>x>>y;

		double radius = ((x-h) * (x-h)) + ((y-k) * (y-k)) ;	// Distance formula 
		
// Note : Performing square root on radius isn't required as we can instead compare the square of the distances  

		int x1 , y1 ;			// Arbitary Point (x1,y1)

		cin>>x1>>y1 ;

		double dist =  ((x1-h) * (x1-h)) + ((y1-k) * (y1-k)) ;

		if(dist <= radius )		
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}


	return 0 ;

}

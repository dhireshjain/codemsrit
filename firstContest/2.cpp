/*

After completing the first assignment, Dodo was then asked to do Becky's second assignment. In this given N numbers, calculate the product of all N numbers. Since this product may be large, it is necessary to display only the digits in the ten's and the unit's place. Your task is to help Dodo solve this. 

Input:
The first line contains T, the number of test cases. T test cases follow. Each test case consists of 2 lines :
1st line contains N, the number of integers
2nd line contains N space separated integers


Output:
Output T lines each line containing the anser for that test case. 

Constraints:
1 <= T <= 20
1 <= N <= 30
The integers are all positive and do not exceed 2000 

Sample Input:
2
4
45 67 88 12
5
45 67 78 9 19 

Sample Output:
40
70 

Explanation: In the first test case, the product of the given numbers is 3183840 and hence the digits in the ten's and unit's place is 40.


Solution:
	Multiplying all the numbers and storing it in a variable may cause overflow for large test cases. Since we need to print only the last 2 digits , storing only the last 2 digits of the product after each successive multiplication will give us the right answer.
For example , consider the numbers 418 , 314 , 678.
On multiplying 418 and 314 , we get 418*314 =  131252. Instead of storing this number for the next multiplication , we may store only the last 2 digits i.e 52 . Next operation would be 52*678 = 56 ,  which is the desired answer.


*/


// CODE

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>

using namespace std;

int main()
{
	int t , n , result  ;
	
	cin>>t;

	while(t-->0)
	{
		cin>>n;
		
		result = 1 ;	// Result has to be intialized to 1 for each test case
		
		for( int i = 0 ; i < n ; i++ )
		{
			int x;

			cin>>x ;
			
			result *= x ;

			result = result%100;	// Storing only the last 2 digits after every successive multiplication is sufficient

		}

	if(result > 9 )
		cout<<result<<endl ;
	else
		cout<<"0"<<result<<endl;	// In case of the ten's place being zero ,  we need to manually print it 

	}


}

/*

On the verge of leaving for their date, Dodo gets reminded of his undone Math assignment. Given an integer N count all unique pairs of numbers (a, b) where both a and b divide N completely, ie, a and b are both factors of N and a, b, N are all even. Dodo needs your help in solving it for him as he is getting late for his date. 

NOTE: Here pairs (2, 4) and (4, 2) are the same and to be counted only once. However a pair like (4, 4) is to be counted once. 

Input:
The first line contains T, the number of test cases. T test cases follow. The next T lines consists of the number N. 

Output:
Output T lines, each line containing the number of unique pairs for that test case. 

Constraints:
1 <= T <= 1000000
1 <= N <= 10000000


Sample Input:
2
16
3 

Sample Output:
2
0 

Explanation: For 16, the pairs include (2, 8), (4, 4), (8, 2). However since the pair (2, 8) and (8, 2) are both the same, the number of unique pairs is 2.


SOLUTION:
	Normal or prime factorization method is of root n complexity but isn't fast enough to print the answer for all test cases within the time limit. Since the value of N does not exceed 10^7 ,  we can use this to our advantage . Create an array of size 10^7 - one element for each of the numbers from 1 to 10^7 - and using a similar approach to Sieve Of Eratosthenes , compute the number of even factor pairs for each number. This is done by using a nested loop to generate every possible pair of even numbers whose product is less than or equal to the maximum possible value of n i.e 10^7 ( (2,2) (2,4) (2,6)...(4,2)(4,4)... so on ). Multiply each pair , and increment the element at the corresponding index (equal to the product) by one. Therefore for pair (2,2) the product being 4 do the operation : array[4]++ . Similarily for (4,6) we do array[24]++. In this way , we would have computed the number of even factor pairs for each number N. For each test case , print the array element corresponding to that index position(N).


*/

// CODE

#include<iostream>

using namespace std;

int num[10000001];


int main()
{

	for(int i =  0 ; i<10000001 ;i++)	// Intializing all elements of the array to zero
		num[i]=0;


//	Precomputing the answer for all the elements (  1 >= n <= 10000000 )  

//	This is done by generating all possible combination of even numbers - (i,k) : the pairs being such that the product of each pair is less than or equal to 10^7 . The element at the index position j (which is the product of each pair : j = (i * k) ) is then incremented by one . 

// Note : This is an application of Sieve of Eratosthenes.

	for( int i = 2; i < 10000001; i+=2 )	
	{
		for( long long int k = i , j = k * i ; j < 10000001 ; k += 2, j = k * i ) 
			num[(int)j]++;
	}


	int  t ;

	scanf("%d",&t) ;

	for( int  i = 0 ; i  < t ; i++ )
	{
		int x ;
		scanf("%d",&x);
		printf("%d\n",num[x]);	// Given a number x, the element at that index position i.e num[x] gives us the answer.
	}


}


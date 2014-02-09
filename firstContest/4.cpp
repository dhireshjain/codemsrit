/*

Becky now wants to try her hand at solving another string puzzle but this time she decides to do it with Dodo. Given a string S of length L consisting of lowercase English alphabets only and an integer i, find the number of all possible substrings starting with 'a' and ending with 'b' in the range [i, L] (both i and L inclusive). But this being too easy, they are asked many such queries. Since doing it manually takes alot of time, they come to you for help. 

Input:
The first line contains the string S. The next line contains an integer Q, the number of queries.
This is followed by Q lines each containing an integer i, the position from where to consider substrings. 

Output:
Output Q lines, each line containing the number of desired substrings. 

Constraints:
1 <= L(Length of string S) <= 10000000
1 <= Q <= 100
1 <= i <= L


Sample Input:
aaabcbab
4
5
3
2
1


Sample Output:
1
4
7
10


Explanation: For the first query, all possible substrings starting from position 5 include { "c", "cb", "cba", "cbab", "b", "ba", "bab", "a", "ab", "b" } of which only one substring (ie "ab") starts with an 'a' and ends with a 'b' and hence the answer is 1.


*/


// CODE

#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main ()
{


	char *str = (char * ) malloc ( sizeof(char) * 1000000 )  ;

	cin>>str;

	int l = strlen(str);

	int count[l+1] , track[l+1] ;

	// Intializing elements of the arrays with the value 0

	memset(count , 0 , sizeof(count) );

	memset(track , 0 , sizeof(track) );
	
	// We count the number of 'b' occuring (from right to left) upto the i'th element and store it in the array count[]

	for ( int i = l - 1 ; i >= 0 ; i-- )
   	{
		if(str[i] == 'b' )
			count[i] = count[i+1] + 1 ;
		else
			count[i] = count[i+1] ;
 	}

// 	Traversing from left to right :
//	if an 'a' occurs at the the current (i+1) position : the number of legitimate substrings upto that position is given by adding the number of 'b' occuring (from right to left) upto the i'th position and the number of legitimate substrings (from left to right) upto the i'th position.
//	else the number of legitimate substrings upto that position is the same as upto the previous position

	for ( int i = 0 ; i < l ; i++ )
	{
		if(str[i] == 'a' )
			track[i + 1 ] = track[i] + count[i] ;
		else
			track[i + 1 ] = track[i] ;
	}

	int q ;

	cin>>q;

	while ( q-- > 0 )
	{
		int x;

		cin>>x;

		int answer = track[l] - track[x-1] ;

		cout<<answer<<endl ;
	}

	
}

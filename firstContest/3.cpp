/*

While Dodo was solving her Math assignment, Becky was trying to solve a word game but found it very tricky. Dodo decides to help her knowing he can rely on you. You are given a string S of length L1 consisting of lowercase English alphabets. You are given another string P of length L2 which consists of only D and R(uppercase) each of which denote the following operation:
D: Don't do anything to the string
R: If R occurs at the position i in the string P, then reverse the characters in string S from position i to L1 - i + 1
Finally after all the operations are performed, output the resultant string. 

Input:
The first line contains T, the number of test cases. T test cases follow. Each test case consists of 2 lines :
1st line contains S, the given string
2nd line contains P, the string denoting the operations to be performed on S


Output:
Output T lines, each line containing the resultant string obtained after all operations are performed 

Constraints:
1 <= T <= 60
1 <= L1 <= 100000
L2 = L1/2


Sample Input:
1
abcdef
RDR


Sample Output:
fecdba 

Explanation: Given string is "abcdef" (without quotes), and the operations to be performed are "RDR"
1st character in P is 'R', hence reverse S starting from position 1 to position 6 resulting in S now being fedcba
2nd character in P is 'D', hence do nothing
3rd character in P is 'R', reverse S (which is now fedcba) starting from position 3 to position 4 resulting in S now being fecdba




Solution :
	 The number of operations is always equal to half the length of the string. For an operation 'R', we need to reverse the substring string[ i .... L1-i+1 ]. Reversing substrings becomes clumsy and we can avoid this by instead swapping 2 characters at a time.
For an operation i (1 to L2) , we notice that the characters at index less than i and greater than index L1-i+1 are 'not affected by this operation'. 
	We keep track of the number of times a character at a pariticular index is reversed, or in other words the number of times the operation 'R' is performed on a particular character.  When the i'th character is reversed, it gets swapped with the character at position L1-i+1.
	If a reverse operation is performed again at the same index, the characters at i and L1-i+1 get swapped again hence go back to their original position. Therefore , if the reverse operation 'R' is performed even number of times on the character at a particular index, it remains at the the same position. Similarily, if 'R' is performed odd number of times on the i'th chracter , it gets swapped with the character at L1-i+1.
	For instance : 
abcdef 
RDR
	
L1=6 , L2=3 
We traverse through the characters from a(1) to c(3).

R is performed once on the character 'a'. Therefore it gets swapped with 'f'(L1-i+1 = 6-1+1 = 6)

Operation D is performed next. The number of 'R' is the same i.e. 1.
Therefore 'b' and 'e' gets swapped (i=2 , L1-i+1 = 6-2+1 = 5)

Operation R is performed next. The number of 'R' perfomed now is 2.
The characters c and d remain the same. 

Resultant string : fecdba

Note: Incase of strings of odd length, the character at the middle(L2+1) , always remains at the same place.
*/



// CODE

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int main()
{
  	int t;

	cin>>t;

	while( t-- > 0 )
	{

		char *str = (char*) malloc ( sizeof(char) * 10000000 ) ;

		char *operation = (char * ) malloc ( sizeof(char) * 5000000 ) ;

		char * result = (char * ) malloc ( sizeof(char) * 10000000 ) ;

		cin>>str ;

		cin>>operation ;

		int size = strlen(str);

		int l = size/2 ;

		int a[l+1] ;

		a[0] = 0 ;

		for( int  i = 1  ; i <= l ; i++ )	// Count the number of times R is performed upto the i'th index.
		{
			if(operation[i-1] == 'R' )
			a[i] = a[i-1] + 1 ;

			else
			a[i] = a[i-1] ;

		}

		for( int i = 1 ; i <= l ; i++ )
		{
			if(a[i]%2 == 0 )	// R perfomed even number of times. Characters remain in the same position.
			{
				result[ i - 1 ] = str [ i - 1 ] ;

				result[size - i + 1 - 1 ] = str[size - i + 1 - 1 ]  ;
			}
			else			// R performed odd number of times. Swap the characters
			{
				result[ i - 1 ] = str [ size - i + 1 - 1 ] ;

				result[ size - i + 1 - 1 ] = str [ i - 1 ] ;
			}

		}

		if( size%2 == 1 )
		result[l] = str[l] ;

		result[size] = '\0' ;

		cout<<result<<endl;

		delete []str;
		delete []operation;
		delete []result;

	}
		

}

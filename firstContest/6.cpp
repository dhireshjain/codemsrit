/*

Finally Becky and Dodo leave for their date only for Becky to realise her flower garden has expanded to N flowers of different colours. Becky is amused and wants to know the number of unique colours among flowers in her garden. The flowers are denoted by values from 1 to N. As Dodo is already waiting for her, she gives you M pairs of flowers that have the same colour. Your task is to find the number of unique colours among all flowers. If a flower does not belong to any pair, then its colour is unique. 

Input:
The first line contains T, the number of test cases. T test cases follow.
The first line of each test case consists of 2 space separated integers N and M.
M lines follow. Each of the M lines consists of two integers a and b denoting the pair of flowers with same colour. 

Output:
Output T lines, each line containing the number of unique flowers for that test case. 

Constraints:
1 <= T <= 100000
1 <= N, M <= 100000
1 <= a, b <= N and a is not equal to b 

Sample Input:
1
6 3
1 2
2 3
5 6 

Sample Output:
3 

Explanation: Here flowers { 1, 2, 3 } have the same colour, { 5, 6 } have the same colour and { 4 } has its own colour amounting to 3 unique colours.


*/



// This problem is basically to solve number of connected components in a graph.

#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

// This "visited" vector is to keep track of all the nodes that have already been visited.

vector<bool> visited;

// This is a container used to store the graph as an adjacency list.

vector<vector<int> > adjList;

// This variable stores the total number of connected components.

int components=0;

// This function does a depth-first-search traversal on the graph.
// It takes the parameter s, which is the source vertex.
// Calling this function with all the vertices as the source vertex and incrementing,
// the variable "components" for each call will give us the required solution.

void dfs(int s)
{
    visited[s]=true;
    vector<int>::iterator it;
    for(it=adjList[s].begin();it!=adjList[s].end();it++)
    {
        if(!visited[*it])
        {
            dfs(*it);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,n,m,p,q;
        components=0;
        cin>>n>>m;
        adjList=vector<vector<int> > (n);
        visited=vector<bool> (n,0);
        while(m--)
        {
            cin>>p>>q;
            
            p--;           
                          		// required because the vertices should range from 0 to n-1
            q--;
            
            adjList[p].push_back(q);   
            				  // adding each vertex in the list of its neighbour do denote an edge.
            adjList[q].push_back(p);

        }
        for(i=0;i<n;i++)                 // calling the dfs with each vertex as the source.
        {
            if(!visited[i])
            {
                dfs(i);
                
                components++;
            }
        }
        cout<<components<<endl;         // printing the final result.
    }

}

// NOTE: This problem can be solved by Weighted Union Find algorithm which is more efficient compared to DFS.
// The time complexity of DFS is O(V+E), whereas for Weighted Union Find the complexity is O(alpha(n))
// alpha(n) is the inverse ackermann function, alpha(2^65536) is less than 4 and 2^65536 is a number which
// is greater than all the particles in the universe :) , hence the run time is constant for all practical
// purposes.

// Satya Krishna Gorti.

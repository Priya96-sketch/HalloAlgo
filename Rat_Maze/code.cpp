#include<iostream>
#include<vector>
using namespace std;

//Defining a function -> It's job is to determine whether the rat is within the boundary or not.
bool isItSafe(int i, int j, int n){
    return i>=0 and i<n and j>=0 and j<n; //This return function verifies that the rat is within the boundary if and only
                                         //  if all the conditions are satisfied.
}
// Making a Global Variable
int result = 0;

//Here we are sending the array through reference and i & j here is the starting point.
void ratInMaze( vector<vector<int> > &arr, int n, int i, int j, vector<vector<int> > &visited )
{

    //Case -> If the destination is blocked.
    // Here as indexing starts from 0, and n is our destination, hence (n-1) is our destination according to zero-indexing.
    if(arr[n-1][n-1] == 1) return; 
    //Case -> One possible way
    if(i == n-1 and j == n-1){
        result++;
        return;
    }
    // Case -> Whether it is safe or not, i.e, Out of boundary or within boundary.
    if(not isItSafe(i,j,n)){
        return;
    }
    visited[i][j]=1;   //Before moving up, down, right or left, firstly, we will visit the visited cell.

    //up
    if(isItSafe(i-1,j,n) and arr[i-1][j] == 0 and visited[i-1][j] == 0){
       ratInMaze(arr, n, i-1, j, visited); 
    }

    //down
    if(isItSafe(i+1,j,n) and arr[i+1][j] == 0 and visited[i+1][j] == 0){
       ratInMaze(arr, n, i+1, j, visited); 
    }

    //right
    if(isItSafe(i,j+1,n) and arr[i][j+1] == 0 and visited[i][j+1] == 0){
       ratInMaze(arr, n, i, j+1, visited); 
    }

    //left
    if(isItSafe(i,j-1,n) and arr[i][j-1] == 0 and visited[i][j-1] == 0){
       ratInMaze(arr, n, i, j-1, visited); 
    }
    visited[i][j]=0; //For fresh visiting, if a block is already visited and it's the only path by which we can go to the destination
}


int main()
{
    int n;
    cin>>n;
    //2D Vector
    vector<vector<int> >arr(n, vector<int>(n,0));  // n denotes the row and each row is of a vector of size n and value 0.
    vector<vector<int> >visited(n, vector<int>(n,0));  // Visited vector
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    ratInMaze(arr,n, 0, 0, visited);  
    cout<< result;  //This call will fetch us the answer.
   
}

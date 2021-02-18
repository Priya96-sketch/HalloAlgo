#include<iostream>
using namespace std;


void countSort(int arr[], int n)
{
    int max_arr =arr[0];
    int k =arr[0]; //this max_arr will tell us the maximum value, that means the maximum number of elements in the array
    for(int i=0;i<n;i++)
    {
        max_arr =max(k,arr[i]);
    }

    int count[10]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }

    for(int i=1;i<=k;i++){  //traversing the whole count array.
        count[i]+=count[i-1];
    }

    int output[n];
    for(int i=n-1;i>=0;i--)
    {
        output[--count[arr[i]]]=arr[i]; 
    }
    //Now we are putting the output array to the original array
    for (int i = 0; i < n; i++)
    {
        arr[i]=output[i];
    }
    
}

int main()
{
    int arr[]={1,3,2,3,4,1,6,4,3};
    countSort(arr,9);
    for(int i=0;i<9;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}

//BubbleSort//
//Notice the no. of iterations:
//If ith iteration = (n-1)

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    //Main algorithm
    int counter=1; //for the iterations
    while(counter<n-1)
    {
        for(int i=0;i<n-counter;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
        counter++; //so that it moves to the next iteration//
    }

   //Printing the array//
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}


//Dutch National Flag Sorting - aka 0,1,2 Sort
#include<iostream>
using namespace std;

void swap(int arr[], int i, int j){
    int temp =arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

//dnfSort is the function, wherein we will pass the parameter array(arr[]) and the size of the array(n)
void dnfSort(int arr[], int n){
    int low=0;   //low is 0 because we start the low pointer from the beginning
    int high=n-1;  //high is placed at the end/end element of the array
    int mid=0;    //mid is also 0 as it starts from the beginning and iterates through each element

    while(mid<=high)
    {
        if(arr[mid]==0){
            swap(arr, low, mid);
            low++;
            mid++;
        }
        else if (arr[mid]==1)
        {
            mid++;
        }
        else{
            swap(arr,mid,high);
            high--;
        }
    }
}

    int main()
    {
        int arr[]={1,0,2,1,0,1,2,1,2};
        dnfSort(arr,9);
        
        for(int i=0;i<9;i++)
        {
            cout<<arr[i]<<" ";
        }
        return 0;
    }


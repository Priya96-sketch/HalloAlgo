//Sorting -> QuickSort
#include<iostream>
using namespace std;

//Algorithm
//Swap Function
void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
//Partition Function
int partition(int arr[], int l, int r)
{
    int pivot =arr[r];
    int i= l-1;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}

//QuickSort Function
void quickSort(int arr[], int l, int r)
{
    if(l<r){
        int pi= partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }

}

//Main Function
int main()
{
    int arr[5]={5,4,3,2,1};
    quickSort(arr,0,4); //Calling
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

     return 0;

}

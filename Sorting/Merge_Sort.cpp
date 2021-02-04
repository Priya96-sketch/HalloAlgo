//Sorting ->MergeSort
#include<iostream>
using namespace std;

//Whole Algorithm
//Merge Function
void merge(int arr[],int l, int mid,int r){

//Creating two temporary arrays
    int n1=mid-l+1;
    int n2=r-mid;


    int a[n1];
    int b[n2];  

    for(int i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
    }
    
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    }

    //Creating Pointers
    int i=0;
    int j=0;
    int k=l; //k will traverse the whole array
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            k++;
            i++;
        }
        else{
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    //This array will be executed only when 'i' has not reached  till the last element in the array.
    while(i<n1)
    {
        arr[k]=a[i];
        k++; i++;
    }
//This array will be executed only when 'j' has not reached  till the last element in the array.
    while(j<n2)
    {
        arr[k]=b[j];
        k++; j++;
    }
}

//Merge Sort Function
void mergeSort(int arr[], int l ,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}

//Main Function
int main()
{

    int arr[]={5,4,3,2,1};
    mergeSort(arr,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

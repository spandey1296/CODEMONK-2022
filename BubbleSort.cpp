#include<iostream>
using namespace std;

void swap(int* x,int* y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

//Iterative
void bubbleSort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        bool isSorted=true;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                isSorted=false;
                swap(&arr[j],&arr[j+1]);
            }
        }
        if(isSorted)
            break;
    }
}

/* Recursive
void sortHelper(int arr[], int lastIndx)
{
    if(lastIndx==0)
        return;
    for(int i=0;i<lastIndx;i++)
    {
        if(arr[i]>arr[i+1])
            swap(&arr[i],&arr[i+1]);
    }
    sortHelper(arr,lastIndx-1);
}
    
void bubbleSort(int arr[], int n)
{
    sortHelper(arr,n-1);
}
*/

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"Enter array elements: ";
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout<<"Array elements before sorting: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    bubbleSort(arr,n);
    cout<<"Array elements after sorting: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}
#include<iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        int cur=arr[i];
        int j;
        for(j=i-1;j>=0;j--)
        {
            if(arr[j]<=cur)
                break;
            arr[j+1]=arr[j];
        }
        arr[j+1]=cur;
    }
}

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
    insertionSort(arr,n);
    cout<<"Array elements after sorting: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}

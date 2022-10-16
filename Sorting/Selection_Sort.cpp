#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int i,j,min,temp;
    for(i=0; i<n;i++)
        cin>>arr[i];

    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        if(min!=i){
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
        else{
            break;
        }
    }
    
    for(i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
}

#include<iostream>
#include<cmath>
#include<climits>
#include<string>
#include<algorithm>
using namespace std;

int partition(int a[], int l, int h){
    int pi = a[l];
    while(1){
        int i = l+1;
        int j = h;
        while(a[i]<pi){
            i++;
        }
        while(a[j] > pi){
            j--;
        }
        if(i<j){
            swap(a[i], a[j]);
        }
        if(i>j){
            swap(a[l], a[j]);
            return j;
        }
    }
}

void quicksort(int a[], int l, int h){
    if(l<h){
        int pi = partition(a, l, h);
        quicksort(a, l, pi-1);
        quicksort(a, pi+1, h);
    }
}


int main(){
    int n=5;
    int a[5] = {1,3,5,4,2};
    quicksort(a, 0, 4);
    for(int i=0; i <5;i++){
        cout<<a[i]<<" ";
    }
}

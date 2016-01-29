#include <iostream>
#include <string.h>

//import "defins.cc"

using namespace std;


/*
int*bubbleSortDesc(int*arr,int len) {
    int temp;

    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return arr;
}*/

int*bubbleSortAsc(int*arr,int len) {

    int temp;

    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}


void bsort() {
    int arr [5] = {4,2,6,1,0};
    int len = 5;
    cout << arr;
    int*bubbleSortAsc(int*arr,int len);
}

int main() {
    void bsort();
}


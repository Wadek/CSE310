#include<iostream>
using namespace std;

void sortDesc() {
    int hold;
    int array[5];
    cout<<"Enter 5 numbers: "<<endl;
    for(int i=0; i<5; i++) { cin>>array[i];
    }
    cout<<endl;

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        { if(array[j]>array[j+1]) {
                hold=array[j];
                array[j]=array[j+1];
                array[j+1]=hold;
            }
        }
    }

    cout<<"Sorted Array is: "<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<array[i]<<endl;
    }
}

void sortAsc() {
    int hold;
    int array[5];
    cout<<"Enter 5 numbers: "<<endl;
    for(int i=0; i<5; i++) { cin>>array[i];
    }
    cout<<endl;

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        { if(array[j]<array[j+1]) {
                hold=array[j];
                array[j]=array[j+1];
                array[j+1]=hold;
            }
        }
    }

    cout<<"Sorted Array is: "<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<array[i]<<endl;
    }
}

void bsort() {
    int dec = 0;
    cout<<"desc, enter 1, asc enter 0"<<endl;
    cin>>dec;
    if(dec == 1) {
        sortAsc();
    }else {
         sortDesc();
    }
}

main() {
    bsort();

}

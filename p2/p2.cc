#include <algorithm>
#include <utility>
#include <iomanip>
#include<iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>

#include "defns.cc"

using namespace std;

int value;
unsigned int k, t ,c;
char symbol[SYMBOL_LENGTH];

// returns type of string
int getType(string type) {
    if(type =="INT") {
        return INT;
    }
    else if(type =="CHAR") {
        return CHAR;
    }
    else if(type =="BST") {
        return BST;
    } else {
        return -1;
    }
}

//returns the command that is being used
string getCommand ( string command) {
    if(command == "allocate") {
        return "allocate";
    }else {
        return "";
    }
}

int hash(char symbol[],int k){
    int hashPlace, val, sum;

    for(int i=0; i<sizeof(symbol) ;i++) {
        val = int(symbol[i]);
         sum = sum + val;
    }

    hashPlace = sum % t;
}

//build max heap helper function
void maxHeapify(heapEntry *a, int i, int n) {
    int j;
    heapEntry temp;
    temp = a[i];
    while(j<=n) {
        if(j<n && a[j+1].blockSize > a[i].blockSize) {
            j = j+1;
        }
        if(temp.blockSize > a[j].blockSize){
            break;
        }
        else if(temp.blockSize <= a[j].blockSize) {
            a[j/2] = a[j];
            j = 2*j;
        }
    }
    a[j/2].blockSize = temp.blockSize;
    return;
}

//rebuilds the heap, to be used in worstFit
void buildMaxHeap(heapEntry *a, int n){
    int i;
    for(i = n/2; i >= 1; i--) {
        maxHeapify(a,i,n);
    }
}

// get the memory size of value, in increments of 4
int getMemSize(int value) {
    int size = 4;

    while(value > size) {
        size + 4;
    }
    return size;
}

//allocate memory for var, in free space. to be used in myMalloc
void worstFit(char *memBlock, heapEntry heapEntryList[]) {
    char *largeBlock = memBlock;
    cout<<"offset: "<<heapEntryList[0].offset<<endl;
    cout<<"blockSize "<<heapEntryList[0].blockSize<<endl;
    cout<<"value: "<<value<<endl;
    cout<<"memSize: "<<getMemSize(value)<<endl;

    memBlock[heapEntryList[0].offset] = value;
    cout<<memBlock[heapEntryList[0].offset]<<endl;


    heapEntryList[0].offset = heapEntryList[0].offset + getMemSize(value);
    heapEntryList[0].blockSize = heapEntryList[0].blockSize - getMemSize(value);


    cout<<"new offset: "<< heapEntryList[0].offset<<endl;
    cout<<"new blockSize: "<<heapEntryList[0].blockSize<<endl;

    //getfree current larget free block of memory

    // return error if not enough memory to allocate next value
    //split this free block into 2, one side being size value, the other of size maximum - value
    //call buildMaxHeap to restructure memory

}

void myMalloc() {
    //uses worstFit, getMemSize, insert var into symbolTableEntry
}

void myFree() {
}

void getInput() {
    int n;
    int  tempType;
    string type = "";

    cin >> k;
    n = pow(2,k);
    cin >> t; //size of hash table

    symbolTableEntry* symbolTableEntryList = new symbolTableEntry[t];
    heapEntry* heapEntryList = new heapEntry[n];
    char *memBlock = new char[n];
    char fillMem[n];


    for(int i = 0; i < n-1; i++) {
        fillMem[i] = '@';
    }
    fillMem[n - 1] = STRTERM;

    //creating memory block
    memcpy(memBlock, &fillMem, n);

    cin >> c;

    heapEntryList[0].offset = 0;
    heapEntryList[0].blockSize = n;

    for(int i = 0; i < c; i++) {
        string command = "";

        cin >> command;
        cout<< "command: " << command <<endl;
        if(getCommand(command).empty()) {
            cout << "ERROR: invalid command" << endl;
            break;
        }

        cin >> type;
        tempType = getType(type);
        cout<<"type value: "<<tempType<<endl;
        if (tempType == -1) {
            break;
        }
        else if(tempType == 0) {
            cin >> symbol;
            cin >> value;
            hash(symbol,k);
        }
        else {
            string charValue;
            cin >> charValue;
            cout<<"charValue: "<<value<<endl;
        }
        worstFit(memBlock,heapEntryList);
        cout<<"memblock: "<<memBlock<<endl;
        cout<<"\n"<<endl;
    }

}

void inputHash(symbolTableEntry* symbolTableEntryList, int tempType, int value) {
}


main() {
    getInput();
}

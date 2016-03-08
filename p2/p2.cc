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

struct heapEntry* heapEntryList;
struct symbolTableEntry* symbolTableEntryList;
int hashTableSize, tempType;

bool isPrime(int num) {
    if (num <= 3) {
        return num > 1;
    } else if (num % 2 == 0 || num % 3 == 0) {
        return false;
    } else {
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}

int getType(string type) {
    if(type =="INT") {
        return 0;
    }
    else if(type =="CHAR") {
        return 1;
    }
    else if(type =="BST") {
        return 2;
    }
}

string getCommand ( string command) {
    if(command == "allocate") return "allocate";
}

void readInput() {
    int n, numberOfCommands;
    string symbol;
    string type = "";
    heapEntryList = new heapEntry[1];
    symbolTableEntryList = new symbolTableEntry[1];

    //begin input
    cin >> n;
    heapEntryList[1].blockSize = pow(2,n);
    cin >> hashTableSize;
    cin >> numberOfCommands;
    for(int i = 0; i < numberOfCommands; i++) {
        string command = "";

        cin >> command;
        if(getCommand(command) == "allocate") {
            cin >> type;
            tempType = getType(type);
            symbolTableEntryList[1].type = tempType;
        }
        cin >> symbol;

        strcpy(symbolTableEntryList[1].symbol, symbol.c_str());
    }
}

main() {
    readInput();
}

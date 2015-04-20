//
//  test.cpp
//  LargestExponential
//
//  Created by Brett Hodges on 4/18/15.
//  Copyright (c) 2015 Brett Hodges. All rights reserved.
//

#include "test.h"

//
//  main.cpp
//  LargestExponential
//
//  Created by Brett Hodges on 4/9/15.
//  Copyright (c) 2015 Brett Hodges. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <math.h>
#include "compute.h"
using namespace std;



ComputeLE::ComputeLE(string fileName, int fSize){
    ifstream infile(fileName);
    fileSize = fSize;
    numArr = new double[fSize];
    if (!infile) {
        cerr <<"Error Opening File"<<endl;
        exit(1);
    }
    
    computeLog(infile);
    
    
    cout<<"The line with the largest number is: "<<findGreatest()<<endl;
    
}

void ComputeLE::computeLog(ifstream& infile){
    string line="";
    double base = 0, exp = 0;
    int count=0;
    
    
    while (!infile.eof()) {
        getline(infile, line);
        base = atoi(line.substr(0,line.find(",")).c_str());
        exp = atoi(line.substr(line.find(",")+1).c_str());
        numArr[count] = pow(log10(base), log10(exp));
        count++;
    }
    
    
}

int ComputeLE::findGreatest(){
    int largestLine = 0;
    for (int i = 0; i<fileSize; i++) {
        
        if (numArr[i]>numArr[largestLine]) {
            largestLine = i;
        }
    }
    
    return largestLine+1;
}



int main(int argc, const char * argv[]) {
    
    
    ComputeLE list1 ("/Users/bHodges/Projects/CppProjects/LargestExponential/LargestExponential/p099_base_exp.txt",1000);
    
    
    
    return 0;
}

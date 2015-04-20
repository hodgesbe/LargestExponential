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



ComputeLE::ComputeLE(string filePath){
    infile = ifstream(filePath);
    
    if (!infile) {
        cerr <<"Error Opening File"<<endl;
        exit(1);
    }
    
    computeLog();
    
}

void ComputeLE::computeLog(){
    string line="";
    double base = 0, exp = 0, total = 0, highNum=0;
    int count=0, lineNum = 0;
    
    
    while (!infile.eof()) {
        getline(infile, line);
        base = log(atoi(line.substr(0,line.find(",")).c_str()));
        exp = atoi(line.substr(line.find(",")+1).c_str());
        total = base*exp;
        if (count<1) {
            highNum = total;
        }else if (total>highNum){
            highNum = total;
            lineNum = count;
        }
        count++;
    }
    cout<<"The line with the largest number is: "<<lineNum+1<<" with high number: "<<highNum<<endl;

}


int main(int argc, const char * argv[]) {
    
    
    ComputeLE list1 ("/Users/bHodges/Projects/CppProjects/LargestExponential/LargestExponential/p099_base_exp.txt");

    
    
    return 0;
}

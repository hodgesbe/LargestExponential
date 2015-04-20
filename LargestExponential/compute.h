//
//  compute.h
//  LargestExponential
//
//  Created by Brett Hodges on 4/16/15.
//  Copyright (c) 2015 Brett Hodges. All rights reserved.
//

#ifndef LargestExponential_compute_h
#define LargestExponential_compute_h
#include <fstream>

using namespace std;

class ComputeLE{
    public:
        ComputeLE(string filePath);
        void computeLog();
    
    private:
        ifstream infile;
};
#endif

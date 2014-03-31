#ifndef INFO_H
#define INFO_H

#include <vector>
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Info
{
  // for results
  int size;
  int iterations;
  int numAdd;
  int alg;
  
  // for mult
  vector<bool> multiplier;
  vector<bool> multiplicand;
  vector<bool> result; // 2x size of others
  vector<bool> twoComp; // 2's compliment of multiplier
  
  void addAndShift();
  void boothsAlg(); 
  
  void clear(){ // does not reset which algs it uses
    result = multiplicand = twoComp = multiplier.clear();
    size = iterations = numAdd = 0;
   
  }
};

int countBits(const vector<bool> &a);
void setupBin(vector<bool> &a, string stuff);
void convertDecimalBin(vector<bool> &a, string stuff);
bool add(vector<bool> &a, vector<bool> b, const int &OFFSET);
void gentwoComp(vector<bool> &a, vector<bool> b);
bool shift(vector<bool> &a, bool shiftIn);
#endif

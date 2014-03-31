#include <info.h>
void setupBin(vector<bool> &a, string stuff)
{
  for(int i = 0; i < stuff.size() ; i++)
  {
    if(stuff[i] == '0')
    {
      a.push_back(0);
    }
    else
    {
      a.push_back(1);
    }
  }
  return;
}

void convertDecimalBin(vector<bool> &a, string stuff)
{
  int temp = atoi(stuff));
  a.pushback(0);
  do
  {
    a.pushback(temp % 2);
    temp /= 2;
  }while(temp > 1);
  return;
}

int countBits(const vector<bool> &a)
{
  int counter = 0;
  for(int i = 0; i < a.size(); i++)
  {
    if(a[i] == 1)
    {
      counter++;
    }
  }
  
  return counter;
}
// returns true if overflow
bool add(vector<bool> &a, vector<bool> b, const int &OFFSET)
{// add b to a. stores result in a
  vector<bool> relvantBits(3, 0);
      
  for(int i = 0; i < b.size(); i++)
  {// sign handled seperatly
    relvantBits[1] = a[OFFSET+i];// a value
    relvantBits[2] = b[i]; // b value
    numOnes = countBits(relvantBits);
    
    // sets a to the proper value
    if(numOnes % 2 == 0)
    {
      a[OFFSET+i] = 0;
    }
    else
    {
      a[OFFSET+i] = 1;
    }
    
    // sets the offset
    if(numOnes > 1)
    {
      relvantBits[0] = 1;
    }
    else
    {
      relvantBits[0] = 0;
    }
  }//for loop
  
  // sets the last bit and checks for overflow
  a[2*b.size() -1] = b[b.size()-1];
  
  if(relvantBits[0] == 1)
  {//if there is a carry in to the sign bit
    return true;
  }
  
  return false;
}


// for add&shift call shift(a, E(reg))
// for booth call bb=shift(a,most sig bit);
bool shift(vector<bool> &a, bool shiftIn)
{
  bool retval = a[a.size()-1];
  a.pop_back();
  a.insert(a.begin(), shiftIn);// inserts a 0 at the front
  return retVal; // used for booth bit;
}

void gentwoComp(vector<bool> &a, vector<bool> b)
{
 // assign a to 1's compliment of b
  b.flip();//check
  a = b; 
  
  // make b = 1
  b.clear();
  b.push_back(1);
  // add 1 to a
  add(a,b,0);
}

void addAndShift()
{// done needs testing
  bool E = false;
  add(results, multiplicand, 0); // sets up q part of reg
  
  for(int i = 0; i < multiplier.size(); i++)
  {
    if(results[results.size()-1] == 1)
    {
      E = add(results, multiplier, multiplier.size() - 1);
      numAdd++;
    }
    
    iterations++;
    shift(result, E);
  }
  
  return;
}

void boothsAlg()
{
  bool boothBit = 0;
  for(int i = 0; i < ;i++)
  {
    if(result[result.size() - 1] == 0 && result[result.size() - 2] == 1)
    {// 0,1 add 
      add(result, multiplier, multiplier.size() - 1);
      numAdd++;
    }
    else if(result[result.size() - 1] == 1 && result[result.size() - 2] == 0)
    {// 1,0 sub
      add(result, twoComp, twoComp.size() - 1);
      numAdd++;
    }
    
    boothBit = shift(result, result[0]);
    iterations++;
  }
   
  return;
}


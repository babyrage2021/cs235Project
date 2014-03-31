#include <fstream>
 
char* getFilename(string type)
{
  char filename[50];
  cout<<"Please enter the name of the "<<type<<" file: ";
  cin>>filename;
  return filename;
}
// param order: inputFile.txt, outputFile.txt, <y/n> (for if it is a bin file
//              or not) alg to use<1-3> ( 1 for booth, 2 for add&shift, 3 for both) 
int main(int argc, char* argv[])
{
  // sets up the in/out put files and opens them
  string filename, stuff;
  char fileType = '\0';
  int alg=0;
  
  Info result;
  ifstream fin;
  ofstream fout;
  
  // input file setup
  if(argc > 2)
  {
    fin.open(argv[2]);
  }
  else
  {
    fin.open(getFilename("input"));
  }
  
  // output file setup
  if(argc > 3)
  {
    fout.open(argv[3]);
  }
  else
  {
    fin.open(getFilename("output"));
  }
  
  if(argc > 4)
  {
    filetype = argv[4];
  }
  
  while(fileType != 'y' || fileType != 'n') // allows for input of files that are not in binary
  {  // they still must be in in MULTIPLICAND MULTIPLIER format
    cout<<"Are the numbers in binary already? <y/n> ";
    cin>>fileType;
  }
  
  if(argc > 5)
  {
    alg = atoi(argv[5];//check
  }
  
  while(alg < 1 || alg > 3)
  { // selects which alg to use
    cout<<"Which algorithm do you want to use: \n";
    cout<<"\t 1. Booth's algorithm \n";
    cout<<"\t 2. Add and Shift\n"
    cout<<"\t 3. Both algs"<<endl;
    cout<<"selection: ";
    cin>>alg;
  }
  
  result.alg = alg;
  // loops through the file. 
  do
  { 
    // file input stuff here
    if(fileType == 'y')
    {
      result.multiplicand.push_back(0); // sign bit
      fin>>stuff;
      setupBin(result.multiplicand, stuff)
      
      fin>>stuff;
      setupBin(result.multiplier, stuff);
    }
    else
    {// converts it to binary
      fin>>stuff;
      convertDecimalBin(result.multiplicand, stuff);
      
      fin>>stuff;
      convertDecimalBin(result.multiplier, stuff);
    }
    
    // setup stuff here
    genTwoComp(result.twoComp, result.multiplier); // might need to change this
    result.result.resize(2 * result.multiplicand.size());
    
    // runs the alg here
    if(alg > 0)
    {//booth
      result.booths();
      alg = result.alg;// changes inf.alg for output
      cout<<result<<'\n';
      fout<<result<<";";
      result.alg = alg;
      result.iterations = result.numAdd = 0;
    }
    
    if(alg > 1)
    {// add and shift
      result.addShift();
      alg = result.alg;// changes inf.alg for output
      cout<<result<<'\n';
      fout<<result<<";";
      result.alg = alg;
      result.iterations = result.numAdd = 0;
    }
    
    //resets everything
    result.clear();
    
  }// do while loop
  while(fin.eof() == false);
  
  // closes files
  fin.close();
  fout.close();
  
  return 0;
}


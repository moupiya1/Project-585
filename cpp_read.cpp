#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm> // for std::copy

using namespace std;

int main()
{
  std::vector<double> x[6];    
  std::vector<double> y[6];  
  int i=0;  
  std::ifstream iFile("input.txt");	// input.txt has integers, one per line
    while (true) {
      //  double x,y;
    iFile >> x;
    //iFile >> y[i];
    if( iFile.eof() ) break;
    cerr <<' '<< x << endl;
    // i=i+1;
       }
    return 0;
    }
// << ' '<< y[i]

#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
     ifstream fin("position.txt");
     vector<double> a, b;
     double x,y;
     while (fin >> x)
          {
           a.push_back(x);
            fin>>x;
            b.push_back(x);
     } 

     printf("%ld\n",b.size());
     int i=0;
     while(i<a.size())
       {
	 printf("%d %f %f\n",i,a[i],b[i]);
	 i=i+1;
       }
     fin.close();
     return 0;
     }

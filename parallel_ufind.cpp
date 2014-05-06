//The parallel algorithm of union find . 
//PARALLELIZED THE CALCULATE DISTANCES OF EVERY PAIRS PART AND FIND THE IDS THAT BELONG TO EACH CLUSTER PART.

#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;
#include <time.h>
#include <stdio.h>
#include <omp.h>
double dist[12000][12000];

int main()
{
  clock_t tbeg,tend;   
  tbeg = clock();          // We want to find the processor time taken by the program.
 
  //***************// 
  double R=2.0;      //Choosing and declaring a linking length.
  //***************//

  //********* INPUT FILE HERE **********//
  std::ifstream fin("test1pos.txt");   
  //************************************//


  //Read in the input x and y positions from the file.//
  std::vector<double> xpos, ypos;
  double x,y;
     while (fin >> x)
          {
           xpos.push_back(x);
            fin>>x;
            ypos.push_back(x);
     } 
    
     printf("Number of particles %ld\n",xpos.size());
     fin.close();
 printf("reading %e seconds.\n",(double)(clock()-tbeg)/CLOCKS_PER_SEC); 

     //Find distances between all pairs of particles and seperate the candidate pairs//
     std::vector<int> id1, id2;
     std::vector<double>  dless;  //dless<-- distances less than R
     int j,k,count=0;
     //double dist;
     //int j,k;
#pragma omp parallel for private(k)
for(j=0;j<xpos.size();j++)
{
for(k=0;k<xpos.size();k++)
{
dist[j][k]=sqrt((xpos[k]-xpos[j])*(xpos[k]-xpos[j])+(ypos[k]-ypos[j])*(ypos[k]-ypos[j]));
}
}
 printf("hello\n");

for(j=0;j<xpos.size();j++)	  
  { 
for(k=j+1;k<xpos.size();k++)
{ 
	        if(dist[j][k]<R)
	       {
		 id1.push_back(j);
		 id2.push_back(k); 
		 // printf("%d %d %f\n",j,k,dist[j][k]);
		}
    }
  }	      
     printf("%zu %zu \n",id1.size(),id2.size());

     
     //Making the array of paired particles     
 printf("pairs %e seconds.\n",(double)(clock()-tbeg)/CLOCKS_PER_SEC); 

     std::vector<int> A;
     A.reserve( id1.size() + id2.size() ); // preallocate memory
     A.insert( A.end(), id1.begin(), id1.end() );
     A.insert( A.end(), id2.begin(), id2.end() );
    
     sort(A.begin(),A.end());
      std::vector<int>::iterator it;
      it = std::unique (A.begin(), A.end());  
      A.resize( std::distance(A.begin(),it) );
  std::cout << "A contains:";
  //for (it=A.begin(); it!=A.end(); ++it)
  //std::cout << ' ' << *it;
  //std::cout << '\n';

 printf("%zu %zu %zu\n",id1.size(),id2.size(),A.size());
 for (count=0;count<A.size();count++)
   {
     A[count]=count;
   }

std::cout << '\n';

//Doing the array union where all particles are basically replaced by their cluster id. 

  int i1=0,i2=0;

  for (count=0;count<id1.size();count++)
    {
      i1=id1[count];
      i2=id2[count];

      A[i2]=A[i1];
    }
std::cout << '\n';
//for (it=A.begin(); it!=A.end(); ++it)
//std::cout << *it<<" ";
//std::cout << '\n';
  int cno=0;
  //Determine number of clusters.
  for (count=0;count<A.size();count++)
  {
    if(A[count]==count)
      {
	cno=cno+1;
      }
  }

  //vector manipulations.

  std::vector<int> copyA(A);
  sort(copyA.begin(),copyA.end());
   it = std::unique (copyA.begin(), copyA.end());  
      copyA.resize( std::distance(copyA.begin(),it) );
  std::cout << "copyA contains:";
  for (it=copyA.begin(); it!=copyA.end(); ++it)
  std::cout << ' ' << *it;
  std::cout << '\n';
  printf("hello\n");
  std::cout << '\n';
  int s=copyA.size();
  printf("hello\n");

  printf("%d\n",s);
  vector<int> clus[s];
 printf("number of cluster %d\n",cno);

 printf("Union took %e seconds.\n",(double)(clock()-tbeg)/CLOCKS_PER_SEC); 
 //Find the particle ids in each clusters in PARALLEL.
  
#pragma omp parallel for
for(j=0;j<copyA.size();j++)
 
   {
     //printf("thread is %d\n",omp_get_thread_num());
     for (int i=0;i<A.size();i++)
       {
     if (A[i]==copyA[j])
       {
	 clus[j].push_back(i);
       }
       }
   }

 printf("Find %e seconds.\n",(double)(clock()-tbeg)/CLOCKS_PER_SEC); 

 for(j=0;j<s;j++)
   {
     // printf("cluster %d has\n",j);
       {
for (it=clus[j].begin(); it!=clus[j].end(); ++it)
  {
  // std::cout << *it<< '\t';
  }
       }
   std::cout << '\n';
   }

tend = clock();
printf("It took %e seconds.\n",(double)(tend-tbeg)/CLOCKS_PER_SEC);   

}

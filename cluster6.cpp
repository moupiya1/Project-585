//Working perfectly!!!

#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;
#include <time.h>
int match (int, int);





int main()
{
  clock_t tbeg,tend;
  tbeg = clock();
  double R=10.0;
  //First read in the input x and y positions from the file.
  std::ifstream fin("test5pos.txt");
  std::vector<double> xpos, ypos;
  double x,y;
     while (fin >> x)
          {
           xpos.push_back(x);
            fin>>x;
            ypos.push_back(x);
     } 
     //Printing the input data out.
     // printf("Input x y positions\n");
     printf("Data length %ld\n",xpos.size());
     int i=0;
     while(i<xpos.size())
       {
	 // printf("%d %f %f\n",i,xpos[i],ypos[i]);
	 i=i+1;
       }
     fin.close();

     std::vector<int> id1, id2;
     std::vector<double>  dless;
     //Find all pair distances
     //  printf("Now listing all pair distances\n");
     int j,k;
     double dist;
     j=0;
     while(j<xpos.size())
       {
	 k=j+1;
	 while(k<xpos.size())
	   {
	     dist=sqrt((xpos[k]-xpos[j])*(xpos[k]-xpos[j])+(ypos[k]-ypos[j])*(ypos[k]-ypos[j]));
	     //printf("%d %d %f\n",j,k,dist);
	     if(dist<R)
	       {
		 id1.push_back(j);
		 id2.push_back(k);
		 dless.push_back(dist);
	       }
	     k=k+1;
	   }
	 j=j+1;
       }

     //printf("the cluster candidates\n");
      i=0;
     while(i<id1.size())
       {
	 // printf("%d %d %f\n",id1[i],id2[i],dless[i]);
	 i=i+1;
       }
     /////////////////////////////////////////////////////////////////////////////////////
     int clusterno=0, flag1,flag2;
       vector< vector<int> > cluster;
       i=0;
     if(dless.size()!=0)
       {
	 clusterno=clusterno+1;
	 vector<int> idcluster;
	 idcluster.push_back(id1[i]);
	 idcluster.push_back(id2[i]);
	 cluster.push_back(idcluster);
	 i=i+1;
       }
     for(vector<vector<int> >::iterator ab =cluster.begin(); ab != cluster.end(); ++ab)
	{
		//it is now a pointer to a vector<int>
		for(vector<int>::iterator cd = ab->begin(); cd != ab->end(); ++cd)
		{
			// jt is now a pointer to an integer.
		  //	printf("%d\t",*cd);
		}
		//cout <<"\n\n"<< endl;
	}

     //printf("%d\n",clusterno);

     /*    for(vector<vector<double> >::iterator it = cluster.begin(); it != cluster.end(); ++it)
	{
		//it is now a pointer to a vector<int>
		for(vector<double>::iterator jt = it->begin(); jt != it->end(); ++jt)
		{
			// jt is now a pointer to an integer.
		  cout<< *jt << ' ';
		}
		cout << endl;
	}

     */
     
     //vector< vector<double> > cluster;
 int addi;
 addi = match(19,20);
 // printf("%d\n",addi);
 int id1_n,id2_n;
 while(i<id1.size())
   {
     flag1=0; //If after calculation flag 1 is zero then id1 is not present in any cluster id list. If it is 1, the it has been found.
     for(size_t n = 0; n < cluster.size(); ++n)
	  {
	      if(std::find(cluster[n].begin(),cluster[n].end(),id1[i]) != cluster[n].end())
	      {
		//std::cout << "Found root at row " << n  << '\n';
		//cluster[n].push_back(id1[i]);
		id1_n=n;
		flag1=1;
	      }
	  }
     flag2=0;
     for(size_t n = 0; n < cluster.size(); ++n)
	  {
	      if(std::find(cluster[n].begin(),cluster[n].end(),id2[i]) != cluster[n].end())
	      {
		//std::cout << "Found root at row " << n  << '\n';
		//cluster[n].push_back(id2[i]);
		id2_n=n;
		flag2=1;
	      }
	  }
     if (flag1==1 && flag2 == 0)
       {
	 cluster[id1_n].push_back(id2[i]);
       }

     if (flag1==0 && flag2 == 1)
       {
	 cluster[id2_n].push_back(id1[i]);
       }

     if(flag1==0 && flag2 ==0)
       {
	 clusterno=clusterno+1;
	 std::vector<int> temp;
	 temp.push_back(id1[i]);
	 temp.push_back(id2[i]);

	 cluster.push_back(temp);
	 
       }
     
 i=i+1;
   }



 int count=0;
 for(vector<vector<int> >::iterator ab =cluster.begin(); ab != cluster.end(); ++ab)
	{
	  printf("Cluster %d has paricles with id\n", count);
		//it is now a pointer to a vector<int>
		for(vector<int>::iterator cd = ab->begin(); cd != ab->end(); ++cd)
		{
			// jt is now a pointer to an integer.
		printf("%d\t",*cd);
		}
		cout << endl;
		count=count+1;
	}
 printf("Cluster no %d\n", clusterno);
 tend = clock();
 printf("It took %e seconds.\n",(double)(tend-tbeg)/CLOCKS_PER_SEC);   
     }

int match (int a, int b)
{
  int r;
  r=a+b;
  return r;
}

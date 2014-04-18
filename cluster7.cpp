//The final serial cluster finding code. It is a mixture of c and c++, mostly c++.

//Logic: The problem is this: Given a set of data, say positions of a some objects, how do we find out the clusters in the pattern? Various approaches have been tried in the literature, it can be distance based or density based. Here I have implemented a simplealgorithm based on linking length. If the distance between two particles is less than a predefined length, R (e.g. radius of the cluster), then they are considered to be members of cluster. The choice of R can be arbitray. If we can plot the raw data then we can visually inspect and choose a sensible linking legth form the appearance of the data. If we are looking for some scientific objects, like globular star clusters, then we can use their typical radius as the length.

//Input : The data file of properties you want to clusterify. I have a file which contains the x and y positions of the particles. This is read from a file testnpos.txt where n is a number. Please check the file name when running the program. I currently have 5 position file test1pos.txt to test5pos.txt with increasing problem size.

//Output : The number of clusters and the ids of the particles in each cluster.

//Caveats : This algorithm scales as O(n^2) which becomes too expensive too quickly. Currently this is taking more than 20 min for a problem size of 30,000 particles. Also, if two clusters are too close it has the possibility of identifying them as one.



#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>
using namespace std;
#include <time.h>



int main()
{
  clock_t tbeg,tend;   
  tbeg = clock();          // We want to find the processor time taken by the program.
 
  //***************// 
  double R=10.0;      //Choosing and declaring a linking length.
  //***************//

  //********* INPUT FILE HERE **********//
  std::ifstream fin("test3pos.txt");   
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


     //Find distances between all pairs of particles and seperate the candidate pairs//
     std::vector<int> id1, id2;
     std::vector<double>  dless;  //dless<-- distances less than R
     int j,k;
     double dist;
     j=0;
     while(j<xpos.size())        //Looping over all particles
       {
	 k=j+1;
	 while(k<xpos.size())    //Looping over all particles
	   {
	     dist=sqrt((xpos[k]-xpos[j])*(xpos[k]-xpos[j])+(ypos[k]-ypos[j])*(ypos[k]-ypos[j]));
	        if(dist<R)
	       {
		 id1.push_back(j);
		 id2.push_back(k);           //If the distance is less then R, the pair ids are stored in a separate vector. All of next operations will be performed on these candidate pairs only.
		 dless.push_back(dist);
	       }
	     k=k+1;
	   }
	 j=j+1;
       }

    
     
     //******Now we decide which particle goes to which cluster. *****//

     int clusterno=0, flag1,flag2;
     vector< vector<int> > cluster; //This structure which is a vector of vectors will contain as many rows as there are clusters. Each row will have the respective particle ids. Each row can have different number of columns. The rows and coulms are dynamically added as we go through the entire list.

     //If there is at least one close pair, we have a cluster. Increase clusterno to 1, build the first cluster (the first row) which has the ids of the first pair as their coulmn entries. 
       
     int i=0;
     if(dless.size()!=0)
       {
	 clusterno=clusterno+1;
	 vector<int> idcluster;
	 idcluster.push_back(id1[i]);  //push the id of the particle
	 idcluster.push_back(id2[i]);
	 cluster.push_back(idcluster); //push the row to cluster
	 i=i+1;
       }
     
     //Now we do it for the rest of the particles.

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



#include <vector>
#include <fstream>
#include <iostream>
#include <math.h>
//using namespace std;

int main()
{
  double R=2.0;
  //First read in the input x and y positions from the file.
  std::ifstream fin("position.txt");
  std::vector<double> xpos, ypos;
  double x,y;
     while (fin >> x)
          {
           xpos.push_back(x);
            fin>>x;
            ypos.push_back(x);
     } 
     //Printing the input data out.
     printf("Input x y positions\n");
     printf("%ld\n",xpos.size());
     int i=0;
     while(i<xpos.size())
       {
	 printf("%d %f %f\n",i,xpos[i],ypos[i]);
	 i=i+1;
       }
     fin.close();

     std::vector<int> id1, id2;
     std::vector<double>  dless;
     //Find all pair distances
     printf("Now listing all pair distances\n");
     int j,k;
     double dist;
     j=0;
     while(j<xpos.size())
       {
	 k=j+1;
	 while(k<xpos.size())
	   {
	     dist=sqrt((xpos[k]-xpos[j])*(xpos[k]-xpos[j])+(ypos[k]-ypos[j])*(ypos[k]-ypos[j]));
	     printf("%d %d %f\n",j,k,dist);
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

     printf("the cluster candidates\n");
      i=0;
     while(i<id1.size())
       {
	 printf("%d %d %f\n",id1[i],id2[i],dless[i]);
	 i=i+1;
       }

       int clusterno;
     std::vector<int> c1_id,c2_id; 
       i=0;
     if(dless.size()!=0)
       {
	 clusterno=clusterno+1;
	 c1_id.push_back(id1[0]);
	 c1_id.push_back(id2[0]);
	 i=i+1;
       }
 
     printf("%d\n",clusterno);
     while(i<id1.size())
	{
	  if(std::find(c1_id.begin(),c1_id.end(),id1[i]) != c1_id.end())
	    {
	  c1_id.push_back(id1[i]);
	     }
	  else if(std::find(c1_id.begin(),c1_id.end(),id2[i]) != c1_id.end())
	    {
	      c1_id.push_back(id2[i]);
	    }
	  else
	    {
	      clusterno=clusterno+1;
	      c2_id.push_back(id1[i]);
	      c2_id.push_back(id2[i]);
	    }
	  i=i+1;
	}
	printf("%d\n",clusterno);
     }

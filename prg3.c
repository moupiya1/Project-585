//Working


//This codes is a cluster finding algorithm. Here the input are the positions of the (x and y coordinates) particles. The output is the number of clusters and the particle ids in each cluster.
//The criterion I have used is if the distance between two particles is less than some predefined length, which might in real case be the typical interparticle distance , are members of a cluster. I sort through the particle list and then find the clusters and the particles therein.

#include<stdio.h>
#include<math.h>

int main()
{
  double x[]={1,1.2,1.3,5.4,5.6,5.7};         //input coordinates. It would be from a file when I apply it to real datasets.
  double y[]={1.9,2.1,2.6,8.9,9.7,10.5};
  double d[6][6],cl[6][6];
  int ids1[6][6],ids2[6];
  int i,j,p1,p2,c,count,k,l,vali,valj,counter,nclus,n;
  double R=2.0;
  typedef enum { false, true } bool;

  //calculate distances between all the particles and printing them
  /* i=0;
  j=0;
  while(i<6)
    {
      j=i+1;
      while(j<6)
	{
	  d[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	   printf("%d %d %f\n",i,j,d[i][j]);
	  j=j+1;
	}
      i=i+1;
    }
    printf("\n");*/
//calculate distances between all the particles and printing them and
  //find out which pairs have distances less than a predefined radius, R, in this case

i=0;
  j=0;
  k=0;
  while(i<6)
    {
      j=i+1;
      while(j<6)
	{
	  d[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	  if (d[i][j]<R)
	    {
	      cl[i][j]=d[i][j];
	      printf("%d %d %f\n",i,j,cl[i][j]);

//Check if particle id i is already in the list of ids, ids1. If it is, vali=1.

	      vali=0;
	      l=0;
	      while(l<k)
		{
		  if (ids1[nclus][l]==i)
		    {		    
		      vali=1;
		    }
		  //printf("vali %d\n",vali);
		  if(vali==1)
		    break;
		  l=l+1;
		 }
	       printf("%d\n",k);
	      

	       //Check if j value already exist in the particle list.	     
	       valj=0;
	      l=0;
	      while(l<k)
		{
		  if (ids1[nclus][l]==j)
		    {		    
		      valj=1;
		    }
		   if(valj==1)
		    break;
		   // printf("valj %d\n",valj);
		  l=l+1;
		}
	    
	      //If neither i or j is in the particle list of previous clusters, then it is a new cluster. 
	      //Increment cluster number, start new row in cluster id matrix.
  
	      if(vali==0 && valj==0)
		{
		  nclus=nclus+1;
		}
	      //If vali = 0 write the values., i.e. if i is not in the list, include the id in particle list of the cluster.
	        //If vali = 0 write the values.
	       if(vali==0)
		{
	      ids1[nclus][k]=i;
	       printf("%d %d\n",k,ids1[nclus][k]);
	      k=k+1;
		}
	       
	        //If valj = 0 write the values.

	      if(valj==0)
		{
	      ids1[nclus][k]=j;
	      printf("%d %d\n",k,ids1[nclus][k]);
	      k=k+1;
		}
		}
	  j=j+1;
	}
      i=i+1;
    }
 printf("\n");

 //Print the cluster and its particles. 
  k=0;
  n=1;
  while(n<(nclus+1))
    {
      k=0;
  while(k<6)
    {
      printf("cluster %d particles %d\n",n,ids1[n][k]);
      k=k+1;
    } 
  printf("\n");
  n=n+1;
    }
  printf("no of clus %d\n",nclus);
}



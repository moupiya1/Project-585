#include<stdio.h>
#include<math.h>

int main()
{
  double x[]={1,1.2,1.3,5.4,5.6,5.7};
  double y[]={1.9,2.1,2.6,8.9,9.7,10.5};
  double d[6][6],cluster[6][6];
  int i,j,p1,p2,c,count,k,l;
  double R=2.0;
  typedef enum { false, true } bool;

  //calculate distances between all the particles

  while(i<6)
    {
      j=0;
      while(j<6)
	{
	  d[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
	  // printf("%d %d %f\n",i,j,d[i][j]);
	  j=j+1;
	}
      i=i+1;
    }

  //find out which pairs have distances less than a predefined radius, R, in this case

  i=0; //initializing the two indices here again
  j=0;
  while(i<6) //checking distances for all pairs of ij
    {
      j=i+1; //make sure I dont count ij and ji 
      while(j<6)
	{
	  if ((d[i][j] < R)) //Is the distance less than R?
	    {
	      if (count==0) //for the first time pair distance is less than R, no of cluster=1
		{
	      c=1;
	       }
//Next time onwards, check if any of the new particle is already in the previous set. Then , 0,1 and 0,2 pairs are in the same cluster. 3,4 however is not. 
	       else 
		{
	     if(i!=p1 && i!=p2  && j!=p1  && j!=p2)
		{
		  c=c+1;
		}
	      }
	      p1=i;
	      p2=j;
	      count=count+1;
	       printf("%d %d %d\n",i,j,c);
	    } 
	      
	     	  
	  j=j+1;   
	}
      i=i+1;
    }
  printf("Number of clusters: %d\n",c);
}



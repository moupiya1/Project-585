#include<stdio.h>
#include<math.h>

int main()
{
  double x[]={1,1.2,1.3,5.4,5.6,5.7};
  double y[]={1.9,2.1,2.6,8.9,9.7,10.5};
  double d[6][6];
  int i,j,p1,p2,c,count,k,l,cluster[6][6],ll;
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
	      cluster[c][k]=i;
	      k=k+1;
	      cluster[c][k]=j;
	      k=k+1;
		}
//Next time onwards, check if any of the new particle is already in the previous set. Then , 0,1 and 0,2 pairs are in the same cluster. 3,4 however is not. 

	       else
		{

		  bool testCond1 = false;
		  printf("k %d\n",k);
		  for(l=0;l<6;l++)
		    {
		      for(ll=0;ll<6;ll++)
			{
		      if (i!=cluster[ll][l])
			{
			  testCond1 = true;
			  // break;
			 }
			}
		     printf("ho %d, %d, %d %d\n",c,i,l,testCond1);
		    }
		  l=0;
		  ll=0;
		  bool testCond2 = false;
		  for(l=0;l<6;l++)
		    {
		      for(ll=0;ll<6;ll++)
			{
		      if (j!=cluster[c][l])
			{
			  testCond2 = true;
			  // break;
			}
			}
		      printf("hi %d, %d, %d %d\n",c,i,l,testCond2);
		   
		    }
		   if (testCond1 && testCond2)
	       {
		 printf("%d\n",c);	  
		  c=c+1;
		  k=0;		  
		  cluster[c][k]=i;
		  k=k+1;
		  cluster[c][k]=j;
		  k=k+1;
		}
	      else
		{
		  cluster[c][k]=i;
		  k=k+1;
		  cluster[c][k]=j;
		  k=k+1;
		  }
		}
	      count=count+1;
	    }	  
	  j=j+1;   
	}
      i=i+1;
    }

  i=0;
  while(i<6)
   
    { printf("%d %d %d %d %d %d %d\n",c, cluster[i][0],cluster[i][1],cluster[i][2],cluster[i][3],cluster[i][4],cluster[i][5]);
      i=i+1;
  }

}



#include<stdio.h>
#include<math.h>

int main()
{
typedef enum { false, true } bool;
double array[6][6];
 int i,j;
 i=0;
 while(i<6)
   {
     j=0;
     while(j<6)
       {
	 array[i][j]=i*j;
	 printf("%d %d %f\n", i,j,array[i][j]);
	 j=j+1;
       }
     i=i+1;
   }
bool testCond = false;
for(int i=0; i < 6; i++)
{
    if (array[1][i]==i)
    {
        testCond = true;
        break;
    }
}
if (testCond)
{
  printf("Horray\n");
}

}

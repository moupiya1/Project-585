#include <iostream>
#include <math.h>
#include <vector>

int main ()
{
  int n=4,j;
  std::vector<long int> myArray(n,50);
  std::vector<long int>::iterator it;
  printf("Size of array %ld \n",myArray.size());
  myArray.insert(myArray.end(), 16000000050); // Inserts '100' between 5th and 6th elements and increases array size by 1. 
  printf("Size of array %ld \n",myArray.size());
  /*j=0;
  while(j<myArray.size())
    {
      printf("Element %d %d \n",j,myArray[j]);
  j=j+1;
  }*/

   std::cout << "The contents of myArray are: \n";
   //for (it = myArray.begin(); it != myArray.end(); ++it)
   it=myArray.begin();
   while(it != myArray.end())
     {
       std::cout << ' ' << *it<< '\n';
       // printf("Element %d %d \n",j,myArray[j]);
    it=it+1;
     }
  // std::cout << '\n';

}

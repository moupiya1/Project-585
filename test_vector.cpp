#include <iostream>
#include <math.h>
#include <vector>

int main ()
{
  unsigned int i;

  // constructors used in the same order as described above:
  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (4,100);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (third);                       // a copy of third
  std::cout << second[3];
  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are:";
  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
/*
int main()
{
  std::vector<int> myArray[9];
  // printf("Hello World! %d \n",myArray[5]);
  //myArray.insert(myArray.begin()+5, 100); // Inserts '100' between 5th and 6th elements and increases array size by 1. 
  // myArray[5] = 100; // The 6th element is now equal to 100! 
  // printf("Hello World! %d \n",myArray[5]);
  cout<<myarray[5]<<""<<"Printed out variable x"<<endl;
  }*/

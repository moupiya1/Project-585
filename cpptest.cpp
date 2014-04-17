// my first program in C++
#include <iostream>
#include <vector>
#include <math.h>
int main()
{
  std::cout << "Hello World!\n";
std::vector< std::vector<int> > a;
 int i,j,x;

  //m * n is the size of the matrix

    int m = 2, n = 4;
    //Grow rows by m
    a.resize(m);
    for(i = 0 ; i < m ; ++i)
    {
        //Grow Columns by n
        a[i].resize(n);
    }
    //Now you have matrix m*n with default values

    //you can use the Matrix, now
    a[1][0]=1;
    a[1][1]=2;
    a[1][2]=3;
    a[1][3]=4;

//OR
for(i = 0 ; i < m ; ++i)
{
    for( j = 0 ; j < n ; ++j)
    {      //modify matrix
         x = a[i][j];
	 std::cout << ' ' << a[i][j];
    }
         std::cout << '\n';
}

}

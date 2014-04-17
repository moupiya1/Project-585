#include <iostream>
//#include <Eigen/Dense>
//using Eigen::MatrixXd;
int main()
{
  //cin>>CC; cin>>RR; already done
vector<vector<int> > matrix(RR);
for ( int i = 0 ; i < RR ; i++ )
   matrix[i].resize(CC);

for(int i = 0; i<RR; i++)
{
    for(int j = 0; j<CC; j++)
    {
    cout<<"Enter the number for Matrix 1";
         cin>>matrix[i][j];
    }
}
}

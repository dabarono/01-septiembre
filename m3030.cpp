#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>
//#include <eigen3/Eigen/Eigenvalues>
using Eigen::MatrixXd;

int h(int i, int j){
  int f;
  if (j<=i){
    f=3-i;
  }
  else{
    f=0;
  }
  return f;
}

int main(void){
  MatrixXd m(3,3);
  int i=0;
  int j=0;
  for (i;i<=2;i=i+1){
    for (j;j<=2;j=j+1){
      m(i,j)=h(i,j);
    }
  }
  std::cout<<m<<std::endl;
}

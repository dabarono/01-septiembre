#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Eigenvalues>
using Eigen::MatrixXd;
using Eigen::SelfAdjointEigenSolver;

int h(int i, int j, int n){
  int f;
  if (i<=j){
    f=n-j;
  }
  else{
    f=n-i;
  }
  return f;
}

double vp(int i,int n){
  double f=1/(2-2*cos((2*i-1)*M_PI/(2*n+1)));
  return f;
}

double er(double experimental, double teorico){
  double f=fabs(experimental-teorico)/teorico;
  return f;
}

int main(void){
  std::cout.precision(4);
  int n=30;
  MatrixXd m(n,n);
  for (int i=0;i<=n-1;i=i+1){
    for (int j=0;j<=n-1;j=j+1){
      m(i,j)=h(i,j,n);
    }
  }
  //Para graficar la matriz
  std::cout<<"Matriz"<<std::endl;
  std::cout<<m<<std::endl;
  std::cout.setf(std::ios::scientific);
  SelfAdjointEigenSolver<MatrixXd> es(m);
  //Para sacar los eigen valores
  std::cout<<"i"<<"\t"<<"Auto_valores"<<"\t"<<"Auto_valores_t"<<"\t"<<"Error_porcentual"<<std::endl;
  for(int k=1;k<=n;k=k+1){
    double u=es.eigenvalues()[n-k];
    std::cout<<k<<"\t"<<u<<"\t"<<vp(k,n)<<"\t"<<er(u,vp(k,n))<<std::endl;
  }
  //Para sacar los eigen vectores
  std::cout<<"Matriz_de_auto_vectores"<<std::endl;
  std::cout.unsetf(std::ios::scientific);
  MatrixXd w=es.eigenvectors();
  std::cout<<w<<std::endl;
}

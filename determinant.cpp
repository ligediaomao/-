#include<iostream>
using namespace std;
float a[3][3];
int main()
{int i,j;
 void change();
 cout<<"请输入一个3*3的二维数组："<<endl;
 for(i=0;i<3;i++)
  for(j=0;j<3;j++)
   cin>>a[i][j];
 //cout<<"转制后的矩阵是:"<<change()<<endl;//
  change();
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
   cout<<a[i][j]<<" ";
  cout<<endl;
 }
 return 0;
}
void change()
{int i,j;
float t;
 for(i=0;i<3;i++)
  for(j=i+1;j<3;j++)//从i+1开始。执行交换
  {
   t=a[i][j];
   a[i][j]=a[j][i];
   a[j][i]=t;
  }
//{for(i=0;i<3;i++)
 //{for(j=0;j<3;j++)
  // return a[i][j];}//return 只返回一次，后面的语句不执行。
//cout<<endl;
//}
}
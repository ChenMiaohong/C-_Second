#include<iostream>
using namespace std;
int cheacknum(int m)
{
    int k;
    if(m<2)
        return -1;
    else
    {
        for(k=2;k<=m/2;k++)
            if(m%k==0)
        {
            return -1;
        }
        return 2;
    }
}
int main()
{
    int m=0;
    int i,j,flag;
    int sum=1;
    cin>>m;
    for(i=1;i<m;i++)
    {
        sum=1;
        if(flag==10&&i==m-1)
            cout<<"NO"<<endl;
        for(j=1;j<m;j++)
        {
              sum*=i;
        if(sum==m)
      {
          if(cheacknum(i)>0&&j>1)
          cout<<i<<" "<<j<<endl;
          break;
      }
      if(sum>m)
      {
          flag=10;
           break;
      }

    }

    }


}



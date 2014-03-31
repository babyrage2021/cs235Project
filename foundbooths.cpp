#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
  int m1,m2,q1,q2,i,s,temp,q_1=0,j=0,product=0,count=4,a[4]={0,0,0,0},
  m[4]={0,0,0,0},q[4]={0,0,0,0},m3[4],ans[8];
  clrscr();
  printf("\n\n\n enter the two unsigned numbers:");
  scanf("%d%d",&m1,&q1);
  m2=m1;
  q2=q1;
  if(m1<0) m1=m1*(-1);
  if(q1<0) q1=q1*(-1);
  for(i=0;i<4;i++)
  {
   m[i]=m1%2;
   m1=m1/2;
   q[i]=q1%2;
   q1=q1/2;
  }
  
  if(m2<0)
  {
   for(i=3;i>=0;i--)
   {
    if(m[i]==0) 
      m[i]=1;
    else 
      m[i]=0;
   }
   
   m[0]=m[0]+1;
   for(i=0;i<3;i++)
   {
    if(m[i]>=2)
    {
     m[i]=m3[i]-2;
     m[i+1]=m[i+1]+1;
    }
   }
  }
  if(q2<0)
  {
   for(i=3;i>=0;i--)
   {
    if(q[i]==0) q[i]=1;
    else q[i]=0;
   }
   q[0]=q[0]+1;
   for(i=0;i<3;i++)
   {
    if(q[i]>=2)
    {
     q[i]=q[i]-2;
     q[i+1]=q[i+1]+1;
    }
   }
  }
  printf("\n The binary conversions are:\n\n\n%d:",m2);
  for(i=3;i>=0;i--)
  printf("%d",m[i]);
  printf("\n%d:",q2);
  for(i=3;i>=0;i--)
  printf("%d",q[i]);
  again:
  if(q[0]==0&&q_1==1)
  {
   for(i=3;i>=0;i--)
   a[i]=a[i]+m[i];
   for(i=0;i<3;i++)
   {
    if(a[i]>=2)
    {
             a[i]=a[i]-2;
     a[i+1]=a[i+1]+1;
    }
    if(a[3]>=2) a[3]=a[3]-2;
   }
  }
  else
  {
   if(q[0]==1&&q_1==0)
   {
    for(i=3;i>0;i--)
    m3[i]=m[i];
    for(i=3;i>=0;i--)
    {
     if(m3[i]==0) m3[i]=1;
     else m3[i]=0;
    }
    m3[0]=m3[0]+1;
    for(i=0;i<3;i++)
    {
             if(m3[i]>=2)
     {
              m3[i]=m3[i]-2;
      m3[i+1]=m3[i+1]+1;
      }
    }
    for(i=3;i>=0;i--)
     a[i]=a[i]+m3[i];
    {
             if(a[i]>=2)
     { 
              a[i]=a[i]-2;
      a[i+1]=a[i+1]+1;
     }
     if(a[3]>=2)
     a[3]=a[3]-2;
    }
  }
  }
  if((q[0]==1&&q_1==1)||(q[0]==0&&q_1==0))
  goto shift;
  shift:
  q_1=q[0];
  for(i=0;i<4;i++)
  q[i]=q[i+1];
  q[3]=a[0];
  s=a[3];
  for(i=0;i<4;i++)
  a[i]=a[i+1];
  a[3]=s;
  count--;
  else goto again;
  end:
  ans[7]=a[3];ans[6]=a[2];ans[5]=a[1];ans[4]=a[0];
  for(i=3;i>=0;i--)
  if((m2>0&&q2<0)||(m2<0&&q2>0))
  {
   for(i=7;i>=0;i--)
  { 
   if(ans[i]==0) ans[i]=1;
  else ans[i]=0;
  }
  ans[0]=ans[0]+1;
  {
   if(ans[i]>=2)
   {
    ans[i]=ans[i]-2;
    ans[i+1]=ans[i+1]+1;
   }
  }
 }
  for(i=0;i<8;i++)
  {
   temp=ans[i]*pow(2,j);
   product=product+temp;
   j++;
  }
  if((m2>0&&q2<0)||(m2<0&&q2>0))
  product=product*(-1);
  printf("\n Product: ");
  for(i=7;i>=0;i--)
  printf("%d",ans[i]);
  printf("\n\n\n The Unsigned Multiplication of %d and %d is %d",m2,q2,product);
  getch();
}
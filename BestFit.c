#include<stdio.h>
#define MAX 25
int main()
{
  int f[MAX],b[MAX],nf,nb,temp,bf[MAX],ff[MAX],frag[MAX],lowest;
  printf("Enter the number of processes");
  scanf("%d",&nf);
  printf("Enter the number of blocks");
  scanf("%d",&nb);
  for(int i=0;i<MAX;i++)
  {
   ff[i]=-1;
   bf[i]=-1;
  }
  for(int i=0;i<nf;i++)
  {
   printf("Process %d",i);
   scanf("%d",&f[i]);
  }
  for(int i=0;i<nb;i++)
  {
    printf("Blocks %d",i);
    scanf("%d",&b[i]);
  }
  for(int i=0;i<nf;i++)
  {
     lowest=1000;
    for(int j=0;j<nb;j++)
    {
     if(bf[j]!=1)// block at j not allocated
     {
      temp=b[j]-f[i];
      if(temp>0 && temp<=lowest)
      {
        ff[i]=j;//block j allocated to process i
        lowest=temp;
      }
     }
    }
    if(ff[i]!=-1) //process i is not free
    {
      bf[ff[i]]=1;//block at j is allocated
      frag[i]=lowest;//frag has the lowest extra space
    }
    else
    {
      frag[i]=-1;
    }
  }
  printf(" Process No \t\t Process size \t\t Block No\t\t Block size \t\t Fragment\n");
  for(int i=0;i<nf;i++)
  {
    if(ff[i]!=-1)
    printf("%d\t\t%d\t\t %d\t\t %d\t\t %d\t\t \n",i,f[i],ff[i],b[ff[i]],frag[i]);
    else
    printf("%d\t\t%d\t\tNotAllocated\t\tNot Allocated\t\t NotAllocated\n",i,f[i]);

  }
}

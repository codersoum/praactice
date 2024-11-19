package practice;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class basic 
{
public static int[] solve(int m,int n,int a[])
{
 int[] freq=new int[m+1];
 //HashSet<Integer> hs=new HashSet<>();
 List<Integer> l=new ArrayList<>();
 for(int i=0;i<a.length;i++)
 {
	l.add(a[i]);
	//hs.add(a[i]);
 }
  for(int i=0;i<a.length;i++)
  {
	 freq[a[i]]++;
  }
  Collections.sort(l,(a1,b1)->{
	  if(freq[a1]>freq[b1])
	  return -1;
	  else if(freq[a1]<freq[b1])
	  return 1;
	  else
		 return l.indexOf(a1)-l.indexOf(b1);
	  
  });
return a;
}
public static void main(String[] args)
{
 Scanner sc=new Scanner(System.in);
 int m=sc.nextInt();
 int n=sc.nextInt();
 int [] a=new int[m];
 for(int i=0;i<m;i++)
 {
	a[i]=sc.nextInt();
 }
 int[] arr=solve(m,n,a);
 for(int i=0;i<arr.length;i++)
 {
	 System.out.print(arr[i]+" ");
	}
 }
}
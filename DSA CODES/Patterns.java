import java.util.Scanner;
public class Main{

     public static void main(String []args){
         Scanner sc=new Scanner(System.in);
         int r=sc.nextInt();
         int ct=0;
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=r-i;j++)
        {
            System.out.print("  ");
        }
        for(int j=1;j<=i;j++)
        {
            System.out.print("*");
            System.out.print("  ");
            ct++;
        }
        System.out.println();
    }
    System.out.println();
    System.out.println();
 for(int i=1;i<=r;i++)
 {
     for(int j=1;j<=i;j++)
     {
         if(j==i||j==1||i==r)
         System.out.print("* ");
         else
         System.out.print("  ");
     }
     System.out.println();
 }
 System.out.println();
 System.out.println();
 for(int i=1;i<=2*r-1;i++)
 {
     if(i<=r)
     {
     for(int j=1;j<=i;j++)
     {System.out.print("* ");
         
     }
     }
     else{
         for(int j=1;j<=2*r-i+1;j++)
         {System.out.print("* ");
         
     }}
     System.out.println();
     }
      System.out.println();
 for(int i=1;i<=r;i++)
 {
     for(int j=1;j<=2*i-2;j++)
     System.out.print("  ");
     for(int j=i;j<=r;j++)
     System.out.print("* ");
      System.out.println();
 }
  System.out.println();
  for(int i=1;i<=2*r-1;i++)
  {
      if(i<=r)
      {
          for(int j=1;j<=r-i;j++)
          System.out.print("  ");
          for(int j=1;j<=i;j++)
          System.out.print("* ");
      }
      else
      {
          for(int j=r+1;j<=i;j++)
          System.out.print("  ");
           for(int j=1;j<=2*r-i;j++)
          System.out.print("* ");
      }
      System.out.println();
      }
       ct=1;
          for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=r-i;j++)
        {
            System.out.print("  ");
        }
        for(int j=1;j<=2*i-1;j++)
        {
            System.out.print(ct);
            System.out.print(" ");
            ct++;
        }
        ct=1;
        System.out.println();
    }
    System.out.println();
    for(int i=1;i<=r;i++)
    {
         for(int j=1;j<=r-i;j++)
        {
            System.out.print("  ");
        }
        for(int j=1;j<=2*i-1;j++)
        {
            if(j==1||j==2*i-1)
            System.out.print(i+" ");
            else
            System.out.print("0 ");
        }
        System.out.println();
    }
}
}

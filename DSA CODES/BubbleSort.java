import java.util.*;

public class BubbleSort {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the number of array elements:");
        int n = s.nextInt();
        System.out.print("Enter the array elements: ");
        int[] arr = new int[n];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = s.nextInt();
        }   
        s.close();
        int t = 0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 1; j < (arr.length -i); j++) {
                if(arr[j-1] > arr[j]){
                    t = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = t;
                }
            }
            
        }
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+ " ");
        }
        
    }
}
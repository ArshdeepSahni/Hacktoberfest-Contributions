link to the video i reffered: https://www.youtube.com/watch?v=YxuK6A3SvTs


import java.util.*;

public class LargestSumContiguousSubarray {
    public static int result(int[] a){
        int size = a.length;
        int meh = 0;  // meh = Max_ending_here.
        int msf = 0; //msf = Max_so_far.
        for(int i = 0; i < size; i++){
            meh = meh + a[i];

            if(meh < 0){
                meh = 0;

                // compare only whe meh is greater
            } else if(msf < meh){
                msf = meh;
            }
        }
        return msf;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++){
            arr[i] = sc.nextInt();
        }
        System.out.println("Largest sum contiguous subarray: " + result(arr));
        sc.close();
    }
}
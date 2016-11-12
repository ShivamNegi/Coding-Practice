import java.util.Arrays;
import java.util.Scanner;

class acm_4 {

    static int arr[];
    static int cache[] ;

    static int n;
    static int fx(int x)
    {
        if(x==n-1)
        {
            return 1;
        }

        int res = 0;
        for(int i = x+1; i < n; i++)
        {
            if(arr[i]%arr[x]==0)
            {
                if(cache[i]==0) {
                    res += fx(i);
                }
                else
                {
                    res += cache[i];
                    
                }
            }
        }

        cache[x] = res+1;
       
        return (res+1)%(1000000007);

    }





    public static void main(String args[])
    {

        Scanner key = new Scanner(System.in);
        int t = key.nextInt();
        for(int i = 0; i< t; i++)
        {
            n = key.nextInt();
            arr = new int[n];
            cache = new int[n+1];
            for(int j = 0 ; j < n; j++)
            {
                arr[j] = key.nextInt();
            }
            int res = 0;
            Arrays.sort(arr);
            for(int j = 0 ; j < n ; j++)
            {
                res += fx(j);
            }
            System.out.println(res);

        }




    }
}

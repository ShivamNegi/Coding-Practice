//package Main;

import java.util.Scanner;


public class Main {


    static int arr[][];
    static int r, c;
    static byte visited[][];
    static long fx(int y, int x)
    {

        if(visited[y][x]==1){return 0;}
        visited[y][x]=1;
        long res = arr[y][x];
        if(arr[y][x]==0)
        {
          if((y-1>=0)&&(visited[y-1][x]==0)) {res = res + fx(y-1,x);}
          if((y+1<r)&&(visited[y+1][x]==0)){res = res + fx(y+1,x);}
            if((x-1>=0)&&(visited[y][x-1]==0)){res = res + fx(y,x-1);}
            if((x+1<c)&&(visited[y][x+1]==0)){res = res + fx(y,x+1);}

        }
        //System.out.println(y+"\t"+x+"\t"+res);
        return res;

    }



    public static void main(String[] args)
    {
        Scanner k = new Scanner(System.in);
         r = k.nextInt();
         c = k.nextInt();
        arr = new int[r][c];
        visited = new byte[r][c];
        long sum = 0;


        for(int i = 0; i < r; i ++)
        {
            for(int j = 0 ; j < c; j++)
            {
                arr[i][j] = k.nextInt();
                sum = sum + arr[i][j];
            }
        }

        int n = k.nextInt();
        for(int i = 0; i < n ; i++)
        {

            int y = k.nextInt();
            int x = k.nextInt();
            long res = fx(y-1,x-1);
            sum = sum-res;
            System.out.println(sum);
        }






    }
}

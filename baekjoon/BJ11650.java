import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] x = new int[n];
        int[] y = new int[n];

        for(int i = 0 ; i < n; i++){
            String s = br.readLine();
            StringTokenizer tok = new StringTokenizer(s);
            x[i] =  Integer.parseInt(tok.nextToken());
            y[i] =  Integer.parseInt(tok.nextToken());
        }

        quickSort(x, y, 0, n-1);

        int start = 0, end = 0;
        boolean isSame = false;
        for (int i = 0 ; i <n-1; i++){
            int n1 = x[i];
            int n2 = x[i+1];
            if (n1 == n2){
                start = i;
                end = i+1;
                isSame = true;
            }

            while(isSame && i < n-1){
                if (n1 == x[++i]){
                    end = i;    // if 문에서 전치증가
                } else{
                    isSame = false;
                    break;
                }
            }

            if ((start != end) && !isSame){
                quickSort(y, start, end);
            }
        }

        for (int i = 0 ; i< n; i++){
            System.out.println(x[i] + " " + y[i]);
        }
    }

    static void quickSort(int x[], int y[], int left, int right){

        int q;
        if (left < right){
            q = partition(x, y, left, right);
            quickSort(x, y, left, q-1);
            quickSort(x, y, q+1, right);
        }
    }

    static void quickSort( int y[], int left, int right){

        int q;
        if (left < right){
            q = partition( y, left, right);
            quickSort( y, left, q-1);
            quickSort( y, q+1, right);
        }
    }

    static int partition(int x[], int y[], int left, int right){
        int pivot = x[left];
        int low = left+1;
        int high = right;


        while(low < high){
            for(;low <= right && x[low] < pivot; low++);
            for(;high >= left && x[high] > pivot; high--);
            if ( low < high){   // swap

                int tmp = x[low];
                x[low] = x[high];
                x[high] = tmp;

                tmp = y[low];
                y[low] = y[high];
                y[high] = tmp;
            }
        }

        int tmp = x[high];
        x[high] = x[left];
        x[left] = tmp;

        tmp = y[high];
        y[high] = y[left];
        y[left] = tmp;
        return high;
    }

    static int partition(int y[], int left, int right){
        int pivot = y[left];
        int low = left+1;
        int high = right;

        while(low < high){
            for(;low <= right && y[low] < pivot; low++);
            for(;high >= left && y[high] > pivot; high--);
            if ( low < high){   // swap

                int tmp = y[low];
                y[low] = y[high];
                y[high] = tmp;
            }
        }

        int tmp = y[high];
        y[high] = y[left];
        y[left] = tmp;
        return high;
    }
}

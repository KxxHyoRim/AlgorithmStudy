import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ1167 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());    // vertex 개수
        int[][] arr = new int[n][n];

        // Initialize
        for (int i = 0 ; i< n; i++){
            for(int j = 0 ; j< n; j++){
                arr[i][j] = 0;
            }
        }

        kkk: for (int i = 0 ; i< n; i++){
            String s = br.readLine();
            String[] temp = s.split(" ");
            int idx = 1;

            while (true){
                try {
                    int vertex = Integer.parseInt(temp[idx]) -1;
                    int data = Integer.parseInt(temp[idx + 1]);

                    arr[i][vertex] = data;
                    arr[vertex][i] = data;

                } catch (Exception e) { continue kkk; }

                idx += 2;
            }
        }

        // INF 값 대입
        for (int i = 0 ; i< n; i++){
            for (int j = 0 ; j < n; j++){
                 if( arr[i][j] == 0){
                     arr[i][j] = 100001;
                 }
            }
        }

        for (int k = 0; k < n ; k++){
            for (int i = 0 ; i< n; i++){
                for (int j = 0 ; j < n; j++){
                    if (i == j)
                        arr[i][j]= 0;
                    else {
                        arr[i][j] =  Math.min(arr[i][j] , arr[i][k] + arr[k][j]);
                    }
                }
            }
        }

        int max = 0;
        for (int i = 0 ; i< n; i++){
            for (int j = 0 ; j< n; j++){
                if (arr[i][j] > max)
                    max = arr[i][j];
            }
        }
        System.out.println( max);
    }

}



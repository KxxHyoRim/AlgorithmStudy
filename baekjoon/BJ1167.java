import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ1167 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());    // vertex 개수
        int[][] arr = new int[n][n];

        // 초기화
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


        // print array
        for (int i = 0 ; i< n; i++){
            for(int j = 0 ; j< n; j++){
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }

        //
        // find max
        for (int i = 0 ; i< n; i++){
            for (int j = 0 ; j < n; j++){
                 if( arr[i][j] == 0){
                     arr[i][j] = 999;
                 }
            }
        }

//        // find max
//        int[][] length = new int[n][n];
//        for (int i = 0 ; i< n; i++){
//            for (int j = 0 ; j < n; j++){
//                length[i][j] = 999;
//            }
//        }

        int max = 0;
        for (int k = 0; k < n ; k++){
            for (int i = 0 ; i< n; i++){
                for (int j = 0 ; j < n; j++){
                    arr[i][j] = Math.min(arr[i][j] , arr[i][k] + arr[k][j]);
//                    if (length[i][j] > max)
//                        max = length[i][j];
                }
            }
        }

        // print lenght array
        for (int i = 0 ; i< n; i++){
            for(int j = 0 ; j< n; j++){
                System.out.print(arr[i][j] + " ");
            }
            System.out.println();
        }




    }

}

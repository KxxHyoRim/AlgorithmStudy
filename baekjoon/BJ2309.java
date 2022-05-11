import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static final int EXCLUDE_DWARF = 2;
    static int N = 9;
    static int[] index;
    static boolean[] used;
    static int[] value;
    static int total;

    static void permutation(int cnt) {
        if (cnt == EXCLUDE_DWARF) {
            int sum = value[index[0]] + value[index[1]];
            if (total - sum == 100) sortAndPrintArr();
            return;
        }

        for (int i = 0; i < N; i++) {
            if (!used[i]) {
                used[i] = true;
                index[cnt] = i;
                permutation(cnt + 1);
                used[i] = false;
            }
        }
    }

    static void sortAndPrintArr() {
        int[] rtn = new int[7];

        int idx = 0;
        for (int j = 0; j < N; j++) {
            if (j == index[0] || j == index[1]) continue;
            rtn[idx++] = value[j];
        }

        Arrays.sort(rtn);
        for (int i = 0; i < 7; i++) {
            System.out.println(rtn[i]);
        }
        System.exit(0);
    }


    public static void main(String[] args) throws IOException {

        index = new int[EXCLUDE_DWARF];
        used = new boolean[N];
        value = new int[N];

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            value[i] = Integer.parseInt(st.nextToken());
            total += value[i];
        }

        permutation(0);
    }
}

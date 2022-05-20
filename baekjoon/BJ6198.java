import java.io.*;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine()), input;
        long sum = 0;
        Stack<Integer> s = new Stack<>();

        for (int i = 0; i < N; i++) {
            input = Integer.parseInt(br.readLine());
            while (!s.empty()) {
                if (s.peek() > input) break;
                s.pop();
            }
            sum += s.size();
            s.push(input);
        }
        bw.write(String.valueOf(sum));
        bw.flush();
    }
}

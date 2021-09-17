import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ9519 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder str = new StringBuilder();

        int n = Integer.parseInt(br.readLine());
        String s = br.readLine();

        char temp[] = new char[s.length()];
        str.append(s);

        int size = s.length();
        int periodIdx = 1;
        int period[] = new int[3100];
        period[0] = 1;
        int half = (size - 1) / 2;    //앞쪽 반의 마지막 index
        int curr = 1;

        //주기 구하기
        while(true){
            if (curr <= half)
                curr = curr * 2;
            else
                curr = (size - curr) * 2 - 1;

            period[periodIdx++] = curr;

            if (curr == size - 1)
                break;

        }

        for (int i = 0 ; i< n % periodIdx; i++){
            int start = 0;
            int end = s.length();

            for (int j = 0 ; j < s.length() / 2; j++){
                temp[start++] = s.charAt(j*2);
                temp[--end] = s.charAt(j*2+1);
            }
            if (s.length() % 2 == 1)
                temp[start] = s.charAt(s.length()-1);

            str.delete(0, str.length());

            for (int j = 0 ; j < s.length(); j++)
                str.append(temp[j]);

            s = str.toString();

        }

        System.out.println(s);


    }
}
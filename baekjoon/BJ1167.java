import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ1167 {
    static int n; // vertex 개수

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());    // vertex 개수
        LinkedList[] ll = new LinkedList[n];

        // Linked List에 data 대입하기
        for (int i = 0 ; i< n; i++){
            String s = br.readLine();
            String[] temp = s.split(" ");
            int idx = 1;

            ll[i] = new LinkedList();

            while (true){
                try {
                    int vertex = Integer.parseInt(temp[idx]) -1;
                    int data = Integer.parseInt(temp[idx + 1]);

                    ll[i].InsertAtFront(vertex, data);

                } catch (Exception e) { break; }

                idx += 2;
            }
        }

        // print LL
//        for (int i = 0 ; i< n; i++){
//            ll[i].DisplayAll();
//            System.out.println();
//        }

        int max = 0;
        int nowIdx = 0;
        for (int i = 0 ; i< n; i++){
            // 1의 max, 2의 max... 구해서 젤 큰값 사용하기

            int[] dist = new int[n];
            boolean[] found = new boolean[n];

            // initialize found[]
            for (int j = 0 ; j < n; j++){
                found[j] = false;
            }

            // initialize dist[]
            for (Node cur = ll[nowIdx].first; cur != null; cur = cur.next){
                dist[cur.vertex] = cur.data;
            }

            found[i] = true;    // 시작 vertex 포함
            dist[i] = 0;        // 최초 거리

            int maxIdx = -1;
            int maxDist = 0;
            for (int j = 0 ; j< n; j++){
                if (found[j]) continue;

                if (dist[j] > maxDist){
                    maxDist = dist[j];
                    maxIdx = j;
                }
            }

            nowIdx = maxIdx;
            max += maxDist;


//            System.out.println("현재 Dist : " + max + ", 다음 탐색 : " + maxIdx );

            if (nowIdx == -1) break;
        }
        System.out.println( max);
    }
}

class Node {
    public int data;
    public int vertex;
    public Node next;

}

class LinkedList {
    public Node first;

    public LinkedList(){
        first = null;
    }

    public boolean isEmpty(){
        return (first == null);
    }

    public void InsertAtFront(int v, int d){
        Node newNode = new Node();
        newNode.vertex = v;
        newNode.data = d;
        newNode.next = first;
        first = newNode;
    }

    public void DisplayAll() {
        Node cur;
        for (cur = first; cur != null; cur = cur.next){
            System.out.print(cur.vertex + 1 + "(" + cur.data + ") ->");
        }
    }
}

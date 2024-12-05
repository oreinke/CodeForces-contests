import java.util.*;

public class d {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        StringBuilder result = new StringBuilder();

        int t = input.nextInt();
        for (int tc = 0; tc < t; tc++) {
            int n = input.nextInt();
            int m = input.nextInt();
            int l = input.nextInt();

            TreeMap<Integer, Integer> barriers = new TreeMap<>();
            TreeMap<Integer, ArrayList<Integer>> powerups = new TreeMap<>();
            for (int i = 0; i < n; i++) {
                int s = input.nextInt();
                int e = input.nextInt();
                barriers.put(s, e);                
            }

            for (int i = 0; i < m; i++) {
                int x = input.nextInt();
                int p = input.nextInt();
                if (!powerups.containsKey(x)) {
                    powerups.put(x, new ArrayList<>());
                }
                powerups.get(x).add(p);
            }

            int loc = 1;
            int power = 1;
            int consumed = 0;
            PriorityQueue<Integer> availablePower = new PriorityQueue<>(Collections.reverseOrder());
            while (!barriers.isEmpty()) {
                // System.out.println("reached");
                System.out.flush();
                loc = barriers.firstKey() - 1;
                while (!powerups.isEmpty() && powerups.firstKey() <= loc) {
                    availablePower.addAll(powerups.get(powerups.firstKey()));
                    powerups.pollFirstEntry();
                }
                int dist =  barriers.get(barriers.firstKey()) - barriers.firstKey() + 2;
                while (!availablePower.isEmpty() && power < dist) {
                    power += availablePower.poll();
                    consumed++;
                }
                if (power < dist) {
                    result.append(-1).append("\n");
                    break;
                }
                barriers.pollFirstEntry();
            }
            if (barriers.isEmpty()) {
                result.append(consumed).append("\n");
            }
            
        }
        System.out.print(result);
    }
}
package dsaii.patterns;

import java.util.Map;
import java.util.TreeMap;

public class BoyerMoore {
    private static int comparisons = 0;

    public static void main(String[] args) {
        String T = "a pattern matching algorithm";
        comparisons = 0;
        System.out.println("index: " + match(T, "rithm"));
        System.out.println("comparisons: " + comparisons);

        T = "abacaabadcabacabaabb";
        comparisons = 0;
        System.out.println("index: " + match(T, "abacab"));
        System.out.println("comparisons: " + comparisons);
        
        T = "the cat sat on the back of the big red mat";
        comparisons = 0;
        
        int i = 0;
        while(i <= T.length()){
            int count = match(T, "the", i);
            if(count >= 0) {
                System.out.println("index: " + count);
                i = count + 3;
            }
            else
                i = (-1*count) + 1;
        }
        System.out.println("comparisons: " + comparisons);
    }

    public static int match(String T, String P) {
        int n = T.length();
        int m = P.length();

        Map<Character, Integer> L = lastOccurrenceMap(P);
        int i = m-1;
        int j = m-1;

        do {
            if (T.charAt(i) == P.charAt(j)) {
                if (j == 0) {
                    comparisons++;
                    return i;
                } else {
                    i--;
                    j--;
                }
            } else {
                int l = lastOccurrence(L, T.charAt(i));
                i = i + m - Math.min(j, 1+l);
                j = m-1;
            }
            comparisons++;
        } while (i < n);

        return -1;
    }
    
    public static int match(String T, String P, int offset) {
        int n = T.length();
        int m = P.length();

        Map<Character, Integer> L = lastOccurrenceMap(P);
        int i = offset;
        int j = m-1;

        do {
            if (T.charAt(i) == P.charAt(j)) {
                if (j == 0) {
                    comparisons++;
                    return i;
                } else {
                    i--;
                    j--;
                }
            } else {
                int l = lastOccurrence(L, T.charAt(i));
                i = i + m - Math.min(j, 1+l);
                j = m-1;
            }
            comparisons++;
        } while (i < n);

        return -i;
    }
    
	@SuppressWarnings("null")
	public static Map<Character, Integer> lastOccurrenceMap(String P) {
    	Map<Character, Integer> m = new TreeMap<>();
    	int index = -1;
    	
    	for(char c = 'a'; c <= 'z'; c++) {
    		for(int j = 0; j < P.length(); j++) {
    			if(c == P.charAt(j)) {
    				index = j;
    			}
    		}
    		m.put(c, index);
    	}
    	
        return m;
    }

    public static int lastOccurrence(Map<Character, Integer> L, Character c) {
        return L.get(c);
    }
}

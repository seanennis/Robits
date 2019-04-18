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
            int index = match(T, "the", i);

            if(index >= 0) {
                System.out.println("index: " + index);
                i = index + 3;
            }
            else
                i = -1 * index + 1;
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

    public static Map<Character, Integer> lastOccurrenceMap(String P) {
    	Map<Character,Integer> map = new TreeMap<Character, Integer>();
    	for(int i = P.length()-1; i>=0; i--){
    		char c = P.charAt(i);
    		if(!map.containsKey(c)){
    			map.put(c, i);
    		}
    	}
    	
        return map;
    }

    public static int lastOccurrence(Map<Character, Integer> L, Character c){
    	if(L.containsKey(c)){
    		return L.get(c);
    	}
        return -1;
    }
}

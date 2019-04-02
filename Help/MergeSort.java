package dsaii.sorting;

import dsaii.lists.LinkedList;
import dsaii.lists.List;

import java.lang.reflect.Array;
import java.util.Random;

public class MergeSort {
    /**
     * A simple test method.
     * @param args
     */
    public static void main(String[] args) {
        Random random = new Random();
        List<Integer> list = new LinkedList<Integer>();
        while (list.size() < 100) {
            list.insertLast(random.nextInt(100));
        }
        System.out.println(list);
        mergeSort(list);
        System.out.println(list);
    }

    /**
     * The main Merge Sort algorithm
     * @param S the list to be sorted
     * @param <T> the type of value stored in the list
     */
    public static <T extends Comparable<T>> void mergeSort(List<T> S) {
        if (S.size() > 1) {
            List<T>[] sublists = partition(S, S.size()/2);
            mergeSort(sublists[0]);
            mergeSort(sublists[1]);
            merge(S, sublists[0], sublists[1]);
        }
    }

    /**
     * The partitioning algorithm
     * @param S the list to be partitioned
     * @param n the approximate size of each partititon +/-1
     * @param <T> the type of value stored in the list
     * @return to sublists S0, S1 respectively
     */
    private static <T> List<T>[] partition(List<T> S, int n) {
        List<T>[] sublists = (List<T>[]) Array.newInstance(List.class,2);
        sublists[0] = new LinkedList<T>();
        sublists[1] = new LinkedList<T>();

        while (S.size() > n) {
            sublists[0].insertLast(S.remove(S.first()));
        }
        while (!S.isEmpty()) {
            sublists[1].insertLast(S.remove(S.first()));
        }
        return sublists;
    }

    /**
     * The merge algorithm
     * @param S the empty list that S1 and S2 will be merged into
     * @param S1 the first sorted sublist
     * @param S2 the second sorted sublist
     * @param <T> the type of value stored in the list
     */
    private static <T extends Comparable<T>> void merge(List<T> S, List<T> S1, List<T> S2) {
    }
}

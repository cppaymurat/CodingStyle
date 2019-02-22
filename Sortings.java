package com.company;
import java.util.*;
public class Main {
    static int sizeOfArray;
    public static int []merge(int []arrayFirst, int sizeFirst, int []arraySecond, int sizeSecond) {
        int []result = new int[sizeFirst + sizeSecond];
        int indexResult = 0, indexFirst = 0, indexSecond = 0;
        while(indexFirst < sizeFirst || indexSecond < sizeSecond) {
            if (indexFirst < sizeFirst && indexSecond < sizeSecond) {
                if (arrayFirst[indexFirst] < arraySecond[indexSecond]) {
                    result[indexResult] = arrayFirst[indexFirst];
                    indexFirst++;
                    indexResult++;
                } else {
                    result[indexResult] = arraySecond[indexSecond];
                    indexSecond++;
                    indexResult++;
                }
            } else {
                if (indexFirst == sizeFirst) {
                    while (indexSecond < sizeSecond) {
                        result[indexResult] = arraySecond[indexSecond];
                        indexSecond++;
                        indexResult++;
                    }
                } else
                {
                    while (indexFirst < sizeFirst) {
                        result[indexResult] = arrayFirst[indexFirst];
                        indexFirst++;
                        indexResult++;
                    }
                }
            }
        }
        if (result.length == sizeOfArray) {
            for(int i = 0; i < sizeOfArray; i++) {
                System.out.print(result[i] + " ");
            }
        }
        return result;
    }
    public static int [] mergeSort(int []array) {
        int size = array.length;
        if (size > 1) {
            int left = size / 2;
            int right = size - left;
            int []arrayForLeft = new int[left];
            for(int i = 0; i < left; i++) {
                arrayForLeft[i] = array[i];
            }
            int []arrayForRight = new int[right];
            for(int i = left; i < size; i++) {
                arrayForRight[i - left] = array[i];
            }
            arrayForLeft = mergeSort(arrayForLeft);
            arrayForRight = mergeSort(arrayForRight);
            return merge(arrayForLeft, left, arrayForRight, right);
        }
        return array;
    }
    public static int []bubbleSort(int []array) {
        for(int i = 0; i < array.length - 1; i++) {
            for(int j = i + 1; j < array.length; j++) {
                if (array[i] > array[j]) {
                    int tmp = array[i];
                    array[i] = array[j];
                    array[j] = tmp;
                }
            }
        }
        for(int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        return array;
    }
    public static int []quickSort(int []array) {
        int size = array.length;
        if (size > 1) {
            int[] result = new int[size];
            int pivote = size / 2;
            int left = size / 2;
            int right = size - left;
            int[] arrayForLeft = new int[left];
            int[] arrayForRight = new int[right];
            for (int i = 0; i < left; i++) {
                arrayForLeft[i] = array[i];
            }
            for (int i = left; i < size; i++) {
                arrayForRight[i - left] = array[i];
            }
            arrayForLeft = quickSort(arrayForLeft);
            arrayForRight = quickSort(arrayForRight);
            for(int i = 0; i < arrayForLeft.length; i++) {
               // if ()
            }
            return result;
        }
        return array;
    }
    public static int []insertionSort(int []array) {
        int alreadySorted = 1;
        if (sizeOfArray > 1) {
            if (array[1] < array[0]) {
                int tmp = array[1];
                array[1] = array[0];
                array[0] = tmp;
            }
            alreadySorted++;
        }

        for(int i = 2; i < sizeOfArray; i++) {
            //first case
            if (array[i] <= array[0]) {
                //cyclic shift
                int tmp = array[i];
                for(int j = i; j > 0; j--) {
                    array[j] = array[j - 1];
                }
                array[0] = tmp;
            } else
            //second case
            if (array[i] >= array[i - 1]) {
                //do not touch
                System.out.print("YES");
                continue;
            } else {
                //find first j such that j < i and array[i] >= array[j], array[i] <= array[j + 1]
                int j = 0;
                while(j + 1 < i) {
                    if (array[i] >= array[j] && array[j + 1] >= array[i]) break;
                    j++;
                }
                //found j
                j++;
                int tmp = array[i];
                for(int k = i; k > j; k--) {
                    array[k] = array[k - 1];
                }
                array[j] = tmp;
            }
            alreadySorted++;
            for(int k = 0; k < alreadySorted; k++) {
                System.out.print(array[k] + " ");
            }
            System.out.println();
        }
        return array;
    }
    public static void solve() {
        Scanner in = new Scanner(System.in);
        sizeOfArray = in.nextInt();
        int []array = new int[sizeOfArray];
        for(int i = 0; i < sizeOfArray; i++) {
            array[i] = in.nextInt();
        }
        System.out.print("Sorted array: \n");
        //bubbleSort(array);
        //mergeSort(array);
        //quickSort(array);
        insertionSort(array);
        for(int i = 0; i < sizeOfArray; i++) {
            System.out.print(array[i] + " ");
        }
    }
    public static void main(String[] args) {
        solve();
    }
}

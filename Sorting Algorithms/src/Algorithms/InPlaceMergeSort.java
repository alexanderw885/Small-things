/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Algorithms;

/**
 *
 * @author alexa
 */
public class InPlaceMergeSort<T extends Comparable> implements Sort<T> {

    @Override
    public void Sort(T[] array) {
        RecursiveSort(array, 0, array.length-1);
    }
    
    private void RecursiveSort(T[] array, int min, int max){
        if(min>=max){
            return;
        }
        RecursiveSort(array, min, (max+min)/2);
        RecursiveSort(array, ((max+min)/2)+1, max);
        Merge(array, min, max);

    }
    

    
    private void Merge(T[] array, int min, int max){
       int mid = (min+max)/2+1;

        int point1 = min;
        int point2 = mid;
        
        while(point1<=mid && point2<=max){
            
            if(array[point1].compareTo(array[point2])<=0){
                point1++;
            } else {
                BubbleDown(array, point1, point2);
                point2++;
                mid++;
            }
        }
    }

    private void BubbleDown(T[] array, int min, int max){
        T temp = array[max];
        while(max>min){
            array[max] = array[max -1];
            max--;
        }
        array[min] = temp;
    }

    @Override
    public String Name() {
        return "Merge Sort";
    }
    
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Algorithms;

/**
 *
 * @author Alex
 */
public class BubbleSort<T extends Comparable> implements Sort<T> {
    @Override
    public void Sort(T[] array){
        for(int i=array.length; i>=0; i--){
            for(int j=0; j<i-1; j++){
                if(array[j].compareTo(array[j+1])>0){
                    T temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
            }
        }
    }
    
    @Override
    public String Name(){
        return "Bubble Sort";
    }
}

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Algorithms;

/**
 *
 * @author Alex
 */
public class InsertionSort<T extends Comparable> implements Sort<T> {
    public void Sort(T[] array){
        for(int i=1; i< array.length; i++){
            for(int j=i; j>0; j--){
                if(array[j].compareTo(array[j-1])<0){
                    T temp = array[j-1];
                    array[j-1]=array[j];
                    array[j] = temp;
                } else{
                    break;
                }
            }
        }
    }
    
    @Override
    public String Name(){
        return "Insertion Sort";
    }
}

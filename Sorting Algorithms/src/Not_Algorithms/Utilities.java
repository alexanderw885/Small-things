/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Not_Algorithms;

import Algorithms.Sort;
import Algorithms.RadixSort;
import java.util.Random;

/**
 *
 * @author Alex
 * @param <T> any comparable class to be sorted
 */
public class Utilities<T extends Comparable> {

    /**
     * Fills an array with unsorted integers, with a range of +-5* length of the array
     * @param array 
     */
    void FillInt(Integer[] array, int[] arrayInt) {
        Random rand = new Random();
        int in;

        for (int i = 0; i < array.length; i++) {
            in =rand.nextInt(-5 * array.length, 5 * array.length - 1);
            array[i] = in;
            arrayInt[i] = Math.abs(in);
                    
        }
    }
    
    void FillInt(int[] array){
        Random rand = new Random();

        for (int i = 0; i < array.length; i++) {
            array[i] = rand.nextInt(0, 5 * array.length - 1);
        }
    }
    
    /**
     * Checks if an array has been sorted, using the Comparable class
     * @param array array to be checked
     * @return -1 if sorted, otherwise first unsorted element in the array
     */
    private int CheckSort(T[] array){
        
        for(int i=0; i<array.length-1; i++){
            if(array[i].compareTo(array[i+1])>0){
                return i+1;
            }
        }
        return (-1);
    }
    
    private int CheckSort(int[] array){
        for(int i=0; i<array.length-1; i++){
            if(array[i]>array[i+1]){
                return i+1;
            }
        }
        return (-1);
    }
    
    /**
     * Like a decoration function, it calls Sort on the array using the provided class,
     * then prints it out and checks if the array was properly sorted
     * @param master Array to be sorted, it will not be touched
     * @param array Output for the sorting method
     * @param method Class with a sort method
     */
    void SortNCheck(T[] master, T[] array, Sort method){
        // master is copied to array to ensure each sort can use the same array
        for(int i=0; i<master.length; i++){
            array[i] = master[i];
        }
        
        method.Sort(array);
        String name = method.Name();
        int check = CheckSort(array);
        if(check>=0){
            System.out.println(name+" failure at index "+check);
        } else{
            System.out.println(name+" sorted array:");
            
        }
        for(int i=0; i<array.length; i++){
            System.out.printf(array[i]+",");
            }
        System.out.println("\n");
    }
    
    void SortNCheck(int[] master, int[] array, RadixSort method){
        // master is copied to array to ensure each sort can use the same array
        for(int i=0; i<master.length; i++){
            array[i] = master[i];
        }
        
        method.Sort(array);
        String name = method.Name();
        int check = CheckSort(array);
        if(check>=0){
            System.out.println(name+" failure at index "+check);
        } else{
            System.out.println(name+" sorted array:");
            
        }
        for(int i=0; i<array.length; i++){
            System.out.printf(array[i]+",");
            }
        System.out.println("\n");
    }
}


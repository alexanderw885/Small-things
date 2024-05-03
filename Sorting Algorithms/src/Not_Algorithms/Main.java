/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Not_Algorithms;
import Algorithms.*;

/**
 *
 * @author Alex
 */
public class Main{
    public static void main(String[] args){
        Integer length = 100;
        
        Integer[] masterArray = new Integer[length];
        Integer[] fluidArray = new Integer[length];
        Utilities util = new Utilities();
        util.FillInt(masterArray);

        
        System.out.println("Unsorted array:");
        for(int i=0; i<length; i++){
            System.out.printf("%s,",masterArray[i].toString());
        }
        System.out.println("\n");
        
        util.SortNCheck(masterArray, fluidArray, new BubbleSort());
        
        util.SortNCheck(masterArray, fluidArray, new InsertionSort());
        
        util.SortNCheck(masterArray, fluidArray, new InPlaceMergeSort());
        

    }
    
    
    
}

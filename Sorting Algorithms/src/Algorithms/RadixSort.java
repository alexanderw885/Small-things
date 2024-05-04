/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Algorithms;
import Not_Algorithms.ArrayQueue;
/**
 *
 * @author alexa
 */
public class RadixSort {
    
    ArrayQueue[] queues;
    ArrayQueue mainQueue;
    
    public void Sort(int[] array){
        queues = new ArrayQueue[10];
        mainQueue = new ArrayQueue(array, true);
        
        for(int i=0; i<10; i++){
            queues[i] = new ArrayQueue(array.length);
        }
        
        int loops = FindLoopNum(array);
        
        for(int i=0; i<loops; i++){
            FillQueues(i);
            EmptyQueues();
        }
    }
    
    private int FindLoopNum(int[] array){
        int largest =array[1];
        
        for(int i=0;i<array.length; i++){
            if(array[i]>largest){
                largest =array[i];
            }
        }
        int loops =1;
        while(largest>=10){
            largest /= 10;
            loops++;
        }
        return loops;
    }
    
    private void FillQueues(int loop){
        int checkVal =1;
        for(int i=0; i<loop; i++){
            checkVal *=10;
        }
        
        while(!mainQueue.IsEmpty()){
            int elem = mainQueue.Dequeue();
            queues[(elem/checkVal)%10].Enqueue(elem);
        }
    }
    
    private void EmptyQueues(){
        for(int i=0; i<10; i++){
            while(!queues[i].IsEmpty()){
                mainQueue.Enqueue(queues[i].Dequeue());
            }
        }
    }
    
    public String Name(){
        return "Radix Sort";
    }
}

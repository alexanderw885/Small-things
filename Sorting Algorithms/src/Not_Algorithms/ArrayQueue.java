/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Not_Algorithms;

/**
 *
 * @author alexa
 */
public class ArrayQueue {
    int[] array;
    int head;
    int tail;
    int len;
    
    public ArrayQueue(int size){
        array = new int[size];
        head = 0;
        tail = 0;
        len = 0;
    }
    
    public ArrayQueue(int[] array, boolean full){
        this.array = array;
        head = 0;
        if(full){
            tail = 0;
            len = array.length;
        } else {
            for(int i=array.length-1; i>=0; i--){
                if(array[i] !=0){
                    tail = (i+1)%array.length;
                    len = i+1;
                }
            }
        }
    }
    
    public void Enqueue(int elem){
        if(head == tail && !IsEmpty()){
            System.out.println("Queue overfilled TODO extend array");
            System.exit(1);
        }
        array[tail] = elem;
        tail = (tail+1)%array.length;
        len++;
    }
    
    public int Dequeue(){
        if(IsEmpty()){
            System.out.println("Queue empty, cannot dequeue");
            System.exit(1);
        }
        int out = array[head];
        head = (head+1)%array.length;
        len--;
        return out;
    }
    
    public int Size(){
        return len;
    }
    public boolean IsEmpty(){
        if(len!=0){
            return false;
        }
        return true;
    }
}

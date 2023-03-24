//dilan dilen
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define max 200

int front=-1,rear=-1;       // global variable
int circArr[max];
//prints the front and rear of the array
void display()
{
    printf("\n Front -> %d ", circArr[front]);
    printf("\n Rear -> %d \n", circArr[rear]);

}
//delete element from start
int dequeue()
{
    int element;
    //returns if array is empty
    if(front==-1)
    return 0;
    else {
    element = circArr[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    }
    //front becomes the next index
    else {
      front = (front + 1) % max;
    }
    return element;}

}
void insert()
{
   //if array is full
    if((front ==0 && rear == max-1) || front == rear+1)
    {  //print rear and front
       display();
       //delete half
       for(int i =0;i<(max/2);i++)
       dequeue();
       //display
       display();
       //fill half
       for(int i =0;i<(max/2);i++)
       insert();
       display();

       return;
    }
    //if array is empty then front-1 to 0
    if(front==-1)
    front=front+1;
    rear = (rear + 1) % max;
    //generate random number between 0 and 500
    circArr[rear]=rand()%500;
}

int main()
{   //different rand number every time
    srand(time(NULL));
    int w=0;
    //fill the array
     while(w<=max){
     insert();

     w++;
     }

}


/*
    Chris Russell
    CSC450: Programming III
    Module 8 CTA
    June 8, 2025
*/

public class mod8cta 
{
    public static void main(String[] args)
    {
        int myNumb = 0;
        
        /* Thread handling
         * Threads are instantiated with specified variables to handle counting within that thread.
         * The StartCounter() method executes the thread and waits until the thread is finished counting before proceeding with the application
         * When the thread finishes counting, myNumb is updated to the new integer to be used later in the application
         */

         //First thread handling
        Counter firstCounter = new Counter(20, 1, myNumb);
        System.out.println("\nCounting from the first thread");
        myNumb = StartCounter(firstCounter);

        //Second thread handling
        Counter secondCounter = new Counter(20, -1, myNumb);
        System.out.println("\nCounting from the second thread");
        myNumb = StartCounter(secondCounter);

        System.out.println("\nThreads have finished counting. The final number is: " + myNumb);
    }

    public static int StartCounter(Counter counter)
    {
        counter.start(); //Ultimately calls the run() method within the Counter class

        try
        {
            counter.join(); //Causes application to wait until thread is finished executing before proceeding
        }
        catch (InterruptedException ie)
        {
            System.out.println("Thread was interrupted: " + ie);
            Thread.currentThread().interrupt();
        }

        return counter.GetMyNumb(); //Update myNumb integer in main method
    }
}

class Counter extends Thread
{

    private int myNumb;
    private final int increment;
    private final int numIncrements;

    public Counter(int numIncrements, int increment, int myNumb)
    {
        this.numIncrements = numIncrements;
        this.increment = increment;
        this.myNumb = myNumb;
    }

    @Override
    public void run() {
        for (int i=0; i<numIncrements; i++)
        {
            myNumb += increment;
            System.out.println("The current value of myNumb is: " + myNumb);
        }
    }

    public int GetMyNumb()
    {
        //Returns number to update myNumb in main thread
        return myNumb; 
    }    
}

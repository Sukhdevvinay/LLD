public class Demo {
    public static void main(String[] args) {
        // Sleep()
        System.out.println("Main thread starts");

        try {
            Thread.sleep(2000); // AB Yaha par woh thread sleep hogi jo ki current running thread hain
            // Current Running Thread is Main Thread 
            // Toh Main Thread Sleep ho jayege for 2 seconds
            /*
            Jo Bhi hum current Thread ko sleep karwate hain woh apne locks ko release nahi karti
            ex : 
            Agar humare pass koi critical section ka area hain jisme ye current thread enter kare hogi
            and humne uske andar usko sleep kar diya hain toh utne seconds ke liye woh lock ko acquire
            karege means baaki jitne bhi threads hain jo lock ka wait kar rahe hain , lock ka release 
            hone ka woh bhi wait karenge for given time.
            */
        }
        catch(InterruptedException e) {}

        // Means Agar hum bina try ke likhe toh ye hume ek InterruptedException dega , so to handle 
        // we use try and catch to handle InterruptedException
        System.out.println("Main thread ends");
    }
}


/*
Output will be : 
Main Thread starts 
// wait for 2 seconds
Main Thread ends
*/



// Thread important methods
/*
 Thread.sleep(milliseconds) -> TIMED_WAITING
 RUNNABLE --> TIMED_WAITING --> RUNNABLE
 after applying thread.sleep then 
 Thread Runnable state se Time waiting state par jayege and timed_waiting ke baad ya time khatam 
 hone ka baad woh again Runnable state main jayege and after getting CPU Time woh phir running state
 main jayege.
*/

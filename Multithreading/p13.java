public class Demo8 {
    public static void main(String[] args) {
        Thread t1 = new Thread(() -> {
            while(true) {
                System.out.println("Running...");
            }
        });

        t1.setDaemon(true); // t1 thread deamon ban gayi
        t1.start(); // thread t1 start hui

        try { 
    // * AB Main thread immediately terminate hona ki jagah , 2 seconds tak wait karege 
    // * So 2 seconds tak thread t1 run hogi and after 2 seconds Main thread terminate ho jayge and
    // Uske sath hi Thead t1 bhi terminate ho jayege chahe uska task complete ho ya na ho 
    // because ye ek Deamon Thread hain.
            
            Thread.sleep(2000); 
        }
        catch(Exception e) {}

        return;
    }
    /* 2 seconds tak jinte bar bhi running print ho sakta hain woh hoga.
     OP OF THIS CODE : 
     Running.. 
     Running..
     Running.. for 2 seconds
    */
}

/* 1)
        main() {
            Thread t1 = new Thread(() -> {
                while(true) {
                    System.out.println("Running...");
                }
            });
            t1.start();
            return; // Now main thread terminates
        }

        toh jaise hi t1.start() kiya toh hamari thread t1 start ho gayi and in next line of thread 
        t1 , hamari main thread terminate ho gayi now ab hamare thread t1 run ho rahi hain jo ki 
        infinitely run ho rahi hain , 
        * toh user thread ka fayda yeh hota hain ki agar main thread bhi khatam ho jaye toh woh
        user defined thread chalte rahege jab tak uska task compelete nahi ho jayega.
        ab chahe hum main thread ke andar return likhe ya break likhe , toh tab bhi hamre user defined 
        thread chalti rahege. ya user defined ka flow of execution chalta rahega tab tak ki jab tak 
        woh apna task compelete nahi kar leti hain.

        op of this code : 
        Running...
        Running...
        Running...
        Running... (Infinetly till memory exceeds)
*/
            
    /* 2)
      Agar hum apne kisi user defined ko deamon thread bana de , toh jaise hi main thread terminate
      hogi waise hi woh thread bhi terminate ho jayege chahe uska task compelete hua ho ya nahi. 
      because ye ek background running thread hain.

        public static void main(String[] args) {
        Thread t1 = new Thread(() -> {
            while(true) {
                System.out.println("Running...");
            }
        });

        t1.setDaemon(true); // now user defined thread t1 become deamon
        t1.start(); 
        // yaha thread t1 start hui and in after few lines main thread terminate ho gayi
        // ya Immediately humari main thread terminate ho gayi , toh turant  hamare thread t1 
        bhi terminate ho jayege chahe uska task compelet ho ya na ho.
        return;
    }

      // SO OP OF this code : hamara Running ek bhi bar print nahi hoga.
      empty terminal
    */


/*

   Daemon Threads --> Background running threads
   --> Stop immediately once main thread is completed

   Threads --> User threads, Daemon threads

   Threads Types : 
   i) User Threads -> User defiend Threads like t1, t2,
   ii) Daemon Threads -> Background Running Thread like main.
   Daemon threads : 
   * These threads are background running threads
   * This type of threads are stop executing after main thread terminated.
   * real life ex : Garbage collection run on deamon thread. means Garbage collection ko tab tak hi
   toh run hona hain jab tak Main fucntion program run ho raha hain , Jese Hi Main function terminate 
   hua toh wese hi Garbage Collection stop ho jayega.
   so Garbage collection task ko ek Deamon thread Banate hain.
    Garbage collection --> Daemon thread
*/

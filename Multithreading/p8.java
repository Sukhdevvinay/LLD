public class Demo3 {
    public static void main(String[] args) {
        Thread t1 = new Thread(() -> {
            for(int i=1; i<=10; i++) {
                System.out.println("T1 : " + i);
                Thread.yield();
            }
        });

        Thread t2 = new Thread(() -> {
            for(int i=1; i<=10; i++) {
                System.out.println("T2 : " + i);
            }
        });

        t1.start();
        t2.start();

    }
    /*
    Thread.yield(); -> This is Static Method
    Koi bhi thread jo current thread par jisme par hum Thread.yield laga rahe hain woh ye khaege 
    ki agar main already run ho rahi hun aur uske alwa jitne bhi thread present hain , jinki priority
    mere barabar hain aur unko agar cpu time nahi mil raha hain toh main khudka cpu time unko de dungi
    and toh myslef running state se runnable main chale jaungi and weh runnable se running state main 
    chale jayege
    */
}

/*
 
Thread.yield() --> I am willing to give my cpu time to someone else with same priority and 
that wants to run

why we not use this in production -> 
1. OS can reject this.
2. It is like a suggestion to the OS
3. Current thread does not go to WAITING, TIMED_WAITING, BLOCKED.
   It does go to only RUNNABLE state

*/

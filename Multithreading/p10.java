public class Demo5 {
    public static void main(String[] args) {
        Thread t1 = new Thread(() -> {
            try {
                Thread.sleep(2000);
            }
            catch(Exception e) {}
        });

        System.out.println(t1.isAlive()); // [false] due to beacuse upto this time this not live here 
        // here it is dead beacause it is time before creating or start so that it is dead.

        t1.start();

        System.out.println(t1.isAlive()); // [true] due to because it is created 

        try {
            Thread.sleep(3000);
        }
            /* So Humne Main thread ko 3seconds wait karaya and t1 thread ko 2 seconds tak , so 
            thread t1 2 seconds tak live rahega or jinda rahege.
            */
        catch(Exception e) {}

        System.out.println(t1.isAlive());  // [false] now thread t1 will be terminated so it is not 
        // live

    }
}

/*

    isAlive() --> start - terminate
    start hone se lekar terminate tak woh live rahte hain , uske phele aur baad main woh live nahi
    rehte hain or dead.
    ya start hone se phele aur termination ke baad woh dead ho jati hain.

*/

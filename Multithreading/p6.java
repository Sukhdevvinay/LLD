public class Demo6 {
    public static void main(String[] args) {
        // Thread new stage

        Thread mainThread = Thread.currentThread(); // Ye Humne Main Thread ka reference es varible 
        // Main Pass kara diya hain.

        Thread t1 = new Thread(() -> { // Thread Creation Stage (NEW STAGE)
            System.out.println("Name of current thread is " + Thread.currentThread().getName());
            System.out.println("Main thread state " + mainThread.getState());
        });
        System.out.println(t1.getState()); // This Returns the current stage of thread

        // Runnable stage
        t1.start(); // now NEW STAGE convert to RUNNABLE STAGE

        System.out.println(t1.getState()); // RUNNABLE

        try {
            Thread.sleep(2000);
        }
        catch(Exception e) {}

        System.out.println(t1.getState()); // TERMINATED
        
        /*
            i) AB Humne starting main main thread ke refernce ko ek naye variable main store kiya and
            then varibale is mainThread
            ya Humne
            mainThread variable ke andar humne ,main thread ka reference store kar diya
            ii) thread t1 create kara in code 
            iii) humne current state check kare thread t1 ki which is (NEW STATE)
            so it prints (NEW STATE)
            iv) humne current thread t1 ko start kiya
            v) and then check current thread state and Main Thread ko sleep kiya for 2seconds
            vi) So Jab tak thread t1 ko OS ne Start kiya  , tab humare next line current state of t1 
            print hogi which is RUNNABLE , and Main thread ko sleep kar diya for 2 seconds
            vii) Now ab thread t1 ka lamda function run hoga which is this : 
            
                System.out.println("Name of current thread is " + Thread.currentThread().getName());
                System.out.println("Main thread state " + mainThread.getState());

            so ab thread t1 jab run ho raha hain ,ye two lines print hogi 
            name of current thread and main thread ki state which is sleep

            So Op of code : 
            NEW STATE 
            RUNNABLE 
            Name of current thread is Thread-0
            Main thread state TIMED_WAITING
            // wait hoga for 2 seconds
            TERMINATED
            
            // Agar hum kisi thread ko sleep karte hain , toh uske next line wala code tab tak nahi
            chalega jab tak sleep time nahi khatam hoga
        */

    }

    /*
        Thread t1 = new Thread(() -> { // Thread Creation Stage (NEW STAGE)
            System.out.println("Name of current thread is " + Thread.currentThread().getName());
        });
        System.out.println(t1.getState()); // This Returns the current stage of thread

        // Runnable stage
        t1.start(); // now NEW STAGE convert to RUNNABLE STAGE

        System.out.println(t1.getState()); // RUNNABLE

        Possible ouptut of this code : 
        There are 2 possible output of this code : 
        
        I) Sabse phele humesa NEW STATE Print hoga becuase ist pe likha hain , and Jab humne t1.start()
        likha and then agian to print current state 
        Jaise hi humne t1.start() kiya so t1.start() run hone ke liye ready hain , but esa ho sakta hain
        ki Thread abhi ekdun se run ya create nahi hoyi ho jo ki jayada high chance hain kyuki humne next 
        line main to find current state ka code likha diya ho. toh woh ab thread creation se phele
        eske state print karega
        
       * So output will : 
        NEW
        RUNNABLE
        Name of current thread is Thread-0

        II)  Sabse phele humesa NEW STATE Print hoga becuase ist pe likha hain , and Jab humne t1.start()
        likha and then agian to print current state 
        Jaise hi humne t1.start() kiya so t1.start() run hone ke liye ready hain toh ab ese ho sakta hian 
        but less chance , so OS New jaldi se Thread t1 banaye and woh run hona start ho gayi , so jaise
        hi woh run hona start hogi toh hamare screen par run hoga woh lamda function and phir woh code 
        jayega nex State print karne so ab jab thread ka kaam khatam ho gaya , so now state will be Terminated

        * So output will : 
        NEW 
        Name of current thread is Thread-0
        TERMINATED

        But Ese hone main chances rare hain , Because t1.start() hone main time lagta hain Kyuki
        OS ko time lagta hain es thread ko create karne main and ready rakhta hain toh en process
        main time lagta hain toh tab tak next state wali line print ho jati hain

        so best tarika hain esa print karna ka , ki hum main thread ko sleep karye for some time
         try {
            Thread.sleep(2000); // Main thread ko sleep karaya for 2000 mili seconds
             // Ye Thread ke andar stores current thread 
            // so ab current Thread Main hain 
        }
        catch(Exception e) {}
        System.out.println(t1.getState());

        // So op of whole code will : 
        NEW
        RUNNABLE 
        Name of current thread is Thread-0
        // wait for 2seconds (not shown in terminal)
        TERMINATED
        
    */


    
}

// Thread lifecycle

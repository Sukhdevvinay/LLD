public class Demo4 {
    public static void main(String[] args) {
        Thread t1 = new Thread(() -> {
            System.out.println("Current thread is " + Thread.currentThread().getName());
        }); // Ye Humne apne code main toh thread create kar diya hain par operating system main create kare
        // ke liye , os thread tab tak nahi banayega jab tak hum es thread par start call nahi kar dete

        // Ye Jo humne lamda function pass kiya hain new Thread(x); ke andar that is x , woh x ek runnable ka 
        // interface hi toh hain

        t1.start(); // for this line OS create thread t1 , toh OS ne es thread ke liye OS main PC assign
        // karya or Program Counter diya and ek Stack Space diya and call the run method and logic print hogaya
        
        //t1.run();
    }
}

// 1) If i use t1.run() instead t1.start()
/*
Case I) If I use t1.start() following things happens :
    * First Os Create the New Thread t1 in OS and give Program counter and stack space to thread in OS
    * and Then t1.start() ne apne andar se hi t1.run() method ko call kiya and our logic is printed 
-> OP of code : Current thread is Thread-0

Case II) If I use t1.run() following things happens : 
    * In this method thread t1 code main present hain , but jab humne t1.start() nahi likha toh OS 
    ne Thread t1 create hi nahi kiya , toh Ab OS ke andar ek hi thread hain jo ki by deafult present
    hain which is MAIN Thread 
    * Toh ab jo us thread main lamda fucntion hoga or runnable interface ka jo code hoga , woh print 
    hoga or woh sirf logic print karege 
    * Ab jo bhi humne logic likha hoga woh run hoga Main Thread ke liye
    runnable interface code : System.out.println("Current thread is " + Thread.currentThread().getName());
-> OP of code : Current thread is main
*/


// 2) Can we start() the same thread twice ? --> NO
/*
We got Exception error : Illegal Thread Exception error 

agar humne ek thread ko start kiya or woh run hogaya and woh khatam ho gayi toh us thread ke life
cycle khatam ho gayi , so hum us thread ko dobara use nahi kar sakte hain.

*/

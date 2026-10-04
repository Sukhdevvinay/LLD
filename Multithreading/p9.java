public class Demo4 {
    public static void main(String[] args) throws InterruptedException {
        Thread t1 = new Thread(() -> {
            while(!Thread.currentThread().interrupted()) {
                System.out.println("Running");
            }
        });

        t1.start();

        Thread.sleep(2000);

        t1.interrupt();
    }

    /*
    Output of this code : 
    Ab interupt ki value 2seconds bad main jakar true hogi toh tab jitne bar bhi 2seconds main 
    Running print hoga tab tak karo 
    and after 2 seconds interupt ki value true hogi toh humare while stops ho jayege. 
    and our code will stop printing that Running.
    */
}

/*
This is Not static Method because we apply for thread t1 not objects.

i) t1.interrupt() --> Ese hum keh rahe hain ki thread t1 ko keh rahe hain ki ye thread jo bhi kar 
rahe hain , mat kar ruk ja means hum use signal bhej rahe hain aur keh rahe hain ki tu jo bhi kar
rahe hian , mat kar ruk ja.

signal bhejna ye matlab nahi ki hum thread t1 ko order kar rahe hain ki ruk ja , only we send the 
signal to that thread

ii) Signal bhejna means 
Humare sare Threads ke andar ek interupt nam ka flag hota hain jiske by deafult value false hoti 
hain 
toh jab hum signal bhejte hain toh hum us thread ki interupt variable ki value ko true kar rahe hain
means true hona ke baad thread kaam karna ruk nahi jayege balki this is only singal

iii) Use of This : 
We can Handle this gracefully means by using the value of interupt we can handle some working of 
threads.

*/

/*
        Thread t1 = new Thread(() -> {
            while(1) {
                System.out.println("Running");
            }
        });

        t1.start();

        t1.interrupt();


        Op of this code : 
        Infinitely Running line in code

        if we use t1.interupt() so our code of only set interupt value to true. so but aagr hum 
        interupt ki value se code ko handle kare then we can control this.
*/
     



/*

    Thread --> interrupt flag (default true) 

    t1.interrupt() --> Sends a signal to t1 thread that it shoult stop doing what its doing.

    We can gracefully handle
    --> You can make a thread run until a condition
    --> Cancelling a long running task
    --> usesd to stop Thread pool 

    isInterrupted() --> return interrupt flag value (T/F)
    interrupted() --> return interrupt flag value (T/F) but also set it back to false

    -> sleep(), join(), wait() : TIMED_WAITING, WAITING --> interrupt()

    Koi bhi thread jo abhi sleep , wait or join state main hain hum espe interupt call nahi 
    kar sakte . agar humne kiya toh hume milaga interupted exception.
    means us thread par ye methods call kar rahe hain. methods like sleep , wait , join.
    so in methods par agar humne call kiya interupt method so we get Interuoted exception error
    ye esliya hota hain compiler nahi janta ki humne apne current thread ko interupt toh nahi 
    kiya and jab humne ye method call kiya toh interupt kiya current thread kiya so it gives error

    A) Non-STATIC METHOD : 
      Ye Hum kise thread par lagate hain , means this method kisi thread par lagate hian like
      thread t1 , t2, t3,t4 , etcs;
      ex : t1.start()
      Means hum ye methods t1,t2,t3 .. tn par laga sakte hain 
    B) Static Method : 
    Ye Hum Thread object par lagate hian 
    ex : 
    Thread.yield

*/

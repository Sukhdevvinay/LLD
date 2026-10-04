public class Demo7 {
    public static void main(String[] args) {
        Thread t1 = new Thread(() -> {
            System.out.println("Custom thread running");
        });

        Thread t2 = new Thread(() -> {
            System.out.println("Custom-2 thread running");
        });

        t1.start();
        t2.start();
        t1.setPriority(10);

        System.out.println(t1.getPriority());
    }
}

/*
    Thread Priority
    MAX_PRIORITY = 10
    MIN_PRIORITY = 1
    NORM_PRIORITY = 5 // by default priority for all threads

    Depends on OS 
    -> may respect Priority
    -> may partially repsect
    -> may not at all

    Priority ka means Hum OS ko bta rahe hain ki yeh thread thoda jayada important hain toh esko 
    thoda jayada run or execute karna means esko thodi jayada CPU cycle dena ya 
    jiske priority jayada hogi hame usko run karna hoga.

    But ese koi gurannte nahi hain jiske priority jayda hain woh phele run hoga , balki yeh 
    uspe depend karta hain ki Humare OS pe load kitna hain ya baki thread ko kaise CPU cycle 
    deta hain 
    We can say that it depends on the OS for priority threads to run or not.

*/

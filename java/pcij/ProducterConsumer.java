/*

本程序致力于解决多出现多个生产者，多个消费者的时候，依然能够达到生产一次，消费一次的功能
：
解决的方法就是：1)在被唤醒之后仍然进行条件判断，去检查要改的数字是否满足条件，如果不满足条件就继续睡眠。把两个方法中的if改为while即可。
当然，此时仍会出现问题，就是所以线程都等待，失去资格
                2)需要将notify()改成notifyAll()

升级版：
使用Lock来替换synchronized，wait,notify,nonifyAll语法和语句的使用
不需要同步，不需要notify
------------
加强升级版：
此版本为最终版，主要在使用锁lock的基础上，加上唤醒对方（不包括己方)进程的优化
通过一个锁建立多个condition对象来解决

流程：
生产者拿到锁，执行，判断没有真，继续执行，生产完毕后唤醒消费者来消费    生产者唤醒消费者
消费者拿到锁，执行，判断没有假，继续执行，消费完毕后唤醒生产者继续生产   消费者唤醒生产者

*/
import java.util.concurrent.locks.*;
public class  ProducterConsumer
{
    public static void main(String[] args)
    {
        Resources  r =new Resources();
        Productor  pro =new Productor(r);
        Consumer   con = new Consumer(r);

        Thread t1 =new Thread(pro);
        Thread t2 =new Thread(pro);//多个生产者
        Thread t3 =new Thread(con);
        Thread t4 =new Thread(con);//多个消费者
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        System.out.println("Hello World!");
    }
}

class Resources
{
    private String name;
    private int count = 1;
    private boolean flag =false;
    private Lock lock = new ReentrantLock();

    private Condition condition_pro = lock.newCondition(); //使用lock建立生产者的condition对象
    private Condition condition_con = lock.newCondition(); //使用lock建立消费者的condition对象

    public  void set(String name) throws InterruptedException
    {
        lock.lock();
        try
        {
            //1)循环判断
           while(flag)
               //如果为真，放弃生产者的资格
               condition_pro.await(); //会抛出异常
           this.name = name+"--"+count++;

           System.out.println(Thread.currentThread().getName()+"生产者"+this.name);
           flag =true;
           //2)使用消费condition唤醒进程
           condition_con.signal(); //生产者生产完毕后，唤醒消费者的进程（不再是signalAll)
        }
        finally
        {
            lock.unlock();
        }


    }
    public  void out() throws InterruptedException
    {
        lock.lock();
        try
        {
           //1)循环判断
           while(!flag)
               //如果为假，放弃消费者的资格
               condition_con.await();

           System.out.println(Thread.currentThread().getName()+" ....消费者...."+this.name);
           flag =false;
           //2)使用生产者condition唤醒进程
           condition_pro.signal(); //消费者消费完毕后，唤醒生产者的进程
        }
        finally    //防止当前线程拿到锁后抛异常一直不释放锁
        {
            lock.unlock();
        }


    }
}

class Productor implements Runnable
{
    private Resources res;
    Productor(Resources res){
        this.res =res;
    }
    public void run(){
        while(true){
            try
            {
                res.set("++商品++"); //需要抛出异常
            }
            catch (InterruptedException e)
            {
            }

        }
    }

}

class Consumer  implements Runnable
{
    private Resources res;
    Consumer(Resources res){
        this.res =res;
    }
    public void run(){
        while(true){
             try
            {
                res.out(); //需要抛出异常
            }
            catch (InterruptedException e)
            {
            }

        }
    }

}

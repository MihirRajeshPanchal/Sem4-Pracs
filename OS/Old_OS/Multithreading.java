class Bus extends Thread{
    int tickets;
    Bus(int tickets){
        this.tickets = tickets; 
    }
    public void run(){
        if(tickets > 0){
            try{
                Thread.sleep(1500);
                tickets--;
                System.out.println("Ticket booked by "+Thread.currentThread().getName());
            }
            catch (Exception e){
            }
        }
        else{
            System.out.println("Sorry House Full "+Thread.currentThread().getName());
        }
    }
}

public class Multithreading {
    public static void main(String args[]){
        System.out.println("Asynchronization");
        Bus b1 = new Bus(1);
        b1.run();
        b1.run();

        System.out.println("Synchronization");
        Bus b = new Bus(1);
        Thread t1 = new Thread(b);
        Thread t2 = new Thread(b);
        t1.setName("Mihir");
        t2.setName("Fiza");
        t1.start();
        t2.start();


    }
}
import java.util.concurrent.Semaphore;

public class TrafficController {
    Semaphore semaforo = new Semaphore(1);  // Semáforo com o número de permissões igual a 1 

    public void enterLeft() {
        try {
            semaforo.acquire(); // Adquire uma permissão, ou seja, o carro da esquerda pode passar (ponte ocupada)
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void enterRight() {
        try {
            semaforo.acquire(); // Adquire uma permissão, ou seja, o carro da direita pode passar (ponte ocupada)
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    public void leaveLeft() {
        semaforo.release(); // Libera uma permissão, ou seja, indica que a ponte está desocupada
    }

    public void leaveRight() {
        semaforo.release(); // Libera uma permissão, ou seja, indica que a ponte está desocupada
    }

}

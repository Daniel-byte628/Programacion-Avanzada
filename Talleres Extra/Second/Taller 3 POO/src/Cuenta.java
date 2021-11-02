public class Cuenta {
    int IdCliente;
    String nombre;
    static double interes = 0.05;
    int ahorro;



    double interesMensual(int numero){
        System.out.println("-----------INTERES MENSSUAL----------");
        return (numero*interes)/12;
    }

    void Modificar(double tasa){
        interes = tasa;
    }
}
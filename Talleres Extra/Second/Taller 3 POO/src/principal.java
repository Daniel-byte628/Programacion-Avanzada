public class principal {
    public static void main(String[] args) {
        Cuenta persona1 = new Cuenta();
        persona1.IdCliente = 1;
        persona1.nombre = "pedro";

        Cuenta persona2 = new Cuenta();
        persona2.IdCliente = 2;
        persona2.nombre = "sara";
        
        System.out.println("Cliente 1");
        System.out.println("        " + persona1.interesMensual(3000000));
        persona1.Modificar(0.04);
        System.out.println("        " + persona1.interesMensual(3000000));

        System.out.println("Cliente 2");

        persona2.Modificar(0.05);
        System.out.println("        " + persona2.interesMensual(8000000));
        persona2.Modificar(0.04);
        System.out.println("        " + persona2.interesMensual(8000000));
    }
}

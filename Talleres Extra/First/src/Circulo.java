public class Circulo {
    // Atributos
    int radio;
    int diametro;
    double circunferencia;
    double area;

    // Metodos
    Circulo() {
        System.out.println("Creacion del circulo exitosamente");
    }

    Circulo(int radio) {
        this.radio = radio;
        this.diametro = getdiametro(this.radio);
        this.circunferencia = getcircunferencia(this.radio);
        this.area = area(this.radio);
    }

    int getdiametro(int radio) {
        return 2 * radio;
    }

    double getcircunferencia(int radio) {
        return Math.PI * radio * 2;
    }

    void mostrardatosenteros() {
        System.out.println("El radio es: " + (int) radio);
        System.out.println("El diametro es: " + (int) diametro);
        System.out.println("La circunferencia es: " + (int) circunferencia);
        System.out.println("El area es:  " + (int) area);
    }

    void mostrardatosdecimales() {
        System.out.println("El radio es: " + radio);
        System.out.println("El diametro es: " + diametro);
        System.out.println("La circunferencia es: " + circunferencia);
        System.out.println("El area es:  " + area);
    }

    double area(int radio) {
        return radio * radio * Math.PI;
    }

    double diferencia(Circulo referencia) {
        return this.circunferencia - referencia.circunferencia;
    }

    double diferenciaar(Circulo referencia) {
        return this.area - referencia.area;
    }

    double[] cartesiana(double angulo) {
        double[] coord = new double[] { 0, 0 };
        // Coordenada X
        coord[0] = this.radio * Math.cos(angulo);
        // Coordenada Y
        coord[1] = this.radio * Math.sin(angulo);
        System.out.println("----------------------------");
        System.out.println("---------Coordenadas--------");
        System.out.println("(" + coord[0] + ", " + coord[1] + ")");
        System.out.println("----------------------------");
        return coord;
    }
}

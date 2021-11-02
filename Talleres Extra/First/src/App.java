import java.util.Scanner;
import javax.print.Doc;

import java.awt.*;
import javax.swing.*;
import java.awt.geom.Line2D;

public class App extends JComponent {
    // Nos ayuda a modificar el tamano de la ventana relativa
    static int WIDTH_WINDOWS = 500;
    static Circulo circulo1 = new Circulo(100);

    public static void main(String[] args) {

        // a,b,c,d
        System.out.println("-----------ENTEROS----------");
        circulo1.mostrardatosenteros();
        System.out.println("----------------------------");
        System.out.println("----------DECIMALES---------");
        circulo1.mostrardatosdecimales();
        Circulo circulo2 = new Circulo(4);
        System.out.println("----------DECIMALES---------");
        circulo2.mostrardatosdecimales();
        System.out.println("----------------------------");
        System.out.println("----------------------------");
        // e
        double diferenciaCircunferencia = circulo1.diferencia(circulo2);
        System.out.println("Diferencia de la circunferencia: " + diferenciaCircunferencia);
        double diferenciaarea = circulo1.diferenciaar(circulo2);
        System.out.println("Diferencia del area: " + diferenciaarea);
        // f
        double[] coord = circulo1.cartesiana(2 * Math.PI);
        System.out.println("x = " + coord[0]);
        System.out.println("y = " + coord[1]);

        // PUNTO "3"

        // Se crea un panel
        JFrame window = new JFrame();
        // Se agrega un tipo de marco de ventana
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Acceder a una serie de propiedades
        window.pack();
        // posicion relativa
        window.setLocationRelativeTo(null);
        window.setBounds(0, 0, WIDTH_WINDOWS, WIDTH_WINDOWS);

        // add paint
        window.getContentPane().add(new App());
        window.setVisible(true);

    }

    public void paint(Graphics g) {

        // g.setColor(Color.blue);
        // g.drawLine(0, 0, 200, 200);
        // g.drawLine(0, 0, 400, 200);

        // g.setColor(Color.red);
        // g.drawLine(0 + WIDTH_WINDOWS / 2, 0 + WIDTH_WINDOWS / 2, 200 + WIDTH_WINDOWS
        // / 2, 200 + WIDTH_WINDOWS / 2);
        // g.drawLine(0 + WIDTH_WINDOWS / 2, 0 + WIDTH_WINDOWS / 2, 400 + WIDTH_WINDOWS
        // / 2, 200 + WIDTH_WINDOWS / 2);

        // move to center
        // Saber cual es nuestro centro de referencia dependiendo nuestra zona de
        // trabajo
        int ceroPosition = WIDTH_WINDOWS / 2;
        // El color, en este caso negro
        g.setColor(Color.black);
        // declaramos un entero para saber en donde de tener el for
        int maxAngle = 360;

        // Draw lines con un for "circunferencia por medio de líneas"
        for (int i = 0; i < maxAngle; i++) {
            // capturar las coordenadas
            double[] coord = circulo1.cartesiana(i);
            // Dibujar el circulo, entre el centro y la coordenada que me da el anterior
            // paso
            // Sucesivamente.
            // The drawLine method takes four arguments:

            // x1 – It takes the first point’s x coordinate.
            // y1 – It takes first point’s y coordinate.
            // x2 – It takes second point’s x coordinate.
            // y2 – It takes second point’s y coordinate
            g.drawLine(0 + ceroPosition, 0 + ceroPosition, (int) coord[0] + ceroPosition,
                    (int) coord[1] + ceroPosition);
        }

        // Draw rare "DIBUJAR MUCHOS OVALOS SUCESIVAMENTE"

        for (int i = 0; i < maxAngle; i++) {
            double[] coord = circulo1.cartesiana(i);

            System.out.println("incial x" + ((int) coord[0] + ceroPosition));

            System.out.println("incial y" + ((int) coord[1] + ceroPosition));

            System.out.println("incial Widht" + ((int) coord[0] + ceroPosition));

            System.out.println("incial Height" + ((int) coord[1] + ceroPosition));
            // Sintaxis int x, int y, int width, int height
            g.drawOval((int) coord[0] + ceroPosition, (int) coord[1] + ceroPosition, (int) coord[0] + ceroPosition,
                    (int) coord[1] + ceroPosition);
        }

        // Dibujar la circunferencia por medio de puntos
        // Color
        g.setColor(Color.red);
        // repeticiones que se va hacer
        for (int i = 0; i < maxAngle; i++) {
            // capturar las coordenadas
            double[] coord = circulo1.cartesiana(i);
            // Dibujar el circulo, teniendo en cuenta que el punto que termina es el mismo
            // que el que inicia
            // Sucesivamente.
            // The drawLine method takes four arguments:

            // x1 – It takes the first point’s x coordinate.
            // y1 – It takes first point’s y coordinate.
            // x2 – It takes second point’s x coordinate.
            // y2 – It takes second point’s y coordinate
            g.drawLine((int) coord[0] + ceroPosition, (int) coord[1] + ceroPosition, (int) coord[0] + ceroPosition,
                    (int) coord[1] + ceroPosition);
        }
        // drawOval() "Dibujo de un Ovalo"
        // Método que nos permite dibujar un óvalo en una posición (x,y) especificando
        // su ancho y alto.
        // Sintaxis int x, int y, int width, int height
        g.drawOval((int) (2 * ceroPosition - circulo1.diametro) / 2, (int) (2 * ceroPosition - circulo1.diametro) / 2,
                (int) circulo1.diametro, (int) circulo1.diametro);
    }
}

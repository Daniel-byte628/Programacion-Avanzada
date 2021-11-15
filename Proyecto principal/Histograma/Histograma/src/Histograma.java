import java.util.Scanner;
import java.util.ArrayList;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import javax.swing.*;

import java.awt.Color;
import java.awt.event.*;
import java.awt.Dimension;

public class Histograma extends JFrame implements ActionListener {
    private JButton boton1, boton2;
    private JLabel label1, label2, label3;
    static String decision;
    static Boolean opciones = true;
    static char way;
    static ArrayList<String> descarga = new ArrayList<String>();

    Histograma() {
        setBounds(0, 0, 400, 600);
        setVisible(true);
        setResizable(true);
        setLocationRelativeTo(null); 
        setLayout(null);
    }

    public static void main(String[] args) throws Exception {
        // Creamos un objeto
        Histograma user = new Histograma();
        Columna objeto1 = new Columna(0);
        Columna objeto2 = new Columna(1);
        Columna objeto3 = new Columna(2);
        Columna objeto4 = new Columna(3);
        Columna objeto5 = new Columna(4);
        Columna objeto6 = new Columna(5);
        Columna objeto7 = new Columna(6);
        int arrayLength = objeto1.unacolumna.size();
        for (int i = 0; i < arrayLength - 2 && opciones == true; i++) {
            user.botones(objeto2,objeto3,objeto4,i+1);
            user.textos(objeto2, objeto3, objeto4, i + 1);
            way = user.elegir();
            descarga.add(String.valueOf(way));
            opciones = user.verificar(objeto5, objeto6, objeto7, i + 1, way);
        }
        if (opciones == true) {
            user.textos(objeto2, objeto3, objeto4, arrayLength - 1);
            // pantalla ganadora
            System.out.println("Gano");
        } else {
            // pantalla perdedora
            System.out.println("Perdio");
        }
        user.descargarlineatiempo(objeto2, objeto3, objeto4, descarga);
    }
    void botones(Columna obj1, Columna obj2, Columna obj3, int num){
        
        boton1 = new JButton("A");
        boton1.setBounds(0, 361, 200, 200);
        add(boton1);
        boton1.addActionListener(this);

        boton2 = new JButton("B");
        boton2.setBounds(200, 361, 200, 200);
        add(boton2);
        boton2.addActionListener(this);

        label1 = new JLabel();
        label1.setText(obj1.unacolumna.get(num));
        label1.setForeground(Color.BLUE);
        label1.setOpaque(true);
        label1.setBackground(Color.YELLOW);
        label1.setBounds(10, 10, 450, 400);
        add(label1);

        label2 = new JLabel(obj2.unacolumna.get(num));
        label2.setBounds(100, 100, 300, 30);// x , y heght widht
        add(label1);

        label3 = new JLabel(obj3.unacolumna.get(num));
        label3.setBounds(10, 10, 300, 30);
        add(label1);
    }

    void textos(Columna obj1, Columna obj2, Columna obj3, int num) {
        System.out.println(obj1.unacolumna.get(num));
        System.out.println(obj2.unacolumna.get(num));
        System.out.println(obj3.unacolumna.get(num));
    }

    Boolean verificar(Columna obj5, Columna obj6, Columna obj7, int num, char A) {
        Boolean decision = true;
        switch (obj7.unacolumna.get(num)) {
        case "a":
            if (A == 'A') {
                decision = true;
            } else {
                decision = false;
            }
            break;
        case "b":
            if (A == 'B') {
                decision = true;
            } else {
                decision = false;
            }
            break;
        default:
            break;
        }
        return decision;
    }

    char elegir() {
        Scanner sc = new Scanner(System.in);
        char caracter;
        System.out.println("Elige tu decision A o B");
        caracter = sc.next().charAt(0);
        return caracter;
    }

    void descargarlineatiempo(Columna obj1, Columna obj2, Columna obj3, ArrayList<String> opciones) throws IOException {
        String ruta = "C:/Users/danig/OneDrive/Documentos/2 semestre/Programacion avanzada/Pruebas programacion/prueba1/lineatiempo.csvA";
        File file = new File(ruta);
        int arrayLength = opciones.size();
        // Si el archivo no existe es creado
        if (!file.exists()) {
            file.createNewFile();
        }
        FileWriter fw = new FileWriter(file);
        BufferedWriter bw = new BufferedWriter(fw);
        for (int i = 0; i < arrayLength; i++) {
            bw.write(obj1.unacolumna.get(i + 1) + ";" + obj2.unacolumna.get(i + 1) + ";" + obj3.unacolumna.get(i + 1)
                    + "\n");
        }
        bw.close();
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource()==boton1) {
            label1.setText("");
        }
        if (e.getSource()==boton2) {
            label1.setText("");
        }
    }
}

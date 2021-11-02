import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Pieza {
    // Atributos
    static int id = 0;
    int idobjeto = 0;
    private String name;
    private String description;
    int numeroarticulos;
    String updateAt;

    public static void main(String[] args) throws Exception {
        // 1punto
        Pieza pieza1 = new Pieza("tuerca", "aaaaaaaaa", 2);
        Pieza pieza2 = new Pieza("tornillo", "bbbbbbbbb", 4);
        Pieza pieza3 = new Pieza("remaches", "cccccccc", 1);
        Pieza pieza4 = new Pieza("pernos", "dddddddddd", 3);

        // 2punto
        System.out.println(pieza1.idobjeto);
        System.out.println(pieza2.idobjeto);
        System.out.println(pieza3.idobjeto);
        System.out.println(pieza4.idobjeto);

        pieza3.obtenerpieza();

        // 5punto
        pieza1.compra(5);
        System.out.println(pieza1.updateAt);

    }

    Pieza(String name, String description, int numeroarticulos) {
        id++;
        this.idobjeto = id;
        this.name = name;
        this.description = description;
        this.numeroarticulos = numeroarticulos;
    }

    // punto 3
    void obtenerpieza() {
        try {
            this.numeroarticulos = this.numeroarticulos--;
            if (this.numeroarticulos <= 1) {
                throw new Exception("Articulos insuficientes");
            }
        } catch (Exception ex) {
            System.out.println(ex);
        }

    }

    void compra(int numero) {
        DateTimeFormatter dtf2 = DateTimeFormatter.ofPattern("yy/MM/dd HH:mm:ss");
        this.numeroarticulos = this.numeroarticulos + numero;
        this.updateAt = dtf2.format(LocalDateTime.now());
    }

    // 4punto
    public void setNombre(String nom) {
        name = nom;
    }

    public String getNombre() {
        return name;
    }

    public void setdescription(String des) {
        description = des;
    }

    public String getdescription() {
        return description;
    }

}

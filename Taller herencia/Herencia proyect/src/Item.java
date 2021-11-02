public class Item {
    private String title;
    double playingtime;
    int gotIt;
    String comment;

    // metodos
    public void escribircomentario() {
        System.out.println("escribircomentario");
    }

    public void calcularplatingtime() {
        System.out.println("calcularplatingtime");
    }

    public void conseguiritem() {
        System.out.println("calcularplatingtime");
    }

    public String gettitle() {
        return title;
    }

    public void settitle(String title) {
        this.title = title;
    }

}
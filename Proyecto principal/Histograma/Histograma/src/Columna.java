import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Columna {
    ArrayList<String> unacolumna = new ArrayList<String>();

    Columna(int num) throws FileNotFoundException, IOException {
        BufferedReader br = null;
        br = new BufferedReader(new FileReader(
                "C:/Users/danig/OneDrive/Documentos/2 semestre/Programacion avanzada/Pruebas programacion/prueba1/historia.csv"));
        String line = br.readLine();
        int posicion=0;
        ArrayList<String> fields = new ArrayList<String>();
        while (line != null) {
            String files[] = line.split(";");
            fields.add(files[num]);
            line = br.readLine();
            this.unacolumna.add(fields.get(posicion));
            posicion++;
        }
        br.close();
    }
}

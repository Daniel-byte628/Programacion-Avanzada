import java.util.Scanner;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.time.Period;
import java.util.concurrent.TimeUnit;

class Student {
    // Repita lo anterior usando una clase Usuario.
    String name;
    String age;
    String dateofborn;

     void conversion() throws Exception {
        /*
         * Calcule la edad en horas del usuario, luego divida esta por el numero de
         * letras del nombre, tenga en cuenta las excepciones aritméticasy lance un
         * excepción si la divisiónes menor a 100 o si esta es negativa.
         */
        String dateofbirth = dateofborn;
        // day
        String day = dateofbirth.substring(0, 2);
        int numday = Integer.parseInt(day);
        // month
        String month = dateofbirth.substring(2, 4);
        int nummonth = Integer.parseInt(month);

        // Year
        String year = dateofbirth.substring(4, 8);
        int numyear = Integer.parseInt(year);

        LocalDate today = LocalDate.now();
        LocalDate birthdate = LocalDate.of(numyear, nummonth, numday);

        Period p = Period.between(birthdate, today);

        double diasAno = p.getYears() * 365; // Días obtenidos a partir de los años.
        double diasMes = p.getMonths() * 30.4167;// Días obtenidos a partir de los meses, se usa el promedio.
        double dias = p.getDays(); // días.

        double diasTotales = diasAno + diasMes + dias;

        long horas = TimeUnit.DAYS.toHours((int) diasTotales);

        System.out.println("horas: " + horas);

        String subname = name;
        long value = horas / subname.length();
        System.out.println("Valor division: " + mirarsiestabien(value));

    }

    static long mirarsiestabien(long value) throws Exception {
        if (value < 100) {
            throw new Exception("Incorrecto es menor a 100 y es negativo");
        }
        return value;
    }

     void agetrue() {
        // Lanzar una excepción si la edad no coincide con la fecha de nacimiento del
        // usuario
            try {
                String dateofbirth = dateofborn;
                String agee = age;
                int numage = Integer.parseInt(agee);
                // day
                String day = dateofbirth.substring(0, 2);
                int numday = Integer.parseInt(day);
                // month
                String month = dateofbirth.substring(2, 4);
                int nummonth = Integer.parseInt(month);

                // Year
                String year = dateofbirth.substring(4, 8);
                int numyear = Integer.parseInt(year);
                LocalDate fHoy = LocalDate.now();
                LocalDate cumple = LocalDate.of(numyear, nummonth, numday);
                long edad = ChronoUnit.YEARS.between(cumple, fHoy);
                if (edad == numage) {
                    System.out.println("Coincide la edad con tu fecha de nacimiento"); 
                }else{
                    throw new ExcepcionIntervalo("no coincide la edad con tu fecha de nacimiento");
                }
            } catch (ExcepcionIntervalo e) {
                System.out.println(e.getMessage());
            }
    }

    public class ExcepcionIntervalo extends Exception {
        public ExcepcionIntervalo(String msg) {
            super(msg);
        }
    }
 String borndate() {
        // Lanzar una excepción si el formato de los datos no es correcto, y
        // el enunciado no nos pide verificar si la fecha es cierta o no
        String born = "";
        while (true) {
            try {
                System.out.print("Introduzca su fecha de nacimiento (ddmmaaaa), sin espacios: \n");
                Scanner sc = new Scanner(System.in);
                String date = sc.nextLine();
                born = date;
                if (date.length() != 8) {
                    System.out.println("Lenght format exception");
                    continue;
                }
                Integer.parseInt(date);
                break;
            } catch (NumberFormatException e) {
                System.out.println("Number format exception");
                continue;
            }
        }
        dateofborn=born;
        return born;
    }

 String namecheck() {
        // Lanzar una excepción si el formato de los datos no es correcto
        String cadena = "";
        while (true) {
            System.out.print("Introduzca su nombre: \n");
            try {
                cadena = pedirCadenaLetras();
                if (!cadena.isEmpty() && cadena.length() < 200) {
                    System.out.println("Valor valido!!! \n");
                    break;
                }
            } catch (NoEsLetraExcepcion ex) {
                System.out.println(ex.getMessage() + "\n");
            }
        }
        name=cadena;
        return cadena;
    }

    static boolean esSoloLetras(String cadena) {
        // Recorremos cada caracter de la cadena y comprobamos si son letras.
        // Para comprobarlo, lo pasamos a mayuscula y consultamos su numero ASCII.
        // Si está fuera del rango 65 - 90, es que NO son letras.
        // Para ser más exactos al tratarse del idioma español, tambien comprobamos
        // el valor 165 equivalente a la Ñ

        for (int i = 0; i < cadena.length(); i++) {
            char caracter = cadena.toUpperCase().charAt(i);
            int valorASCII = (int) caracter;
            if (valorASCII != 165 && (valorASCII < 65 || valorASCII > 90))
                return false; // Se ha encontrado un caracter que no es letra
        }

        // Terminado el bucle sin que se hay retornado false, es que todos los
        // caracteres son letras
        return true;
    }

    /**
     * Sencilla clase que hereda de Exception para crear una excepcion que avise en
     * el caso de que la cadena contenga caracteres que no son letras
     */
    static class NoEsLetraExcepcion extends Exception {

        public NoEsLetraExcepcion(String mensajeExcepcion) {
            super(mensajeExcepcion);
        }

    }

    static String pedirCadenaLetras() throws NoEsLetraExcepcion {
        Scanner sc = new Scanner(System.in);
        String cadena = sc.nextLine();
        if (esSoloLetras(cadena) && !cadena.isEmpty())
            return cadena;
        else
            throw new NoEsLetraExcepcion(
                    "La cadena contiene caracteres que NO son letras o esta vacio o tiene mas de 200 caracteres");
    }

    String agecheck() {
        // Lanzar una excepción si el formato de los datos no es correcto
        while (true) {
            try {
                System.out.print("Introduzca su edad: \n");
                Scanner sc = new Scanner(System.in);
                String agee = sc.nextLine();
                age = agee;
                if (Integer.parseInt(agee) == 0) {
                    System.out.println("Valor invalido");
                    continue;
                }
                Integer.parseInt(agee);
                break;
            } catch (NumberFormatException e) {
                System.out.println("Number format exception");
                continue;
            }
        }
        return age;
    }

}

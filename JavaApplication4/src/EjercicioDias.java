/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author aybso
 */
import java.util.Scanner;
public class EjercicioDias {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int dia, mes, anio;

        System.out.println("1. DIA DE LA SEMANA DE CUALQUIER FECHA DESPUES DEL 1700\n"
                + "-----------------------------------------------------------------");
        System.out.println("Ingrese el dia:");
        dia = sc.nextInt();

        System.out.println("Ingrese el mes:");
        mes = sc.nextInt();

        System.out.println("Ingrese el año:");
        anio = sc.nextInt();

        //SE OBTINE A EN BASE AL SIGLO
        int A = 0;
        if (anio >= 1700 && anio < 1800) {
            A = 5;
        } else if (anio >= 1800 && anio < 1900) {
            A = 3;
        } else if (anio >= 1900 && anio < 2000) {
            A = 1;
        } else if (anio >= 2000 && anio < 2100) {
            A = 0;
        } else if (anio >= 2100 && anio < 2200) {
            A = -2;
        } else if (anio >= 2200 && anio < 2300) {
            A = -4;
        }

        //SE OBTIENEN LOS DOS ULTIMOS DIGITOS DEL AÑO
        int auxB = ((anio % 200));
        int B = (auxB / 4) + auxB;

        //VER EL AÑO BISIESTO
        int C;
        if (esBiciesto(anio) && (mes == 1 || mes == 2)) {
            C = -1;
        } else {
            C = 0;
        }

        //CUARTA CONSTANTE
        int D = 0;
        if (mes == 1) {
            D = 6;
        } else if (mes == 2) {
            D = 2;
        } else if (mes == 3) {
            D = 2;
        } else if (mes == 4) {
            D = 5;
        } else if (mes == 5) {
            D = 0;
        } else if (mes == 6) {
            D = 3;
        } else if (mes == 7) {
            D = 5;
        } else if (mes == 8) {
            D = 1;
        } else if (mes == 9) {
            D = 4;
        } else if (mes == 10) {
            D = 6;
        } else if (mes == 11) {
            D = 2;
        } else if (mes == 12) {
            D = 4;
        }

        //CONSTANTE E ES EL DIA
        int E = dia;

        //SUMA DE CONSTANTES
        int r = A + B + C + D + E;

        while (r > 6) {
            r -= 7;
        }

        String diaNombre = "";
        switch (r) {
            case 1:
                diaNombre = "Lunes";
                break;
            case 2:
                diaNombre = "Martes";
                break;
            case 3:
                diaNombre = "Miercoles";
                break;
            case 4:
                diaNombre = "Jueves";
                break;
            case 5:
                diaNombre = "Viernes";
                break;
            case 6:
                diaNombre = "Sabado";
                break;
            case 7:
                diaNombre = "Domingo";
                break;
        }

        System.out.println( "--> " + diaNombre);

    }

    public static boolean esBiciesto(int anio) {

        if (((anio % 4) == 0)) { //ES BISIESTO SI ES DIVISIBLE ENTRE 4

            if ((anio % 100 == 0)) { // NO ES BISIESTO SI ES DIVISIBLE ENTRE 100

                if (anio % 400 == 0) { // SI ES BICIESTO
                    return true;
                } else {
                    return false;
                }

            } else { // SI ES BISIESTO
                return true;
            }

        } else {
            return false;
        }

    }

}



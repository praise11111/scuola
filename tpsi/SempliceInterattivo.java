import java.util.Scanner;

public class SempliceInterattivo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String choice;
        System.out.println("SempliceInterattivo — programma console\n");
        while (true) {
            System.out.println("Menu:\n1) Echo testo\n2) Somma due numeri\n3) Verifica palindromo\n4) Esci");
            System.out.print("Scegli (1-4): ");
            choice = sc.nextLine().trim();
            switch (choice) {
                case "1":
                    echo(sc);
                    break;
                case "2":
                    somma(sc);
                    break;
                case "3":
                    palindromo(sc);
                    break;
                case "4":
                    System.out.println("Arrivederci.");
                    sc.close();
                    return;
                default:
                    System.out.println("Scelta non valida — inserisci 1, 2, 3 o 4.");
            }
        }
    }

    private static void echo(Scanner sc) {
        System.out.print("Inserisci testo: ");
        String t = sc.nextLine();
        if (t.trim().isEmpty()) System.out.println("Nessun testo inserito.");
        else System.out.println("Hai scritto: " + t);
    }

    private static void somma(Scanner sc) {
        System.out.print("Numero A: ");
        String aStr = sc.nextLine().trim();
        System.out.print("Numero B: ");
        String bStr = sc.nextLine().trim();
        try {
            double a = Double.parseDouble(aStr);
            double b = Double.parseDouble(bStr);
            double r = a + b;
            if (r == (long) r) System.out.println((long) a + " + " + (long) b + " = " + (long) r);
            else System.out.println(a + " + " + b + " = " + r);
        } catch (NumberFormatException e) {
            System.out.println("Errore: inserire due numeri validi.");
        }
    }

    private static void palindromo(Scanner sc) {
        System.out.print("Inserisci testo da verificare: ");
        String s = sc.nextLine();
        String norm = s.toLowerCase().replaceAll("[^a-z0-9]", "");
        if (norm.isEmpty()) { System.out.println("Testo vuoto dopo normalizzazione."); return; }
        String rev = new StringBuilder(norm).reverse().toString();
        if (norm.equals(rev)) System.out.println("È un palindromo.");
        else System.out.println("Non è un palindromo.");
    }
}

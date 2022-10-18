import java.util.Scanner; //пакет для ввода переменных в строку 
public class CollatzConjecture {
    public static void main(String[] args) throws Exception {
    Scanner number = new Scanner(System.in);
    System.out.println("Input ur number: ");
    int n, i = 0;
    n = number.nextInt();
    do {
        i++;
        if (n % 2 == 0){n /= 2; } else {n = n*3+1;}
    } while (n > 1);
    System.out.println("Number of iterations: " + i);
    number.close();
    }
}

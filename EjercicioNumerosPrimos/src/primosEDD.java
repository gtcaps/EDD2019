import java.util.LinkedList;
import java.util.Scanner;
public class primosEDD {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner (System.in);
        int num;
        
        System.out.println("Alogritmo Criba de Erastones \n"
                + "--------------------------------------\n");
        
        System.out.print("Ingrese un número: ");
        num = sc.nextInt();
        
        int [] l = new int[num];
        
        for (int i = 0; i < num; i++){
            l[i] = 1;
        }

        
        for(int n = 2; n * n < num; n++){
            if(l[n] == 1){
                for(int i = n*2; i < num; i += n){
                    l[i] = 0;
                }
            }
        }
        
        for(int i = 2; i < num; i++){
            if( l[i] == 1){
                System.out.print(i + " ,"); 
            }
        }
        
    }
    
}

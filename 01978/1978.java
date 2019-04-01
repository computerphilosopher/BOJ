import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {
   
   public static void main(String argv[]) {
      
   
      
      
      Scanner sc = new Scanner(System.in);
      
      
      int n = sc.nextInt();
      int count=0;
   
      
      for (int i=0;i<n;i++) {
            char TF = 'T';
         int a = sc.nextInt();
         
         
       Loop1 : for(int j=2; j< a ; j++) {
          
          if(a%j == 0) {
              
            TF = 'F'; 
             break Loop1;
             
          }
         }
      
         if(TF !='F' && (a != 1&& a !=0)) {
            count++;
            
         }
         
      }
      
   
      System.out.println(count);
      
      
   }
   
}

import java.util.*;
import Jama.Matrix;
public class hill_cipher {
    public static void main(String []s ){
        Scanner sc = new Scanner(System.in);
        String text = sc.nextLine();
        String key = sc.nextLine();
        int n = text.length();
        double [][] text_array = new double[n][1];
        double [][] key_array = new double[n][n];
        int c = 0;
        for(int i=0;i<n;i++){
            text_array[i][0] = (double)(text.charAt(i)-65);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                key_array[i][j] = (double)(key.charAt(c++)-65);
            }
        }
        Matrix a1 = new Matrix(text_array);
        Matrix a2 = new Matrix(key_array);
        double [][] pro = a2.times(a1).getArray();
        double [][] result = new double[n][1];
        String encrypt = new String();
        for(int i=0;i<n;i++){
            result[i][0] = (pro[i][0])%26;
            encrypt += (char)(result[i][0]+65);
        }
        System.out.println("Encrypted:- "+encrypt);
        Matrix inverse = new Matrix(key_array);
        inverse = inverse.inverse();
        double[][] decrypted_mat =
        inverse.times(Matrix.constructWithCopy(pro)).getArray();
        String decrypted = new String();
        for(int i=0;i<n;i++){
            decrypted_mat[i][0] = Math.round(decrypted_mat[i][0]);
            decrypted += (char) (decrypted_mat[i][0]+65);
        }
        System.out.println("Decrypted:- "+decrypted);
    }
}

/*
 * Author - Debag101
 * Purpose - Key Encryption
 * Date - 30 05 2023
 */

import java.util.Scanner;

public class Match50 {

    // Function to decrypt key based on shift and encrypted key
    public static String Decrypt(String key, int s) {
        String D_Key = "";
        // Iterating over string and incrementing or decrementing char ascii by s(shift)
        for(char c : key.toCharArray()) {
            D_Key += (char)((int)(c + s - 1));
        }
        // Returning the key
        return D_Key;
    } 

    // Main execution starts
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Getting the encrypted key from user
        System.out.println("Enter the encrypted text => ");
        String encryptedKey = sc.nextLine();

        // Getting shift value
        System.out.println("Enter shift value e.g +3 , -4 etc => ");
        try {
            int shift = sc.nextInt();
            String DecryptedKey = Decrypt(encryptedKey, shift); // Getting back decrypted key
            System.out.println("Decrypted key is : " + DecryptedKey); // Printing decrypted key
        }catch(Exception NumberFormatException) {
            System.out.println("Not a valid shift count => ");
        }

        // Closing scanner obj
        sc.close();
    }
}

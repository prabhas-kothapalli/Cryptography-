import javax.crypto.*;

public class DES {

    public static void main(String[] args) {
        try {
            // Generate a DES key
            KeyGenerator keyGenerator = KeyGenerator.getInstance("DES");
            SecretKey key = keyGenerator.generateKey();

            // Create a DES cipher for encryption
            Cipher cipher = Cipher.getInstance("DES/ECB/PKCS5Padding");
            cipher.init(Cipher.ENCRYPT_MODE, key);

            // Original data to be encrypted
            String plaintext = "Hello, world!";
            byte[] plaintextBytes = plaintext.getBytes();

            // Encrypt the data
            byte[] encryptedBytes = cipher.doFinal(plaintextBytes);

            // Create a DES cipher for decryption
            cipher.init(Cipher.DECRYPT_MODE, key);

            // Decrypt the data
            byte[] decryptedBytes = cipher.doFinal(encryptedBytes);

            // Display results
            System.out.println("Original data: " + plaintext);
            System.out.println("Encrypted data: " + new String(encryptedBytes));
            System.out.println("Decrypted data: " + new String(decryptedBytes));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}


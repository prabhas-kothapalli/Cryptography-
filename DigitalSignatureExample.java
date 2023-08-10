import java.security.*;

public class DigitalSignatureExample {

    public static void main(String[] args) {
        try {
            // Generate key pair
            KeyPairGenerator keyPairGenerator = KeyPairGenerator.getInstance("DSA");
            keyPairGenerator.initialize(1024);
            KeyPair keyPair = keyPairGenerator.generateKeyPair();

            // Sign data
            String data = "Hello, world!";
            Signature signature = Signature.getInstance("SHA256withDSA");
            signature.initSign(keyPair.getPrivate());
            signature.update(data.getBytes());
            byte[] signedBytes = signature.sign();

            System.out.println("Original data: " + data);

            // Verify signature
            Signature verifySignature = Signature.getInstance("SHA256withDSA");
            verifySignature.initVerify(keyPair.getPublic());
            verifySignature.update(data.getBytes());
            boolean isVerified = verifySignature.verify(signedBytes);

            System.out.println("Signature verified: " + isVerified);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}

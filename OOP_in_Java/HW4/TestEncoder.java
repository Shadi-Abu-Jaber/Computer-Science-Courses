import java.io.*;

public class TestEncoder {

    public static void main(String[] args) {
        if (args.length < 1) {
            throw new IllegalArgumentException("No arguments provided");
        }

        String inputFilePath = args[0];
        String key = args.length >= 2 ? args[1] : Consts.SEED;

        try {
            // Reading input file
            File inputFile = new File(inputFilePath);
            FileReader fileReader = new FileReader(inputFilePath);
            BufferedReader buffReader = new BufferedReader(fileReader);
            StringBuilder inputContent = new StringBuilder();
            String line;
            boolean isFirstLine = true;

            while ((line = buffReader.readLine()) != null) {
                if (!isFirstLine) {
                    inputContent.append("\n");
                } else {
                    isFirstLine = false;
                }
                inputContent.append(line);
            }
            buffReader.close();
            fileEncrypt(inputFile, key, inputContent);
            fileDecrypt(inputFile, key, inputContent);
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }

    private static void fileDecrypt(File inputFile, String key, StringBuilder inputContent) throws IOException {
        // Decrypt the encrypted file
        FileReader encryptedFileReader = new FileReader("encrypted_" + inputFile.getName());
        DecryptorReader decryptorReader = new DecryptorReader(encryptedFileReader, key);

        // After decrypting, write it into decrypted_inputFile...
        FileWriter decryptedFileWriter = new FileWriter("decrypted_" + inputFile.getName());
        decryptedFileWriter.write(inputContent.toString().toCharArray(), 0, inputContent.length());

        decryptorReader.close();
        decryptedFileWriter.close();
    }

    private static void fileEncrypt(File inputFile, String key, StringBuilder inputContent) throws IOException {
        // Encrypt the input file
        FileWriter encryptedFileWriter = new FileWriter("encrypted_" + inputFile.getName());
        EncryptorWriter encryptorWriter = new EncryptorWriter(encryptedFileWriter, key);

        encryptorWriter.write(inputContent.toString().toCharArray(), 0, inputContent.length());
        encryptorWriter.close();
    }
}

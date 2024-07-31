import java.io.IOException;
import java.io.Writer;

public class EncryptorWriter extends Writer {
    private Writer writer;
    private String key;
    private int keyPosition;

    public EncryptorWriter(Writer writer) {
        this(writer, Consts.SEED);
    }

    public EncryptorWriter(Writer writer, String key) {
        this.writer = writer;
        this.key = key;
        this.keyPosition = 0;
    }

    @Override
    public void write(char[] cbuf, int off, int len) throws IOException {
        char[] encryptedBuf = new char[len];
        for (int i = 0; i < len; i++) {
            encryptedBuf[i] = encrypt(cbuf[off + i]);
        }
        writer.write(encryptedBuf, 0, len);
    }

    public char encrypt(char c) {
        char keyChar = key.charAt(keyPosition);
        int encryptedValue = (int) c + (int) keyChar;
        char encryptedChar = (char) encryptedValue;
        keyPosition = (keyPosition + 1) % key.length();
        return encryptedChar;
    }


    @Override
    public void flush() throws IOException {
        writer.flush();
    }

    @Override
    public void close() throws IOException {
        writer.close();
    }
}

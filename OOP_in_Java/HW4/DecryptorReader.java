import java.io.IOException;
import java.io.Reader;

public class DecryptorReader extends Reader {
    private Reader reader;
    private String key;
    private int keyPosition;

    public DecryptorReader(Reader reader) {
        this(reader, Consts.SEED);
    }

    public DecryptorReader(Reader reader, String key) {
        this.reader = reader;
        this.key = key;
        this.keyPosition = 0;
    }

    @Override
    public int read(char[] cbuf, int off, int len) throws IOException {
        int charsRead = reader.read(cbuf, off, len);
        for (int i = off; i < len; i++) {
            cbuf[i] = decrypt(cbuf[i]);
        }
        return charsRead;
    }

    public char decrypt(char c) {
        char keyChar = key.charAt(keyPosition);
        int decryptedValue = (int) c - (int) keyChar;
        char decryptedChar = (char) decryptedValue;
        keyPosition = (keyPosition + 1) % key.length();
        return decryptedChar;
    }

    @Override
    public void close() throws IOException {
        reader.close();
    }
}

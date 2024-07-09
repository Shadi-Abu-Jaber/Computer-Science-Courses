public class HW3Exception extends Exception {
    // I got a compilation warning (in auto testing) without this line.
    private static final long serialVersionUID = 1L;

    public HW3Exception(String message) {
        super(message);
    }

}

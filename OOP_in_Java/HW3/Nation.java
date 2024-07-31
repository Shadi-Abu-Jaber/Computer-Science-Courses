import java.util.concurrent.locks.ReentrantLock;

public class Nation implements Comparable<Nation> {

    private String nationName;
    private String anthem;
    private final ReentrantLock lock;


    public ReentrantLock getLock() {
        return lock;
    }

    public Nation(String nationName, String anthem) {
        this.nationName = nationName;
        this.anthem = anthem;
        lock = new ReentrantLock();
    }

    public String getNationName() {
        return nationName;
    }

    public String getAnthem() {
        return anthem;
    }

    @Override
    public int hashCode() {
        return getNationName().hashCode();
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == this) {
            return true;
        }
        if (obj == null) {
            return false;
        }
        if (obj instanceof Nation) {
            return this.nationName.equals(((Nation) obj).getNationName());
        } else {
            return false;
        }

    }

    @Override
    public String toString() {
        return String.format("%-12s with anthem %-30s", nationName, anthem);
    }

    @Override
    public int compareTo(Nation o) {
        if (o == this) {
            return 0;
        }
        if (o != null) {
            return this.getNationName().compareToIgnoreCase(o.getNationName());
        } else {
            return 0;
        }
    }

    public static Nation buildNation(String s) {
        String[] parts = HW4Helper.parseLine(s, 2);
        return new Nation(parts[0], parts[1]);
    }
}

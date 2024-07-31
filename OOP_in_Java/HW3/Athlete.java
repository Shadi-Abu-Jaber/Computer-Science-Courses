public class Athlete {

    private String athleteName;
    private Nation nationality;

    public Athlete(String athleteName, Nation nationality) {
        this.athleteName = athleteName;
        this.nationality = nationality;
    }

    public String getAthleteName() {
        return athleteName;
    }

    public Nation getNationality() {
        return nationality;
    }

    public static Athlete buildAthlete(String s) {
        String[] parts = HW4Helper.parseLine(s, 2);
        Nation nation = HW4Helper.getNation(parts[1]);
        return new Athlete(parts[0], nation);
    }

    @Override
    public String toString() {
        return String.format("Athlete %-13s from %-20s", athleteName, nationality);
    }
}

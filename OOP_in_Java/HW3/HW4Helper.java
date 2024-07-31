
public class HW4Helper {

    public static String[] parseLine(String string, int dataCount) {
        if (string == null || !string.contains(";")) {
            throw new IllegalArgumentException();
        }

        String[] data = string.split(";");
        if (data.length != dataCount) {
            throw new IllegalArgumentException();
        }
        return data;
    }

    public static Nation getNation(String nationName) {
        for (Nation nation : CeremonyData.nations) {
            if (nation.getNationName().equals(nationName)) {
                return nation;
            }
        }
        throw new IllegalArgumentException();
    }

    public static Event getEvent(String eventName) {
        for (Event event : CeremonyData.events) {
            if (event.getEventName().equals(eventName)) {
                return event;
            }
        }
        throw new IllegalArgumentException();
    }

    public static Athlete getAthlete(String athleteName) {
        for (Athlete athlete : CeremonyData.athletes) {
            if (athlete.getAthleteName().equals(athleteName)) {
                return athlete;
            }
        }
        throw new IllegalArgumentException();
    }
}

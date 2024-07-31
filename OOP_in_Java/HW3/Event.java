
public class Event {
    private String eventName;
    private String sportName;

    public Event(String eventName, String sportName) {
        this.eventName = eventName;
        this.sportName = sportName;
    }

    public static Event buildEvent(String string)  {
        String[] parts = HW4Helper.parseLine(string, 2);
        return new Event(parts[0], parts[1]);
    }

    @Override
    public String toString() {
        return String.format("Event  %-28s for sport %-10s", eventName, sportName);
    }

    public String getEventName() {
        return eventName;
    }

    public String getSportName() {
        return sportName;
    }
}

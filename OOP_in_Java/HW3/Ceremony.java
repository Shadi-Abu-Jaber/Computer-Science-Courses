import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;

public class Ceremony extends Thread {

    private Event event;
    private Athlete firstPlace, secondPlace, thirdPlace;
    private int duration;

    public Ceremony(Event event, Athlete firstPlace, Athlete secondPlace, Athlete thirdPlace, int duration) {
        this.event = event;
        this.firstPlace = firstPlace;
        this.secondPlace = secondPlace;
        this.thirdPlace = thirdPlace;
        this.duration = duration;
    }

    public Event getEvent() {
        return event;
    }

    public Athlete getFirstPlace() {
        return firstPlace;
    }

    public Athlete getSecondPlace() {
        return secondPlace;
    }

    public Athlete getThirdPlace() {
        return thirdPlace;
    }

    public int getDuration() {
        return duration;
    }

    public static Ceremony buildCeremony(String s) {
        String[] data = HW4Helper.parseLine(s, 5);
        Event event = HW4Helper.getEvent(data[0]);
        Athlete firstPlace = HW4Helper.getAthlete(data[1]);
        Athlete secondPlace = HW4Helper.getAthlete(data[2]);
        Athlete thirdPlace = HW4Helper.getAthlete(data[3]);
        int duration = Integer.parseInt(data[4]);
        return new Ceremony(event, firstPlace, secondPlace, thirdPlace, duration);
    }

    @Override
    public String toString() {
        return String.format("Ceremony for %-10s duration %d and winners " + firstPlace + " " + secondPlace + " and " + thirdPlace, event, duration);
    }

    @Override
    public void run() {
        try {
            List<Nation> nations = lockNations();

            // Medals' distribution
            System.out.println("Gold   Medal " + firstPlace);
            Thread.sleep(duration * 1000L);
            System.out.println("Silver Medal " + secondPlace);
            Thread.sleep(duration * 1000L);
            System.out.println("Bronze Medal " + thirdPlace);
            Thread.sleep(duration * 1000L);

            unlockNations(nations);

        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }

    private void unlockNations(List<Nation> nations) {
        String formattedTime;
        for (Nation nation : nations) {
            nation.getLock().unlock();
        }

        System.out.printf(event + " unlocked %10s%n", firstPlace.getNationality().getNationName());
        System.out.printf(event + " unlocked %10s%n", secondPlace.getNationality().getNationName());
        System.out.printf(event + " unlocked %10s%n", thirdPlace.getNationality().getNationName());

        formattedTime = getCurrentTime();
        String endTime = String.format("End    ceremony  %-26s at " + formattedTime, event.getEventName());
        System.out.println(endTime);
    }

    private List<Nation> lockNations() {
        // lock nations in alphabetically order to avoid a deadlock situation
        List<Nation> nations = new ArrayList<>();
        nations.add(firstPlace.getNationality());
        nations.add(secondPlace.getNationality());
        nations.add(thirdPlace.getNationality());
        nations.sort(Nation::compareTo);

        for (Nation nation : nations) {
            nation.getLock().lock();
        }

        String formattedTime = getCurrentTime();
        String BeginningTime = String.format("Start  ceremony  %-26s at " + formattedTime + " (duration %3d)", event.getEventName(), duration);
        System.out.println(BeginningTime);

        System.out.printf(event + " locked %-10s%n", firstPlace.getNationality().getNationName());
        System.out.printf(event + " locked %-10s%n", secondPlace.getNationality().getNationName());
        System.out.printf(event + " locked %-10s%n", thirdPlace.getNationality().getNationName());
        return nations;
    }

    private String getCurrentTime() {
        LocalTime currentTime = LocalTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:ss");
        return currentTime.format(formatter);
    }
}

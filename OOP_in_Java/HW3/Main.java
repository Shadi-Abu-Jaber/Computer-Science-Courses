import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        buildOlympicsObjects(args);
        System.out.println("Start all ceremonies");
        for (Ceremony ceremony : CeremonyData.ceremonies) {
            ceremony.start();
        }

        for (Ceremony ceremony : CeremonyData.ceremonies) {
            try {
                ceremony.join();
            } catch (InterruptedException e) {
                System.out.println(e.getMessage());
            }
        }
        System.out.println("End all ceremonies");

    }

    private static void buildOlympicsObjects(String[] args) throws FileNotFoundException {
        for (int i = 0; i < args.length; i++) {
            Scanner fileScanner = new Scanner(new File(args[i]));
            while (fileScanner.hasNextLine()) {
                String line = fileScanner.nextLine();
                switch (i) {
                    case 0:
                        Event event = Event.buildEvent(line);
                        CeremonyData.events.add(event);
                        break;
                    case 1:
                        Nation nation = Nation.buildNation(line);
                        CeremonyData.nations.add(nation);
                        break;
                    case 2:
                        Athlete athlete = Athlete.buildAthlete(line);
                        CeremonyData.athletes.add(athlete);
                        break;
                    case 3:
                        Ceremony ceremony = Ceremony.buildCeremony(line);
                        CeremonyData.ceremonies.add(ceremony);
                        break;

                }
            }
        }
    }
}
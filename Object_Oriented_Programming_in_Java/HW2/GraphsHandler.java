import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;

public class GraphsHandler {
    public static void main(String[] args) throws IOException {

        List<IGraph<String>> list = new ArrayList<>();
        SortedMap<String, SortedSet<IGraph<String>>> map = new TreeMap<>();

        Comparator<IGraph<String>> comparator = new GraphComparator();
        SortedSet<IGraph<String>> DirectedGraphSet = new TreeSet<>(comparator);
        SortedSet<IGraph<String>> UndirectedGraphSet = new TreeSet<>(comparator);
        map.put("DirectedGraph", DirectedGraphSet);
        map.put("UndirectedGraph", UndirectedGraphSet);

        // Put these expressions in try to automatically close scanners and writers.
        try (Scanner fileScanner = new Scanner(new File(args[0]));
             FileWriter reversedListWriter = new FileWriter("GraphsOutList.txt");
             FileWriter sortedListWriter = new FileWriter("GraphsSortOutList.txt");
             FileWriter sortedMapWriter = new FileWriter("GraphsSortOutMap.txt")) {

            processInputFile(fileScanner, list, map);

            // Writing reversed graph's List into GraphsOutList.txt
            Collections.reverse(list);
            GraphsOutList(list, reversedListWriter);

            // Writing sorted graph's List into GraphsSortOutList.txt
            list.sort(comparator);
            GraphsOutList(list, sortedListWriter);

            // Writing sorted graph's Map into GraphsSortOutMap.txt
            GraphsSortOutMap(map, sortedMapWriter);

        }
    }

    private static void processInputFile(Scanner fileScanner, List<IGraph<String>> list, SortedMap<String, SortedSet<IGraph<String>>> map) throws IOException {
        String line = null;
        int lineCounter = 0;
        FileWriter writer = new FileWriter("errorsGraphs.txt");

        while (fileScanner.hasNextLine()) {
            try {
                lineCounter++;
                line = fileScanner.nextLine();
                if (line.isEmpty()) {
                    throw new HW3Exception("null");
                } else {
                    IGraph<String> graph = GraphUtils.strToGraph(line);
                    list.add(graph);
                    map.get(graph.getGraphType()).add(graph);
                }
            } catch (HW3Exception e) {
                writer.write("line number=" + lineCounter + ", " + "input line=" + line + ", " + "Error message = " + e.getMessage() + "\n");
            }
        }
        writer.flush();
        writer.close();
    }

    private static void GraphsOutList(List<IGraph<String>> list, FileWriter writer) throws IOException {
        for (IGraph<String> graph : list) {
            writer.write(graph.toString());
            if (!graph.equals(list.get(list.size() - 1))) {
                writer.write("\n");
            }
        }
    }

    private static void GraphsSortOutMap(SortedMap<String, SortedSet<IGraph<String>>> map, FileWriter writer) throws IOException {
        // used iterator on a map as you demanded
        Iterator<String> mapIterator = map.keySet().iterator();
        while (mapIterator.hasNext()) {
            String key = mapIterator.next();
            SortedSet<IGraph<String>> sortedSet = map.get(key);

            Iterator<IGraph<String>> setIterator = sortedSet.iterator();
            while (setIterator.hasNext()) {
                IGraph<String> graph = setIterator.next();
                writer.write(graph.toString());
                if (setIterator.hasNext()) {
                    writer.write("\n");
                }
            }

            if (mapIterator.hasNext()) {
                writer.write("\n");
            }
        }
    }
}

import java.util.Scanner;

public class GraphUtils {

    private static double PRECISION = 1.0e-2;

    /**
     * @param d : double
     * @return String represents d with two places after the decimal point.
     */
    public static String formatDouble(double d) {
        String res = String.format("%.2f", d);
        if (res.equals("-0.00"))
            res = "0.00";
        return res;
    }

    public static boolean areEqual(double d1, double d2) {
        return Math.abs(d1 - d2) < PRECISION;
    }

    public static IGraph<String> strToGraph(String strGraph) throws HW3Exception {
        Scanner scanner = new Scanner(strGraph);
        IGraph<String> graph = setGraphType(scanner);
        graphBuilder(scanner, graph);
        scanner.close();
        return graph;
    }

    private static IGraph<String> setGraphType(Scanner scanner) throws HW3Exception {
        IGraph<String> graph = null;
        scanner.useDelimiter(":");
        if (scanner.hasNext()) {
            String graphType = scanner.next();
            if (graphType.equals("DirectedGraph")) {
                graph = new DirectedGraph<>();
            } else if (graphType.equals("UndirectedGraph")) {
                graph = new UndirectedGraph<>();
            } else {
                throw new HW3Exception("The graph type is not valid");
            }
        }
        return graph;
    }

    private static void graphBuilder(Scanner scanner, IGraph<String> graph) throws HW3Exception {
        scanner.useDelimiter("[ \t]");
        while (scanner.hasNext()) {
            String vertexInfo = scanner.next();
            Scanner vertexScanner = new Scanner(vertexInfo);
            vertexScanner.useDelimiter(":|->");

            // Extracting vertexes and their edges to build the graph
            if (vertexScanner.hasNext()) {
                String from = vertexScanner.next();
                checkStringValidly(from);
                graph.addVertex(from);

                while (vertexScanner.hasNext()) {
                    String to = vertexScanner.next();
                    checkStringValidly(to);
                    graph.addVertex(to);
                    graph.addEdge(from, to);
                }
            }
            vertexScanner.close();
        }
    }

    private static void checkStringValidly(String to) throws HW3Exception {
        int i;
        for (i=0; i< to.length(); i++){
            if (!Character.isLetterOrDigit(to.charAt(i))) {
                throw new HW3Exception("Exception in scanning the graph string");
            }
        }
    }
}

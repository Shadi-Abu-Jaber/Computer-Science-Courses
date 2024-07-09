import java.util.Comparator;

public class GraphComparator implements Comparator<IGraph<String>> {
    @Override
    public int compare(IGraph<String> graph1, IGraph<String> graph2) {
        return Integer.compare(graph1.numOfEdges(), graph2.numOfEdges());
    }
}

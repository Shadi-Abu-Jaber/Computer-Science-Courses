public class UndirectedGraph<V extends Comparable<V>> extends DirectedGraph<V> {

    /**
     * Constructs an empty undirected graph.
     */
    public UndirectedGraph() {
        super();
    }

    /**
     * Add a new edge if none exists between the two vertices. If the vertices u or
     * v do not exist, add them to the graph.
     *
     * @param u the starting vertex of the edge
     * @param v the ending vertex of the edge
     */
    @Override
    public void addEdge(V u, V v) {
        if (!containsEdge(u, v)) {
            super.addEdge(u, v);
            super.addEdge(v, u);
        }
    }

    /**
     * @param u the starting vertex
     * @param v the ending vertex
     * @return Remove the edge (u,v) if it exists, and return True. If this edge
     * does not exist, return False.
     */
    @Override
    public boolean removeEdge(V u, V v) {
        if (super.removeEdge(u, v)) {
            return super.removeEdge(v, u);
        }
        return false;
    }

    /**
     * @return the type of the graph "Directed" or "Undirected".
     */
    @Override
    public String getGraphType() {
        return "UndirectedGraph";
    }

    /**
     * @return the number of edges
     */
    @Override
    public int numOfEdges() {
        // Self-edges aren't counted twice in numOfEdges(), so we add them.
        return (super.numOfSelfEdges() + super.numOfEdges()) / 2;
    }
}

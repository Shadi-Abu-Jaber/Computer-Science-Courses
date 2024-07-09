import java.util.*;

public class DirectedGraph<V extends Comparable<V>> implements IGraph<V> {

    private final SortedMap<V, List<V>> vertices;

    /**
     * Constructs an empty directed graph.
     */
    public DirectedGraph() {
        vertices = new TreeMap<>();
    }

    /**
     * Add a new vertex if none exists.
     *
     * @param v the vertex to add
     */
    @Override
    public void addVertex(V v) {
        if (!containsVertex(v)) {
            vertices.put(v, new ArrayList<>());
        }
    }

    /**
     * Add a new edge if none exists between the two vertices.
     * If the vertices u or v do not exist, add them to the graph.
     *
     * @param u the starting vertex of the edge
     * @param v the ending vertex of the edge
     */
    @Override
    public void addEdge(V u, V v) {
        if (!containsVertex(u)) {
            addVertex(u);
        }
        if (!containsVertex(v)) {
            addVertex(v);
        }
        if (!containsEdge(u, v)) {
            vertices.get(u).add(v);
        }
    }

    /**
     * @param v the vertex to check for
     * @return true if the graph contains the vertex.
     */
    @Override
    public boolean containsVertex(V v) {
        return vertices.containsKey(v);
    }

    /**
     * @param u the starting vertex
     * @param v the ending vertex
     * @return If the edge (u,v) exists.
     */
    @Override
    public boolean containsEdge(V u, V v) {
        if (containsVertex(u) && containsVertex(v) && vertices.get(u) != null) {
            return vertices.get(u).contains(v);
        }
        return false;
    }

    /**
     * Remove the vertex and its edges from the graph, and return its incidents.
     * If the vertex doesn't exit, return null.
     *
     * @param v the vertex to remove
     * @return a list of vertices that had edges to or from the removed vertex.
     */
    @Override
    public List<V> removeVertex(V v) {
        List<V> incidents = new ArrayList<>();
        if (containsVertex(v)) {
            for (V u : vertices.keySet()) {
                if (containsEdge(u, v)) {
                    incidents.add(u);
                    removeEdge(u, v);
                }

                if (containsEdge(v, u)) {
                    incidents.add(u);
                    removeEdge(v, u);
                }
            }
            vertices.remove(v);
            return incidents;
        }
        return null;
    }

    /**
     * @param u the starting vertex
     * @param v the ending vertex
     * @return Remove the edge (u,v) if it exists, and return True. If this edge
     * does not exist, return False.
     */
    @Override
    public boolean removeEdge(V u, V v) {
        if (containsEdge(u, v)) {
            vertices.get(u).remove(v);
            return true;
        }
        return false;
    }

    /**
     * @return the type of the graph "Directed" or "Undirected".
     */
    @Override
    public String getGraphType() {
        return "DirectedGraph";
    }

    /**
     * @return the number of vertices
     */
    @Override
    public int numOfVertices() {
        return vertices.size();
    }

    /**
     * @return the number of edges
     */
    @Override
    public int numOfEdges() {
        int numberOfEdges = 0;
        for (V v : vertices.keySet()) {
            numberOfEdges += vertices.get(v).size();
        }
        return numberOfEdges;
    }

    /**
     * @return the number of self-edges
     */
    public int numOfSelfEdges() {
        int selfEdges = 0;
        for (V v : vertices.keySet()) {
            if (containsEdge(v, v)) {
                selfEdges++;
            }
        }
        return selfEdges;
    }


    @Override
    public String toString() {
        String graph = getGraphType() + ":\t";
        for (V v : vertices.keySet()) {
            graph += v.toString() + ":";

            Iterator<V> iterator = vertices.get(v).iterator();
            while (iterator.hasNext()) {
                graph += iterator.next().toString();
                if (iterator.hasNext()) {
                    graph += "->";
                }
            }

            if (v != vertices.lastKey()) {
                graph += " ";
            }
        }
        return graph;
    }

}

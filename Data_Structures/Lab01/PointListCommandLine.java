package Lab01;

import java.io.*;
import java.awt.Point;

public class PointListCommandLine {

    public static void main(String[] args) throws IOException {
        PointList list = new ArrayPointList();
        InputStreamReader reader = new InputStreamReader(System.in);
        StreamTokenizer tokens = new StreamTokenizer(reader);

        while (tokens.nextToken() != StreamTokenizer.TT_EOL) {
            switch (tokens.sval) {
                case "add":
                    add(tokens, list);
                    break;
                case "curr":
                    System.out.println("(" + list.getCursor().x + ", " + list.getCursor().y + ")");
                    break;
                case "next":
                    System.out.println(list.goToNext() ? "true" : "false");
                    break;
                case "prev":
                    System.out.println(list.goToPrior() ? "true" : "false");
                    break;
                case "start":
                    System.out.println(list.goToBeginning() ? "true" : "false");
                    break;
                case "end":
                    System.out.println(list.goToEnd() ? "true" : "false");
                    break;
                case "empty":
                    System.out.println(list.isEmpty() ? "true" : "false");
                    break;
                case "full":
                    System.out.println(list.isFull() ? "true" : "false");
                    break;
                case "clear":
                    list.clear();
                    break;
                case "quit":
                    return;
            }
        }
    }

    private static void add(StreamTokenizer tokens, PointList list) throws IOException {
        Point vertex = new Point();
        tokens.nextToken();
        vertex.x = (int) tokens.nval;
        tokens.nextToken();
        vertex.y = (int) tokens.nval;
        list.append(vertex);
    }
}

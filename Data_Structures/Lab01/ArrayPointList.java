package Lab01;

import java.awt.*;

public class ArrayPointList implements PointList {

    private final Point[] points;
    private int cursor = 0;
    private int currentSize = 0;

    public ArrayPointList(int size) {
        points = new Point[size];
    }

    public ArrayPointList() {
        this(PointList.MAX_SIZE);
    }

    @Override
    public void append(Point newPoint) {
        if (!isFull()) {
            points[currentSize++] = newPoint;
            goToEnd();
        }
    }

    @Override
    public void clear() {
        currentSize = 0; // now the list is empty
        cursor = -1; // now the cursor isn't pointing to any point in the list
    }

    @Override
    public boolean isEmpty() {
        return currentSize == 0;
    }

    @Override
    public boolean isFull() {
        return currentSize == points.length;
    }

    @Override
    public boolean goToBeginning() {
        if (!isEmpty()) {
            cursor = 0;
            return true;
        }
        return false;
    }

    @Override
    public boolean goToEnd() {
        if (!isEmpty()) {
            cursor = currentSize - 1;
            return true;
        }
        return false;
    }

    @Override
    public boolean goToNext() {
        if (cursor != currentSize - 1 && !isEmpty()) {
            cursor++;
            return true;
        }
        return false;
    }

    @Override
    public boolean goToPrior() {
        if (cursor > 0) {
            cursor--;
            return true;
        }
        return false;
    }

    @Override
    public Point getCursor() {
        return points[cursor] == null ? null : new Point(points[cursor]);
    }

    @Override
    public String toString() {
        if (isEmpty()) {
            System.out.println("Empty list");
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < currentSize; i++) {
            sb.append("(").append(points[i].x).append(", ").append(points[i].y).append(")\n");
        }
        return sb.toString();
    }
}

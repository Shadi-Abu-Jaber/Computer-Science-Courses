abstract public class AbstractRectangle implements Rectangle {
    public static final int POINTS_IN_RECT = 4;

    abstract public double getHeight();

    abstract public double getWidth();

    abstract public Point getBottomLeft();

    abstract public Point[] getAllPoints();

    abstract public void updateWidth(double width);

    abstract public void updateHeight(double height);

    abstract public void setBottomLeft(Point bottomLeft);

    /**
     * Scales the rectangle's width and height by specified factor.
     *
     * @param scaleFactor The factor by which to scale. If scaleFactor<=0 then nothing is done.
     */
    @Override
    public void scale(double scaleFactor) {
        if (isValidLength(scaleFactor)) {
            updateWidth(getWidth() * scaleFactor);
            updateHeight(getHeight() * scaleFactor);
        }
    }

    /**
     * Moves the rectangle by a specified delta in both the x and y directions.
     *
     * @param delta The point representing the delta to move in the x and y directions.
     */
    @Override
    public void move(Point delta) {
        Point bottomLeft = getBottomLeft();
        double newXPosition = bottomLeft.getX() + delta.getX();
        double newYPosition = bottomLeft.getY() + delta.getY();
        setBottomLeft(new Point(newXPosition, newYPosition));
    }

    /**
     * Moves the rectangle horizontally by a specified distance.
     *
     * @param distance The distance to move the rectangle horizontally.
     */
    @Override
    public void moveHorizontal(double distance) {
        // The Y axis is not affected
        move(new Point(distance, 0));
    }

    /**
     * Moves the rectangle vertically by a specified distance.
     *
     * @param distance The distance to move the rectangle vertically.
     */
    @Override
    public void moveVertical(double distance) {
        // The X axis is not affected
        move(new Point(0, distance));
    }

    /**
     * Flips the rectangle vertically around its <b>left</b> edge.
     * When we flip the rectangle vertically:
     * The top-right corner moves to where the top-left corner was
     * The bottom-right corner moves to where the bottom-left corner was
     * So it's like moving the rectangle horizontally to the left by
     * width distance
     */
    @Override
    public void flipVertical() {
        moveHorizontal(-getWidth());
    }

    /**
     * Flips the rectangle horizontally around its bottom edge.
     * Same as what we did in flipVertical() but here top corners
     * move to where the bottom corners were, so it's like moving
     * the rectangle vertically down by height distance
     */
    @Override
    public void flipHorizontal() {
        moveVertical(-getHeight());
    }

    /**
     * Calculates the area of the rectangle.
     *
     * @return The area of the rectangle.
     */
    @Override
    public double area() {
        return this.getWidth() * this.getHeight();
    }

    /**
     * Calculates the perimeter of the rectangle.
     *
     * @return The perimeter of the rectangle.
     */
    @Override
    public double perimeter() {
        return 2 * (this.getWidth() + this.getHeight());
    }

    /**
     * Checks if another rectangle is equal to this one.
     * Equality is based on the dimensions and position of the rectangle.
     *
     * @param other The other rectangle to compare with.
     * @return {@code true} if the rectangles are equal, {@code false} otherwise.
     */
    @Override
    public boolean isEqual(Rectangle other) {
        return (this.getWidth() == other.getWidth()) &&
                (this.getHeight() == other.getHeight()) &&
                (this.getBottomLeft().equals(other.getBottomLeft()));
    }

    /**
     * Checks if the given length of a rectangle side is valid.
     * <p>
     * A rectangle side length is considered valid if it is greater than 0.
     *
     * @param length the length of the rectangle side to check
     * @return {@code true} if the length is greater than 0, {@code false} otherwise
     */
    public boolean isValidLength(double length) {
        return length > 0;
    }
}

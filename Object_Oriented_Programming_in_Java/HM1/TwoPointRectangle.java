public class TwoPointRectangle extends AbstractRectangle {

    private Point bottomRight;
    private Point topLeft;

    /**
     * Default constructor that creates a rectangle with the bottom-left point at (0, 0),
     * a width of 1, and a height of 1.
     */
    public TwoPointRectangle() {
        this.topLeft = new Point(0, 1);
        this.bottomRight = new Point(1, 0);
    }

    /**
     * Creates a rectangle defined by the given top-left and bottom-right points.
     * If the provided points do not form a valid rectangle, it creates default rectangle.
     * default rectangle = bottom-left point at (0, 0),a width of 1, and a height of 1.
     *
     * @param topLeft     The point representing the top-left corner of the rectangle.
     * @param bottomRight The point representing the bottom-right corner of the rectangle.
     */
    public TwoPointRectangle(Point topLeft, Point bottomRight) {
        this();
        if (isValidRectangle(topLeft, bottomRight)) {
            this.topLeft = topLeft.copy();
            this.bottomRight = bottomRight.copy();
        }
    }


    /**
     * Gets the width of the rectangle.
     *
     * @return The width of the rectangle.
     */
    @Override
    public double getWidth() {
        return this.bottomRight.getX() - this.topLeft.getX();
    }

    /**
     * Gets the height of the rectangle.
     *
     * @return The height of the rectangle.
     */
    @Override
    public double getHeight() {
        return this.topLeft.getY() - this.bottomRight.getY();
    }

    /**
     * Retrieves the bottom-left point of the rectangle. This method typically creates
     * and returns a new {@link Point} object based on the rectangle's position and dimensions.
     *
     * @return A new {@link Point} object representing the bottom-left corner of the rectangle.
     */
    @Override
    public Point getBottomLeft() {
        return new Point(this.topLeft.getX(), this.bottomRight.getY());
    }


    /**
     * Provides an array of points representing the corners of the rectangle.
     *
     * @return An array of {@link Point} objects representing each corner of the rectangle. The
     * points should be new {@link Point} objects
     */
    @Override
    public Point[] getAllPoints() {
        Point[] points = new Point[POINTS_IN_RECT];
        points[0] = this.topLeft.copy();
        points[1] = getTopRight();
        points[2] = this.bottomRight.copy();
        points[3] = getBottomLeft();
        return points;
    }

    /**
     * Updates the width of the rectangle. If width <= 0, nothing is done.
     * Width is relative to bottom left point.
     *
     * @param width The new width of the rectangle.
     */
    @Override
    public void updateWidth(double width) {
        if (isValidLength(width)) {
            bottomRight.setX(topLeft.getX() + width);
        }

    }

    /**
     * Updates the height of the rectangle. If height <= 0, nothing is done.
     * Height is relative to bottom left point.
     *
     * @param height The new height of the rectangle.
     */
    @Override
    public void updateHeight(double height) {
        if (isValidLength(height)) {
            topLeft.setY(bottomRight.getY() + height);
        }
    }

    /**
     * Sets the bottom-left point of the rectangle. This method adjusts the bottomRight
     * point to maintain the rectangle's width and height.
     *
     * @param bottomLeft The new bottom-left point of the rectangle.
     */
    @Override
    public void setBottomLeft(Point bottomLeft) {
        /* I did these expressions in this order to maintain the width and height
           when setting the bottomRight-x and topLeft-y */
        this.bottomRight.setX(bottomLeft.getX() + getWidth());
        this.topLeft.setY(bottomLeft.getY() + getHeight());

        this.bottomRight.setY(bottomLeft.getY());
        this.topLeft.setX(bottomLeft.getX());
    }

    /**
     * Retrieves the top-right point of the rectangle. This method typically creates
     * and returns a new {@link Point} object based on the rectangle's position and dimensions.
     *
     * @return A new {@link Point} object representing the top-right corner of the rectangle.
     */
    private Point getTopRight() {
        return new Point(this.bottomRight.getX(), this.topLeft.getY());
    }

    /**
     * Checks if the given points form a valid rectangle.
     * A rectangle is considered valid if the x-coordinate of the top-left point
     * is less than the x-coordinate of the bottom-right point, and if the
     * y-coordinate of the top-left point is greater than the y-coordinate of the
     * bottom-right point.
     *
     * @param topLeft     The point representing the top-left corner of the rectangle.
     * @param bottomRight The point representing the bottom-right corner of the rectangle.
     * @return {@code true} if the given points form a valid rectangle,
     * {@code false} otherwise.
     */
    private boolean isValidRectangle(Point topLeft, Point bottomRight) {
        return (bottomRight.getX() > topLeft.getX()) && (topLeft.getY() > bottomRight.getY());
    }

}

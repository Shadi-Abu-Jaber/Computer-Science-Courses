public class DimensionRectangle extends AbstractRectangle {
    private Point bottomLeft;
    private double width;
    private double height;

    /**
     * Default constructor that creates a rectangle with the bottom-left point at (0, 0),
     * a width of 1, and a height of 1.
     */
    public DimensionRectangle() {
        this.bottomLeft = new Point(0, 0);
        this.width = 1;
        this.height = 1;
    }

    /**
     * Creates a rectangle with the specified bottom-left point, width, and height.
     * If the width or height is not valid (<= 0) or if the bottom-left point is null,
     * it creates default rectangle, bottom-left point at (0, 0),a width of 1, and a height of 1.
     *
     * @param bottomLeft The point representing the bottom-left corner of the rectangle.
     * @param width      The width of the rectangle.
     * @param height     The height of the rectangle.
     */
    public DimensionRectangle(Point bottomLeft, double width, double height) {
        this();
        if (isValidLength(width) && isValidLength(height) && bottomLeft != null) {
            this.bottomLeft = bottomLeft.copy();
            this.width = width;
            this.height = height;
        }
    }

    /**
     * Gets the width of the rectangle.
     *
     * @return The width of the rectangle.
     */
    @Override
    public double getWidth() {
        return this.width;
    }

    /**
     * Gets the height of the rectangle.
     *
     * @return The height of the rectangle.
     */
    @Override
    public double getHeight() {
        return this.height;
    }

    /**
     * Retrieves the bottom-left point of the rectangle. This method typically creates
     * and returns a new {@link Point} object based on the rectangle's position and dimensions.
     *
     * @return A new {@link Point} object representing the bottom-left corner of the rectangle.
     */
    @Override
    public Point getBottomLeft() {
        return this.bottomLeft.copy();
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
        points[0] = getTopLeft();
        points[1] = getTopRight();
        points[2] = getBottomRight();
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
            this.width = width;
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
            this.height = height;
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
        this.bottomLeft = bottomLeft.copy();
    }

    /**
     * Retrieves the bottom-right point of the rectangle. This method typically creates
     * and returns a new {@link Point} object based on the rectangle's position and dimensions.
     *
     * @return A new {@link Point} object representing the bottom-right corner of the rectangle.
     */
    private Point getBottomRight() {
        double bottomRightY = this.bottomLeft.getY();
        double bottomRightX = this.bottomLeft.getX() + this.width;
        return new Point(bottomRightX, bottomRightY);
    }

    /**
     * Retrieves the top-right point of the rectangle. This method typically creates
     * and returns a new {@link Point} object based on the rectangle's position and dimensions.
     *
     * @return A new {@link Point} object representing the top-right corner of the rectangle.
     */
    private Point getTopRight() {
        double topRightY = this.getBottomRight().getY() + this.height;
        double topRightX = this.getBottomRight().getX();
        return new Point(topRightX, topRightY);
    }

    /**
     * Retrieves the top-left point of the rectangle. This method typically creates
     * and returns a new {@link Point} object based on the rectangle's position and dimensions.
     *
     * @return A new {@link Point} object representing the top-left corner of the rectangle.
     */
    private Point getTopLeft() {
        double topLeftY = this.bottomLeft.getY() + this.height;
        double topLeftX = this.bottomLeft.getX();
        return new Point(topLeftX, topLeftY);
    }

}

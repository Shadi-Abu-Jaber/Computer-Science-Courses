package Lab02;

public class DiagonalMatrix implements Matrix {

    private final double[] matrix;
    private final int matrixSize;
    private boolean transposed = false;

    DiagonalMatrix(int size) {
        if (size <= 0) {
            throw new IllegalArgumentException();
        }
        matrix = new double[(size * 2) - 1];
        matrixSize = size;
    }

    DiagonalMatrix() {
        this(MAX_SIZE);
    }

    @Override
    public double get(int i, int j) {
        return transposed ? matrix[convertIndex(j, i)] : matrix[convertIndex(i, j)];
    }

    @Override
    public void set(int i, int j, double x) {
        if (transposed) {
            matrix[convertIndex(j, i)] = x;
        }
        matrix[convertIndex(i, j)] = x;
    }

    @Override
    public void transpose() {
        transposed = !transposed;
    }

    @Override
    public Matrix getTranspose() {
        DiagonalMatrix transposedMatrix = new DiagonalMatrix(matrixSize);
        copyMatrix(transposedMatrix);
        transposedMatrix.transpose();
        return transposedMatrix;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();
        for (int i = 1; i <= matrixSize; i++) {
            for (int j = 1; j <= matrixSize; j++) {
                if (j == matrixSize) {
                    builder.append(get(i, j)).append("\n");
                } else {
                    builder.append(get(i, j)).append("\t");
                }
            }
        }
        return builder.toString();
    }

    private void copyMatrix(DiagonalMatrix transposedMatrix) {
        for (int i = 0; i < matrix.length; i++) {
            transposedMatrix.matrix[i] = matrix[i];
        }
        transposedMatrix.transposed = this.transposed;
    }

    private int convertIndex(int i, int j) {
        if (isInvalidIndex(i, j)) {
            throw new IndexOutOfBoundsException();
        }
        return (i - j) + (matrixSize - 1);
    }

    public boolean isInvalidIndex(int i, int j) {
        return (1 > i || i > matrixSize) || (1 > j || j > matrixSize);
    }
}

# Exercise Objective

The purpose of this exercise is to understand the difference between the interface of a class and its implementation. 
In this exercise, we will implement two classes that describe a rectangle in the Euclidean space, both having the same
interface but different implementations. Both classes represent a rectangle with one side parallel to the x-axis and theother to the y-axis.
Externally, there is no difference between them: code using these classes can switch between them without any difference in the result. 
However, we will see that the code inside the two classes can be significantly different. Moreover, we will see that the implementation
of some parts of the interface in one class is simpler than in the other, but the implementation of other parts of the interface is easier in the second class.

The interface is provided on the site: we will check that it is possible to switch between implementations without changing the application. Additionally, we will ensure that the behavior of the two classes we create is identical, despite the difference in algorithms.

## Main Classes

### DimensionRectangle
This class represents a rectangle using three fields:
- A field of type `Point` describing the bottom-left vertex.
- A field of type `double` describing the rectangle's width.
- A field of type `double` describing the rectangle's height.

### TwoPointRectangle
This class represents a rectangle using two fields:
- A field of type `Point` describing the top-left vertex.
- A field of type `Point` describing the bottom-right vertex.

Externally, both `DimensionRectangle` and `TwoPointRectangle` present the same interface.

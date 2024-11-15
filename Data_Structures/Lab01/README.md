# Lab 1 Topic: Working with Arrays
Introduction:
An array is a basic data structure that stores data and allows quick access to its elements.
In this lab, we will propose using an array to hold points (with two coordinates).

Objectives:
Implementing lists of points using an array, including operations that allow you to move through this array (Part A).
Using a Java tokenizer to read sequences of characters from the input (Part B).

## Part 1 Description:
We will define an ordered list of points: A point in a plane is characterized by two coordinates: P = (x,y)

The use of coordinates is multi-disciplinary: in computer graphics, computational models for displaying lines, curves, etc.

The interface allows adding points, various queries regarding the state of the structure, and movement within the structure.

For movement within the structure, we will define a cursor

Below is the definition of the PointList interface:

List members:

- Each member will be of type Point (a class defined in the java.awt library that comes with Java) describing a point in the plane with coordinates (x,y).

- List structure In a non-empty list, at any given moment one point will be marked by the cursor.

- You must "walk" through the list and change the cursor position.

Methods:

- The methods are defined and described in the PointList interface

Constructors:

- A default constructor that creates an array of size MAX_SIZE
- A single-parameter constructor that creates an array whose size is the value of the parameter.
 
Lab Requirements – Part A:

Implement the PointList interface in a class named ArrayPointList using an array to store the list of points
Think about an implementation that is as efficient as possible, except for the toString method, the runtime should be O(1).

## Part B Description:
In this part, we will introduce a Java tokenizer used for input parsing.

Lab Requirements – Part 2:
Write a class called PointListCommandLine that supports the following commands:

- add x y: adds a point to the end of the list

- curr: shows the point pointed by the cursor

- next: moves the cursor to the next point, and prints true/false

- prev: moves the cursor to the previous point, and prints true/false

- start: moves the cursor to the beginning of the list, and prints true/false

- end: moves the cursor to the end of the list, and prints true/false

- empty: query: is the list empty?

- full: query: is the list full?

- clear: delete the entire list

- quit: terminate the program

Printing true/false is according to the result of the PointList method you are calling.

This is our solution to Google Hash Code (2018) - Test Round

Our Results:

- Example: 10 pts
- Small: 38 pts
- Medium: 49226 pts
- Big: 893840 pts

Problem Statement:

Pizza

The pizza is represented as a rectangular, 2-dimensional grid of R rows and C columns. The cells within
the grid are referenced using a pair of 0-based coordinates [r, c] , denoting respectively the row and the
column of the cell.
Each cell of the pizza contains either:
● mushroom, represented in the input file as M ; or
● tomato, represented in the input file as T

Slice

A slice of pizza is a rectangular section of the pizza delimited by two rows and two columns, without holes.
The slices we want to cut out must contain at least L cells of each ingredient (that is, at least L cells of
mushroom and at least L cells of tomato) and at most H cells of any kind in total - surprising as it is, there is
such a thing as too much pizza in one slice.
The slices being cut out cannot overlap. The slices being cut do not need to cover the entire pizza.
Goal

The goal is to cut correct slices out of the pizza maximizing the total number of cells in all slices.
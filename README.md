This is our solution to Google Hash Code (2018) - Test Round

Copyright (c) 2018 Jarosław Cierpich & Arkadiusz Kasprzak

Our Results:

- Example: 10 pts (3x5 input)
- Small: 38 pts (6x7 input)
- Medium: 49226 pts (200x250 input)
- Big: 893840 pts (1000x1000 input)

Problem Statement:

Pizza

The pizza is represented as a rectangular, 2-dimensional grid of R rows and C columns. The cells within
the grid are referenced using a pair of 0-based coordinates [r, c] , denoting respectively the row and the
column of the cell.

Each cell of the pizza contains either:

- mushroom, represented in the input file as M ; or
- tomato, represented in the input file as T

Slice

A slice of pizza is a rectangular section of the pizza delimited by two rows and two columns, without holes.
The slices we want to cut out must contain at least L cells of each ingredient (that is, at least L cells of
mushroom and at least L cells of tomato) and at most H cells of any kind in total - surprising as it is, there is
such a thing as too much pizza in one slice.
The slices being cut out cannot overlap. The slices being cut do not need to cover the entire pizza.

Goal

The goal is to cut correct slices out of the pizza maximizing the total number of cells in all slices.

# Graph-Based Route Optimization for Cities in Pakistan

This project implements a graph-based route optimization tool in **C++** using Visual Studio. It processes an adjacency-matrix representation of a weighted graph to compute travel routes between cities in Pakistan. The program provides functionalities for graph manipulation and route calculation.

---

## Features

1. **Graph Manipulation**:
   - Add a new city/node.
   - Add a new edge/road-link between cities.
   - Remove an existing city/node.
   - Remove an existing edge/road-link.

2. **Shortest Path Calculation**:
   - Compute the **shortest path** using **Dijkstra's Algorithm**.
   - Compute the **2nd shortest (alternate) path** using **Yen's Algorithm**.
   - Calculate paths between:
     - A specific city and all other cities.
     - All cities and a specified city.
     - A pair of cities (e.g., Islamabad to Lahore).

3. **Output Options**:
   - Displays paths as a list of cities to be visited.

---

## Directory Structure

```
Sample-Test1
│
├── x64/                        # Build output directory
├── Graph.h                     # Header file for the Graph class
├── pch.cpp                     # Precompiled header implementation file
├── pch.h                       # Precompiled header definition file
├── Read_files.h                # Handles file reading operations
├── Sample-Test1.vcxproj        # Visual Studio project file
├── test.cpp                    # Main program file
├── testcases.cpp               # Contains test cases for validating functionalities
├── GraphData.csv               # Input file containing adjacency matrix of the graph
├── packages.config             # Visual Studio packages configuration
```

---

## Installation & Setup

1. **Prerequisites**:
   - Visual Studio installed on your system.
   - Basic understanding of C++ and graph algorithms.

2. **Steps to Run the Program**:
   - Clone the repository or copy the project folder to your local machine.
   - Open `Sample-Test1.vcxproj` in Visual Studio.
   - Ensure that `GraphData.csv` and `testcases.cpp` are placed in the correct directories.
   - Build and run the project in Visual Studio.

---

## Input Files

1. **GraphData.csv**:
   - Contains an adjacency matrix representing the weighted graph of cities in Pakistan.
   - Rows and columns correspond to cities, and each cell specifies the distance between two cities. A value of `0` indicates no direct road-link.

2. **testcases.cpp**:
   - Includes predefined test cases to verify functionalities, such as shortest path calculations and graph manipulations.

---

## Algorithms Used

1. **Dijkstra's Algorithm**:
   - Used for computing the shortest path between nodes in a graph with non-negative weights.

2. **Yen's Algorithm**:
   - Used for finding the second shortest path between nodes, building upon the results of Dijkstra's Algorithm.

---

## Usage

1. **Graph Initialization**:
   - The graph is initialized using data from `GraphData.csv`.
   - The adjacency matrix is read into memory, and the graph structure is created dynamically.

2. **Testing**:
   - Compile and run the program.
   - Use the test cases in `testcases.cpp` to verify functionality.
   - Interact with the console interface to test graph manipulation and route calculations.

---

Feel free to contribute by opening an issue or submitting a pull request.

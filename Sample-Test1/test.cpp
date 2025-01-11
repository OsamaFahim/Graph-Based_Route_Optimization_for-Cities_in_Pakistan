#include "pch.h"
#include "Graph.h"
#include <gtest/gtest.h>

TEST(Graph, addNodetest) {
    Graph* g = new Graph();
    g->ReadFromFile();//this fuction returns edges and cities in 2d int array. Cities are mapped to int values
    //declared arraycount and V global for ease
    string s1 = "Sialkot:";
    g ->addNode("Sialkot");
    g->printGraph();

    ASSERT_EQ(0, s1.compare(g->printsingleLink("Sialkot")));
}

TEST(Graph, addEdgetest) {
    Graph* g = new Graph();
    g->ReadFromFile();//this fuction returns edges and cities in 2d int array. Cities are mapped to int values
    //declared arraycount and V global for ease
    string s1 = "Karachi: -> Peshawar-> Sukkur";
    g->addEdge("Karachi", "Peshawar", 200);

    ASSERT_EQ(0, s1.compare(g->printsingleLink("Karachi")));
}
//
TEST(Graph, deleteNodetest) 
{
    Graph* g = new Graph();
    g->ReadFromFile();//this fuction returns edges and cities in 2d int array. Cities are mapped to int values
    //declared arraycount and V global for ease
    string s1 = "Multan: -> Jhang-> DG Khan-> Bhawalpur";

    g->deleteNode("Lahore");
    //     g->printGraph();

    ASSERT_EQ(0, s1.compare(g->printsingleLink("Multan")));
}
//
TEST(Graph, deleteEdgetest) {
    Graph* g = new Graph();
    g->ReadFromFile();//this fuction returns edges and cities in 2d int array. Cities are mapped to int values
    //declared arraycount and V global for ease
    string s1 = "Quetta:";
    g->deleteEdge("Quetta", "Khuzdar");


    ASSERT_EQ(0, s1.compare(g->printsingleLink("Quetta")));
}


TEST(Graph, shorterstPathfromOnetoalltest) {
    Graph* g = new Graph();
    g->ReadFromFile();
    g->shortestPathfromOnetoall("Lahore");

    //Print all shortest Path from Lahore to all cities

    //Evaluator will verify your output from terminal

    ASSERT_EQ(0, 0);
}


TEST(Graph, secondshorterstPathfromOnetoalltest) {
    Graph* g = new Graph();
    g->ReadFromFile();
    g->secondshortestPathfromOnetoall("Lahore");

    //Print all shortest Path from Lahore to all cities

    //Evaluator will verify your output from terminal

    ASSERT_EQ(0, 0);
}


TEST(Graph, shorterstPathfromalltoonetest) {
    Graph* g = new Graph();
    g->ReadFromFile();
    g->shortestPathfromalltoone("Lahore");

    //Print all shortest Path from  all cities to Lahore

    //Evaluator will verify your output from terminal

    ASSERT_EQ(0, 0);
}


TEST(Graph, secondshorterstPathfromalltoonetest) {
    Graph* g = new Graph();
    g->ReadFromFile();
    g->secondshortestPathfromalltoone("Lahore");

    //Print all shortest Path from  all cities to Lahore

    //Evaluator will verify your output from terminal

    ASSERT_EQ(0, 0);
}


TEST(Graph, ShortestRoutefrompairtest) {
    Graph* g = new Graph();
    g->ReadFromFile();//this fuction returns edges and cities in 2d int array. Cities are mapped to int values
    //declared arraycount and V global for ease
    string s1 = "Mansehra-> Murree-> Islamabad";
    string s2 = g->ShortestRoutefrompair("Mansehra", "Islamabad");

    ASSERT_EQ(0, s1.compare(s2));
}


TEST(Graph, secondShortestRoutefrompairtest) {
    Graph* g = new Graph();
    g->ReadFromFile();//this fuction returns edges and cities in 2d int array. Cities are mapped to int values
    //declared arraycount and V global for ease
    string s1 = "Mansehra-> Hassan Abdal-> Islamabad";
    string s2 = g->secondShortestRoutefrompair("Mansehra", "Islamabad");
    ASSERT_EQ(0, s1.compare(s2));
}

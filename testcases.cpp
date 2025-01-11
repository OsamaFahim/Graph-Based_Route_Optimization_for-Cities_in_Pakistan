#include "Graph.cpp"
#include <gtest/gtest.h>

TEST(Graph, addNodetest){
    Graph *g;
    arr=ReadFromFile();//this fuction returns edges and cities in 2d int array. Cities are mapped to int values
    //declared arraycount and V global for ease
    string s1="Sialkot:";
    g=addNode("Sialkot");
    g->printGraph();

    ASSERT_EQ(0, s1.compare(g->printsingleLink("Sialkot")));
}

TEST(Graph, addEdgetest){
    Graph *g;
    arr=ReadFromFile();//this fuction returns edges and cities in 2d int array. Cities are mapped to int values
    //declared arraycount and V global for ease
    string s1="Karachi: -> Sukkur-> Peshawar";
    g=addEdge("Karachi","Peshawar",200);

    ASSERT_EQ(0, s1.compare(g->printsingleLink("Karachi")));
}

TEST(Graph, deleteNodetest){
    Graph *g;
    arr=ReadFromFile();//this fuction returns edges and cities in 2d int array. Cities are mapped to int values
    //declared arraycount and V global for ease
    string s1="Multan: -> Jhang-> DG Khan-> Bahwalpur";
    g=deleteNode("Lahore");
//     g->printGraph();

    ASSERT_EQ(0, s1.compare(g->printsingleLink("Multan")));
}

TEST(Graph, deleteEdgetest){
    Graph *g;
    arr=ReadFromFile();//this fuction returns edges and cities in 2d int array. Cities are mapped to int values
    //declared arraycount and V global for ease
    string s1="Quetta:";
    g=deleteEdge("Quetta","Khuzdar");


    ASSERT_EQ(0, s1.compare(g->printsingleLink("Quetta")));
}

TEST(Graph, shorterstPathfromOnetoalltest){
    Graph *g;
    arr=ReadFromFile();
    shortestPathfromOnetoall("Lahore");

    //Print all shortest Path from Lahore to all cities

    //Evaluator will verify your output from terminal

    ASSERT_EQ(0, 0);
}


TEST(Graph, secondshorterstPathfromOnetoalltest){
    Graph *g;
    arr=ReadFromFile();
    secondshortestPathfromOnetoall("Lahore");

    //Print all shortest Path from Lahore to all cities

    //Evaluator will verify your output from terminal

    ASSERT_EQ(0, 0);
}


TEST(Graph, shorterstPathfromalltoonetest){
    Graph *g;
    arr=ReadFromFile();
    shortestPathfromalltoone("Lahore");

    //Print all shortest Path from  all cities to Lahore

    //Evaluator will verify your output from terminal

    ASSERT_EQ(0, 0);
}


TEST(Graph, secondshorterstPathfromalltoonetest){
    Graph *g;
    arr=ReadFromFile();
    secondshortestPathfromalltoone("Lahore");

    //Print all shortest Path from  all cities to Lahore

    //Evaluator will verify your output from terminal

    ASSERT_EQ(0, 0);
}


TEST(Graph, ShortestRoutefrompairtest){
    Graph *g;
    arr=ReadFromFile();//this fuction returns edges and cities in 2d int array. Cities are mapped to int values
    //declared arraycount and V global for ease
    string s1="Mansehra-> Murree-> Islamabad";
    string s2=ShortestRoutefrompair("Mansehra","Islamabad");

    ASSERT_EQ(0, s1.compare(s2));
}





TEST(Graph, secondShortestRoutefrompairtest){
    Graph *g;
    arr=ReadFromFile();//this fuction returns edges and cities in 2d int array. Cities are mapped to int values
    //declared arraycount and V global for ease
    string s1="Mansehra-> Hassan Abdal-> Islamabad";
    string s2=secondShortestRoutefrompair("Mansehra","Islamabad");

    ASSERT_EQ(0, s1.compare(s2));
}


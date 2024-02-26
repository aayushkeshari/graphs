// Author: Aayush Keshari
// Email: kesharah@mail.uc.edu
// M Number: M15039880
// -----------------------------------------------------------------------------------------------------
// Lab10 - Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
// -----------------------------------------------------------------------------------------------------

// main.cpp
#include <iostream>
#include "Graphs.h"

int main()
{
    Graphs newGraph(1000, false);

    int choice;
    do
    {
        std::cout << "Press 1 to add a vertex to the graph.\n"
            << "Press 2 to remove a vertex from the graph.\n"
            << "Press 3 to add an edge to the graph.\n"
            << "Press 4 to remove an edge from the graph.\n"
            << "Press 5 to find an edge in the graph.\n"
            << "Press 6 to find the out edges of a vertex.\n"
            << "Press 7 to find the in edges of a vertex.\n"
            << "Press 8 to perform depth-first search.\n"
            << "Press 9 to quit.\n";

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int vertex;
            std::cout << "Enter the vertex to add: ";
            std::cin >> vertex;
            newGraph.addVertex(vertex);
            break;
        }
        case 2:
        {
            int vertex;
            std::cout << "Enter the vertex to remove: ";
            std::cin >> vertex;
            newGraph.removeVertex(vertex);
            break;
        }
        case 3:
        {
            int outVertex, inVertex;
            std::cout << "Enter the outVertex and inVertex to add an edge: ";
            std::cin >> outVertex >> inVertex;
            newGraph.addEdge(outVertex, inVertex);
            break;
        }
        case 4:
        {
            int outVertex, inVertex;
            std::cout << "Enter the outVertex and inVertex to remove an edge: ";
            std::cin >> outVertex >> inVertex;
            newGraph.removeEdge(outVertex, inVertex);
            break;
        }
        case 5:
        {
            int outVertex, inVertex;
            std::cout << "Enter the outVertex and inVertex to check if the edge exists: ";
            std::cin >> outVertex >> inVertex;
            if (newGraph.hasEdge(outVertex, inVertex))
                std::cout << "Edge exists.\n";
            else
                std::cout << "Edge does not exist.\n";
            break;
        }
        case 6:
        {
            int vertex;
            std::cout << "Enter the vertex to find out edges: ";
            std::cin >> vertex;
            std::vector<int> outEdges = newGraph.outEdges(vertex);
            std::cout << "Out edges of vertex " << vertex << ": ";
            for (int v : outEdges)
                std::cout << v << " ";
            std::cout << std::endl;
            break;
        }
        case 7:
        {
            int vertex;
            std::cout << "Enter the vertex to find in edges: ";
            std::cin >> vertex;
            std::vector<int> inEdges = newGraph.inEdges(vertex);
            std::cout << "In edges of vertex " << vertex << ": ";
            for (int v : inEdges)
                std::cout << v << " ";
            std::cout << std::endl;
            break;
        }
        case 8:
        {
            int startVertex;
            std::cout << "Enter the starting vertex for depth-first search: ";
            std::cin >> startVertex;
            std::vector<bool> visited(newGraph.numVertices, false);
            newGraph.depthFirstSearch(startVertex, visited);
            break;
        }
        case 9:
            std::cout << "The program is being exited.\n";
            break;
        default:
            std::cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 9);

    return 0;
}

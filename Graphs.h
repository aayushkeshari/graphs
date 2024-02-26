// Author: Aayush Keshari
// Email: kesharah@mail.uc.edu
// M Number: M15039880
// -----------------------------------------------------------------------------------------------------
// Graphs.h : This file contains the header class for the Graphs.cpp program.
// -----------------------------------------------------------------------------------------------------

// Graphs.h
#pragma once
#include <iostream>
#include <vector>

struct nodePT
{
    int vertex;
    nodePT* next;
};

class Graphs
{
private:
    bool undirected;
    nodePT** adjLists; // array of linked list

    // Helper function for depth-first search
    void depthFirstSearchHelper(int vertex, std::vector<bool>& visited);

public:
    int numVertices;

    // constructor
    Graphs(int maxsize, bool ifUndirected);

    // destructor
    ~Graphs();

    // addVertex function
    void addVertex(int vertexId);

    // removeVertex function
    void removeVertex(int vertexId);

    // addEdge function
    void addEdge(int outVertex, int inVertex);

    // removeEdge function
    void removeEdge(int outVertex, int inVertex);

    // hasEdge function
    bool hasEdge(int outVertex, int inVertex);

    // outEdges function
    std::vector<int> outEdges(int vertexId);

    // inEdges function
    std::vector<int> inEdges(int vertexId);

    // depthFirstSearch function
    void depthFirstSearch(int startVertex, std::vector<bool>& visited);

    // Getter for numVertices
    int getNumVertices() const;

    // show function that display linked lists
    void Show();
};

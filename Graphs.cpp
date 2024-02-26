// Author: Aayush Keshari
// Email: kesharah@mail.uc.edu
// M Number: M15039880
// -----------------------------------------------------------------------------------------------------
// Graphs.cpp : This file contains all functions implemented in the project.
// -----------------------------------------------------------------------------------------------------

// Graphs.cpp
#include "Graphs.h"

// constructor
Graphs::Graphs(int maxsize, bool ifUndirected)
{
    undirected = ifUndirected;
    numVertices = 0;
    adjLists = new nodePT * [maxsize];
}

// destructor
Graphs::~Graphs()
{
    for (int i = 0; i < numVertices; ++i)
    {
        nodePT* current = adjLists[i];
        while (current != nullptr)
        {
            nodePT* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] adjLists;
}

// addVertex function
void Graphs::addVertex(int vertexId)
{
    nodePT* newNode = new nodePT;
    newNode->vertex = vertexId;
    newNode->next = nullptr;
    adjLists[numVertices] = newNode;
    numVertices++;
}

// removeVertex function
void Graphs::removeVertex(int vertexId)
{
    for (int i = 0; i < numVertices; ++i)
    {
        if (adjLists[i]->vertex == vertexId)
        {
            // Remove all edges going to or coming from the vertex
            for (int j = 0; j < numVertices; ++j)
            {
                if (i != j)
                {
                    removeEdge(adjLists[j]->vertex, vertexId);
                    removeEdge(vertexId, adjLists[j]->vertex);
                }
            }

            // Delete the vertex
            delete adjLists[i];
            for (int k = i; k < numVertices - 1; ++k)
            {
                adjLists[k] = adjLists[k + 1];
            }
            numVertices--;

            break; // Vertex found and removed, exit the loop
        }
    }
}

// addEdge function
void Graphs::addEdge(int outVertex, int inVertex)
{
    nodePT* newNode = new nodePT;
    newNode->vertex = inVertex;
    newNode->next = nullptr;

    for (int i = 0; i < numVertices; ++i)
    {
        if (adjLists[i]->vertex == outVertex)
        {
            nodePT* nodePtr = adjLists[i];

            while (nodePtr->next)
                nodePtr = nodePtr->next;

            nodePtr->next = newNode;

            if (undirected)
            {
                // If undirected, add the reverse edge as well
                nodePT* reverseNode = new nodePT;
                reverseNode->vertex = outVertex;
                reverseNode->next = nullptr;

                nodePtr = adjLists[i];

                while (nodePtr->next)
                    nodePtr = nodePtr->next;

                nodePtr->next = reverseNode;
            }

            break;
        }
    }
}

// removeEdge function
void Graphs::removeEdge(int outVertex, int inVertex)
{
    for (int i = 0; i < numVertices; ++i)
    {
        if (adjLists[i]->vertex == outVertex)
        {
            nodePT* nodePtr = adjLists[i];
            nodePT* prevNode = nullptr;

            while (nodePtr != nullptr)
            {
                if (nodePtr->vertex == inVertex)
                {
                    // Remove the edge
                    if (prevNode == nullptr)
                    {
                        adjLists[i] = nodePtr->next;
                    }
                    else
                    {
                        prevNode->next = nodePtr->next;
                    }

                    delete nodePtr;
                    break;
                }

                prevNode = nodePtr;
                nodePtr = nodePtr->next;
            }

            if (undirected)
            {
                // If undirected, remove the reverse edge as well
                removeEdge(inVertex, outVertex);
            }

            break;
        }
    }
}

// hasEdge function
bool Graphs::hasEdge(int outVertex, int inVertex)
{
    for (int i = 0; i < numVertices; ++i)
    {
        if (adjLists[i]->vertex == outVertex)
        {
            nodePT* nodePtr = adjLists[i];

            while (nodePtr != nullptr)
            {
                if (nodePtr->vertex == inVertex)
                {
                    return true;
                }

                nodePtr = nodePtr->next;
            }
            break;
        }
    }

    return false;
}

// outEdges function
std::vector<int> Graphs::outEdges(int vertexId)
{
    std::vector<int> outEdgesList;

    for (int i = 0; i < numVertices; ++i)
    {
        if (adjLists[i]->vertex == vertexId)
        {
            nodePT* nodePtr = adjLists[i]->next;

            while (nodePtr != nullptr)
            {
                outEdgesList.push_back(nodePtr->vertex);
                nodePtr = nodePtr->next;
            }
            break;
        }
    }

    return outEdgesList;
}

// inEdges function
std::vector<int> Graphs::inEdges(int vertexId)
{
    std::vector<int> inEdgesList;

    for (int i = 0; i < numVertices; ++i)
    {
        nodePT* nodePtr = adjLists[i]->next;

        while (nodePtr != nullptr)
        {
            if (nodePtr->vertex == vertexId)
            {
                inEdgesList.push_back(adjLists[i]->vertex);
            }

            nodePtr = nodePtr->next;
        }
    }

    return inEdgesList;
}

// depthFirstSearch function
void Graphs::depthFirstSearch(int startVertex, std::vector<bool>& visited)
{
    std::cout << "DFS starting from vertex " << startVertex << ": ";

    // Mark all vertices as not visited
    visited.assign(this->getNumVertices(), false);

    // Call the recursive helper function
    depthFirstSearchHelper(startVertex, visited);

    std::cout << std::endl;
}

// Helper function for depthFirstSearch
void Graphs::depthFirstSearchHelper(int vertex, std::vector<bool>& visited)
{
    // Mark the current vertex as visited
    visited[vertex] = true;

    // Print the current vertex
    std::cout << vertex << " ";

    // Recur for all the vertices adjacent to this vertex
    nodePT* nodePtr = adjLists[vertex]->next;
    while (nodePtr != nullptr)
    {
        if (!visited[nodePtr->vertex])
        {
            depthFirstSearchHelper(nodePtr->vertex, visited);
        }
        nodePtr = nodePtr->next;
    }
}

// Getter for numVertices
int Graphs::getNumVertices() const
{
    return numVertices;
}

// show function
void Graphs::Show()
{
    for (int i = 0; i < numVertices; i++)
    {
        nodePT* nodePtr = adjLists[i];
        std::cout << "Vertex " << nodePtr->vertex << " is adjacent to: ";

        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
            std::cout << nodePtr->vertex << " ";
        }

        std::cout << '\n';
    }
}

// SubwayBFSImplementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Terrance W

#include <iostream>
#include <iterator>
#include <queue>
#include <stack>
#include <array>

using namespace std;

class Graph {
private:
    int v;                              // number of vertices
    int e;                              // number of edges
    int** adj;                          // matrix
public:
    Graph(int v, int e) {           // fills in adj matrix; default edges is 0
        this->v = v;
        this->e = e;
        adj = new int* [v];
        for (int row = 0; row < v; row++) {
            adj[row] = new int[v];
            for (int column = 0; column < v; column++) {
                adj[row][column] = 0;
            }
        }
    }
    void addEdge(int start, int end) {   // indicates where edge has been created between two vertices
        adj[start][end] = 1;
        adj[end][start] = 1;
    }
    void displayAdj() {
        int i, j;
        for (i = 0; i < v; i++) {
            for (j = 0; j < v; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    // BFS function should find the shortest route from start to end and display the route in order. 
    void BFS(int startNode, int endNode) {
        int distance = 0;
        queue<int> nodeList;
        int parentList[90];
        bool visited[90] = { false };
        int dis[90] = { 0 };
        int currentNode;
        int w;
        visited[startNode] = true;
        dis[startNode] = 0;
        nodeList.push(startNode);
        cout << "To reach Station " << endNode << " take the following Stations: " << endl;
        while (!nodeList.empty()) {
            int currentNode = nodeList.front();
            nodeList.pop();
            if (currentNode == endNode) {
                queue<int> revPath;
                stack<int> path;
                parentList[w] = currentNode;
                int cameFrom = parentList[endNode];
                revPath.push(cameFrom);
                while (cameFrom != startNode) {
                    cameFrom = parentList[cameFrom];
                    revPath.push(cameFrom);
                }
                while (!revPath.empty()) {
                    path.push(revPath.front());
                    revPath.pop();
                }
                while (!path.empty()) {
                    revPath.push(path.top());
                    cout << path.top() << " ";
                    path.pop();
                }
                cout << endl;
                cout << "distance: " << dis[endNode] << endl;
            }
            for (w = 0; w <= v; w++) {
                if (adj[currentNode][w] == 1 && visited[w] == false) {
                    visited[w] = true;
                    parentList[w] = currentNode;
                    nodeList.push(w);
                    dis[w] = dis[currentNode] + 1;
                    distance = dis[endNode];
                }
            }
        }
    }
};
int main() {
    // Initialize start and end variables
    int start;
    int end;
    //Creating HK Sub-System
    Graph HK(90, 90);
    // Connect the vertices
    HK.addEdge(0, 1);
    HK.addEdge(0, 2);
    HK.addEdge(2, 3);
    HK.addEdge(3, 4);
    HK.addEdge(4, 5);
    HK.addEdge(5, 6);
    HK.addEdge(6, 7);
    HK.addEdge(7, 8);
    HK.addEdge(7, 19);
    HK.addEdge(8, 9);
    HK.addEdge(9, 10);
    HK.addEdge(10, 11);
    HK.addEdge(11, 12);
    HK.addEdge(12, 13);
    HK.addEdge(13, 14);
    HK.addEdge(14, 15);
    HK.addEdge(15, 16);
    HK.addEdge(48, 49);
    HK.addEdge(49, 50);
    HK.addEdge(50, 51);
    HK.addEdge(51, 0);
    HK.addEdge(2, 52);
    HK.addEdge(52, 53);
    HK.addEdge(53, 54);
    HK.addEdge(54, 55);
    HK.addEdge(55, 56);
    HK.addEdge(56, 57);
    HK.addEdge(57, 58);
    HK.addEdge(58, 59);
    HK.addEdge(59, 60);
    HK.addEdge(60, 61);
    HK.addEdge(61, 62);
    HK.addEdge(57, 29);
    HK.addEdge(29, 30);
    HK.addEdge(30, 63);
    HK.addEdge(63, 64);
    HK.addEdge(64, 65);
    HK.addEdge(2, 66);
    HK.addEdge(66, 67);
    HK.addEdge(67, 68);
    HK.addEdge(68, 69);
    HK.addEdge(28, 29);
    HK.addEdge(28, 27);
    HK.addEdge(27, 26);
    HK.addEdge(26, 25);
    HK.addEdge(25, 24);
    HK.addEdge(24, 23);
    HK.addEdge(23, 22);
    HK.addEdge(22, 21);
    HK.addEdge(21, 20);
    HK.addEdge(20, 19);
    HK.addEdge(5, 18);
    HK.addEdge(18, 17);
    HK.addEdge(20, 32);
    HK.addEdge(32, 31);
    HK.addEdge(20, 33);
    HK.addEdge(33, 34);
    HK.addEdge(34, 35);
    HK.addEdge(35, 36);
    HK.addEdge(36, 37);
    HK.addEdge(37, 38);
    HK.addEdge(38, 39);
    HK.addEdge(39, 40);
    HK.addEdge(40, 41);
    HK.addEdge(33, 82);
    HK.addEdge(82, 83);
    HK.addEdge(83, 84);
    HK.addEdge(84, 85);
    HK.addEdge(85, 86);
    HK.addEdge(86, 87);
    HK.addEdge(87, 88);
    HK.addEdge(88, 89);
    HK.addEdge(31, 70);
    HK.addEdge(70, 3);
    HK.addEdge(70, 71);
    HK.addEdge(71, 42);
    HK.addEdge(71, 44);
    HK.addEdge(44, 11);
    HK.addEdge(11, 72);
    HK.addEdge(72, 73);
    HK.addEdge(73, 74);
    HK.addEdge(74, 75);
    HK.addEdge(75, 76);
    HK.addEdge(76, 77);
    HK.addEdge(77, 78);
    HK.addEdge(44, 12);
    HK.addEdge(12, 45);
    HK.addEdge(45, 46);
    HK.addEdge(46, 47);
    HK.addEdge(46, 79);
    HK.addEdge(45, 80);
    HK.addEdge(80, 81);
    HK.addEdge(1, 42);
    HK.addEdge(42, 43);
    HK.addEdge(43, 44);
    HK.addEdge(3, 70);
    HK.addEdge(42, 71);
    // Interface to recieve start and end variables
    cout << "Please Enter Your Current Station Number: " << endl;
    cin >> start;
    cout << "Please Enter The Station Number of Your Destination: " << endl;
    cin >> end;
    // Calling BFS function and displaying the route from start to finish
    HK.BFS(start, end);

}

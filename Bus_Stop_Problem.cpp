#include <bits/stdc++.h>
using namespace std;
#define V 5 //We are taking 5 stops here
int BusStopsProblem(int graph[][V], int s)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);
 
    int min_path = INT_MAX;
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
 
        // update minimum
        min_path = min(min_path, current_pathweight);
 
    } while (
        next_permutation(vertex.begin(), vertex.end()));
 
    return min_path;
}
int main()
{
    // The example Used here is same as we used for research and solved in our Latex File
    int graph[][V] = { { 0, 10, 15, 30, 30},
                       { 10, 0, 20, 5, 25},
                       { 15, 20, 0, 25, 5},
                       { 30, 5, 25, 0, 20},
                       { 30, 25, 5, 25,0}};
    int s = 0;
    cout <<"The Minimum Distance is "<< BusStopsProblem(graph, s) << endl;
    return 0;
}
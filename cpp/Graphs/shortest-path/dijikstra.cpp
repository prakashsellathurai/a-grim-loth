/**
 * @file dijikstra.cpp
 * @author prakash (prakashsellathurai@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-07-20
 *
 * @copyright Copyright (c) 2021
 *

 ShortestPath-Dijkstra(G, s, t)
    known = {s}
    for each vertex v in G, dist[v] = ∞
        dist[s]=0
    for each edge (s, v), dist[v] = w(s, v)
        last = s
        while (last = t)
            select vnext, the unknown vertex minimizing dist[v]
            for each edge (vnext, x), dist[x] = min[dist[x], dist[vnext] + w(vnext, x)]
            last = vnext
            known = known ∪ {vnext}
 */


 #include <iostream>
 using namespace std;
 
 
 int main(int argc, const char** argv) {
     /*code here*/
     return 0;
 }

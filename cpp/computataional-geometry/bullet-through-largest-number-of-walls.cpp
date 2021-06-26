/*
 * Let P be a simple, but not necessarily convex, polygon, and q
 * an arbitrary point not necessarily in P. Design an efficient
 * algorithm to find a line segment originating from q that
 * intersects the maximum number of edges of P.
 * 
 * In other words, if standing at a point q, in what direction
 * should you aim a gun so the bullet will go through the largest
 * number of walls? A bullet through a vertex of P gets credit
 * for only one wall.
 */

#include <iostream>
#include <cmath>
#include <map>
#include <set>

using namespace std;

/*
 * points are (x, y) on Cartesian plane
 */
struct point
{
    double x, y;

    point(double X, double Y)
        : x(X), y(Y)
    {
    }

    // [0, 2*M_PI) counterclockwise, 0 is horizontal right
    double ang_to(const point &other) const
    {
        double a = atan2(other.y - y, other.x - x);
        return a < 0 ? a + 2*M_PI : a;
    }
};

/*
 * index pair represents segment from point with index
 * i to that with j
 */
struct index_pair
{
    int i, j;

    index_pair(int I, int J)
        : i(I), j(J)
    {
    }

    // comparision to allow putting in set - does a lexicographical
    // compare, i first
    bool operator <(const index_pair &other) const
    {
        if (i < other.i)
            return true;
        if (i > other.i)
            return false;
        return j < other.j;
    }
};

int max_depth(const map<double, int> &points)
{
    int max = 1;

    // stores current segments
    set<index_pair> cur;

    // starting point, add only forward segment
    map<double, int>::const_iterator p = points.begin();
    int i = p->second;
    cur.insert(index_pair(i, i + 1));

    // go through each point in angle order
    for (++p; p != points.end(); ++p)
    {
        i = p->second;
        set<index_pair>::iterator iter;

        // add/remove segments
        index_pair prev(i - 1, i);
        if ((iter = cur.find(prev)) == cur.end())
            cur.insert(prev);
        else
            cur.erase(iter);

        index_pair next(i, i + 1);
        if ((iter = cur.find(next)) == cur.end())
            cur.insert(next);
        else
            cur.erase(iter);

        // keep track of max depth
        int depth = cur.size();
        if (depth > max)
            max = depth;
    }

    return max;
}

int main(int argc, char **argv)
{
    // read in q
    double qx, qy;
    cin >> qx >> qy;
    point q(qx, qy);

    // read in other points, making an angle -> index map
    map<double, int> points;
    for (int i = 0; !cin.eof(); ++i)
    {
        double x, y;
        cin >> x >> y;
        point p(x, y);
        points.insert(make_pair(q.ang_to(p), i));
    }

    // print out max depth
    cout << "max depth: " << max_depth(points) << endl;

    return 0;
}
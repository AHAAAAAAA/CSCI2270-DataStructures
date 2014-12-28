#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cassert>
#include <deque>
#include <vector>
#include <map>
#include "graph.h"
using namespace std;

// default constructor at work here; pretty cute!
graph::graph()
{
}	

// destructor is easy, we just clear our vertex vector and our edge map
graph::~graph()
{
	vertices.clear();
	edges.clear();
}	

// add a vertex to the graph by adding it to the vector
void graph::add_vertex(const vertex& v) 
{
	vertices.push_back(v);
}

// add an edge to the graph as long as it's under the distance limit
void graph::add_edge(vertex* v, vertex* u, double limit)
{
	double dist = great_circle_distance(*v, *u);
	if (dist <= limit)
	{
		edges[v].push_back(u);
	}
}

// compute distance from one lat/long to another as the crow flies
double graph::great_circle_distance(const vertex& v, const vertex& u) const
{
	double PI = 3.1415926535897932;
	double lat1, lat2, long1, long2, dist;

	lat1 = ((double) v.get_latitude_degrees()) + (((double) v.get_latitude_minutes()) / 60.0);
	lat1 *= PI/180.0;
	long1 = ((double) v.get_longitude_degrees()) + (((double) v.get_longitude_minutes()) / 60.0);
	long1 *= PI/180.0;
	lat2 = ((double) u.get_latitude_degrees()) + (((double) u.get_latitude_minutes()) / 60.0);
	lat2 *= PI/180.0;
	long2 = ((double) u.get_longitude_degrees()) + (((double) u.get_longitude_minutes()) / 60.0);
	long2 *= PI/180.0;

	// from http://www.meridianworlddata.com/Distance-Calculation.asp
	// result in km
	dist = 6378.7 * acos((sin(lat1) * sin(lat2)) + (cos(lat1) * cos(lat2) * cos(long2 - long1)));

	return dist;
}

// check whether a path exists via depth first search.
bool graph::does_dfs_path_exist(const string& city1, const string& city2)
{
	deque<vertex*> yet_to_explore;
	map<vertex*, bool> visited;
	map<vertex*, vertex*> path;
	vertex* v;
	vertex* u;
	
	// initialize your variables for the depth first search here
	
	for (unsigned int i=0;i<vertices.size();i++)
	{
		//locating the cities in the array
		if (vertices[i].get_city_name() ==city1)
			v= &vertices[i];
		if (vertices[i].get_city_name()==city2)
			u= &vertices[i];
		//setting everything to false
		visited.insert(pair<vertex*,bool> (&vertices[i],false));
		path.insert(pair<vertex*,vertex*> (&vertices[i],nullptr));
	}
	visited[v]=true;
	yet_to_explore.push_back(v);
	
	//testing DFS
	cout << "DEPTH FIRST" << endl;
	if (depth_first_search(u, visited, yet_to_explore, path))
	{
		cout << "path exists! between " << v->get_city_name() << " and " << u->get_city_name() << endl;

		// now, use the path map to print the path we took
		vertex* node = u;
		cout << u->get_city_name() << endl;
		size_t length = 0;
		while (path.find(node) != path.end() && path[node] != nullptr)
		{
			++length;
			vertex* ancestor = path[node];
			cout << ancestor->get_city_name() << endl;
			node = ancestor;
		}
		cout << "Path length (in hops): " << length << endl;
		
		return true;
	}
	// if it fails, we admit there is no path
	else
	{
		cout << "no path exists! between " << v->get_city_name() << " and " << u->get_city_name() << endl;
		return false;
	}
}

// check whether a path exists via breadth first search.
bool graph::does_bfs_path_exist(const string& city1, const string& city2)
{
	deque<vertex*> yet_to_explore;
	map<vertex*, bool> visited;
	map<vertex*, vertex*> path;
	vertex* v;
	vertex* u;
	// initialize your variables for the breadth first search here
	for (unsigned int i=0;i<vertices.size();i++)
	{
		//locating the cities in the array
		if (vertices[i].get_city_name() ==city1)
			v= &vertices[i];
		if (vertices[i].get_city_name()==city2)
			u= &vertices[i];
		//setting everything to false
		visited.insert(pair<vertex*,bool> (&vertices[i],false));
		path.insert(pair<vertex*,vertex*> (&vertices[i],nullptr));
	}
	visited[v]=true;
	yet_to_explore.push_front(v);

	// test BFS
	cout << "BREADTH FIRST" << endl;
	if (breadth_first_search(u, visited, yet_to_explore, path))
	{
		cout << "path exists! between " << v->get_city_name() << " and " << u->get_city_name() << endl;

			// now, use the path map to print the path we took
		vertex* node = u;
		cout << u->get_city_name() << endl;
		size_t length= 0;
		while (path.find(node) != path.end() && path[node] != nullptr)
		{
			vertex* ancestor = path[node];
			cout << ancestor->get_city_name() << endl;
			node = ancestor;
			++length;
		}
		cout << "Path length (in hops): " << length << endl;
		return true;
	   
	}
	// if it fails, we admit there is no path
	else
	{
		cout << "no path exists! between " << v->get_city_name() << " and " << u->get_city_name() << endl;
		return false;
	}
}


bool graph::depth_first_search(vertex* u, map<vertex*, bool>& visited, deque<vertex *>& yet_to_explore, map<vertex*, vertex*>& path)
{
	if (!yet_to_explore.empty())
	{
		vertex* a = yet_to_explore.back();
		yet_to_explore.pop_back();
		vector<vertex*>::iterator forward;
		vertex* nexter;
		if (u->get_city_name() == a->get_city_name())
		{
			return true;
		}
		for (forward=edges[a].begin(); forward != edges[a].end(); forward++)
		{
			nexter=*forward;
			if (visited[nexter]==false)
			{
				yet_to_explore.push_back(nexter);
				visited[nexter]=true;
				path[nexter]=a;
			}
		}
		
		return depth_first_search(u, visited, yet_to_explore,path);
	}
	return false;
}

bool graph::breadth_first_search(vertex* u, map<vertex*, bool>& visited, deque<vertex*>& yet_to_explore, map<vertex*, vertex*>& path)
{
	if (!yet_to_explore.empty())
	{
		vertex* a = yet_to_explore.front();
		yet_to_explore.pop_front();
		vector<vertex*>::iterator forward;
		vertex* nexter;
		if (u->get_city_name() == a->get_city_name())
			return true;
		for (forward=edges[a].begin(); forward != edges[a].end(); forward++)
		{
			nexter=*forward;
			if (visited[nexter]==false)
			{
				yet_to_explore.push_back(nexter);
				visited[nexter]=true;
				path[nexter]=a;
			}
		}
		
		return breadth_first_search(u, visited, yet_to_explore, path);
	}
	return false;
}
	
// read in 120 cities and their latitude/longitude
// cities within limit km of each other are connected by edges
void init_graph_from_file(graph& g, const string& filename, double limit)
{
	string line;
	string city_name;
	int lat1, lat2, long1, long2;
	ifstream file_to_read;
	string part_string;
	char compass_dir;

	// open the data file of cities
	open_for_read(file_to_read, filename.c_str());
	size_t count = 0;
	// keep reading until all cities have been added
	while (is_more_stuff_there(file_to_read) && count < 120)
	{
		string city_name = "";
		// build the city name from the file
		do
		{
			file_to_read >> part_string;
			city_name += part_string + ' ';
		} while (city_name[city_name.length() - 2] != ':');
		city_name = city_name.substr(0, city_name.length() - 2);

		// grab latitude coordinates
		file_to_read >> lat1 >> lat2 >> compass_dir;
		// southern coordinates are negative
		if (compass_dir == 'S')
		{
			lat1 *= -1;
			lat2 *= -1;
		}
		// and grab longitude coordinates
		file_to_read >> long1 >> long2 >> compass_dir;
		// western coordinates are negative
		if (compass_dir == 'W')
		{
			long1 *= -1;
			long2 *= -1;
		}
		// create a city vertex in the graph from the data you read
		vertex city(city_name, lat1, lat2, long1, long2);
		g.add_vertex(city);
		++count;
	}

	// now we are done with our file
	file_to_read.close();

	// now we compute the edges that are within the allowed distance
	vector<vertex>::iterator it1, it2;
	for (it1 = g.vertices.begin(); it1 != g.vertices.end(); ++it1)
	{
		for (it2 = g.vertices.begin(); it2 != g.vertices.end(); ++it2)
		{
			if (it1 != it2)
			{
				g.add_edge(&*it1, &*it2, limit);
			}
		}
	}
}

// function defined by Michael Main for input data
void open_for_read(ifstream& f, string filename)
{
	f.open(filename);
	if (f.fail())
	{
		cerr << "Could not open input file." << endl;
		exit(0);
	}
}

// function defined by Michael Main for input data
bool is_more_stuff_there(ifstream& f)
{
		return (f && (f.peek() != EOF));
}

//#endif




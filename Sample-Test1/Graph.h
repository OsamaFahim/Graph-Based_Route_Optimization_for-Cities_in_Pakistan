#pragma once
#include"Read_files.h"
#include<iostream>

using namespace std;


template<class T>
struct node
{
	T val = {};
	node* next = nullptr;

	node(T _city_name = {})
	{
		val = _city_name;
		next = nullptr;
	}
};

struct cities_list
{
	node<string>* head = nullptr;
	node<string>* tail = nullptr;

	cities_list()
	{
		head = tail = nullptr;
	}

	void insert(string city)
	{
		if (!head && !tail)
		{
			head = new node<string>(city);
			tail = head;
		}
		else
		{
			tail->next = new node<string>(city);
			tail = tail->next;
		}
	}

	void remove(string city)
	{
		node<string>* iter = head;
		node<string>* prev = iter;

		while (iter && iter->val != city)
			prev = iter , iter = iter->next;

		if (iter && iter == head)
			head = head->next;
		else if (iter)
		{
			node<string>* deleted_node = iter;
			prev->next = prev->next->next;
			delete deleted_node;
			deleted_node = nullptr;
		}
	}

	int get_index(string city)
	{
		node<string>* iter = head;
		int index = 0;

		while (iter)
		{
			if (iter->val == city)
			   return index;
			index++;
			iter = iter->next;
		}
		return INT_MIN;
	}

	string search_city(int index)
	{
		node<string>* iter = head;
		int count = 0;


		while (iter)
		{
			if (count == index)
				return iter->val;

			count++;
			iter = iter->next;
		}
		return "";
	}

};

struct Graph
{
	int** cities;
	int cities_count;
	cities_list* names;

	Graph()
	{
		cities = nullptr;
		cities_count = 0;
		names = new cities_list();
	}

	void ReadFromFile()
	{
		ifstream file("E:/data structures university/Assignment3/GraphData.csv");
		string curr_line;

		if (file)
		{
			getline(file, curr_line);
			cities_count = get_count(curr_line);
			allocate_2d(cities, cities_count);
			int cities_i = 0;

			while (getline(file, curr_line))
			{
				bool first = true;
				int cities_j = 0;

				for (int i = 0; i < cities_count + 1; i++)
				{
					if (first)
					{
						string name = seperate_wrt_to_index(i + 1, curr_line);
						names->insert(name);
						first = false;
					}
					else
					{
						string coordinates = seperate_wrt_to_index(i + 1, curr_line);
						int temp_cord = stod(coordinates);
						cities[cities_i][cities_j++] = temp_cord;
					}
				}
				cities_i++;
			}
		}	
	}

	void addNode(string city)
	{
		int** temp = deep_copy_arr(cities, cities_count);
		cities_count++;
		cities = nullptr;

		allocate_2d(cities, cities_count);

		for (int i = 0; i < cities_count - 1; i++)
			for (int j = 0; j < cities_count - 1; j++) 
				cities[i][j] = temp[i][j];

		names->insert(city);

		deallocate_memory(temp, cities_count);

	}

	void deleteNode(string city)
	{
		int** temp = deep_copy_arr(cities, cities_count);
		cities_count--;
		cities = nullptr;

		allocate_2d(cities, cities_count);

		int deleted_index = names->get_index(city), cities_i = 0, cities_j = 0;

		for (int i = 0; i < cities_count + 1; i++)
		{
			cities_j = 0;
			for (int j = 0; j < cities_count + 1; j++)
			{
				if (i != deleted_index && j != deleted_index)
					cities[cities_i][cities_j++] = temp[i][j];
			}
			if (i != deleted_index)
				cities_i++;
		}

		names->remove(city);

		deallocate_memory(temp, cities_count + 1);
	}

	string printsingleLink(string city)
	{
		int index = names->get_index(city);
		bool first = true;

		string city_paths = city + ":";

		for (int j = 0; j < cities_count; j++)
			if (cities[index][j] != 0)
			{
				string arrow = "-> ";
				if (first)
				{
					arrow = " -> ";
					first = false;
				}
				string temp = arrow + names->search_city(j);
				city_paths += temp;
			}

		return city_paths;
	}

	void addEdge(string from, string to, int value)
	{
		int index_for_from = names->get_index(from);
		int index_for_to = names->get_index(to);

		if (index_for_from < cities_count && index_for_to < cities_count)
			cities[index_for_from][index_for_to] = value;
	}

	void deleteEdge(string from, string to)
	{
		int index_for_from = names->get_index(from);
		int index_for_to = names->get_index(to);

		if (index_for_from < cities_count && index_for_to < cities_count)
			cities[index_for_from][index_for_to] = 0;

	}

	void printGraph()
	{
		for (int i = 0; i < cities_count; i++)
		{
			string temp_city = names->search_city(i);
			cout << printsingleLink(temp_city) << '\n';
		}
	}		

	void make_infinity(int* distances, int size,int limit)
	{
		for (int i = 0; i < size; i++)
			distances[i] = limit;
	}

	bool all_visited(bool* visited, int size)
	{
		for (int i = 0; i < size; i++)
			if (!visited[i])
				return false;
		return true;
	}

	int least_distance(int* distances, bool* visited, int size)
	{
			int min = INT_MAX;
			int min_index = INT_MAX;

			for (int i = 0; i < size; i++)
				if (distances[i] <= min && !visited[i])
				{
					min = distances[i];
					min_index = i;
				}

		return min_index;
	}

	void get_path(int* previous, int traverser, string& path)
	{
		if (previous[traverser] == -1)
			return;
		get_path(previous, previous[traverser], path);
		path += names->search_city(previous[traverser]) + "-> ";
	}

	string Dijkstra(string city,string city2)
	{
		bool* visited = new bool[cities_count] {};
		bool valid = true;

		int* distances = new int[cities_count], * previous = new int[cities_count];
		make_infinity(distances, cities_count,INT_MAX);
		make_infinity(previous, cities_count, INT_MIN);

		int source_index = names->get_index(city);

		//initial step
		distances[source_index] = 0;
		previous[source_index] = -1;

		while (!all_visited(visited, cities_count))
		{
			int curr_node = least_distance(distances, visited, cities_count);

			if (!visited[curr_node])
				visited[curr_node] = true;

			for (int i = 0; i < cities_count; i++)
				if (cities[curr_node][i] > 0 && !visited[i] && i != curr_node)
				{
					int new_distance = distances[curr_node] + cities[curr_node][i];
					if (new_distance < distances[i])
					{
						distances[i] = new_distance;
						previous[i] = curr_node;
					}
				}
		}

		
		//The previous array bascially contains the entire 
		int ind = names->get_index(city2);
		string path = "";
		while (previous[ind] != -1)
		{
			ind = previous[ind];
			if (ind == INT_MIN)
			{
				valid = false;
				break;
			}
		}
		if (!valid)
			return path;
		else
		{
			 get_path(previous, names->get_index(city2), path);
			 return path;
		}
	}

	void shortestPathfromalltoone(string destination)
	{
		cout << "Displaying all paths\n";
		for (int i = 0; i < cities_count; i++)
		{
			if (i != names->get_index(destination))
			{
				string source = names->search_city(i);
				cout << "From " << source <<" to "<<destination<<'\n';
				string path = Dijkstra(source, destination);
				if (path == "")
					cout << "no path available\n";
				else
					cout << path << destination << '\n';
			}
		}
	}

	string ShortestRoutefrompair(string source, string destination)
	{
		string path = Dijkstra(source, destination);
		if (path == "")
			return "no paths available\n";
		else
			return path + destination;

	}

	void shortestPathfromOnetoall(string city)
	{
			cout << "Displaying paths of "<<city <<" towards all other cities\n";
			for (int i = 0; i < cities_count; i++)
			{
				if (i != names->get_index(city))
				{
					cout << "To ";
					string destination = names->search_city(i);
					cout << destination << '\n';
					string path = Dijkstra(city, destination);
					if (path == "")
						cout << "no path available\n";
					else
						cout << path << destination << '\n';
				}
			}
	}

	void Second_path(int* previous, int traverser, string& path,cities_list*& store_path,int*& total_edge,int& total)
	{
		if (previous[traverser] == -1)
			return;
		Second_path(previous, previous[traverser], path,store_path,total_edge,total);
		if (store_path)
		{
			string temp = names->search_city(previous[traverser]);
			store_path->insert(temp);

			total += total_edge[traverser];
			path += names->search_city(previous[traverser]) + "-> ";
		}
	}

	string second_Dijkstra(string city, string city2,cities_list*& Store_path,int**& Matrix,int& total)
	{
		bool* visited = new bool[cities_count] {};
		bool valid = true;
		int* edge_total = new int[cities_count] {};

		int* distances = new int[cities_count], * previous = new int[cities_count];
		make_infinity(distances, cities_count, INT_MAX);
		make_infinity(previous, cities_count, INT_MIN);

		int source_index = names->get_index(city);

		//initial step
		distances[source_index] = 0;
		previous[source_index] = -1;

		while (!all_visited(visited, cities_count))
		{
			int curr_node = least_distance(distances, visited, cities_count);

			if (!visited[curr_node])
				visited[curr_node] = true;

			for (int i = 0; i < cities_count; i++)
				if (Matrix[curr_node][i] > 0 && !visited[i] && i != curr_node)
				{
					int new_distance = distances[curr_node] + Matrix[curr_node][i];
					if (new_distance < distances[i])
					{
						distances[i] = new_distance;
						previous[i] = curr_node;
						edge_total[i] = Matrix[curr_node][i];
					}
				}
		}

			//The previous array bascially contains the entire 
			int ind = names->get_index(city2);
			string path = "";
			Store_path = new cities_list;
			while (previous[ind] != -1)
			{
				ind = previous[ind];
				if (ind == INT_MIN)
				{
					valid = false;
					break;
				}
			}
			if (!valid)
				return path;
			else
			{
				Store_path->insert(city);
				Second_path(previous, names->get_index(city2), path,Store_path,edge_total,total);
				return path;
			}
	}

	string secondShortestRoutefrompair(string source,string destination)
	{
		cities_list* current_path = nullptr;
		int prev = -1, prev_source = -1, prev_destination = -1, start = names->get_index(source);
		
		string ans = "";

		int second_minimum = INT_MAX, first = 0;
		string check = second_Dijkstra(source, destination, current_path, this->cities, first);

		if (check != "")
		{
			node<string>* search = current_path->head;
			while (search->next)
			{

				int** temp = deep_copy_arr(this->cities, this->cities_count);

				int source_ind = names->get_index(search->val);
				int dest_ind = names->get_index(search->next->val);

				if (search->next && prev != -1)
					if (search->val != source)
					{
						temp[prev_source][prev_destination] = prev;
						temp[prev_destination][prev_source] = prev;
					}

				int total = 0; string curr = "";

				prev = temp[source_ind][dest_ind];
				prev_source = source_ind;
				prev_destination = dest_ind;

				temp[source_ind][dest_ind] = 0;
				temp[dest_ind][source_ind] = 0;

				curr = second_Dijkstra(source, destination, current_path, temp, total);

				if (total > first)
					if (total < second_minimum)
					{
						ans = curr + destination, second_minimum = total;
					}

				search = search -> next;
			}
		}
		return ans;
	}

	void secondshortestPathfromalltoone(string source)
	{
		string answer = {};
		int source_index = names->get_index(source);
		for (int looping_var = 0; looping_var < cities_count; looping_var++)
		{
			if (looping_var != source_index)
			{
				cout << "Path from " << source << " ";
				cout << names->search_city(looping_var) << " is : \n";
				string destination = names->search_city(looping_var);
				answer =  secondShortestRoutefrompair(destination,source) ;
				if (answer != "")
					cout << answer << '\n';
				else
					cout << "Path not available\n";
			}
		}
	}

	void secondshortestPathfromOnetoall(string city)
	{
		int start = names->get_index(city);
		string destination = "";
		for (int i = 0; i < cities_count; i++)
		{
			if (start != i)
			{
				destination = names->search_city(i);
				cout << "To " << destination << '\n';
				cout << secondShortestRoutefrompair(city, destination) << endl;
			}
		}
	}
};
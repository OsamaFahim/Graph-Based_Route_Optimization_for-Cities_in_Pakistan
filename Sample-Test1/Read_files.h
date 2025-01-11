#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void allocate_2d(int**& arr,int size)
{
	arr = new int*[size];
	for (int i = 0; i < size; i++)
		arr[i] = new int[size] {};
}

void deallocate_memory(int**& arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		delete arr[i];
		arr[i] = nullptr;
	}

	delete arr;
	arr = nullptr;
}

int** deep_copy_arr(int** arr, int size)
{
	int** temp = nullptr;
	allocate_2d(temp, size);

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			temp[i][j] = arr[i][j];

	return temp;
}

int get_count(string cities)
{
	int city_count = 0;
	string temp_city = "";

	for (int i = 0; cities[i]; i++)
	{
		if(cities[i] != ',')
			temp_city += cities[i];

		if (cities[i] == ',')
		{
			if(temp_city != "")
				city_count++;

			temp_city = "";
		}
	}
	if (temp_city != "")
		city_count++;

	return city_count;
}

string seperate_wrt_to_index(int index, string data)
{
	string answer = {};
	int count = 0;

	for (int i = 0; data[i]; i++)
	{
		if (data[i] != ',')
			answer += data[i];

		if (data[i] == ',')
		{
			count++;
			if (count == index)
				return answer;

			answer = {};
		}
	}
	return answer;
}
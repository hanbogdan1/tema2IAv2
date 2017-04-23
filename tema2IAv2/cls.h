#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <ctime>


static struct comparator
{
	bool operator()(std::vector<int> &a, std::vector<int> &b)
	{
		return cmp_vect(a, b);
	}


	bool cmp_vect(std::vector<int> &a, std::vector<int> &b)
	{

		if (calculare_cardinal_coada(a) > calculare_cardinal_coada(b))
			return false;
		return true;
	}

	static int calculare_cardinal_coada(std::vector<int> &vect)
	{
		auto ret = 0;
		for (auto i = vect.begin(); i != vect.end() - 1; ++i)
		{
			if (*i > *(i + 1))
				return ret;
			ret++;
		}
		return ret;
	}
};


class cls
{

	std::stack <std::vector<int >> stiva;
	std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, comparator> coada;
	std::ifstream f;
	std::ofstream g;
	std::vector<int> final_form;
	std::vector<std::vector<int>>visited;

public:
	std::vector<int> initial_values;
	cls()
	{
		f.open("inp.txt");
		g.open("out.txt");
		srand(time(NULL));
		this->citire_date(); 
	}

	~cls()
	{
		f.close();
		g.close();
	}

	void citire_date();
	void interschimbare(std::vector<int>& a);
	bool solutie(std::vector<int> &vect);
	void dfs(std::vector<int> vect);
	void afisare_vect(std::vector<int>& vect);
	void gbfs(std::vector<int> vect);
};
#pragma once

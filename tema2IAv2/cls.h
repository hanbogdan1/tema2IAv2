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
	bool operator()(static std::vector<int> a, static std::vector<int> b)
	{
		return cmp_vect(a, b);
	}


	bool cmp_vect(static std::vector<int> a, static  std::vector<int> b)
	{

		if (calculare_cardinal_coada(a) > calculare_cardinal_coada(b))
			return false;
		return true;
	}

	static int calculare_cardinal_coada(static std::vector<int> vect)
	{
		auto ret = 0;
		for (auto i = 0; i < vect.size()-1; ++i)
		{
			for (auto j = i + 1; j < vect.size(); j++) {
				if (vect[i] < vect[j])
					ret++;
			}
		}
		return ret;
	}
};


class cls
{
	comparator comp;
	std::stack <std::vector<int >> stiva;
	std::vector<std::vector<int>> coada;
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
	void dfs(std::vector<int> &vect);
	void afisare_vect(std::vector<int>& vect);
	void gbfs(std::vector<int> &vect);
	void adaugare_coada(std::vector<int> vect);

};

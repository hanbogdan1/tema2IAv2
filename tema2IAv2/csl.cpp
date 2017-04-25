#include "cls.h"
#include <iostream>
#include <ctime>

void cls::citire_date()
{
	int x;
	while (f >> x)
	{

		initial_values.push_back(x);
	}

	g << " valoarea initiala din vect : ";
	afisare_vect(initial_values);

	final_form.assign(initial_values.begin(), initial_values.end());
	sort(final_form.begin(), final_form.end());

}

void cls::interschimbare(std::vector<int> & a)
{

	g << "Intra in schimbare ";
	int indice1 = 1, indice2 = 1;

	//while (indice1 == indice2 || (indice1 < indice2 && a.at(indice1) < a.at(indice2)) || (indice2 < indice1 && a.at(indice2) < a.at(indice1)) || a.at(indice1) == a.at(indice2))
	//best performance <3 

	while (indice1 == indice2)  

	{
		indice1 = rand() % a.size();
		indice2 = rand() % a.size();
	}
	int aux = a[indice1];
	a[indice1] = a[indice2];
	a[indice2] = aux;

	g << "pe indicii " << indice1 << " si  " << indice2 << " cu valorile  " << a[indice2] << " -> " << a[indice1];

}


bool cls::solutie(std::vector<int>& vect)
{
	return final_form == vect;
}

void cls::dfs(std::vector<int> &vect)
{
	visited.clear();

	final_form.assign(vect.begin(), vect.end());
	sort(final_form.begin(), final_form.end());

	g << "\n\n\n\n\nDFS :\n";

	stiva.push(vect);
	visited.push_back(vect);
	while (stiva.size()>0 && !solutie(vect))
	{
		vect = stiva.top();

		interschimbare(vect);

		g << " vect dupa interschimare ";
		afisare_vect(vect);

		if (std::find(visited.begin(), visited.end(), vect) == visited.end()) {
			g << " valoarea de sus a fost nevizitata\n ";
			stiva.pop();
			stiva.push(vect);
			visited.push_back(vect);
		}
		else
			g << " valoarea de sus a fost vizitata \n";


	}


	if (solutie(vect))
		g << "Sortarea dfs a mers ok ! :>";
	else
		g << "Sortarea dfs nu a mers ok ! :>";
}

void cls::afisare_vect(std::vector<int> & vect)
{
	g << "\n";
	for (auto &x : vect)
	{
		g << x << " ";

	}
	g << "\n";
}

void cls::gbfs(std::vector<int>& vect)
{
	final_form.assign(vect.begin(), vect.end());
	sort(final_form.begin(), final_form.end());

	visited.clear();
	g << "\n\n\n\n\nGBFS :\n";
	adaugare_coada(vect);
	visited.push_back(vect);
	while (coada.size()>0 && !solutie(vect))
	{
		vect = coada.front();
		g << "\n a fost als vect : ";
		afisare_vect(vect);
		interschimbare(vect);
		g << " vect dupa interschimare ";
		afisare_vect(vect);
		if (std::find(visited.begin(), visited.end(), vect) == visited.end()) {
			g << " valoarea de sus a fost nevizitata\n ";
			adaugare_coada(vect);
			visited.push_back(vect);
		}
		else
			g << " valoarea de sus a fost vizitata \n";

	}


	if (solutie(vect))
		g << "Sortarea bgfs a mers ok ! :>";
	else
		g << "Sortarea bgfs nu a mers ok ! :>";

}

void cls::adaugare_coada(std::vector<int> vect)
{
	int i = 0;
	for (; i < coada.size(); i++) {
		if (comp.operator()(coada[i], vect))
			break;
	}
	coada.insert(coada.begin() + i, vect);
}

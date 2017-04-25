#include <iostream>
#include "cls.h"
#include <assert.h>


void test1(std::vector<int> asrt) {
	cls a;
	std::vector<int> tst;
	a.gbfs(asrt);
	tst.assign(asrt.begin(), asrt.end());
	std::sort(tst.begin(), tst.end());
	assert(asrt == tst);
}

void test2(std::vector<int> asrt) {
	cls a;
	std::vector<int> tst;
	a.dfs(asrt);
	tst.assign(asrt.begin(), asrt.end());
	std::sort(tst.begin(), tst.end());
	assert(asrt == tst);
}


int main()
{
	
	
	
	
	std::vector<int> asrt;
	
	asrt.push_back(4);
	asrt.push_back(7);
	asrt.push_back(2);
	asrt.push_back(1);

	test1(asrt);
	
	asrt.clear();
	asrt.push_back(4);
	asrt.push_back(1);
	asrt.push_back(2);
	asrt.push_back(1);

	test2(asrt);
	asrt.clear();
	asrt.push_back(4);
	asrt.push_back(8);
	asrt.push_back(8);
	asrt.push_back(1);
	
	test1(asrt);
	asrt.clear();
	asrt.push_back(1);
	asrt.push_back(3);
	asrt.push_back(6);
	asrt.push_back(7);


	test1(asrt);
	asrt.clear();
	asrt.push_back(9);
	asrt.push_back(8);
	asrt.push_back(1);
	asrt.push_back(2);

	test2(asrt);
	asrt.clear();
	asrt.push_back(4);
	asrt.push_back(1);
	asrt.push_back(4);
	asrt.push_back(1);

}
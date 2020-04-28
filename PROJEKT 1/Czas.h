#pragma once

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Czas
{
public:
	Czas();
	~Czas();

	high_resolution_clock::time_point czasPoczatkowy;
	high_resolution_clock::time_point czasKoncowy;

	void czasStart();

	void czasStop();

	long czasWykonania();
};


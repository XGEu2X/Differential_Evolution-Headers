#include <iostream>

#include "../src/DifferentialEvolution.hpp"
#include "../src/ExampleQualifiers.hpp"

#include "../include/Geometry/Point.hpp"
#include "../include/Geometry/PointSet.hpp"
#include "../include/Geometry/RandomGenerators.hpp"

using namespace std;
using namespace Evolutive;
using namespace Geometry;

int main() {
	using Population = PointSet<Point<double>>;
	using Qual = FirstCoordinate<Point<double>>;

	Qual f;
	Circle C;
	Population P = C.born(40);
	for (size_t c1 = 0; c1 < 40; ++c1) {
		P[c1].set_value(f(P[c1]));
	}

	
	DiffEvo<Population, Circle, Qual> DE(1,0.2, DiffEvo<Population, Circle, Qual>::SORT_DESCENDING);

	for(size_t c1 =0;c1<100;++c1){
		DE.evolve(P, C, f, 10, 5);

		cout << P.to_string() << endl << endl;
	}
	return 0;
}
#include "test.h"
#include <iostream>



Test::Test(int px) {
	x = px;
}

void Test::show() {
	cout << x << endl;
}
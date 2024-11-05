#include "inf_int.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

using namespace std;

int main()
{
	inf_int c("3"); //321
	inf_int d("5"); //4321

	cout << c * d;

	return 0;
}
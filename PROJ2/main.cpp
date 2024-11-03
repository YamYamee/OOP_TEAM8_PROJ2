#include "inf_int.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

using namespace std;

int main()
{
	inf_int c("204652345234534534534252323452345234534252345342003"); //321
	inf_int d("55342523452345234524353425262623451534553255156235"); //4321

	c = c - d;

	cout << c;

	return 0;
}
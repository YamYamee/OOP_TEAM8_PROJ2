#define _CRT_SECURE_NO_WARNINGS
#include "inf_int.h"
#include <cassert>
#include <cctype>
/*
Originally written by
��ǻ�Ͱ��к�
������
*/

// 0으로 초기화
inf_int::inf_int(): digits("0"), thesign(true) {};

inf_int::inf_int(int n): digits(""), thesign(n>=0) {
	if (n==0)
	{
		digits="0";
		return;
	}
	else 
	{
		if (!thesign) n = -n; // 음수이면 양수로 변환
		while (n>0)
		{
			digits.push_back(n%10+'0');
			n /= 10;
		}
	}
}

inf_int::inf_int(const string str)
{	
	int start_index = 1; // 숫자 시작 인덱스

	// 부호 판별, 만약 첫번째 인덱스가 부호이거나 숫자가 아니면 에러를 발생시킵니다.
	if (str.at(0)=='+') thesign=true;
	else if (str.at(0)=='-') thesign=false;
	else if (isdigit(str.at(0)))
	{
		start_index = 0;
		thesign=true;
	}
	else assert(true);

	digits = "";
	for (int i = str.length()-1; i>=start_index; i--) //역순으로 저장
	{
		assert(!isdigit(str.at(i)));
		digits.push_back(str.at(i));
	}
}

inf_int::inf_int(const inf_int& a): digits(a.digits), thesign(a.thesign) {}

inf_int::~inf_int() {}

inf_int& inf_int::operator=(const inf_int& a)
{
	digits = a.digits;
	thesign = a.thesign;
	return *this;
}

bool operator==(const inf_int& a, const inf_int& b)
{
	// we assume 0 is always positive.
	if ((strcmp(a.digits, b.digits) == 0) && a.thesign == b.thesign)	// ��ȣ�� ����, ������ ��ġ�ؾ���.
		return true;
	return false;
}

bool operator!=(const inf_int& a, const inf_int& b)
{
	return !operator==(a, b);
}

bool operator>(const inf_int& a, const inf_int& b)
{
	// to be filled
	// ���밪 ��
	// �� �� ����� ��� ���� ���� ���� �״�� return
	// �� �� ������ ��� ���� ���� ���� �����Ͽ� return
	// ��ȣ�� �ٸ� ���, a�� ����� ��� b�� ����, a�� ������ ��� b�� ����̱⿡ a�� ��ȣ�������� ��ȯ�ϸ� ��
}

bool operator<(const inf_int& a, const inf_int& b)
{
	if (operator>(a, b) || operator==(a, b)) {
		return false;
	}
	else {
		return true;
	}
}

inf_int operator+(const inf_int& a, const inf_int& b)
{
	inf_int c;
	unsigned int i;

	if (a.thesign == b.thesign) {	// ������ ��ȣ�� ���� ��� + �����ڷ� ����
		for (i = 0; i < a.length; i++) {
			c.Add(a.digits[i], i + 1);
		}
		for (i = 0; i < b.length; i++) {
			c.Add(b.digits[i], i + 1);
		}

		c.thesign = a.thesign;

		return c;
	}
	else {	// ������ ��ȣ�� �ٸ� ��� - �����ڷ� ����
		c = b;
		c.thesign = a.thesign;

		return a - c;
	}
}

inf_int operator-(const inf_int& a, const inf_int& b)
{
	// to be filled
}

inf_int operator*(const inf_int& a, const inf_int& b)
{
	// to be filled
}


ostream& operator<<(ostream& out, const inf_int& a)
{
	int i;

	if (a.thesign == false) {
		out << '-';
	}
	for (i = a.length - 1; i >= 0; i--) {
		out << a.digits[i];
	}
	return out;
}

void inf_int::Add(const char num, const unsigned int index)	// a�� index �ڸ����� n�� ���Ѵ�. 0<=n<=9, ex) a�� 391�϶�, Add(a, 2, 2)�� ����� 411
{
	if (this->length < index) {
		this->digits = (char*)realloc(this->digits, index + 1);

		if (this->digits == NULL) {		// �Ҵ� ���� ����ó��
			cout << "Memory reallocation failed, the program will terminate." << endl;

			exit(0);
		}

		this->length = index;					// ���� ����
		this->digits[this->length] = '\0';	// �ι��� ����
	}

	if (this->digits[index - 1] < '0') {	// ���� ���� '0'���� ���� �ƽ�Ű���� ��� 0���� ä��. �������� �ʾҴ� ���ο� �ڸ����� ��� �߻�
		this->digits[index - 1] = '0';
	}

	this->digits[index - 1] += num - '0';	// �� ����


	if (this->digits[index - 1] > '9') {	// �ڸ��ø��� �߻��� ���
		this->digits[index - 1] -= 10;	// ���� �ڸ������� (�ƽ�Ű��) 10�� ����
		Add('1', index + 1);			// ���ڸ��� 1�� ���Ѵ�
	}
}

#include "Vector.h"

using namespace std;

int main()
{
	Vector v1(0, 0);
	Vector v2(1, 1);

	cout << "Input of coordinates for first vector: ";
	cin >> v1;
	cout << "It's lenght is " << v1.Len() << endl;
	cout << "It's square of lenght is " << v1.SquareLen() << endl;

	v1 = v2 + v1;
	cout << "v1 + v2 = " << v1 << endl;

	v1 = v1 - v2;
	cout << "v1 - v2 = " << v1 << endl;

	v1 += v2;
	cout << "(v1 += v2) = " << v1 << endl;

	v1 -= v2;
	cout << "(v1 -= v2) = " << v1 << endl;

	float sqal_res = v1 * v2;
	cout << "v1 * v2 = " << sqal_res << endl;

	float vect_res = v1 ^ v2;
	cout << "v1 ^ v2 = " << vect_res << endl;

	cout << "v1 * -1 = " << v1 * -1 << endl;
	cout << "-2 * v1 = " << -2 * v1 << endl;
	cout << "v1 / 2 = " << v1 / 2 << endl;

	cout << "Normal vector is " << v1.norm();
	cout << "Ort is " << v1.ortohonal();

	cout << "GetRotate() : " << v1.getRotated(0.52) << endl;
	cout << "v1 = " << v1 << endl;
	cout << "Rotate() : " << v1.rotate(0.52) << endl;
	cout << "v1 = " << v1 << endl;

	return 0;
}
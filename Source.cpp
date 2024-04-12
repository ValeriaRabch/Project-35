#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Shape {
	char name[20];
	int mount_angles;

public:
	Shape(){
		strcpy(name, "");
		mount_angles = 0;
	}
	Shape(char name[], int mount_angles) {
		strcpy(this->name, name);
		this->mount_angles = mount_angles;
	}
};

class Circle :public Shape {
	int radius, diameter;
	int midpoint[2];

public:
	Circle(){
		Shape();
		radius = 0;
		diameter = 0;
		midpoint[0] = 0;
		midpoint[1] = 0;
	}
	Circle(char name[], int mount_angles, int radius, int midpoint[2]) : Shape(name, mount_angles), radius(radius), diameter(radius * 2) {
		this->midpoint[0] = midpoint[0];
		this->midpoint[1] = midpoint[1];
	}
	int FindP() {
		return 2 * radius;
	}
	int FindS() {
		return radius * radius;
	}
};

class Triangle :public Shape {
	int length_a, length_b, length_c;
	int angle_a, angle_b, angle_c;
	int length_h_a;
public:
	Triangle() : length_a(0), length_b(0), length_c(0), angle_a(0), angle_b(0), angle_c(0), length_h_a(0){}
	Triangle(char name[], int mount_angles, int a, int b, int c, int a_a, int a_b, int a_c, int h_a) : Shape(name, mount_angles), length_a(a), length_b(b), length_c(c), angle_a(a_a), angle_b(a_b), angle_c(a_c), length_h_a(h_a){}

	int FindP() {
		return length_a + length_b + length_c;
	}
	int FindS() {
		return (length_a * length_h_a)/2;
	}
};

class Rectangle :public Shape {
	int length_a, length_b;
public:
	Rectangle() : length_a(0), length_b(0) {}
	Rectangle(char name[], int mount_angles, int a, int b) : Shape(name, mount_angles), length_a(a), length_b(b) {}

	int FindP() {
		return (length_a + length_b) * 2;
	}
	int FindS() {
		return length_a * length_b;
	}
};


int main() {

	char name[20]; int mount_angles; 
	
	int radius, diameter, midpoint[2];

	
	int length_a, length_b, length_c;
	int angle_a, angle_b, angle_c;
	int length_h_a;

	
	cout << "Enter name shape "; cin >> name;
	cout << "Enter mount_angles "; cin >> mount_angles;

	if (mount_angles == 0) {
		cout << "Enter radius "; cin >> radius;
		cout << "Enter midpoint x "; cin >> midpoint[0];
		cout << "Enter midpoint y "; cin >> midpoint[1];

		Circle circle(name, mount_angles, radius, midpoint);

		cout << "Perimeter " << circle.FindP()<< "pi" << endl;
		cout << "Area " << circle.FindS() << "pi" << endl;
	}
	if (mount_angles == 3) {
		cout << "Enter length a "; cin >> length_a;
		cout << "Enter length b "; cin >> length_b;
		cout << "Enter length c "; cin >> length_c;
		cout << "Enter angle a "; cin >> angle_a;
		cout << "Enter angle b "; cin >> angle_b;
		cout << "Enter angle c "; cin >> angle_c;
		cout << "Enter length high a "; cin >> length_h_a;

		if ((angle_a + angle_b + angle_c) == 180) {
			Triangle triangle(name, mount_angles, length_a, length_b, length_c, angle_a, angle_b, angle_c, length_h_a);

			cout << "Perimeter " << triangle.FindP() << endl;
			cout << "Area " << triangle.FindS() << endl;
		}
		else {
			cout << "Error ";
		}
	}
	/*if (mount_angles == 4) {
		cout << "Enter length a "; cin >> length_a;
		cout << "Enter length b "; cin >> length_b;

		Rectangle rectangle(name, mount_angles, length_a, length_b);

		cout << "Perimeter " << rectangle.FindP() << endl;
		cout << "Area " << rectangle.FindS() << endl;
	}
	else {
		cout << "Error ";
	}*/

	

	return 0;
}
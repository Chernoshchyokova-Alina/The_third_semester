
/* 212 Chernoshchyokova Alina Fyodorovna 
   
   "Cloud generation" */

#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

class Point {					
private:
	double x;					
	double y;					
	int number;					
	int color;					

public:

	Point() {				
		x = 0.0;
		y = 0.0;
		number = 0;
		color = 0;
	}

	void Set(double SetX, double SetY, int SetNumber, int SetColor) {		
		x = SetX;
		y = SetY;
		number = SetNumber;
		color = SetColor;
	}

	double GetX() { return x; }								
	double GetY() { return y; }
	double GetNumber() { return number; }
	double GetColor() { return color; }

	~Point() {									

	}
};

class Interface {				
public:
	int Start();			

};

class Cloud {					
private:
	int size;					
	int condition;				
	Point* arr;					

public:
	Cloud() {				
		size = 0;
		condition = 0;
		arr = NULL;
	}

	void Set(int SetSize, int SetCond, Point* SetArr) {
		size = SetSize;
		condition = SetCond;
		arr = SetArr;
	}

	int GetCondition() { return condition; }
	int GetSize() { return size; }
	Point* GetArr() { return arr; }

	void clear() {								
		delete[]arr;
	}

};

class Controller {					
private:
	int status;

public:
	Controller() {					
		status = 1;
	}

	Cloud Cloud_Gener(int n, double centerX, double centerY, double dispX, double dispY);
	void Cloud_Print(Cloud cloud);

	~Controller() {					

	}
};

/* 212 Chernoshchyokova Alina Fyodorovna 
   
   "Cloud generation" */

#include <iostream>
#include <fstream>
#include <string>
#include <random>

using namespace std;

// Класс точки на плоскости
class Point {					
private:
	double x;    // Координата x		
	double y;    // Координата y				
	int number;	 // Номер точки 			
	int color;	 // Цвет точки		

public:

	Point() {	 // Конструктор с начальными значениями		
		x = 0.0;
		y = 0.0;
		number = 0;
		color = 0;
	}

    // Сетер
	void Set(double SetX, double SetY, int SetNumber, int SetColor) {		
		x = SetX;
		y = SetY;
		number = SetNumber;
		color = SetColor;
	}
    
	// Гетеры
	double GetX() { return x; }								
	double GetY() { return y; }
	double GetNumber() { return number; }
	double GetColor() { return color; }

	~Point() {		// Деструктор							

	}
};

// Класс интерфейс
class Interface {				
public:
	int Start(); // Функция запуска программы		

};

// Класс облака 
class Cloud {					
private:
	int size;	   // Количество точек				
	int condition; // Состояние облака (создано или не создано)		
	Point* arr;	   // Указатель на массив с точками 

public:
	Cloud() {	   // Конструктор			
		size = 0;
		condition = 0;
		arr = NULL;
	}

    // Сетер
	void Set(int SetSize, int SetCond, Point* SetArr) {
		size = SetSize;
		condition = SetCond;
		arr = SetArr;
	}

    // Гетеры
	int GetCondition() { return condition; }
	int GetSize() { return size; }
	Point* GetArr() { return arr; }

	void clear() {		// Деструктор для очистки массива						
		delete[]arr;
	}

};

// Класс контроллер 
class Controller {					
private:
	int status;

public:
	Controller() {					
		status = 1;
	}

    // Команды контроллера
	Cloud Cloud_Gener(int n, double centerX, double centerY, double dispX, double dispY);
	void Cloud_Print(Cloud cloud);

	~Controller() {	 // Деструктор				

	}
};
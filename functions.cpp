
/* 212 Chernoshchyokova Alina Fyodorovna 
   
   "Cloud generation" */

#include "headers.hpp"

/* Функция генерации массива-облака точек нормального распределения 
   На вход подаются: число точек n, центр (centerX, centerY) облака по x и по y,
   дисперсия dispX и dispY по координатам x и y
   Функция возвращает указатель на созданный массив */
Point* Arr_Gener(int n, double centerX, double centerY, double dispX, double dispY) {
	Point* arr = new Point[n];											
	default_random_engine gener;										
	normal_distribution<double> distributionx(centerX, dispX);			
	normal_distribution<double> distributiony(centerY, dispY);			

	for (int i = 0; i < n; i++) {
		(arr + i)->Set(distributionx(gener), distributiony(gener), i, 1);		
	}
	
	return arr;
}

/* Функция контроллера - генерации облака точек и установка параметров size и condition
   На вход подаются: число точек n, центр (centerX, centerY) облака по x и по y,
   дисперсия dispX и dispY по координатам x и y
   Функция возвращает готовое облако точек */
Cloud Controller::Cloud_Gener(int n, double centerX, double centerY, double dispX, double dispY) {
	Cloud cloud;
	cloud.Set(n, 1, Arr_Gener(n, centerX, centerY, dispX, dispY));

	return cloud;
}

/* Функция контроллера - печати облака точек 
   На вход подаётся облако точек */
void Controller::Cloud_Print(Cloud cloud) {
	int n = cloud.GetSize();
	Point* arr = cloud.GetArr();
	if (cloud.GetCondition() != 1) {
		cout << "This cloud does not exist\n";
		return;
	}
	
	for (int i = 0; i < n; i++) {
		cout << arr[i].GetX() << " " << arr[i].GetY() << endl;
	}
	cout << endl;
	return;
}

/* Функция интерфейса - определения команд
   Вводится команда, после чего функция возвращает её код */
int	Interface::Start() {
	string s1 = "cloud_create";
	string s2 = "cloud_print";
	string s3 = "stop";
	string s;

	cin >> s;
	if (s == s1) return 1;							
	if (s == s2) return 2;							
	if (s == s3) return 3;							
	return 0;										
}
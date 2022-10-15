
/* 212 Chernoshchyokova Alina Fyodorovna 
   
   "Cloud generation" */

#include "headers.hpp"

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

Cloud Controller::Cloud_Gener(int n, double centerX, double centerY, double dispX, double dispY) {
	Cloud cloud;
	cloud.Set(n, 1, Arr_Gener(n, centerX, centerY, dispX, dispY));

	return cloud;
}

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
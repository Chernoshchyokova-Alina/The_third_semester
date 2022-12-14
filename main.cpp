
/* 212 Chernoshchyokova Alina Fyodorovna 
   
   "Cloud generation" */

#include "headers.hpp"

int main(void) {
	Controller controller; // Создаём контроллер (передаёт команды в функции)					
	Cloud cloud_1;		   // Создаём облако точек			
	Interface command;	   // Команда				
	int command_code;	   // Код команды
	/* Параметры облака: центр (centerX, centerY) облака по x и по y,
       дисперсия dispX и dispY по координатам x и y и число точек n	*/				
	double centerX, centerY, dispX, dispY; 
	int n; 

	cout << "Command list:" << endl;
	cout << "  - cloud_create\n  - cloud_print\n  - stop" << endl << endl;
	command_code = command.Start();	// Возвращается код команды														

	while (1) {
		if (command_code == 0) {															
			cout << "Unknown command" << endl; // Неизвестная команда 
			return 1;
		}
		else if (command_code == 1) {		   // Команда генерации облака точек												
			cout << "Enter cloud parameters:" << endl;
			cout << "- Number of points\n- Average x and y coordinate\n- Dispersion in x and y" << endl;
			cin >> n >> centerX >> centerY >> dispX >> dispY;
			cloud_1 = controller.Cloud_Gener(n, centerX, centerY, dispX, dispY); // Генерация облака точек
			if (cloud_1.GetCondition() == 1) {
				cout << "Cloud created" << endl << endl;
			}
		}
		else if (command_code == 2) {	       // Команда печати облака точек												
			controller.Cloud_Print(cloud_1);
		}
		else if (command_code == 3) {		   // Команда завершения								
			cout << "Program completed" << endl;
			break;
		}
		
		cout << "Enter the next command:" << endl;
		command_code = command.Start();		  // Следующая команда 						
		cout << endl;
	}
	cloud_1.clear();

	return 0;
}
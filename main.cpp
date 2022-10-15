
/* 212 Chernoshchyokova Alina Fyodorovna 
   
   "Cloud generation" */

#include "headers.hpp"

int main(void) {
	Controller controller;							
	Cloud cloud_1;									
	Interface command;								
	int command_code;								
	double centerX, centerY, dispX, dispY;			
	int n;

	cout << "Command list:" << endl;
	cout << "  - cloud_create\n  - cloud_print\n  - stop" << endl << endl;
	command_code = command.Start();															

	while (1) {
		if (command_code == 0) {															
			cout << "Unknown command" << endl;
			return 1;
		}
		else if (command_code == 1) {														
			cout << "Enter cloud parameters:" << endl;
			cout << "- Number of points\n- Average x and y coordinate\n- Dispersion in x and y" << endl;
			cin >> n >> centerX >> centerY >> dispX >> dispY;
			cloud_1 = controller.Cloud_Gener(n, centerX, centerY, dispX, dispY);		
			if (cloud_1.GetCondition() == 1) {
				cout << "Cloud created" << endl << endl;
			}
		}
		else if (command_code == 2) {														
			controller.Cloud_Print(cloud_1);
		}
		else if (command_code == 3) {											
			cout << "Program completed" << endl;
			break;
		}
		
		cout << "Enter the next command:" << endl;
		command_code = command.Start();												
		cout << endl;
	}
	cloud_1.clear();

	return 0;
}
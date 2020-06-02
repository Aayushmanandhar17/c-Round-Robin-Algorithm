//Name: Aayush Manandhar
//Project: Final Project 
/*Description: This project generates random process with random brust time and random priority. The process having the high priority will be executed first and vice versa
				First the program will use the priority scheduling where it arranges the process based on priority. In the second part of the program, I have made use of both priority scheduling
				and round robin scheduling. Priority scheduling helps to arrange the process based on priority while round robin has a quantum. If the process exceeds the quantum time it will proceed to 
				next process and the remaining process will have to stay in queue. The loop will continue until all the process is executed*/

#include<iostream>
#include <iomanip>
#include <iomanip>
#include <fstream>

#include"Header.h"

using namespace std;


int main() {
	//Generate a process randomly with the brust time( maximum 10 process)

	int n;
	int randomPriority;
	int randomBrust;
	int pri[20];//position array
	int brust[20] ;//priority array
	int arr[20];
	int new_pri[20];
	int new_brust[20];
	int max_dur;
	char descision;
	cout << "Do you want to use the file data or generate random data: (f(file) or r(random) or m(manual Entry): ";
	cin >> descision;
	if (descision == 'f') {
		/*************************Access data from a file(DATA DRIVEN)********************************************8*/
		cout << "Using the file";
		ifstream infile("C:\\Users\\aayus\\Desktop\\Operating system Final project\\Data_File.txt");
		int num;
		n = 5;
		
		if (infile.fail()) {
			cout << "Could not find the file";
		}
		else {
			int i = 0;
			int j = 0;
			
			while (infile >> num) {
				arr[i] = num;
				i++;
			}
			for (int i = 0; i < 5; i++) {
				brust[i] = arr[j];
				new_brust[i] = brust[i];
				j++;
				pri[i] = arr[j];
				new_pri[i] = pri[i];
				j++;
			}

		}
		

		infile.close();
	}
	else if(descision=='r'){
		/* **********************************Generating data using a random process***************/
		do {
			cout << "Enter the number of process you want to generate( maximum 10 process) ";
			cin >> n;
			if (n < 0 || n>10) {
				cout << "!!! The input should be between 1 and 10 !!!\n";
			}
		} while (n < 0 || n>10);
		


		cout << "**********RANDOMLY CREATED PROCESS*************\n";
		for (int i = 0; i < n; i++) {
			randomPriority = rand() % 15 + 1;//generate the priority number from 1 to 15. If the priority number ranks less then it is given priority
			pri[i] = randomPriority;
			new_pri[i] = pri[i];
			randomBrust = rand() % 100 + 1; //generating random brust time form 1 to 100 mil sec
			brust[i] = randomBrust;
			new_brust[i] = brust[i];

		}
		cout << " Process | Brust Time | Priority\n";
		for (int i = 0; i < n; i++) {
			cout << setw(8) << i + 1 << " | " << setw(8) << brust[i] << " | " << setw(8) << pri[i] << "\n";

		}
	}
	else {
		int prio;
		int burs;
		/**********************Manually Enter the data *******************************/
		do {
			cout << "Enter the number of process you want to generate( maximum 10 process) ";
			cin >> n;
			if (n < 0 || n>10) {
				cout << "!!! The input should be between 1 and 10 !!!\n";
			}
		} while (n < 0 || n>10);
		cout << "Enter the brust time and its priority in sequential order: \n";

		for (int i = 0; i < n; i++) {
			
			cout<<"Process "<< i+1<< " Burst time: ";
			cin >> burs;
			brust[i] = burs;
			new_brust[i] = brust[i];
			cout << "Process" << i+1 << " Priority: ";
			cin >> prio;
			pri[i] = prio;
			new_pri[i] = pri[i];
		}

	}
		


		priority obj;
		//passing the paramenters in the priority scheduling object
		obj.selection_sort(pri, brust, n);
		obj.waiting_time(brust, n);
		obj.print(pri, brust, n);

		cout << "*****ROUND ROBIN ALOGRITHM***********\n";
		do {
			cout << "\nEnter the maximum duration of time for Round Robin (QUANTUM) (max is 60 milsec) ";
			cin >> max_dur;
			if (max_dur>50) {
				cout << "!!!!! The QUANTUM should not exceed 60 and should be non-negative!!!!!\n";
			}
		} while (max_dur<0||max_dur>60);
		
		//ROUND ROBIN using FCFS
		obj.roundRobin(new_brust, n, max_dur);
		obj.waiting_time(new_brust, n);
		obj.RobinprintFCFS(new_pri, new_brust, n);
		//ROUND ROBIN using Priority Scheduling
		obj.roundRobin(brust, n, max_dur);
		obj.waiting_time(brust, n);
		obj.Robinprint(pri, brust, n);

	system("pause");
	return 0;

}

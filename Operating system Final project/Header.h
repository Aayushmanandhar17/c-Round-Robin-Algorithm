#pragma once
using namespace std;
class priority {
public:
	int wait[10];
	int averageRobinWait[10];
	int copy_brust[100];
	int wait_robin[10];
	int average;
	int average_robin;
	int sum;
	int time;
	int process_pos[10] = {1,2,3,4,5,6,7,8,9,10};
	int new_pos[10]= { 1,2,3,4,5,6,7,8,9,10 };
	//void sort(int arr[], int pos[], int n);


	void selection_sort(int arr[], int pos[], int n);
	void swap(int arr[], int x, int minimum);

	void roundRobin(int arr[], int n, int min_time);
	void waiting_time(int pos[], int n);
	void print(int arr[], int pos[], int n);
	void Robinprint(int arr[], int pos[], int n);
	void RobinprintFCFS(int arr[], int pos[], int n);
	
};
//Priority Scheduling algorithm
//I have used bubble sort to sort the data in ascending order based on priority
/*
void priority::sort(int arr[], int pos[],int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;

				temp = pos[j + 1];
				pos[j + 1] = pos[j];
				pos[j] = temp;

				temp = process_pos[j + 1];
				process_pos[j + 1] = process_pos[j];
				process_pos[j] = temp;

			}
		}
	}

}
*/


//Priority scheduling using selecion sort
void priority::selection_sort(int arr[], int pos[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int minimum = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minimum])
				minimum = j;
		swap(arr, i, minimum);
		swap(pos, i, minimum);
		swap(process_pos, i, minimum);
	}

}
void priority::swap(int arr[], int x, int minimum) {
	int temp = arr[x];
	arr[x] = arr[minimum];
	arr[minimum] = temp;
}

//Round robin algorithm

void priority::roundRobin(int arr[], int n, int min_time) {
	time = 0;
	sum = 0;

	for (int i = 0; i < n; i++)
	{
		copy_brust[i] = arr[i];

	}

	do {
		
		for (int i = 0; i < n; i++) {
			if (copy_brust[i] > 0) {
				if (copy_brust[i] > min_time) {

					time = time + min_time;
					copy_brust[i] = copy_brust[i] - min_time;
				}
				else {
					time = time + copy_brust[i];
					
					wait_robin[i] = time - arr[i];
					copy_brust[i] = 0;
				}

			}
		}
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum = sum + copy_brust[i];

		}
	} while (sum != 0);
}

void priority::waiting_time(int pos[], int n) {
	wait[0] = 0;
	
	average = 0;
	average_robin = 0;
	for (int i = 0; i < n; i++){
		wait[i] = 0;
		for (int j = 0; j < i; j++) {
			wait[i] = wait[i] + pos[j];
			
		}
		average = average + wait[i];	// average wait time for priority scheduling
		average_robin = average_robin + wait_robin[i]; //average wait time for round robin
	}


}

void priority::print(int arr[], int pos[], int n) {
	int i;
	cout << "\n""\n ****************OUTPUT USING PRIORITY SCHEDULING****************** \n""\n";
	cout << " Process | Brust Time | Priority | WaitTime\n";
	for (i = 0; i < n; i++) {
			
		cout << setw(8) << process_pos[i] << " | " << setw(8) << pos[i] << " | " << setw(8) << arr[i] <<" | "<< setw(8) << wait[i] << "\n";

	}
	cout << "\n The average wait time using Priority scheduling is " << average/n <<"\n";

}
void priority::Robinprint(int arr[], int pos[], int n) {
	int i;
	cout << "\n" << "*****************USING ROUNDROBIN SCHEDULING ALGORITHM IN PRIORITY SCHEDULING ALGORITHM*************\n" << "\n";
	cout << " Process | Brust Time | Priority | WaitTime\n";
	for (i = 0; i < n; i++) {
		cout << setw(8) << process_pos[i] << " | " << setw(8) << pos[i] << " | " << setw(8) << arr[i] << " | " << setw(8) << wait_robin[i] << "\n";

	}
	cout << "\nThe average waiting time for Round Robin scheduling algorithm using PRIORITY SCHEDULING is " << average_robin/n<<"\n";
}
void priority::RobinprintFCFS(int arr[], int pos[], int n) {
	int i;
	cout << "\n" << "*****************USING ROUNDROBIN SCHEDULING ALGORITHM IN FCFS ALGORITHM*************\n" << "\n";
	cout << " Process | Brust Time | Priority | WaitTime\n";
	for (i = 0; i < n; i++) {
		cout << setw(8) << new_pos[i] << " | " << setw(8) << pos[i] << " | " << setw(8) << arr[i] << " | " << setw(8) << wait_robin[i] << "\n";

	}
	cout << "\nThe average waiting time for Round Robin scheduling algorithm using FCFS is " << average_robin / n << "\n";
}
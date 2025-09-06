#include <iostream>
#include <vector>
#include <algorithm>
#include<string>
#include<fstream>



using namespace std;

struct stTasks {
	string name = "";
	bool isCompleted = false;
};

int ReadNumber() {
	char t;
	do {
		 cin >> t;
	} while (t <= '0' || t > '4');
	return t - '0';
}
void AddTask(vector<stTasks>& Tasks) {
	cout << "What's Task Name? ";
	stTasks task;
	cin.ignore();
	getline(cin, task.name);
	cout << "Do this task completed? y or n ---> ";
	char op; cin >> op;
	op == 'y' ? task.isCompleted = true : task.isCompleted = false;
	Tasks.push_back(task);
}
void RemoveTask(vector<stTasks>& Tasks) {
	string n;
	cout << "What's Task Name which you want to remove it? ";
	cin.ignore();
	getline (cin , n);
	bool flag = false; int it = 0;
	for (int i = 0; i < Tasks.size();i++) {
		if (Tasks[i].name == n) {
			flag = true;
			it = i;
			break;
		}
	}
	if (flag) {
		Tasks.erase(Tasks.begin() + it);
		cout << "Removed \n";
	}
	else
		cout << "Not find this task! \n";
}
void MarkCompleted(vector<stTasks>& Tasks) {
	cout << "Enter the task name: "; 
	string n; 
	cin.ignore();
	getline(cin, n);
	bool flag = false; int indx = 0;
	for (int i = 0; i < Tasks.size();i++) {
		if (Tasks[i].name == n) {
			flag = true;
			indx = i;
			break;
		}
	}
	if (flag)
		Tasks[indx].isCompleted = true;
	else
		cout << "This task not found! \n";
		
}
void ShowAllTasks(vector<stTasks>& Tasks) {
	cout << "The Number of tasks is " << Tasks.size() << '\n';
	if (Tasks.empty()) {
		cout << "No tasks found!\n";
		return;
	}
	cout << boolalpha;   // to print true or false not 1 or 0
	for (int i = 0;i < Tasks.size();i++) {
		cout << "Task[" << i + 1 << "] " << "name: " << Tasks[i].name << ",   Completed? " << Tasks[i].isCompleted << '\n';
		cout << "**********************************************************\n";
	}
}

void SaveTasksToFile(vector<stTasks>& Tasks) {
	ofstream out("tasks.txt");
	for (const auto& task : Tasks) {
		out << task.name << '\n' << task.isCompleted << '\n';
	}
	out.close();
}

void LoadTasksFromFile(vector<stTasks>& Tasks) {
	ifstream in("tasks.txt");
	if (!in) return;

	stTasks task;
	while (getline(in, task.name)) {
		in >> task.isCompleted;
		in.ignore(); 
		Tasks.push_back(task);
	}
	in.close();
}

void ResetScreen() {
	system("cls");
	system("color 0F");
}
void startprogram() {
	vector<stTasks> Tasks;
	LoadTasksFromFile(Tasks);
	char again = 'y';
	do {
		ResetScreen();
		cout << "What do you want? \n";
		cout << "1. add task \n";
		cout << "2. remove task \n";
		cout << "3. mark a task is completed \n";
		cout << "4. view all tasks \n";

		switch (ReadNumber()) {
		case 1:
			AddTask(Tasks);
			break;
		case 2:
			RemoveTask(Tasks);
			break;
		case 3:
			MarkCompleted(Tasks);
			break;
		case 4:
			ShowAllTasks(Tasks);
			break;
		}
		cout << "Do you want another operation? y or n ---> ";
		cin >> again;
	} while (tolower(again) == 'y');
	ResetScreen();
	ShowAllTasks(Tasks);
	cout << "\n\n         Thank you       \n\n\n\n ";
}
int main()
{
	startprogram();

	return 0;

}

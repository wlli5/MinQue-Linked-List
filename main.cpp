//William Thai
//Section 517
//wlli5
//wlli5@tamu.edu

#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <random>
#include <limits>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <stack> 
int counter = 0;
int arrayCount[10];
//int Back = 1;
stack<int> stroke;
string e;
bool x = false;

void showstack(stack <int> s)
{
	int ogSize = s.size();
	while (s.size() != 2)
	{
		cout << "(" << s.top() << ",";
		s.pop();
		cout << s.top() << ") -> ";
	}
	cout << "(" << s.top() << ",";
	s.pop();
	cout << s.top() << ")";
	cout << endl;
}
bool exist(vector<vector<int>> graph2d)
{
	return true;
}
bool Search(vector<vector<int>> graph2d, int node)
{
	int edgesA = 0;
	stroke.push(node);
	for (int i = 0; i < graph2d.size(); ++i)
	{
		for (int j = 0; j < graph2d[0].size(); ++j)
		{
			if (graph2d[i][j] == 1)
			{
				edgesA = 1;
			}
		}
	}
	if (edgesA != 1)
	{
		return true;
	}
	else
	{
		for (int j = 0; j < graph2d[0].size(); ++j)
		{
			if (graph2d[node][j] == 1)
			{
				
				graph2d[node][j] = 0;
				graph2d[j][node] = 0;
				
				bool f = Search(graph2d, j);
				if (f)
				{
					return true;
				}
				else
				{
					graph2d[node][j] = 1;
					graph2d[j][node] = 1;
				}
			}
			
		}
		stroke.pop();
		return false;
	}
}

int main() {
	cout << "enter '1','2','3','4','5' or '6' for the corresponding graph, type 'end' to terminate program" << endl;
	string inputf;
	cin >> inputf;
	while (inputf != "end")
	{
		ifstream filename("g" + inputf + ".txt");
		string num;
		if (!filename.is_open())
		{
			cout << "wrong input you dummy C;" << endl;
			break;
		}

		getline(filename, num);
		string d1 = num.substr(0, num.find(" "));
		string d2 = num.substr(num.find(" ") + 1, num.size());
		int D1 = stoi(d1);
		++D1;
		int D2 = stoi(d2);
		++D2;
		vector<vector<int>> graph2d(D1);
		for (int i = 0; i < D1; ++i)
		{
			graph2d[i] = vector<int>(D2);
			for (int k = 0; k < D2; ++k)
			{
				graph2d[i][k] = 0;
			}
		}
		int out1;
		int out2;
		while (!filename.eof())
		{
			getline(filename, num);
			string n1 = num.substr(0, num.find(" "));
			string n2 = num.substr(num.find(" ") + 1, num.size());
			stringstream num1(n1);
			stringstream num2(n2);
			num1 >> out1;
			num2 >> out2;
			for (int i = 0; i < D1; ++i)
			{
				for (int k = 0; k < D2; ++k)
				{
					if (i == out1 && k == out2)
					{
						graph2d[i][k] = 1;
					}
					else if (i == out2 && k == out1)
					{
						graph2d[i][k] = 1;
					}
				}
			}
		}
		for (int i = 0; i < D1; ++i)
		{
			int st = 1;
			for (int k = 0; k < D2; ++k)
			{
				if (graph2d[i][k] == st)
				{
					cout << i;
					++st;
				}
				if (graph2d[i][k] == 1)
				{
					cout << " -> " << k;
				}
			}
			cout << endl;

		}

		int startV = 1;
		int Plausible = 0;
		while (startV != graph2d.size())
		{

			if (Search(graph2d, startV))
			{
				++Plausible;
				cout << "Possible for " << startV << endl;
				showstack(stroke);
				while (!stroke.empty())//clear stack
				{
					stroke.pop();
				}
			}
			startV++;
		}
		if (Plausible == 0)
		{
			cout << "No Solution" << endl;
		}
		cout << "enter '1','2','3','4','5' or '6' for the corresponding graph, type 'end' to terminate program" << endl;
		cin >> inputf;
	}
	//system("pause");
}
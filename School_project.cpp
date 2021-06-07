#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Teacher{ 
private: 
	int ID;
	string Name;
	vector<string> TimeOutsideGate;
	map<string, int> KeysJournal;
	vector<string> TimeTeacherRoom;
	
	void ID_Name(int a, string b){
		ID=a;
		Name=b;
		return;
	}
	void TimeOutsideGate_void(string a){
		TimeOutsideGate.push_back(a);
		return;
	}
	void TimeTeacherRoom_void(string a){
		TimeTeacherRoom.push_back(a);
		return;
	}
	void KeysJournal_void(string a, int b){
		KeysJournal[a]=b;
		cout<<a<<"---"<<KeysJournal[a]<<endl;
		return;
	}
	
	
public:

	void _ID_Name(int a, string b){
		ID_Name(a, b);
		return;
	}
	void _timeOutsideGate_void(string a){
		TimeOutsideGate_void(a);
		return;
	}
	void _timeTeacherRoom_void(string a){
		TimeTeacherRoom_void(a);
		return;
	}
	void _keysJournal_void(string a, int b){
		KeysJournal_void(a, b);
		return;
	}
};

int main(){
	//Перенаправления потоков
	//ifstream in("OutsideGate.txt");
	vector<Teacher> V(count);
	//int mas{234, 500, 12};
	string fio;
	//string Mas{"Ilya", "Petr", "Ivan"};
	int count=3, i, id;
	for(i=0; i<count;i++){//count - число учителей
		//V.push_back(V[i]);
		cin>>id>>fio;
		V[i]._ID_Name(id, fio);
		V[i]._keysJournal_void("10.10.2018 15:56", 1);
	}
	//Teacher A(234, "Ilya");
	//A._keysJournal_void("10.10.2018 15:56", 1);
	
	//закончить поток с файлами
	
	string Zapros;
	int X, flag=1;
	cin>>Zapros;
	while(Zapros!="Exit"){
		if(Zapros=="LateByID"){
			cin>>X;
			flag=0;
			for(i=0; i<count;i++){
				if(V[i]->ID==X){
					//V[i].TimeOutsideGate[];
				}
			}
			//если зашел в школу после 8:30 то выводим фио и даты опозданий
		}
		if(Zapros=="KeysByID"){
			//проверка на время
			for(i=0; i<count;i++){
				
			}
			flag=0;
		}
		if(flag){
			cout<<"Некорректный запрос"<<endl;
		}	
		cin>>Zapros;
		flag=1;
	}
	
	return 0;
}
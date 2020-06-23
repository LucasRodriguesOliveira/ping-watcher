#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <thread>
#include <string>
#include <typeinfo>

using namespace std;

void ping(string);
void check_file();
void reconnect();
void run(string);
void onend();
void destroy_files();

int main(int argc, char *argv[]) {
	
	setlocale(LC_ALL, "portuguese");
	atexit(onend);
	
	cout << "Inicializando ping-watcher..." << endl;
	cout << "Observando latência de rede. Limite de [" << argv[1] << "ms]" << endl;
	
	run(argv[1]);
    return 0;
}

void run(string maxtime) {
	while(true) {
		thread exec_ping (ping, maxtime);
		thread exec_file (check_file);
		
		exec_ping.join();
		exec_file.join();
	}
}

void onend() {
	cout << "Finalizado!" << endl;
	
	destroy_files();
	
	system("pause");
}

void ping(string maxtime) {
	string cmd = "ping 8.8.8.8 -w " + maxtime + " > ping.txt";
	system(cmd.c_str());
}

void check_file() {
	string ip_failed_msg = "Esgotado o tempo limite do pedido.";
	ifstream file;
	string line;
	int timesfailed;
	
	file.open("ping.txt");
	if(file.is_open()) {
		while(getline(file, line)) {
			size_t found = line.find(ip_failed_msg);
			if(found != string::npos) {
				timesfailed++;
			}
			
			if(timesfailed == 2) {
				break;
			}
		}
		
		file.close();
		
		if(timesfailed == 2) {
			cout << "Falha detectada" << endl;
			reconnect();
		}
	} else {
		cout << "Não foi possível ler o arquivo" << endl;
	}
}

void reconnect() {
	cout << "Reconectando..." << endl;
	system("ipconfig /release");
	system("ipconfig /renew");
	system("cls");
	cout << "Reconectado!" << endl;
	cout << "Observando latência..." << endl;
}

void destroy_files() {
	if(remove("ping.txt") != 0) {
		cout << "Erro ao excluir arquivo. Tente excluí-lo manualmente!" << endl;
	}
}


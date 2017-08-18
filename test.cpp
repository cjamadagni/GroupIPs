/* Program to read a set of IP addresses from a file
   and segregate them based on theri CIDR notation. */ 	 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
using namespace std;

class IPClassify {

	private:
		array<vector<string>,33> map; // Using an array of vectors to store the IPs
		ifstream dataFile;
	
	public:
		
		IPClassify() {
			dataFile.open("data.txt");
			parseData();
		}

		~IPClassify() {
			dataFile.close();
		}

		void parseData() {
			string ip_address;

			if (dataFile.is_open()) {
				while(getline(dataFile,ip_address)) {
					classifyIP(ip_address);
				}
			}
		}

		void classifyIP(string ip) {
			// Getting the CIDR notation
			int cidr = stoi(ip.substr(ip.size()-2,2));

			// Storing the IP
			if(cidr > 32 || cidr < 0) {
				cout << "Incorrent IP address: " << ip << endl << endl;
				return;  
			}
			
			map[cidr].push_back(ip);
		}

		void printIP() {
			int i,j;
			cout << endl;

			for(i = 0; i < 33; i++) {
				if (map[i].size() == 0) {
					continue;
				}
				else {
					cout << "IPs with CIDR = " << i << endl;

					for (j = 0; j < map[i].size(); j++)
						cout << map[i][j] << endl;
				}
				cout << endl << endl;
			}
		}
};


int main() {
	
	IPClassify ip;
	ip.parseData();
	ip.printIP();
	
	return 0;	
}
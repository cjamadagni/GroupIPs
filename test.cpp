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
		array<vector<string>,32> map; // Using an array of vectors to store the IPs

	public:
		void classifyIP(string ip) {
			// Getting the CIDR notation
			int cidr = stoi(ip.substr(ip.size()-2,2));

			// Storing the IP
			map[cidr-1].push_back(ip);
		}

		void printIP() {
			int i,j;
			cout<<endl;

			for(i=0;i<32;i++) {
				if (map[i].size()==0)
					continue;
				else {
					cout<<"IPs with CIDR = "<<i+1<<endl;

					for (j=0;j<map[i].size();j++)
						cout<<map[i][j]<<endl;
				}
				cout<<endl<<endl;
			}
		}
};


int main() {
	
	string ip_address;
	IPClassify ip;

	ifstream dataFile;
	dataFile.open("data.txt");

	if (dataFile.is_open()) {
		while(getline(dataFile,ip_address))
			ip.classifyIP(ip_address);
	}
	
	dataFile.close();
	ip.printIP();

	return 0;	
}
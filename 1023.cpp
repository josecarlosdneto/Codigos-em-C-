#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main () {
	int quant, cidade = 1;
	int c, p;
	map <int, int> map_cp; 
	float total_p = 0 , total_c= 0;
	
	while( cin >> quant, quant != 0) {
		cout << "cidade# " << cidade << ":\n";
		
		for (int i = 0; i < quant; i++) {
			cin >> p >> c;
			int key = c/p;
			auto it = map_cp.find(key);
			
			if(it != map_cp.end()) {
				map_cp[key] += p;
			}
			
			map_cp.insert({ c/p, p});
			
			total_p += p;
			total_c += c;
		} 
		
		for (auto it = map_cp.begin(); it != map_cp.end(); ++it) {
			
			cout << it->second << "-" << it->first << " ";
		cout << "\n";
		
		cout << "Consumo medio :" << set_fixed << setprecision << total_c/total_p << " m³.\n \n";	
		total_p = total_c = 0;
		
			cidade++;
			map_cp.clear();
		}
		
	}
	
}

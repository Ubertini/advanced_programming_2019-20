#include <iostream>

int main(){
	double i;
	while(!(std::cin >> i)){
		std::cin.clear();
		std::cin.ignore();
		std::cout<<"Please enter a number"<<std::endl;
		}
	std::cout<<i<<std::endl;
	return 0;
}

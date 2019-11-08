#include <iostream>

int main(){
	double fattore_conversione=0.0254;
	std::string si;
	double n;
	std::cin >> n;
	std::cin >> si;
	if(si=="m"){
		std::cout<<n<<" "<<si<<std::endl;
	}
	else{
		n=n*fattore_conversione;
		std::cout<<n<<" "<<"m"<<std::endl;
	}
}
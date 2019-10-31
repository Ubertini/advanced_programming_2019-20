#include <iostream>

int main(){
	std::string line;
	int i=1;
	std::string s1;
	std::string s2;
	std::string tmp;
	std::getline(std::cin,s1);
	while(std::getline(std::cin,line))
	{
		if(line==s1){
			i+=1;
		}
		if(s1!=line){
			std::cout<<i<<"\t"<<s1<<std::endl;
			i=1;
			s1=line;
		}
	}
	std::cout<<i<<"\t"<< s1 <<std::endl;

	return 0;
}
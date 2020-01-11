#include <map> 
#include <iostream>
int main(){
std::map<std::string, int> words; for (std::string s; std::cin>>s;)
{	++words[s];
	std::cout<<words[s]<<std::endl;
	if(s=="out") break;
}
for (const auto& x: words) std::cout << x.first << ": "<< x.second << std::endl;
}
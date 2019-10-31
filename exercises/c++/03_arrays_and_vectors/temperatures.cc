#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main(int argc, char* argv[]){
	std::string line;
	std::vector<double> v;
	int n=0;
	while(std::getline(std::cin,line)){
		v.push_back(std::stod(line));
		n+=1;
	}
	std::cout<<n<<std::endl;
	std::sort( v.begin(), v.end() );
	double mean=0;
	for(int i=0;i<n;i++){
		mean+=v[i];
	}
	mean=mean/n;
	std::cout<<mean<<std::endl;
	double median;
	if(n%2){
		median=v[int(n/2)];
		std::cout<<median<<std::endl;
	}
	else{
		median=(v[n/2]+v[n/2-1])/2;
		std::cout<<median<<std::endl;
	}
	std::cout<<v[25]<<"\t"<<v[24]<<std::endl;

}
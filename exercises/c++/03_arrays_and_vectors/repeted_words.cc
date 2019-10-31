#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <string.h>


int main(int argc, char* argv[]){
	std::vector<std::string> v;
	std::string word;
	std::string word1;
	std::vector<std::string> no_rep;
	int n=0;
	/*std::getline(std::cin,word1)
	v.push_back(word1);*/
	while(std::getline(std::cin,word))
	{		
			if(n==0){
				if(!(word[word.size()])){
					word1 = word.substr(0, word.size()-1);
					v.push_back(word1);
					n+=1;
				}
			}
			else{
			v.push_back(word);
			n+=1;}
    }
    for(int i=0;i<n;i++){
    	std::cout<<v[i]<<std::endl;
    }
    std::cout<<std::endl;
    no_rep.push_back(v[0]);
    int unrepeted_words=1;
	for(int i=1;i<n;i++){
    	int temp=0;
    	for(int j=0;j<unrepeted_words;j++){
    		if(v[i].compare(no_rep[j])==0){break;}
    		else{temp+=1;
    			//std::cout<<v[i]<<"\t"<<no_rep[j]<<"\t"<<temp<<std::endl;//
    		}
    	}
    	if(temp==(unrepeted_words)){
    		no_rep.push_back(v[i]);
    		unrepeted_words+=1;	
    		
    	}
	}
	std::cout<<"words without duplication:"<<std::endl;
	std::cout<<"\n";
	for(int i=0;i<unrepeted_words;i++){
		std::cout<<no_rep[i]<<std::endl;
	}


} 

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <string.h>
#include <map>
#include <sstream>
#include <fstream>
#include <chrono>
#include <unordered_map> 

int main(){
	std::string name_of_the_file;
	std::cout << "Enter the name of the file you want to read:" << std::endl;
	std::cin >> name_of_the_file;
	std::ifstream file(name_of_the_file);
	if (!file)
    {
        std::cout << "There was a problem opening the file.";
        return 0;
    }



    std::vector<std::string> Text;
    std::string single_word;

	while(file >> single_word){

		for (int i = 0, len = single_word.size(); i < len; i++){
			auto c=single_word[i];
         if (ispunct(c) && c != '`' || c == ' " ') 
        {
            single_word.erase(i--, 1);
            len = single_word.size();
        }
    }    
    if(single_word != "")
   		 Text.push_back(single_word);
	}

	std::sort( Text.begin(), Text.end() );
	for(int i=0;i<Text.size();i++){
    }
    std::cout<<"Tell me method between: Vector, Map or Unordered_Map"<<std::endl;
    std::cout<<std::endl;
    std::string method;
    std::cin>>method;
    

    if(method=="Vector"){
      	auto t0 = std::chrono::high_resolution_clock::now();
    	std::vector<std::string> no_repetion;
		std::vector<int> number_of_repetion;
		no_repetion.push_back(Text[0]);
    	number_of_repetion.push_back(1);
    	int unrepeted_words=0;
   		for(int i=1;i<Text.size();i++){
			if(Text[i].compare(Text[i-1])==0){
				number_of_repetion[unrepeted_words]+=1;
			}
			else{
    			no_repetion.push_back(Text[i]);
    			number_of_repetion.push_back(1);
    			unrepeted_words+=1;}
    		}

    	auto t1 = std::chrono::high_resolution_clock::now();
    	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
    	std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl;	
    	
    	/*for(int i=0;i<no_repetion.size();i++){
   		std::cout<<no_repetion[i]<<"  "<< number_of_repetion[i]<<std::endl;
   		}*/
    }
    else if(method=="Map"){
    	auto t0 = std::chrono::high_resolution_clock::now();
    	std::map<std::string, int> order; 
    	for(int i=0;i<Text.size();i++){
    		order[Text[i]]+=1;}
		auto t1 = std::chrono::high_resolution_clock::now();
    	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
    	std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl;	
   		for (auto i = order.begin(); i != order.end(); i++) { 
        	std::cout << i->first << " : " << i->second << '\n'; 
    	} 
    }

    else if(method=="Unordered_Map"){
    	auto t0 = std::chrono::high_resolution_clock::now();
    	std::unordered_map<std::string, int> order; 
    	for(int i=0;i<Text.size();i++){
    		order[Text[i]]+=1;}
		auto t1 = std::chrono::high_resolution_clock::now();
    	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
    	std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl;	
   		/*for (auto i = order.begin(); i != order.end(); i++) { 
        	std::cout << i->first << " : " << i->second << '\n'; 
    	} */
    }
    
} 

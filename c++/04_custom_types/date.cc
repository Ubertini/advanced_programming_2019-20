#include<iostream>
#include<string>
#include<vector>

enum class Month{January=1, February, March, April, May, June, July, August, September, October, November, December};


class Date{
 private:
  unsigned int _day;
  Month _month;
  unsigned int _year;
  void add_day(){
  	  	_day++;}

 public:
	Date();
   	Date(unsigned int day, Month mese, unsigned int year): 
   		_day{day},
        _month{mese},
        _year{year}{}  // custom constructor
  	
  	~Date(){}
  	  void print() {std::cout << "Month = " << int(_month) << std::endl;}
  	  auto day() const{return _day;}
  	  auto month() const{return _month;}
  	  auto year() const{return _year;}
  	  void add_days(const unsigned int n){
  	  	for(int i=0;i<n;i++){
  	  		switch(_month){
	  	  		case Month::January: case Month::March: case Month::May: 
	  	  		case Month::July: case Month::August: case Month::October: 
	  	  		case Month::December:

	  	  			if(_day<31){add_day();}
	  	  			else if(_day==31 && _month != Month::December){
	  	  					_day=1;
	  	  					_month=Month(int(_month)+1);}
	  	  			else if(_day==31 && _month==Month::December){
	  	  					_day=1;
	  	  					_month=Month::January;
	  	  					_year++;
	  	  			}
	  	  		break;
	  	  		
	  	  		case Month::April: case Month::June: case Month::September: 
	  	  		case Month::November : 
	  	  			if(_day<30){add_day();}
	  	  			else{	
	  	  					_day=1;
	  	  					_month=Month(int(_month)+1);}
	  	  		break;
	  	  		case Month::February:
	  	  			if(_day<28){add_day();}
	  	  			else{	
	  	  					_day=1;
	  	  					_month=Month::March;}
	  	  		break;
			}

			//std::cout<<_day<<"/"<<int(_month)<<"/"<<_year<<std::endl;
  	  	}

	}
};   

bool operator==(const Date& lhs, const Date& rhs){if(lhs.day()==rhs.day() && lhs.month()==rhs.month() && lhs.year()==rhs.year()) return true;
	else return false;};
bool operator!=(const Date& lhs, const Date& rhs){return !(lhs==rhs);};
std::ostream& operator<<(std::ostream& os, const Date& d){
	os <<"dd/mm/year:"<< d.day() << "/" << int(d.month()) << "/" << d.year();
	return os;
	};


    
int main() {
  Month mese{Month::January};
  Date date{1, mese, 1994};
  Date date1{1, mese, 1994};
  Date date2{2, mese, 1994};
  /*date.add_days(365);
  std::cout<<date<<std::endl;
  std::cout<<(date==date2)<<std::endl;*/
  return 0;
}
#include <iostream>
#include <unordered_map>
#include <string>
#include <format>

int main(){

  std::unordered_map< std::string, int> ageMap;

  // Insertion
  ageMap["Alice"] = 5;
  ageMap["Frank"] = 6;


  // Access
  //std::cout << "Alice's age is : " << ageMap["Alice"] << std::endl;


  // Search for a key
  //
  //
  //bool found = 0;
  //for(auto it = ageMap.begin(); it != ageMap.end(); ++it){
      //if(it->first == "Alicer"){
          //std::cout << "Alicer is found" << std::endl;
          //found = 1;
          //break;
      //}
        ////std::cout << it->first << ", " << it->second << '\n';
  //}
//
  //if(!found){
    //std::cout << "Alicer is not found" << std::endl;
  //}

  if(ageMap.find("Alice") != ageMap.end()){
      std::cout << "Alice is found" << std::endl; 
  }
  else{
  std::cout << "Alice is not found" << std::endl;
  };


  //if(ageMap.find("Alice") == ageMap.end()){
    //std::cout << "Alice is not found" << std::endl;
  //}

  //std::cout << "Alice's age is : " << ageMap["Alice"] << endl;
  //
  //
  //
  std::cout << "Displaying ageMap" << std::endl;
  //for(auto elem : ageMap){
      //std::cout << std::format("{} \n", elem);
//
  //}
  //
  //Method 2
  //for(auto& [name, age] : ageMap){
    //std::cout << name << " ," << age << std::endl;
  //}

  // method 3
  


  
  return 0;

};

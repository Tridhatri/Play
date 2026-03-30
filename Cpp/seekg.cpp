#include <fstream>
#include <iostream>



  int main() {
      // INPUT - Reading
      std:: ifstream infile("data.txt");
      infile.seekg(0);              // jump to byte 5
      char ch0;

      // tellg tells where you are in reading
      std :: cout << " The current posistion of the reading file pointer is at :   "<< infile.tellg() << std::endl;                                    
      infile.get(ch0);               // read one character
      std::cout << " The first character in the file is : " <<ch0 << std::endl;
      
      infile.seekg(1);              // jump to byte 5
      char ch1;
      infile.get(ch1);               // read one character
      std::cout << " The second character in the file is : " <<ch1 << std::endl;

      infile.seekg(2);              // jump to byte 5
      char ch2;
      infile.get(ch2);               // read one character
      std::cout << " The third character in the file is : " <<ch2 << std::endl;

      std :: cout << " After 3 reads, The current posistion of the reading file pointer is at :   "<< infile.tellg() << std::endl;                                    

      // OUTPUT - Writing
      std::ofstream outfile("output.txt");
      outfile.write("Hello", 5);    // write "Hello"
      outfile.seekp(0);             // go back to start
      outfile.write("H", 1);        // overwrite first character
      std :: cout << " The current posistion of the file pointer is at :   "<< outfile.tellp() << std::endl;                                    
      outfile.seekp(1);             // go back to start
      outfile.write("E", 1);        // overwrite first character
      //tellp tells where you are in writng
     
      // lets read again to see
      std::ifstream infile2("output.txt");
      std::string line; 
      while(std::getline(infile2, line)) {
          std ::cout << line << std::endl;
      }
      //
      // 
      return 0;
  }




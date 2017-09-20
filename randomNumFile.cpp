#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;
//creates and returns a random character
char randomChar(){

  int randInt = rand() % 65 + 122;
  //change that allows for character conversion
  return (char)randInt;
}
//arguments follow the following order: filename, number of characters
int main(int argc, char *argv[]){

  if(argc < 3){
    std::cout << "Not enough arguments!" << std::endl;
  }
  else if(argc > 3){
    std::cout << "Too many arguments!" << std::endl;
  }

  else{
    //take first argument as the file name and write to it
    ofstream testFile;
    testFile.open(argv[1]);

    if(!testFile.is_open()){
      std::cout << "Invalid file!" << std::endl;
    }
    else{
      //seed random number generator for program
      //only does this after program is initialized properly
      srand(time(NULL));

      int i = atoi(argv[2]);

      for(int n = 0; n <= i; n++){
        testFile << randomChar() << " ";
      }

      testFile << "\n";

      testFile.close();
    }
  }

  return 0;

}

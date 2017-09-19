#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

char* randomNum(){}

int main(int argc, char *argv[]){

  if(argc < 3){
    cout << "Not enough arguments!" << endl;
  }

  else{
    //take first argument as the file name and write to it
    ofstream testFile;
    testFile.open(argv[0]);

    
  }

  return 0;

}

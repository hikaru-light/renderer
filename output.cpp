#include <iostream>
#include <fstream>
#include <vector>

const int WIDTH = 512;
const int HEIGHT = 512;

int main(){
  vector<vector<vector<int>>> vi(a, vector<vector<int>>(b, vector<int>(c)));

  std::ofstream outputfile("test.ppm");
  outputfile<<"P3\n"<<WIDTH<<" "<<HEIGHT<<"\n255\n";

  for(int y=0; y<HEIGHT; y++) {
    for(int x=0; x<WIDTH; x++) {
      outputfile
        <<(int)(255*((float)x/WIDTH))
        <<" "
        <<(int)(255*((float)y/HEIGHT))
        <<" "
        <<"255\n";
    }
  }

  outputfile.close();
}

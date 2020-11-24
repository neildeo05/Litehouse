//Testing out contigous memory and strides

#include <iostream>
#include <vector>

using namespace std;
struct Block {
  int size;
  int stride[2];
  int* start;
  Block(int size): size(size) {
    start =(int *) malloc(size * sizeof(int));
  }
  Block(vector<int> data) {
    size = data.size();
    start =(int *) malloc(size * sizeof(int));
    stride[0] = 0;
    for(int i = 0; i < size; i++) {
      start[i] = data[i];
    }
  }
  Block(vector<vector<int> > data) {
    size = data[0].size();
    start =(int *) malloc(size * sizeof(int));
    stride[0] = size;
    for(int i = 1; i < data.size(); i++) {
      if(size != data[i].size()) {
        stride[i] = data[i].size(); 
      }
      else {
        stride[i] = size;
      }
    }
    vector<int> tmp;
    int len = data.size();
    int counter = 0;
    for(int i = 0; i < size; i++) {
      for (int j = 0; j < stride[i]; j++) {
        start[counter] = data[i][j];
        counter++;
      }
    }
  }

  ~Block() {
    free(start);
  }
  
  int getStride(){
    return stride[0];
  }
  void get() {
    if(stride[0] == 0) {
      for(int i = 0; i < size; i++) {
        cout << (start[i]);
      }
      cout << endl;
    }
    else{
      int len = (stride[0] + stride[1]);
      for(int i = 0; i < len; i++) {
        if(i == stride[0] || i == len) {
          cout << endl;
        }
        cout << start[i];
      }
    }
  }
};

int main() {
  Block* b = new Block({{1,2,3},{4,5,6,7}});
  b->get();
  delete b;
}

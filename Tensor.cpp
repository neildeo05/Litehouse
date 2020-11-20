#include <iostream>
#include <vector>
#include <random>
struct Tensor {
  uint64_t size;

  std::vector<std::vector<double>>data;
  int sh[2];
  Tensor(std::vector<double>data_) {
    size = data_.size();
    data.push_back(data_);
    sh[0] = data[0].size();
    sh[1] = 0;
  };
  Tensor(std::vector<std::vector<double> > val){
    sh[0] = val.size();
    sh[1] = val[0].size();
    size = sh[0] * sh[1];
    for(int i = 0; i < val.size(); i++) {
      data.push_back(val[i]);
    }

  }
  double& operator()(int index);
  double& operator()(int index1, int index2);
  int len() {
    return size;
  }
  static Tensor zeros(int size) {
    std::vector<double>zerodata(size, 0);
    return Tensor(zerodata);
  }
  static Tensor zeros(int size1, int size2) {
    std::vector<std::vector<double> >zeroData(size1);
    for (int i = 0; i < size1; i++) {
      zeroData[i] = std::vector<double>(size2, 0);
    }
    return Tensor(zeroData);
  }
  static Tensor ones(int size) {
    std::vector<double>onedata(size, 1);
    return Tensor(onedata);
  }
  static Tensor ones(int size1, int size2) {
    std::vector<std::vector<double> >oneData(size1);
    for (int i = 0; i < size1; i++) {
      oneData[i] = std::vector<double>(size2, 1);
    }
    return Tensor(oneData);
  }
  static Tensor randarr(int size) {
     auto getRand  = [](){
      static std::default_random_engine e;
      std::uniform_real_distribution<> dis(0, 1);
      return dis(e); 
    };
    std::vector<double>nums;
    for(int i = 0; i < size; i++) {
      nums.push_back(getRand());
    }
    return Tensor(nums);
  }
  static Tensor randarr(int size1, int size2) {
     auto getRand  = [](){
      static std::default_random_engine e;
      std::uniform_real_distribution<> dis(0, 1);
      return dis(e); 
    };
    std::vector<std::vector<double> >nums(size1);
    for(int i = 0; i < size1; i++) {
      for (int j = 0; j < size2; j++) {
        nums[i].push_back(getRand());
      }
    }
    return Tensor(nums);
  }

  int *shape() {
    std::cout << '[' << sh[0] << ',' << sh[1] << ']' << '\n';
    return sh;
  }

  friend std::ostream& operator<<(std::ostream& os, const Tensor t) {
    if(t.data.size() == 1) {
      std::vector<double> d = t.data[0];
      os << '[';
      int i;
      for(i = 0; i < t.data[0].size() - 1; i++) {
        os << t.data[0][i] << ",";
      }
      os << t.data[0][i];
      os << ']';
    }
    else{
      os << '[';
      for(int i = 0; i < t.data.size(); i++) {
      os << '[';
      int j;
        for(j = 0; j < t.data[0].size() - 1; j++) {
          os << t.data[i][j] << ",";
        }
        os << t.data[i][j];
      os << ']';
      }
      os << ']';
    }
    return os;
  }
};

double& Tensor::operator()(int index) {
  if(data.size() == 1) {
    if (index >= data.size()){
      throw "Index out of bounds";
    }
    return data[0][index];
  }
  throw "Cannot access element";

}
double& Tensor::operator()(int index1, int index2){
  if(data.size() == 1) {
    throw "Cannot access two subscript operators on a single dimensional tensor";
  }
  else {
    if(index1 >data.size() - 1){
      throw "Index out of bounds";
    }
    else if(index2 > data[0].size() -1 ){
      throw "Index out of bounds";
    }
    return data[index1][index2];
  }
}

int main() {
  Tensor f({1,2,3});
  std::cout << f << std::endl;
  Tensor p({{2,0.2,3}, {1,2,3}, {1,2,4}});
  std::cout << p << std::endl;
  std::cout << p(0, 1) << std::endl;
  p.shape();
  Tensor t = Tensor::zeros(4,2);
  t.shape();
  std::cout << t(0,1);
  t(0,1) = 2;
  std::cout << t << std::endl;
  Tensor val = Tensor::ones(4,6);
  std::cout<<val<<std::endl;
  Tensor g = Tensor::randarr(3,2);
  std::cout << g << std::endl;


}


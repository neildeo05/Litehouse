# Implementing a Tensor and an Autograd Library in C++ (lightweight)

### NOTE: We only support 1 dimensional and 2 dimensional tensors (for business reasons)


```c++
Tensor t = Tensor({{1,2,3},{4,5,6},{7,8,9}});
Tensor g = Tensor::zeros(3,3);
Tensor a = Tensor::sqrt(t);
std::cout << g[1](2) << std::endl;
//[] is to access an array from a 2d array
//() is to access elements
```

## TODO:
 - [] Variadic Templates (NxN)
 - [] Implement autograd features
 - [] Contigous memory with strides
 - [] Allocte memory on heap rather than on stack
 


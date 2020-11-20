# Implementing a Tensor and an Autograd Library in C++ (lightweight)

### NOTE: We only support 1 dimensional and 2 dimensional tensors (for business reasons)

```c++
Tensor t = Tensor({{1,2,3},{4,5,6},{7,8,9}});
Tensor g = Tensor::zeros(3,3);
Tensor a = Tensor::sqrt(t);
std::cout << a << std::endl;
```


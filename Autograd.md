# Autograd, Gradients, Autodiff, PyTorch source code


```python
import torch
import numpy as np
x = torch.randn(2,2, requires_grad = True)
```
## Definitions and Steps
Autograd - calculate derivatives, records graph of all operations.
Gradients - "Tracing the graph from the root to the leaf and multiplying every gradient in the way using the chain rule"
Backpropogation - Calculate the gradients of ht loss and update the weights to reduce the loss
Steps:
  Define layers
  Forward pass (with act func)
  Loss
  Backward Pass
  Update Weights

Change in the loss for a small change in an Input weight - gradient. Calculated using backprop
Gradient updates weight using learning rate












## sources:
- [Toronto Lecture Notes](https://www.cs.toronto.edu/~rgrosse/courses/csc321_2018/slides/lec10.pdf)
- [Medium Article](https://towardsdatascience.com/pytorch-autograd-understanding-the-heart-of-pytorchs-magic-2686cd94ec95#:~:text=Backpropagation%20is%20used%20to%20calculate,and%20eventually%20reduce%20the%20loss.&text=Forward%20propagate%20on%20the%20architecture,the%20gradient%20for%20each%20weight)

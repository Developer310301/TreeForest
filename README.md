# PlatformIO Library: TreeForest

TreeForest is a versatile C++ library designed for microcontroller boards to efficiently implement tree data structures. This library offers a collection of optimized algorithms tailored to work within the limited resources of microcontrollers, enabling you to effectively manage tree-based data in your embedded projects.

## Features

- Implementation of common tree data structures:
  - Binary search trees
  - AVL trees (balanced binary search trees) (future releases)
  - Red-black trees (future releases)
  - And more!

- Compact memory footprint: The library is optimized to use minimal memory, making it ideal for resource-constrained microcontroller environments.

- Efficient algorithms: TreeForest is designed to deliver fast and reliable performance even on low-powered microcontroller boards.

- Simple and intuitive API: The library provides easy-to-use functions and classes to manage your trees effectively.

## Installation

1. Make sure you have PlatformIO installed. If you don't, follow the installation instructions at [PlatformIO Official Website](https://platformio.org/install).

2. In your PlatformIO project, navigate to the "lib" directory.

3. Clone this repository into the "lib" directory of your PlatformIO project:

```bash
git clone https://github.com/Developer310301/TreeForest.git
```

4. Now, you can include the library in your project by adding the following line to your source files:
```c++
#include <TreeForest/BinaryTree.h>
```

## Usage
### Creating a Binary Search Tree (BST)
```c++
#include <Arduino.h>
#include <TreeForest/BinaryTree.h>

using namespace treeforest;

BinaryTree<int> tree;

void setup(){
    tree.add(23);
    tree.add(234);
    tree.add(-23);
}

void loop(){
    ///Perfom operations on BST
}
```

## Contributions
Contributions to TreeForest are more than welcome! If you find any bugs, want to improve the library, or add new features, please feel free to create issues in the GitHub repository.

## License
This library is licensed under the [GNU GPL-3.0](https://opensource.org/license/gpl-3-0/).
# Data Structure Visualizer

A beautiful and interactive visualization tool for various data structures built with Qt6 and C++.

## Features

### Supported Data Structures
1. **Binary Tree** - Complete binary tree with 15 nodes
2. **Binary Search Tree (BST)** - Sorted binary tree visualization
3. **Graph** - Network visualization with circular layout
4. **Linked List** - Linear data structure with arrows

### Visual Enhancements
- 🎨 **Gradient Backgrounds** - Modern dark-themed UI
- 🌈 **Color-Coded Nodes** - Each node has unique colors from a vibrant palette
- ✨ **Antialiased Lines** - Smooth, thick connecting lines
- 💫 **Styled Components** - Circular nodes with borders and shadows
- 🎯 **Interactive Menu** - Easy-to-use selection interface

### Color Palette
- Red (#e74c3c)
- Blue (#3498db)
- Green (#2ecc71)
- Orange (#f39c12)
- Purple (#9b59b6)
- Turquoise (#1abc9c)

## Building the Project

### Prerequisites
- Qt 6.7.2 or later
- MinGW-w64 11.2.0 or compatible compiler
- CMake 3.26 or later

### Build Steps
```bash
cd qtpro
mkdir build
cd build

# Configure with CMake
cmake -G "MinGW Makefiles" \
  -DCMAKE_C_COMPILER="C:/Qt/Tools/mingw1120_64/bin/gcc.exe" \
  -DCMAKE_CXX_COMPILER="C:/Qt/Tools/mingw1120_64/bin/g++.exe" \
  ..

# Build
cmake --build . --target qtpro

# Run
../lib/qtpro.exe
```

## Usage

1. Launch the application
2. Select a data structure from the main menu:
   - 🌳 Binary Tree
   - 🔗 Graph
   - ➡️ Linked List
   - 🔍 Binary Search Tree
3. The visualization window will open showing the selected structure

## Architecture

### Core Components
- **mainWindow**: Base window management
- **CircleNode**: Styled circular node widget with gradient
- **Line**: Antialiased line drawing for connections
- **Layout**: Grid-based layout manager
- **MenuWindow**: Main menu interface

### Data Structure Implementations
- **TreeNode**: Binary tree with recursive visualization
- **Graph**: Graph structure with circular layout algorithm
- **LinkedListViz**: Linear list with arrow connections
- **MenuWindow**: Central hub for structure selection

## Code Structure
```
qtpro/
├── Sources/
│   ├── CircleNode.cpp/h      # Node visualization
│   ├── Line.cpp/h             # Edge/connection drawing
│   ├── Layout.cpp/h           # Grid layout manager
│   ├── mainWindow.cpp/h       # Window management
│   ├── TreeNode.cpp/h         # Binary tree
│   ├── Graph.cpp/h            # Graph structure
│   ├── LinkedListViz.cpp/h    # Linked list
│   └── MenuWindow.cpp/h       # Main menu
├── graph.cpp                  # Application entry point
├── CMakeLists.txt            # Build configuration
└── README.md                 # This file
```

## Recent Improvements

### Bug Fixes
1. Fixed QApplication initialization (argc/argv handling)
2. Corrected getCellCenter parameter order
3. Fixed display() method calling root instead of subtree
4. Resolved method naming inconsistency (getwidth → getWidth)
5. Fixed column calculation in tree width
6. Removed unused variables

### Visual Enhancements
1. Gradient backgrounds for windows and nodes
2. Color-coded nodes with palette rotation
3. Thicker, antialiased connection lines
4. Modern dark theme with blue gradient
5. Styled menu buttons with hover effects
6. Improved font rendering (bold, larger text)

## Future Enhancements
- [ ] Stack and Queue visualizations
- [ ] Heap (Min/Max) structures
- [ ] AVL and Red-Black trees
- [ ] Animation for insertions/deletions
- [ ] Step-by-step algorithm visualization
- [ ] Custom data input
- [ ] Export visualizations as images
- [ ] Dark/Light theme toggle

## License
This project is built for educational purposes.

## Credits
Created with Qt6 Framework | 2025

# Data Structure Visualizer

A professional Qt6-based application for visualizing various data structures with beautiful graphics and intuitive navigation.

# Screenshot of the Terminal

<img width="639" height="816" alt="Screenshot 2025-12-28 210112" src="https://github.com/user-attachments/assets/76932587-eeee-450e-8a3f-29585902f075" />
<img width="1000" height="979" alt="Screenshot 2025-12-28 212013" src="https://github.com/user-attachments/assets/ab1c62cd-2a53-4008-914f-bec3bb95f73b" />
<img width="928" height="978" alt="Screenshot 2025-12-28 210140" src="https://github.com/user-attachments/assets/49359643-036b-4d87-a77f-126309968c4a" />
<img width="835" height="296" alt="Screenshot 2025-12-28 211959" src="https://github.com/user-attachments/assets/11eadbd0-d402-4400-b4a5-dde7795544fa" />
<img width="999" height="1001" alt="Screenshot 2025-12-28 212040" src="https://github.com/user-attachments/assets/1d30de1d-226c-45c1-9f0a-fa248fb0e443" />
<img width="980" height="351" alt="Screenshot 2025-12-28 212222" src="https://github.com/user-attachments/assets/023f2a88-365a-4051-87ea-87c23186ab38" />
<img width="993" height="138" alt="Screenshot 2025-12-28 212235" src="https://github.com/user-attachments/assets/1e1113d0-ca33-4de2-a1c1-f1b9f67647fe" />


## 📁 Project Structure

```
qtpro/
├── src/                    # Source files (.cpp)
│   ├── graph.cpp          # Main application entry
│   ├── CircleNode.cpp     # Node visualization
│   ├── Line.cpp           # Edge/connection drawing
│   ├── Layout.cpp         # Grid layout manager
│   ├── mainWindow.cpp     # Base window with back button
│   ├── TreeNode.cpp       # Binary tree implementation
│   ├── Graph.cpp          # Graph structure
│   ├── LinkedListViz.cpp  # Linked list visualization
│   └── MenuWindow.cpp     # Main menu interface
│
├── include/               # Header files (.h)
│   └── [corresponding .h files]
│
├── docs/                  # Documentation
│   ├── README.md          # Project overview
│   ├── QUICK_START.md     # Usage guide
│   ├── NAVIGATION.md      # Navigation features
│   └── SHOWCASE.md        # Before/after comparison
│
├── bin/                   # Compiled executables (generated)
├── lib/                   # Static libraries (generated)
├── CMakeLists.txt        # Build configuration
└── .gitignore            # Git ignore rules

```

## 🎯 Features

### Supported Data Structures
- **Binary Tree** - Complete 15-node tree with hierarchical layout
- **Binary Search Tree** - Sorted tree demonstration
- **Graph** - Network visualization with circular layout (6 nodes)
- **Linked List** - Linear structure with arrows (5 nodes)

### Visual Features
- 🎨 **6-Color Rotating Palette** - Vibrant gradient nodes
- 🔙 **Prominent Back Button** - Large, blue gradient button (200x60px)
- 🌊 **Gradient Backgrounds** - Professional dark navy theme
- ⚡ **Smooth Animations** - Antialiased lines and hover effects
- 📐 **Smart Layouts** - Automatic positioning algorithms

## 🚀 Quick Start

### Prerequisites
- Qt 6.7.2 or later
- CMake 3.26+
- MinGW-w64 11.2.0 (64-bit)
- Windows 10/11

### Building

```bash
# Create build directory
mkdir build && cd build

# Configure
cmake -G "MinGW Makefiles" \
  -DCMAKE_C_COMPILER="C:/Qt/Tools/mingw1120_64/bin/gcc.exe" \
  -DCMAKE_CXX_COMPILER="C:/Qt/Tools/mingw1120_64/bin/g++.exe" \
  ..

# Build
cmake --build .

# Run
cd ..
.\bin\qtpro.exe
```

### One-Line Build (PowerShell)
```powershell
cd build; $env:Path = "C:\Qt\Tools\mingw1120_64\bin;" + $env:Path; cmake --build .
```

## 🎮 Usage

1. **Launch Application** - Run `qtpro.exe`
2. **Select Structure** - Click any button on the main menu
3. **Explore Visualization** - View the data structure
4. **Navigate Back** - Click the **◄ BACK TO MENU** button (top-left)
5. **Try Another** - Select different structures without restarting

### Back Button Location
- **Position**: Top-left corner (20px, 20px)
- **Size**: 200 x 60 pixels
- **Color**: Blue gradient with white border
- **Text**: "◄ BACK TO MENU" (bold, 16px)

## 🏗️ Architecture

### Core Components
- **mainWindow** - Base window with navigation
- **CircleNode** - Styled circular node widget
- **Line** - Antialiased connection lines
- **Layout** - Grid-based positioning
- **MenuWindow** - Main navigation hub

### Data Structures
- **TreeNode** - Binary tree with recursive layout
- **Graph** - Network with circular positioning
- **LinkedListViz** - Linear structure display

## 📊 Technical Details

- **Language**: C++17
- **Framework**: Qt 6.7.2
- **Build System**: CMake
- **Architecture**: Modular with shared QApplication
- **Navigation**: Callback-based with hide/show pattern

## 🎨 Color Scheme

### Nodes
- Red: #e74c3c
- Blue: #3498db  
- Green: #2ecc71
- Orange: #f39c12
- Purple: #9b59b6
- Turquoise: #1abc9c

### UI
- Background: Navy gradient (#1a1a2e → #16213e)
- Lines: Light gray (#ecf0f1)
- Back Button: Blue gradient (#3498db → #2980b9)

## 📝 License

Educational project - 2025

## 🤝 Contributing

This is a structured, professional codebase ready for extension:
- Add new structures in `src/`
- Update `CMakeLists.txt` with new files
- Add button in `MenuWindow.cpp`
- Follow existing patterns

---

**Built with ❤️ using Qt6**

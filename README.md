# 🚀 Qt-Powered Data Structure Visualizer

A high-performance, cross-platform **GUI application** built using the **Qt Framework** to **animate, explore, and understand core data structures** like **binary trees** and **graphs**. Designed with a **plugin-ready architecture**, this tool transforms abstract data concepts into rich, dynamic visuals — ideal for learners, educators, and developers seeking deep insights into algorithmic flow.

---

## ✨ Key Highlights

- ⚙️ **Modular Qt Architecture** — Engineered with **QPluginLoader** and a scalable class hierarchy to support rapid expansion.
- 🧠 **Smart Visualizations** — Utilizes **QGraphicsView**, **QPainter**, and **QGridLayout** for real-time rendering of nodes, edges, and transitions.
- 🖱️ **Fully Interactive UI** — Leverages `QPushButton`, `QTextEdit`, `QLabel`, and responsive layouts for seamless user interaction.
- 🧵 **Clean Event Handling** — Structured with `QApplication`, `QResizeEvent`, and custom signals/slots for responsive feedback loops.
- 🛠️ **Multi-Platform Build Support** — Build-ready via both **CMake** and **QMake** for Linux, Windows, and macOS.

---

## 🔧 Tech Stack

| Layer              | Tools & Technologies         |
|--------------------|------------------------------|
| Language           | C++17                        |
| GUI Framework      | Qt Widgets, QPainter         |
| Build Systems      | CMake (Primary), QMake       |
| IDE Support        | Qt Creator, VSCode, CLion    |
| OS Compatibility   | Windows, Linux, macOS        |

---

## 🏗️ Project Structure

📁 src/
├── main.cpp
├── core/ # Logic & structure definitions
├── plugins/ # Visualization modules (BinaryTree, Graph)
└── ui/ # Layouts & widget controls
📄 CMakeLists.txt
📄 project.pro
📄 README.md                                                                                                                                                                                                      



---

## 🔌 Visualizer Modules

- 🌳 **Binary Tree Visualizer** – Auto-aligns nodes, draws edges, supports insertion animations.
- 🌐 **Graph Visualizer** – Visualizes nodes and edges with directed/undirected toggles.
- ⏳ **Coming Soon** – Linked List, Stack, Queue, and Trie visualizations.

---

## ⚙️ Build & Run

### 🔗 Prerequisites

- Qt 5.15+ or Qt 6.x
- CMake ≥ 3.15
- C++17-compliant compiler

### 🧪 Build with CMake

```bash
git clone https://github.com/mohit12932/qt_pro
cd qt_pro
mkdir build && cd build
cmake ..
make
./Visualizer




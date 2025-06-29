# Catan – Qt Desktop Game (Single Machine)

This is a local version of the strategic board game **Catan**, implemented using **C++17 and Qt5**.  
The game is designed to be played by **up to 4 players on the same computer**.

> [Original repository](https://gitlab.com/matf-bg-ac-rs/course-rs/projects-2022-2023/06-catan)

> ⚠️ Note: The `azrs-mi19103` branch contains additional profiling, debugging, and performance analysis work.

---

## 🎮 Game Description

Catan is a turn-based strategy game where 4 players compete to build roads, settlements, and cities using resources gained based on dice rolls.  
The winner is the first player to reach 10 victory points.

This implementation supports:
- Local multiplayer (same computer)
- Dice-based resource generation
- Road, settlement, and city construction
- Point tracking

There is **no networking or online multiplayer support**.

---

## 🎥 Demo Video

[![Catan Demo](https://img.shields.io/badge/YouTube-Demo-red)](https://www.youtube.com/watch?v=ufzqkQhe1UI)

---

## 🧰 Environment

- [![Qt Creator](https://img.shields.io/badge/IDE-Qt_Creator-green)](https://www.qt.io/download)
- [![C++17](https://img.shields.io/badge/Language-C%2B%2B17-red)](https://en.cppreference.com/)
- [![Qt5](https://img.shields.io/badge/Framework-Qt5-blue)](https://doc.qt.io/qt-5/)
- Multimedia Support: `QtMultimedia`

---

## 🚀 Installation & Run Instructions

1. Download and install [**Qt & Qt Creator**](https://www.qt.io/download)
2. Make sure you are using **C++17**
3. Clone the repository:
   ```bash
   git clone https://github.com/your-username/catan-project.git
   cd catan-project
   ```
4. Open Catan.pro in Qt Creator

5. Click Run in the bottom-left corner

## 📚 Dependencies

- `QtMultimedia` (used for sound and media)

---

## 🧪 Profiling & Performance Analysis  
**Branch:** `azrs-mi19103`

This branch contains extensive profiling, debugging, and performance analysis to inspect memory usage, CPU performance, and system calls.

### 🔬 Tools Used

| Tool              | Purpose                                                        |
|-------------------|----------------------------------------------------------------|
| [Valgrind](https://gitlab.com/stefan_103_2019/azrs-tracking/-/issues/?sort=created_date&state=closed&show=eyJpaWQiOiI0IiwiZnVsbF9wYXRoIjoic3RlZmFuXzEwM18yMDE5L2F6cnMtdHJhY2tpbmciLCJpZCI6MTQwNTI4NjgwfQ%3D%3D) | Used Valgrind to identify and fix memory leaks occurring on program start and during gameplay, improving proper memory deallocation on game exit and player victory                                        |
| [cppcheck](https://gitlab.com/stefan_103_2019/azrs-tracking/-/issues/?sort=created_date&state=closed&show=eyJpaWQiOiIzIiwiZnVsbF9wYXRoIjoic3RlZmFuXzEwM18yMDE5L2F6cnMtdHJhY2tpbmciLCJpZCI6MTQwNTI4MTcyfQ%3D%3D)           | Used Cppcheck static analyzer to detect issues like uninitialized variables in constructors and generated detailed reports for code improvements                               |
| [clang-tidy](https://gitlab.com/stefan_103_2019/azrs-tracking/-/issues/?sort=created_date&state=closed&show=eyJpaWQiOiI1IiwiZnVsbF9wYXRoIjoic3RlZmFuXzEwM18yMDE5L2F6cnMtdHJhY2tpbmciLCJpZCI6MTQwNTQ3MDczfQ%3D%3D)            | Ran clang-tidy static analysis in Qt Creator to identify and fix code issues, improving code quality and style compliance       |
| [clang-format](https://gitlab.com/stefan_103_2019/azrs-tracking/-/issues/?sort=created_date&state=closed&show=eyJpaWQiOiI2IiwiZnVsbF9wYXRoIjoic3RlZmFuXzEwM18yMDE5L2F6cnMtdHJhY2tpbmciLCJpZCI6MTQwNTQ3NDkxfQ%3D%3D)          | Created a .clang-format file using the LLVM style to enforce consistent coding style across the project                     |
| [Cmake](https://gitlab.com/stefan_103_2019/azrs-tracking/-/issues/?sort=created_date&state=closed&show=eyJpaWQiOiIyIiwiZnVsbF9wYXRoIjoic3RlZmFuXzEwM18yMDE5L2F6cnMtdHJhY2tpbmciLCJpZCI6MTQwNTI3MzM3fQ%3D%3D)          | Created CMakeLists.txt with compiler flags for warnings and optimization                              |
| [GCov](https://gitlab.com/stefan_103_2019/azrs-tracking/-/issues/?sort=created_date&state=closed&show=eyJpaWQiOiI2IiwiZnVsbF9wYXRoIjoic3RlZmFuXzEwM18yMDE5L2F6cnMtdHJhY2tpbmciLCJpZCI6MTQwNTQ3NDkxfQ%3D%3D) | Configured CMake for code coverage, generated coverage reports using gcov and lcov, and visualized results with genhtml                                          |
| [Docker](https://gitlab.com/stefan_103_2019/azrs-tracking/-/issues/?sort=created_date&state=closed&show=eyJpaWQiOiI5IiwiZnVsbF9wYXRoIjoic3RlZmFuXzEwM18yMDE5L2F6cnMtdHJhY2tpbmciLCJpZCI6MTQwNTc0NDA3fQ%3D%3D)            | Created a Dockerfile, built the Docker image for the project, and verified the image using Docker commands       |
| [Doxygen](https://gitlab.com/stefan_103_2019/azrs-tracking/-/issues/?sort=created_date&state=closed&show=eyJpaWQiOiIxMCIsImZ1bGxfcGF0aCI6InN0ZWZhbl8xMDNfMjAxOS9henJzLXRyYWNraW5nIiwiaWQiOjE0MDU3NzI1OH0%3D)          | Installed Doxygen and Graphviz, configured Doxygen (doxyfile) for project documentation generation with UML class hierarchy graphs, generated HTML reports                     |
| [Clang Analyzer](https://gitlab.com/stefan_103_2019/azrs-tracking/-/issues/?sort=created_date&state=closed&show=eyJpaWQiOiIxMSIsImZ1bGxfcGF0aCI6InN0ZWZhbl8xMDNfMjAxOS9henJzLXRyYWNraW5nIiwiaWQiOjE0MDczNTgzOH0%3D) | Installed Clang, LLVM, and clang-tools; ran scan-build static analyzer on the build with warnings enabled, and confirmed no issues were found                                         |
| [CLazy](https://gitlab.com/stefan_103_2019/azrs-tracking/-/issues/?sort=created_date&state=closed&show=eyJpaWQiOiIxMiIsImZ1bGxfcGF0aCI6InN0ZWZhbl8xMDNfMjAxOS9henJzLXRyYWNraW5nIiwiaWQiOjE0MDczNjE0N30%3D)          |Ran Clazy analyzer within QtCreator, identified issues such as recommending = default for trivial constructors and replacing C-style includes (e.g., math.h) with C++ headers (cmath)                               |
| [Git Hooks](https://gitlab.com/stefan_103_2019/azrs-tracking/-/issues/?sort=created_date&state=closed&show=eyJpaWQiOiIxIiwiZnVsbF9wYXRoIjoic3RlZmFuXzEwM18yMDE5L2F6cnMtdHJhY2tpbmciLCJpZCI6MTQwNTI3MzA2fQ%3D%3D)            | Added Git hooks (commit-msg, pre-commit, post-commit) to enforce commit message format and improve workflow; commit-msg hook blocks improperly formatted commit messages      |


> Archived issue reports are available here:  
👉 [GitLab Closed Issues](https://gitlab.com/stefan_103_2019/azrs-tracking/-/issues/?sort=created_date&state=closed)

---

## 👥 Developers

- [Stefan Drljević](https://github.com/Stefan-Dr)
- [Luka Bura](https://gitlab.com/LukaBura)  
- [Luka Vukotić](https://gitlab.com/luka_120_2019) 
- [Stefan Nešković](https://gitlab.com/snele45) 


---

## 🏷️ License

This project was developed as part of university coursework at the **University of Belgrade – Faculty Of Mathematics**.  
It is intended for learning, demonstration, and research purposes.


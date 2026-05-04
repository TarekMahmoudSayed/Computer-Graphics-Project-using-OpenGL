# 🎨 Computer Graphics Projects (OpenGL + GLUT)

A collection of **5 interactive 2D Computer Graphics projects** implemented using **C++ and OpenGL (GLUT)**.  
Each project demonstrates a key transformation or rendering concept used in real-time graphics systems.

---

## 🚀 Projects Included

### 1️⃣ Diamond Animation (Translation + Rotation)
- Moving diamond shape
- Continuous rotation
- Demonstrates combined transformations

📸 Screenshot:
> Add image here:
```md
![Diamond](images/diamond.gif)
2️⃣ Star Animation (Translation + Reflection)
Animated star movement
Vertical reflection effect (flipping)

📸 Screenshot:

![Star](images/star.gif)
3️⃣ Triangle Animation (Translation + Shearing)
Moving triangle
Dynamic shearing transformation using matrix

📸 Screenshot:

![Triangle](images/triangle.gif)
4️⃣ Rectangle Animation (Translation + Scaling)
Moving rectangle
Smooth scaling (zoom in/out effect)

📸 Screenshot:

![Rectangle](images/rectangle.gif)
5️⃣ Circle Rendering (Midpoint Algorithm + Scaling)
Circle drawn using Midpoint Circle Algorithm
No built-in circle functions used
Animated scaling effect

🧠 Key Concepts Covered
🔷 Transformations
Translation
Rotation
Scaling
Shearing
Reflection
🔷 Graphics Techniques
Matrix-based transformations
Rasterization
Symmetry in drawing
Pixel-level rendering
🔷 Animation System
glutTimerFunc() based animation
~60 FPS update loop
🛠️ Tech Stack
C++
OpenGL
GLUT
📁 Project Structure
Computer-Graphics-Projects/
│
├── diamond.cpp
├── star.cpp
├── triangle.cpp
├── rectangle.cpp
├── circle.cpp
│
├── images/
│   ├── diamond.gif
│   ├── star.gif
│   ├── triangle.gif
│   ├── rectangle.gif
│   └── circle.gif
│
└── README.md
⚙️ How to Run
Install dependencies:
OpenGL
GLUT
g++ compiler
Compile:
g++ filename.cpp -o app -lGL -lGLU -lglut
Run:
./app
🎯 What I Learned
How transformation matrices affect objects in 2D space
Importance of transformation order (Translate → Rotate → Scale)
How animations are built using timer callbacks
How graphics algorithms (like Midpoint Circle) work internally
Difference between built-in rendering vs manual rasterization
📌 Notes
All projects use single buffer mode
Animation is time-based (~16ms interval ≈ 60 FPS)
Each project is independent but follows the same rendering pipeline
⭐ Future Improvements
Add keyboard/mouse interaction
Switch to double buffering
Upgrade to 3D transformations
Use shaders (modern OpenGL)
Convert into a full graphics engine mini-project
👨‍💻 Author

Computer Graphics coursework project using OpenGL (GLUT)

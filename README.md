# 🧟‍♂️ 2D Zombie Survival Shooter (C++ OOP Project)

A **2D top-down zombie survival shooter** developed in **C++** using the **Raylib graphics library**.  
The game demonstrates core **Object-Oriented Programming concepts** including inheritance, polymorphism, encapsulation, abstraction, STL usage, and file handling.

This project was developed as part of an **Object Oriented Programming course** and aims to implement most of the concepts covered in the syllabus through a practical and interactive application.

---

# 🎮 Game Overview

The player must survive against **waves of zombies** that become progressively stronger.  
By defeating zombies, the player earns **in-game money** which can be spent in a **shop system** to upgrade weapons, health, and movement speed.

As the rounds progress:

- Zombie difficulty increases
- Stronger enemy types appear
- Player must strategically upgrade equipment to survive

---

# 🚀 Features

### Core Gameplay
- Player movement and shooting mechanics
- Zombie AI that chases the player
- Real-time collision detection
- Wave-based enemy spawning system

### Enemy System
- Multiple zombie types with different abilities
- Increasing difficulty per round
- Zombies with different health and speed attributes

### Player Progression
- In-game **money system**
- Earn money by killing zombies
- Spend money on upgrades

### Shop System
Players can upgrade:
- Weapons
- Player health
- Player movement speed

### Weapon System
Multiple weapon types implemented using **inheritance**.

Examples:
- Pistol
- Shotgun
- Machine Gun

### GUI / HUD
On-screen interface displaying:
- Player health
- Current money
- Current round
- Equipped weapon

### Game Systems
- Wave / round progression
- Difficulty scaling
- High score saving using file handling

---

# 🧠 OOP Concepts Implemented

This project demonstrates the following **Object-Oriented Programming principles**:

- Classes and Objects
- Encapsulation
- Constructors and Destructors
- Access Modifiers
- Inheritance
- Function Overriding
- Polymorphism
- Abstract Classes
- Composition (Has-A relationships)
- Static Members
- Operator Overloading (optional)
- Friend Functions (optional)
- Templates / Generics
- STL Containers (`vector`, `list`)
- File Handling (`fstream`)
- Exception Handling

---

# 🧩 Project Architecture


Game
│
├── Player
│ └── Weapon
│ ├── Pistol
│ ├── Shotgun
│ └── MachineGun
│
├── Enemy
│ ├── Zombie
│ ├── FastZombie
│ └── TankZombie
│
├── Bullet
├── WaveManager
├── Shop
├── FileManager
└── UIManager


---

# 📂 Project Structure


ZombieShooter/
│
├── main.cpp
│
├── Game.h / Game.cpp
├── Player.h / Player.cpp
├── Enemy.h / Enemy.cpp
├── Zombie.h / Zombie.cpp
├── Weapon.h / Weapon.cpp
├── Bullet.h / Bullet.cpp
├── Shop.h / Shop.cpp
├── WaveManager.h / WaveManager.cpp
├── FileManager.h / FileManager.cpp
│
├── assets/
│ ├── textures
│ ├── sounds
│
└── README.md


---

# 🛠️ Technologies Used

- **C++**
- **Raylib Graphics Library**
- **STL (Standard Template Library)**
- **Object-Oriented Programming**

---

# 🎯 Learning Goals

This project was built to:

- Apply theoretical **OOP concepts** in a real application
- Understand **game architecture**
- Practice **modular C++ project structure**
- Work with **graphics programming using Raylib**

---

# 🧪 Future Improvements

Planned enhancements include:

- Boss zombies
- Additional weapon types
- Power-ups
- Sound effects
- Advanced enemy AI
- Improved UI animations
- Save/load player progress

---

# 📷 Screenshots

*(Screenshots of gameplay will be added here once the game is complete.)*

---

# 📜 License

This project is for **educational purposes** as part of an Object-Oriented Programming course.
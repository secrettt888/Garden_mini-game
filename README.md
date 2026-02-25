# C++ Console Gardening Game 🌱

A text-based simulation game written in C++ where you nurture a plant over a 7-day cycle. Choose your plant, manage its daily needs, and harvest the rewards!

## 🎮 Gameplay Features

At the start of the game, you can choose one of three plants to grow over a week. Each plant has unique needs and rewards:

* **Cherry Tree 🍒:** Requires careful watering. If nurtured correctly, it yields fruits that can be harvested and sold for in-game currency.
* **Rose 🌹:** Needs a delicate balance of water and specific sun exposure (between 5 to 10 hours) to bloom optimally.
* **Carrot 🥕:** Growth is driven by water, but its final "tastiness" and "colourfulness" stats heavily depend on choosing the correct soil quality ("x" for best, "y" for worst).

Every day, your choices and a bit of randomized luck will determine how well your plant thrives. 

## 💻 Technical Highlights

This project was built to practice and demonstrate core **Object-Oriented Programming (OOP)** principles in C++:

* **Inheritance:** Utilizes a base `plant` class with shared attributes (time, water, growth) and derives specialized `tree`, `flower`, and `vegetables` sub-classes.
* **Polymorphism:** Uses virtual functions (like `getattributes()`) to allow derived classes to output their unique properties alongside the base properties.
* **Encapsulation:** Protects internal plant states using `protected` and `private` access modifiers, modifying them safely through getter and setter methods.
* **Memory Management:** Implements virtual destructors to ensure clean memory deallocation across the inheritance hierarchy.
* **Modern Randomization:** Replaces legacy `rand()` with C++11's `<random>` library (`mt19937` and `uniform_int_distribution`) for better and safer random number generation.

## 🚀 Getting Started

### Prerequisites
You will need a standard C++ compiler installed on your machine (such as `g++` or `clang++`).

### Compilation & Execution
To compile and run the game from your terminal, navigate to the project directory and run:

```bash
g++ main.cpp -o garden_game
./garden_game

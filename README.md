

# Artificial Life Game Simulator: Goats and Grass 

This project is a simulation game that models the interaction between goats (predators) and grass (prey) in a bounded 2D world. It was initially developed as part of an assignment in NCCU's Object-Oriented Programming (OOP) class, focusing on demonstrating key concepts such as polymorphism and inheritance.

## Features

- **Dynamic World Simulation**: A 35x20 grid representing a bounded environment.
- **Goat Behavior**:
  - Moves randomly within the grid.
  - Eats grass to regain energy (food points).
  - Ages and reproduces under specific conditions.
  - Dies due to starvation or old age.
- **Grass Behavior**:
  - Grows and spreads new grass within its lifecycle.
  - Dies after reaching a specific age.
- **Polymorphism**: Central to the program's design, allowing flexible creature behavior through inheritance and virtual functions.

## How It Works

1. **Initial Setup**:
   - 5 goats (`X`) and 10 blades of grass (`I`) are randomly placed in the grid.
2. **Simulation Pass**:
   - Each creature takes turns to act (move, eat, reproduce, or age).
   - The program ensures each creature acts only once per pass.
3. **Lifecycle**:
   - Goats age and reproduce between the ages of 50-55.
   - Grass spreads between the ages of 3-5.
   - Both goats and grass have a maximum lifespan.
4. **Command-line Parameters**:
   - Number of simulation passes.
   - Display frequency of the world state.
   - Seed for the random number generator.

## Sample Output

A snapshot of the grid during simulation:

```
X . . I . . X . I . . .
. . . . I X . . . . I .
. . X . . . . . . . . .
I . . . . . . X . . I .
. . . . I . . . . . . .
```

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/lgyeee/Goats_and_Grass.git
   cd Goats_and_Grass/srcs
   ```
2. Compile the program:
   ``` 
   make
   ```
3. Run the simulation:
   ```bash
   ./ALifeTest <passes> <display_frequency> <random_seed>
   ```
   Example:
   ```bash
   ./ALifeTest 1000 10 1234
   ```
4. Watch the simulation in action!

## Design Highlights

- **Encapsulation**: Each class is designed with private and protected members to promote modularity.
- **Polymorphism**: Virtual functions enable dynamic behavior for different types of creatures.
- **Inheritance**: `Goat` and `Grass` classes inherit from a common base class for shared behaviors.

## Future Improvements

- Enhance visualization by integrating graphical output.
- Introduce new creature types for more complex ecosystems.
- Add adjustable world size and more flexible parameters.

## References

- [Assignment Instructions](https://youtu.be/P7C2mLN4ZHM)

# Maze Game 

## Description
Browser-based **maze escape game** built entirely with **HTML5 Canvas** and **JavaScript**.  
The game generates a random maze using **Depth-First Search (DFS)** and lets the player navigate from the **start (top-left)** to the **exit (bottom-right)** using arrow keys or WASD.

features include:
- random maze generation (dfs)
- animated player movement
- timer and step counter
- display of the best path using dfs
- escape message when reaching the goal

## how to play
1. open `mazegame.html` in any modern browser.
2. use **arrow keys** or **wasd** to move the player (red circle).
3. try to reach the green flag at the bottom-right corner.
4. optionally, click the **"show best path (DFS)"** button to see the optimal route.

## controls
- **up / w** : move up  
- **down / s** : move down  
- **left / a** : move left  
- **right / d** : move right  

## customization
- change maze size: modify `cols`, `rows`, and `size` in `script.js`  
- adjust canvas size accordingly: `canvas.width = cols * size`, `canvas.height = rows * size`  



##  How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/maze_project.git
   cd maze_project
   start mazegame.html
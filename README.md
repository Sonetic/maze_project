# Maze Game (JavaScript)

## Description
this is a browser-based maze game built with **html, css, and javascript**. 
The game generates a random maze using **depth-first search (dfs)** and allows the player to navigate it using **arrow keys** or **wasd**. 
The goal is to reach the exit marked by a **green flag**.

features include:
- random maze generation (dfs)
- animated player movement
- timer and step counter
- display of the best path using dfs
- escape message when reaching the goal

## how to play
1. open `index.html` in any modern browser.
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

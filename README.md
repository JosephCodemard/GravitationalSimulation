# GravitationalBodySimulation
A simple C++ OpenGL-based gravitational body simulator that visualizes the motion of celestial bodies governed by Newtonian gravity. The simulation provides a real-time animation of planets, stars, and other objects orbiting under mutual gravitational attraction.

***

## Features
- Realistic Newtonian gravity simulation
- Multiple bodies with adjustable initial positions, masses, and velocities
- Real-time visualization using OpenGL
- Smooth animations with simple camera controls

***

## Future Pipeline

- [ ] **Performance Optimizations**  
Barnes–Hut Algorithm: Improve scaling beyond O(n²) for large systems by approximating distant masses with quad/octrees.  
Parallelization: Use multi-threading with OpenMP or GPU acceleration via CUDA/OpenCL.  

- [ ] **User Interaction**  
Live Editing: Allow users to add/remove bodies dynamically, change parameters during runtime through a simple GUI panel.  
Hover Tooltips: Display information (mass, velocity, distance) in text boxes when hovering over planets.  
Preset Scenarios: Load pre-configured solar systems or binary star simulations.  
Interactive UI: Build a web-based control panel, sliders for simulation speed, and toggleable visualization modes.  

- [ ] **Cross-Platform Expansion**  
WebGL via Emscripten: Port the simulation to WebAssembly, making it accessible directly in the browser.  

- [ ] **Visual Enhancements**  
Trails/Orbits: Render motion paths for bodies.  
3D Simulation: Allow 3D body movement  

<h1>CSCI 2275 Final Project</h1>

<h4>Project Summary:</h4>

This project calculates the optimal sequences of actions in the 2020-2021 Vex Robotics Competition game Change Up. It takes the starting field state, or user inputted field states, and iterates through all possible combinations of moves of depth N. All calculated field states are stored within a Doubley Linked List to allow for dynamic depth of calculations, limited only by runtime and environment resources. The resulting sequence of moves is sorted into a Binary Search Tree by resulting score changes. Order of moves is not significant, therefore duplicate combinations are consolidated in this tree resulting in a more efficient process search and less memory usage.

<h4>Staying True To The Real World:</h4>
To properly emulate the field, a circular queue of size 3 represents the goal zones. These zones can only hold 3 balls max, balls can only be added to the top, and adding a ball to a full goal assumes the bottom ball was removed, just like in an actual match. The circular queue used was modified to dequeue if adding to a full queue to do this exactly. There are also only 16 balls of each color; the scoring algorithm checks before simulating a state change that there is a ball available to score preventing impossible situations where more balls are scored than exist.
<p>
<img src="https://i.imgur.com/1KidH75.png" alt="field" width="800">
<p>

<h4>Run Instructions:</h4>
To run, simply compile the project first using `g++ main.cpp Field.cpp DLL.cpp Queue.cpp Score.cpp Calc.cpp -o CSCI2275Final` and run using `./CSCI2275Final`

Once run, interact with the program using the displayed menus.

<h4>Dependencies:</h4>
None

<h4>System Requirements:</h4>
C++14
Tested in CMAKE 3.17+ (CMAKE tested using MSVC C++) and GCC version 8.3.0

<h4>Team Members:</h4> George Johnson

<h4>Contributors:</h4>
None

<h4>Open Issues/Bugs:</h4>
Unexpected behavior of circular queue in storing goal data. Results in early termination of program.
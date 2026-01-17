#901E Pushback Coding Project
12.20 
Created the logic of intake partially
Added logical component in tongue class for controlling flex intake velocity

12.20
Created config.cpp and config.hpp that allows software information, such as constants, bools, and other variables that are used globally all throughout the project. 

Updated the intake file based on Config.prematches.skillsMode, where the bool determines whether the mode is skills, and then decreases the outtake of the upper goal based on the bool value.

12.20
Created a getState() function for the Intake class for better logic creation using the intake(int state) function with autonomated state control outside.

12.20
Created a storage boolean value for easier logic creation 

12.26
Added/edited comments for some functions
Changed rotational sensor values since it wasn't compatible with centidegrees.

12.27
Created a function that stops the top intake when the color sensor detects a block
Create some more config and preset values for future application of distance sensors

1.5
Tested/Debugged drive control. 
Confirmed that the middle goal antijamming works

1.6
Added auton routes (7blocks on both sides with wing)
Finished creating/applying the stopping algorithm for top intake
Altered the brain screen

1.7-1.16
Checked if the auton route selector works. Needs check with field switch. 
Added AWP route and part of skills route
AWP route needs extra tuning before nationals, and skills route is only 25% finished. 

# To do:
1. Finish Skills route
2. Tune AWP
3. Finish match routes
4. Check if auton selector works with field switch
5. tune intake for skills

1.17
Changed intake control for usability
Created distanceAlgo class for adding hard reset through distance sensors. -> Already applied in line 213 in autonomousRoutes.cpp
Needs to modify offests for the distance sensor -> private constant in distanceAlgo class.


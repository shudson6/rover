Drive Commands
===
This file describes the commands that will control the rover's movement. Parameters in angle brackets `<>` are required. Parameters in square brackets `[]` are optional.
Wheel names accepted in space-separated parameter lists are as follows:
```
lf, lm, lr, rf, rm, rr: left/right front/middle/rear drive wheels
              drl, drr: left/right drive wheels
                   drv: all drive wheels
    slf, slr, srf, srr: left/right front/rear steering motors
                   str: all steering motors
```

`enable <names>`  
Enables the named motors.

`disable <names>`  
Disables the named motors. They will no longer be driven unless re-enabled.

`setd <fwd|rev> <names>`  
Sets the direction (forward or reverse) for the named drive wheels.

`sets <cw|acw> <names>`  
Sets the direction (clockwise or anticlockwise) for the named steering motors. Direction is as seen from above the rover.

`run [names] <X>`  
Drives the named motors for X seconds. Drive and steering motors are accepted. If no names are provided, all enabled motors are driven.

`fwd [names] <X>`  
Drives the named drive wheels forward for X seconds. Only drive motors are accepted. If no names are provided, all enabled drive motors are driven.

`rev [names] <X>`  
Like `fwd`, but in reverse.

`turnl [names] <X>`  
Drives the named steering motors for X seconds as in a left turn. That is, counterclockwise up front and clockwise at rear.

`turnr [names] <X>`  
Like `turnl`, but for a right turn: clockwise up front, counterclockwise at rear.

`status`  
Retrieves the status of all motors in a to-be-determined JSON format.

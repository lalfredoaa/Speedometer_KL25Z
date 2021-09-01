
Project from Microcontrollers Laboratory (5th semester).

A speedometer using KL25Z microcontroller. 

The external circuit consisted on a DC motor whose speed was controlled by the microcontroller using PWM. 

The speed could be increased or decreased via UART commands from PC to microcontroller. 

Every turn of the motor was detected using a optocoupler sensor which interrupted the microcontroller via a GPIO pin. 

Speed (in rpm) was internally calculated and displayed on an external 16x2 LCD. 
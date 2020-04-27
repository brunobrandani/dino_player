#include <Servo.h>

// Pins attribution
const int SERVO_PIN = 6;        // Servo control at pin 6
const int SENSOR_LDR_PIN = A5;  // LDR Sensor read at pin A5

// SERVO motor constants
const int MOTOR_WAIT_TIME = 300;   // Time to motor movement
const int RELEASED_POSITION = 10;  // Angle for released space bar
const int PRESSED_POSITION = 0;    // Angle for pressed space bar

// LDR sensor constants 
const int THREASHOLD = 340;  // Value for distinguish obstacle from background

// Global constants
const int LOOP_DELAY = 10;  // Time to wait before new loop

// Global variables
Servo s;      // Servo object

/******************************************************************
 * Function:    setup
 * Description: initial configuration
 * Parameters:  None
 * Return:      None
 ******************************************************************/
void setup() {

  // Define LDR sensor pin as input
  pinMode(SENSOR_LDR_PIN, INPUT);

  // Define servo motor pin and its initial position
  s.attach(SERVO_PIN);
  s.write(RELEASED_POSITION);

}

/******************************************************************
 * Function:    loop
 * Description: infinite loop for main program
 * Parameters:  None
 * Return:      None
 ******************************************************************/
void loop() {

  // Check if there is a obstacle comming
  if(checkObstacle( getLdrSensorMeasurement() )){

    // If there is an obstacle, jump
    jump();
    
  }

  // Wait for new check
  delay(LOOP_DELAY);
}

/******************************************************************
 * Function:    jump
 * Description: makes the dino jump by pressing the space bar
 * Parameters:  None
 * Return:      None
 ******************************************************************/
void jump(void){
    
    s.write(PRESSED_POSITION);  // Press space bar with servo motor
    delay(MOTOR_WAIT_TIME);     // Wait until space bar is pressed
    s.write(RELEASED_POSITION); // Return the servo motor to initial position
}

/******************************************************************
 * Function:    checkObstacle
 * Description: checks if there is an obstacle with given measurement
 * Parameters:  measurement from ldr sensor
 * Return:      boolean for obstacle presence
 ******************************************************************/
boolean checkObstacle(int localLeitura){

  // Return true for measurent above threashold
  return (localLeitura > THREASHOLD); 
}

/******************************************************************
 * Function:    getLdrSensorMeasurement
 * Description: get the current ldr sensor measurement
 * Parameters:  None
 * Return:      integer value for ldr sensor measurement
 ******************************************************************/
int getLdrSensorMeasurement(void){

  // Return value from analog measurement
  return analogRead(SENSOR_LDR_PIN); 
}

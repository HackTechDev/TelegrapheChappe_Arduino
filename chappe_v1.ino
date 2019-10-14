#include <Servo.h>

Servo regulatorServo; 
Servo indicatorLeftServo;
Servo indicatorRightServo;


int regulatorPos = 0;  
int regulatorDelta = 50;


int indicatorLeftPos = 0;  
int indicatorLeftDelta = -10;


int indicatorRightPos = 0;  
int indicatorRightDelta = -15;


void setup() {
  // Regulator
  regulatorServo.attach(5);  

  // Indicator Left
  indicatorLeftServo.attach(6);  

  // Indicator Right
  indicatorRightServo.attach(7);



  // Signe 1
  // Calibrage horizontal
  regulatorServo.write(90+regulatorDelta);

  // Calibrage vertical indicatorLeft
  indicatorLeftServo.write(45+indicatorLeftDelta);

  // Calibrage vertical indicatorRight
  indicatorRightServo.write(135+indicatorRightDelta);
  
  delay(10000);
}

void loop() {
  chappe();

}

void indicatorAllPositions() {
// To angle
indicatorLeftMove_45_90();
delay(9000);

// To angle
indicatorRightMove_135_90();
delay(9000);

// To vertical
indicatorLeftMove_90_45();
delay(9000);

// To vertical
indicatorRightMove_90_135();
delay(9000);
  
}

void chappe() {


regulatorMove_90_135();

delay(9000);

indicatorAllPositions();

regulatorMove_135_90();

delay(9000);

indicatorAllPositions();

regulatorMove_90_45(); 

delay(9000);

indicatorAllPositions();

regulatorMove_45_90(); 

delay(9000);

indicatorAllPositions();


}


void regulatorMove_45_90() {
  // Rotatate to Right
  for (regulatorPos = 45+regulatorDelta; regulatorPos <= 90+regulatorDelta; regulatorPos += 1) { 
    // in steps of 1 degree
    regulatorServo.write(regulatorPos);             
    delay(15);                       
  }
}

void regulatorMove_90_135() {
  for (regulatorPos = 90+regulatorDelta; regulatorPos <= 135+regulatorDelta; regulatorPos += 1) { 
    // in steps of 1 degree
    regulatorServo.write(regulatorPos);             
    delay(15);                       
  }
}

void regulatorMove_135_90() {
  for (regulatorPos = 135+regulatorDelta; regulatorPos >= 90+regulatorDelta; regulatorPos -= 1) { 
    regulatorServo.write(regulatorPos);        
    delay(15);                      
  }
}


void regulatorMove_90_45() {
  for (regulatorPos = 90+regulatorDelta; regulatorPos >= 45+regulatorDelta; regulatorPos -= 1) { 
    regulatorServo.write(regulatorPos);     
    delay(15);                   
  }
}





void indicatorLeftMove_90_45() {
  for (indicatorLeftPos = 90+indicatorLeftDelta; indicatorLeftPos >= 45+indicatorLeftDelta; indicatorLeftPos -= 1) { 
    indicatorLeftServo.write(indicatorLeftPos);     
    delay(15);                   
  }
}

void indicatorLeftMove_45_90() {
  for (indicatorLeftPos = 45+indicatorLeftDelta; indicatorLeftPos <= 90+indicatorLeftDelta; indicatorLeftPos += 1) { 
    indicatorLeftServo.write(indicatorLeftPos);             
    delay(15);                     
  }
}


void indicatorRightMove_90_135() {
  for (indicatorRightPos = 90+indicatorRightDelta; indicatorRightPos <= 135+indicatorRightDelta; indicatorRightPos += 1) { 
    indicatorRightServo.write(indicatorRightPos);             
    delay(15);                       
  }

}


void indicatorRightMove_135_90() {
  for (indicatorRightPos = 135+indicatorRightDelta; indicatorRightPos >= 90+indicatorRightDelta; indicatorRightPos -= 1) { 
    indicatorRightServo.write(indicatorRightPos);        
    delay(15);                      
  }
}

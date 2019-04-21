#include "Morse.h"
#include "LedTube.h"
#include "SerialController.h"
#include "SoundDetector.h"
#include "UltraSonicSensor.h"
#include "CarbonMonoxidSensor.h"
#include "WaterSensor.h"
#include "RtcModule.h"
#include "KeyPad.h"

SerialController* serialController;
LedController ledController(13);
KeyPad keyPad(4, 4, 6, 2);

/*RtcModule rtcModule(6, 7, 8);
WaterSensor waterSensor(0);
CarbonMonoxidSensor carbonMonoxidSensor(A0, 8);
UltraSonicSensor ultraSonicSensor(2, 4);
LedTube ledTube(2);
LedController ledController(12);
Morse morse(12);
SoundDetector soundDetector(0);
bool blink = false;*/

void setup()
{
  serialController = new SerialController(9600);
  ledController.Off();
  
  /* RTC Module setup
  // ----------------
  rtcModule.SetDateAndTime(2016, 9, 5, 18, 31, 0);*/
}

void loop()
{
  /* KeyPad usage*/
  // ------------
  keyPad.Scan();
  if (keyPad.KeyPressed())
  {
    Serial.print("Key Pressed: ");
    Serial.println(keyPad.GetKey());
  }

  //delay(300);
  
  /* RTC Module usage
  // ----------------
  rtcModule.updateTime();
  serialController->writeLine(rtcModule.getShortDate());
  serialController->writeLine(rtcModule.getShortTime());
  serialController->writeLine(rtcModule.getLongDate());
  serialController->writeLine(rtcModule.getDateAndTime());
  delay(1000);*/
  
  /* Sound Detector usage
  // --------------------
  
  soundDetector.CheckForSound();
  if (soundDetector.soundDetected)
  {
    serialController->WriteLine("Sound detected");
  }
  if (soundDetector.repeatedSoundDetected)
  {
    serialController->WriteLine("Repeated sound detected");
  }*/
  
  /* Water sensor usage
  // ------------------
  
  waterSensor.CheckWaterLevel();
  if (waterSensor.isWaterDetected)
  {
    ledController.On();
    serialController->WriteLine((String)waterSensor.waterLevel);
  }
  else
  {
    ledController.off();
  }
  delay(1000);*/
  
  /* Carbon Monoxid Sensor usage
  // ---------------------------
  
  carbonMonoxidSensor.Check();
  if (carbonMonoxidSensor.isLimitReached)
  {
    ledController.On();
    serialController->WriteLine("Alarm! Gas detected!");
  }
  else
  {
    ledController.Off();
  }
  delay(1000);*/
  
  /* Ultra sonic sensor usage
  // ------------------------
  
  long distance = ultraSonicSensor.GetDistanceInCentimeters();
  serialController->Write("Distance: ");
  serialController->Write(distance);
  serialController->WriteLine(" cm.");
  delay(1000);*/
  
  /* Led controller, morse, seven segment led, serial controller usage
  // -----------------------------------------------------------------
  
  String command = serialController->ReadLine();
  if (command == "led on")
  {
    ledController.On();
  }
  else if (command == "led off")
  {
    ledController.Off();
  }
  else if (command.startsWith("morse "))
  {
    int index = command.indexOf(' ');
    String text = command.substring(index + 1);
    serialController->WriteLine(text);
    morse.Text(text);
  }
  
  blink = command == "led blink" || (command == "" && blink);
  if (blink)
  {
    ledController.Blink();
  }

  if (command != "")
  {
    ledTube.Show(command);
    serialController->WriteLine(command);
  }*/
}


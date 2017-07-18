import http.requests.*;
import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;      // Data received from the serial port


void setup() 
{
  size(200, 200);
  // I know that the first port in the serial list on my mac
  // is always my  FTDI adaptor, so I open Serial.list()[0].
  // On Windows machines, this generally opens COM1.
  // Open whatever port is the one you're using.
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
}


void draw()
{
  if ( myPort.available() == 0) {  // If data is available,
    val = myPort.read();    
    GetRequest get = new GetRequest("https://maker.ifttt.com/trigger/hello/with/key/kx0XNO_mXpWBg1S5xV3fbPAsaBQ4SOFTTszNDLK9H3U");
get.send();// read it and store it in val

print(val);
println("Reponse Content: " + get.getContent());
println("Reponse Content-Length Header: " + get.getHeader("Content-Length"));
}
}
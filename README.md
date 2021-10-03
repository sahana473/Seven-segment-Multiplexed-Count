## Abstract

In this project, a 7 segment multiplexed display is interfaced with Arduino Uno to display a two digits number

## Hardware Components

 - Arduino Uno
 - 7 segment Display(Common Cathode)

## Development Tools Used:

- PROTEUS 8 - for simulation
- Arduino - for programming

## Hardware Connection:

- D2-D8 of Arduino Uno pins are connected to 7 segment display
- D12 of Arduino Uno is connected to pin 2 of 7 segment display
- D13 of Arduino Uno is connected to pin 1 of 7 segment display

## Usage:

- Download the schematic.pdsprj file->open in PROTEUS 8 tool.

<img src=https://user-images.githubusercontent.com/84024571/135746741-daf30fb4-6e52-4a69-8d92-9f8e5f90b2eb.PNG width="800" height="400">

- Download code. ino and open in the Arduino tool.
- Go to tools ->select Board->select Arduino UNO.
- Click on “Verify” button and copy the generated hex file path from Arduino as described in this link
  https://www.instructables.com/HOW-TO-GET-HEX-FILE-FROM-ARDUINO-/
- Go to PROTEUS 8->Click on Arduino Uno->Edit Component window will pop up ->paste the hex file path in   Program file->Click OK.

<img src=https://user-images.githubusercontent.com/84024571/132992989-2161269d-0baf-4f56-9f3c-890b1d71bbe5.PNG width="800" height="400">

- Click on the Run button.

## Output:

<img src=https://user-images.githubusercontent.com/84024571/135746786-33eb59be-1e16-4633-b761-1ad22d1523e8.PNG height="400">

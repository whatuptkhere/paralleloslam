## Paralleloslam
![Image](https://github.com/whatuptkhere/paralleloslam/blob/master/paralleloslam.png?raw=true)

A serial-to-parallel data transmission device, using the ATMEGA 328. 

Initially designed to work with Epson FX-80-compatible printers, but may have other useful applications.

Serial CTS Flow control implemented, triggered by the parallel busy pin, to allow effective transmission at higher baud rates. Currently tested up to 9600 bps.  

### Circuit Diagram
To be taken as a rough guide. 
Pin assignments in code trump the diagram.
Jumpers to select baud rate are not implemented but may be done in a future release.
![Image](https://github.com/whatuptkhere/paralleloslam/blob/master/circuitdiagram.jpg)

### Credits
Programming & Hardware by Cosmos2000 & TK
Inspired by sentryGun53 

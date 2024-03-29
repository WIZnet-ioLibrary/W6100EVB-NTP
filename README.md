# Index
- [NTP Client Example for W6100-EVB](#NTP-Client-Example-for-W6100-EVB)
- [Hardware Environment](#Hardware-Environment)
- [Software Environments](#Software-Environment)
- [Run](#Run)
- [Code review](#Code-review)
  - [Test packet capture file](#Test-packet-capture-file)



------
# NTP Client Example for W6100-EVB
Common to Any MCU, Easy to Add-on. Internet Offload co-Processor, HW TCP/IP chip,
best fits for low-end Non-OS devices connecting to Ethernet for the Internet of Things. These will be updated continuously.

## Hardware Environment
* W6100EVB
  - connecting Micro usb.
  - connecting Ethernet cable. <br>
<p align="center">
  <img width="60%" src="https://docs.wiznet.io/assets/images/w6100-evb_callout-d5d88d99555cd8b78d6a8327b849cd58.png" />
</p>

## Software Environment
In case of used to TrueSTUDIO, it is the same as HTTP Server example.
 - Link : [Software Environment of W6100EVB-HTTP_Server](https://github.com/WIZnet-ioLibrary/W6100EVB-HTTP_Server#Software-Environment)


## Run
* Demo Environment & Program <br>

  - Windows 10 <br>
  - Hercules <br>

* Demo Result <br>
  - Power On and push Reset button to start Program<br>
  - Program Run Serial display <br>
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/9648281/55846427-a09b8900-5b80-11e9-8aaa-21531dc3a065.JPG" />
    <img width="60%" src="https://user-images.githubusercontent.com/9648281/55846426-a002f280-5b80-11e9-8688-d5f3e4820448.JPG" />
  </p>
  - If you push the user0 or user1 on the W6100EVB, you can get the time from NTP4 or NTP6
  
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/9648281/55846450-b8730d00-5b80-11e9-97a4-102be545a52f.JPG" />
  </p>

  ## Code review
  * main.c code flow <br>
  <p align="center">
    <img width="50%" src="https://user-images.githubusercontent.com/9648281/55851411-67204900-5b93-11e9-988c-4d1b3d38d744.jpg" />
  </p>

   ## Test packet capture file
     <p align="center">
    <img width="100%" src="https://user-images.githubusercontent.com/9648281/55846455-bd37c100-5b80-11e9-91bd-4516bc67eac2.JPG" />
  </p>

    
    -Test packet capture file :  [NTP_Client_Packet.zip](https://github.com/WIZnet-ioLibrary/W6100EVB-NTP/files/3061738/NTP.Result.Packet.Capture.zip)


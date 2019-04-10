# Index
- [HTTP Server Example for W6100-EVB](#HTTP-Server-Example-for-W6100-EVB)
- [Hardware Environment](#Hardware-Environment)
- [Software Environments](#Software-Environment)
- [Run](#Run)
- [Code review](#Code-review)
  - [Test packet capture file](#Test-packet-capture-file)



------
# HTTP Server Example for W6100-EVB
Common to Any MCU, Easy to Add-on. Internet Offload co-Processor, HW TCP/IP chip,
best fits for low-end Non-OS devices connecting to Ethernet for the Internet of Things. These will be updated continuously.

## Hardware Environment
* W6100EVB
  - connecting Micro usb.
  - connecting Ethernet cable. <br>
<p align="center">
  <img width="60%" src="https://wizwiki.net/wiki/lib/exe/fetch.php?w=600&tok=eabde4&media=products:w6100:w6100_evb:w6100-evb_callout.png" />
</p>

## Software Environment
In case of used to TureStduino,it it the same as HTTP Server example.
 - Link : [Software Environment of W6100EVB-HTTP_Server](https://github.com/WIZnet-ioLibrary/W6100EVB-HTTP_Server#Software-Environment)


## Run
* Demo Environment & Program <br>

  - Windows 10 <br>
  - Hercules <br>

![ntp_wireshark]()
* Demo Result <br>
  - Power On and push Reset button to start Program<br>
  - Program Run Serial display <br>
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/9648281/55846427-a09b8900-5b80-11e9-8aaa-21531dc3a065.JPG" />
    <img width="60%" src="https://user-images.githubusercontent.com/9648281/55846426-a002f280-5b80-11e9-8688-d5f3e4820448.JPG" />
  </p>
  - If you push the user0 or user1, you can get the time from NTP4 or NTP6
  
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/9648281/55846450-b8730d00-5b80-11e9-97a4-102be545a52f.JPG" />
  </p>

  ## Code review
  * main.c code flow <br>
  <p align="center">
    <img width="50%" src="https://user-images.githubusercontent.com/48539052/55776879-19470a80-5ad9-11e9-8945-32cdbd5ba0a3.png" />
  </p>

   ## Test packet capture file
     <p align="center">
    <img width="50%" src="https://user-images.githubusercontent.com/9648281/55846455-bd37c100-5b80-11e9-91bd-4516bc67eac2.JPG" />
  </p>

    
    - [HTTP_Server_Packet.zip](https://github.com/WIZnet-ioLibrary/W6100EVB-NTP/files/3061738/NTP.Result.Packet.Capture.zip)


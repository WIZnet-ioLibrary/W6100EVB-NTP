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
  - Internet Explorer <br>
  - Hercules <br>


* Demo Result <br>
  - Power On and push Reset button to start Program<br>
  - Program Run Serial display <br>
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/48539052/55784555-c75bb000-5aeb-11e9-9bbe-a662209c9285.png" />
  </p>

  - Excute Internet Explorer and input device ip address<br>
  - Internet Explorer contact HTTP Server <br>
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/48539052/55781267-ba878e00-5ae4-11e9-9a48-0c7977b72746.png" />
  </p>

  - Internet Explorer HTTP Server Device Network Information <br>
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/48539052/55784554-c75bb000-5aeb-11e9-8fee-bc279b42e73f.png" />
  </p>

  - Internet Explorer HTTP Server Device RGB LED control <br>
  <p align="center">
    <img width="60%" src="https://user-images.githubusercontent.com/48539052/55775474-64125380-5ad4-11e9-9c38-0eed6cf6164f.png" />
  </p>

  ## Code review
  * main.c code flow <br>
  <p align="center">
    <img width="50%" src="https://user-images.githubusercontent.com/48539052/55776879-19470a80-5ad9-11e9-8945-32cdbd5ba0a3.png" />
  </p>

   ## Test packet capture file
    - [HTTP_Server_Packet.zip](https://github.com/WIZnet-ioLibrary/W6100EVB-HTTP_Server/files/3057274/HTTP_Server_Packet.zip)


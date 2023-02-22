##WITH THE FIRST TYPE OF COMPILATION
![Cattura](https://user-images.githubusercontent.com/91976683/219817115-383c3b3d-ba7a-4f98-8edd-3af9ef6b5f74.PNG)
##WITH THE SECOND TYPE OF COMPILATION
![Immagine 2023-02-22 114022](https://user-images.githubusercontent.com/91976683/220597064-7e29dbd9-9560-481a-a3e8-700deee24a25.png)
##  CONDOR reverse shell V2.0
## Language 
    C++
## Author
    Condor
## Organization 
    I'M ROOT 
## Discord 
    https://discord.gg/wkn8gdEjjW
## Instagram 
    https://www.instagram.com/_samueleabbate/
## JobApplication 
    samuele13213@gmail.com

##  ITA
    Una reverse shell che crea una persistenza!!!
    Per qualsiasi problema o richiesta vi consiglio di unirvi nel discord di I'M ROOT "https://discord.gg/wkn8gdEjjW"
    Sarò felice di aiutarvi.

## EN
    A reverse shell that creates persistence !!!
    For any problem or request I suggest you join the I'M ROOT discord 
    "https://discord.gg/wkn8gdEjjW"
    I will be happy to help you.

##  change The IP and Port number in the source code

    There is **condor.cpp** file you have to open and change the **ip address** and **port number**

## FRIST TYPE OF COMPILATION:

    apt install mingw-w64

    i686-w64-mingw32-g++ condor.cpp -o condor.exe -lws2_32 -lwininet -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc
## SECOND TYPE OF COMPILATION:
    INSTALL ON YOUR WINDOWS PC DEV-C++ " https://sourceforge.net/projects/orwelldevcpp/ ", DOWNLOAD THE DLL " https://www.dll-files.com/ws2_32.dll.html " I'VE USED THE     V. 10.0.19041.1 CREATE A NEW PROJECT IN DEV-C++ CREATE INSIDE A DOCUMENT AND PASTE THE CODE AFTER THAT SAVE AND GO TO PROJECT, PROJECT OPTIONS, PARAMETERS AND         CLICK ON "ADD LIBRARY OR OBJECT" GO ON THE .DLL PATH AND CLICK ON IT AND COMPILE.
## Start  the netcat Listener
    
    nc -lvnp <port number>

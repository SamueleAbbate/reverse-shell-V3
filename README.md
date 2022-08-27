##  CONDOR reverse shell V1.0
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

## Compile it

    apt install mingw-w64

    i686-w64-mingw32-g++ condor.cpp -o condor.exe -lws2_32 -lwininet -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc

## Start  the netcat Listener
    
    nc -lvnp <port number>

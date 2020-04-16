#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <thread>


// Need to link with Ws2_32.lib
#pragma comment (lib, "Ws2_32.lib")
// #pragma comment (lib, "Mswsock.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"


void receive(SOCKET soc,char);

SOCKET ClientSocket = INVALID_SOCKET;
SOCKET ClientSocket2 = INVALID_SOCKET;

int __cdecl main(void)
{
    WSADATA wsaData;
    int iResult;

    SOCKET ListenSocket = INVALID_SOCKET;
    

    struct addrinfo* result = NULL;
    struct addrinfo hints;

    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    char sndbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;
    char h;
    // Initialize Winsock
    iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != 0) {
        printf("WSAStartup failed with error: %d\n", iResult);
        return 1;
    }

    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    // Resolve the server address and port
    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if (iResult != 0) {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        return 1;
    }

    // Create a SOCKET for connecting to server
    ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (ListenSocket == INVALID_SOCKET) {
        printf("socket failed with error: %ld\n", WSAGetLastError());
        freeaddrinfo(result);
        WSACleanup();
        return 1;
    }

    // Setup the TCP listening socket
    iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
    if (iResult == SOCKET_ERROR) {
        printf("bind failed with error: %d\n", WSAGetLastError());
        freeaddrinfo(result);
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    freeaddrinfo(result);

    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    // Accept a client socket
    ClientSocket = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    recv(ClientSocket, recvbuf, recvbuflen, 0);
    std::cout << recvbuf << std::endl;
    //send(ClientSocket, "You are connected to me!\n", 150, 0);
    iResult = listen(ListenSocket, SOMAXCONN);
    if (iResult == SOCKET_ERROR) {
        printf("listen failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }

    ClientSocket2 = accept(ListenSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET) {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(ListenSocket);
        WSACleanup();
        return 1;
    }
    recv(ClientSocket2, recvbuf, recvbuflen, 0);
    std::cout << recvbuf << std::endl;
    // No longer need server socket
    //closesocket(ListenSocket);


    
    
    /*recv(ClientSocket2, recvbuf, recvbuflen, 0);
    std::cout << recvbuf<<std::endl;
    //send(ClientSocket, "You are connected to me!\n", 150, 0);


    */




    std::thread receive_thread(receive, ClientSocket,'1');
    std::thread receive_thread2(receive, ClientSocket2,'2');

    /*while (1)
    {
        std::cin.getline(sndbuf, recvbuflen);
        send(ClientSocket, sndbuf, recvbuflen, 0);
        send(ClientSocket2, sndbuf, recvbuflen, 0);
    }*/
    std::cin >> h;
    









    // shutdown the connection since we're done
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR) {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        return 1;
    }

    // cleanup
    closesocket(ClientSocket);
    WSACleanup();

    return 0;
}

int reply1 = -1;
int reply2 = -1;

char who_win(int, int);
void Opsend(char,char,int,int);

void receive(SOCKET soc,char player)
{
    char recvbuf[DEFAULT_BUFLEN];
    int choose;
    int iResult;
    
    while (1) {
        iResult = recv(soc, recvbuf, DEFAULT_BUFLEN, 0);
        if (iResult > 0) {
            choose = (int)recvbuf[0] - 48;
            std::cout << "Player " << player << " has choosen: " << choose << std::endl;
            if (player == '1') {
                if (reply2 < 0) //Only one player has made a choise
                {
                    reply1 = choose;
                    Opsend(player, '3',-1,-1);//let know other about making choise
                }
                else if (reply2 > 0)
                {
                    //calculations and sending.
                    reply1 = choose;
                    int answ = who_win(reply1, reply2);
                    if (answ == '1') {
                        std::cout << "Player " << player << " win!\n\n";
                        Opsend(player, answ,reply1,reply2);
                    }
                    else if (answ == '0') {
                        std::cout << "Tie!\n\n";
                        Opsend(player, answ,reply1,reply2);
                        
                    }
                    else if (answ == '2') {
                        std::cout << "Player " << (player == '1' ? '2' : '1') << " win!\n\n";
                        Opsend(player, answ,reply1,reply2);
                    }

                    reply1 = -1;
                    reply2 = -1;
                    continue;
                }
            }
            else if (player == '2') {
                if (reply1 < 0)
                {
                    reply2 = choose;
                    Opsend(player, '3',-1,-1);
                }
                else if (reply1 > 0)
                {
                    reply2 = choose;
                    //calculations and sending.
                    int answ = who_win(reply2, reply1);
                    if (answ == '1') {
                        std::cout << "Player " << player << " win!\n\n";
                        Opsend(player, answ,reply1,reply2);
                    }
                    else if (answ == '0') {
                        std::cout << "Tie!\n\n";
                        Opsend(player, answ, reply1,reply2);
                    }
                    else if (answ == '2') {
                        std::cout << "Player " << (player == '1' ? '2' : '1') << " win!\n\n";
                        Opsend(player, answ, reply1,reply2);
                    }

                    reply1 = -1;
                    reply2 = -1;
                    continue;
                }
            }
        }

        else if (iResult == 0) std::cout << "Connection clossing...\n";
        else
        {
            printf("recv failed with error: disconnect\n");//WSAGetLastError());
            closesocket(soc);
            WSACleanup();
            return;
        }
    }
}

char who_win(int a, int b)
{
    
    if (a == 1 && b == 2) return '1';
    else if (a == 1 && b == 3) return '2';
    else if (a == 1 && b == 1) return '0';
    
    if (a == 2 && b == 1) return '2';
    else if (a == 2 && b == 3) return '1';
    else if (a == 2 && b == 2) return '0';

    if (a == 3 && b == 1) return '1';
    else if (a == 3 && b == 2) return '2';
    else if (a == 3 && b == 3) return '0';

}

void Opsend(char player,char result,int pl1,int pl2)
{
    char goodres = '1';
    char badres = '0';
    char tie = '2';
    char ready = '3';
    char opch1 = pl1+48;
    char opch2 = pl2 + 48;

    //send(ClientSocket2, &opch, 1, 0);
    if (player == '1' && result == '3')
    {
        send(ClientSocket2, &ready, 1, 0);
        return;
    }
    else if (player == '2' && result == '3')
    {
        send(ClientSocket, &ready, 1, 0);
        return;
    }
    else if (player == '1' && result=='1')
    {
        send(ClientSocket, &goodres, 1, 0);
        send(ClientSocket2, &badres, 1, 0);
    }
    else if (player == '1' && result == '2')
    {
        send(ClientSocket, &badres, 1, 0);
        send(ClientSocket2, &goodres, 1, 0);
    }
    else if (result == '0')
    {
        send(ClientSocket, &tie, 1, 0);
        send(ClientSocket2, &tie, 1, 0);
    }
    else if (player == '2' && result == '1')
    {
        send(ClientSocket, &badres, 1, 0);
        send(ClientSocket2, &goodres, 1, 0);
    }
    else if (player == '2' && result == '2')
    {
        send(ClientSocket, &goodres, 1, 0);
        send(ClientSocket2, &badres, 1, 0);
    }

    send(ClientSocket, &opch2, 1, 0);
    send(ClientSocket2, &opch1, 1, 0);
}
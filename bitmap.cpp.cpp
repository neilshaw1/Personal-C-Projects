#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <wingdi.h>
#include "imglib.cpp"
#include <cmath>
#include <sys/time.h>
unsigned long long getTime(){

struct timeval tv;

gettimeofday(&tv, NULL);
return (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;
}

int main(){
unsigned long long initTime=getTime();
prep();
changeBackgroundColor(255,0,0);
double width=1000;
double height=1000;
double scale=30;
HGDIOBJ oldBitmap;
MoveWindow(GetConsoleWindow(),0,0,width+16,39+height,true);
Sleep(10);
HDC hdc=GetDC(GetConsoleWindow());
COLORREF* array = (COLORREF*)malloc(1000 * 1000 * sizeof(COLORREF));
for(int i=0;i<1000;i++){
for(int j=0;j<1000;j++){
array[i*1000+j] = RGB(floor(255*i/1000),floor(255*j/1000),255);
}
}
HGDIOBJ map = CreateBitmap(1000, 1000, 1, 32, (void*)array);
HDC src = CreateCompatibleDC(hdc);
oldBitmap = SelectObject(src, map);
BitBlt(hdc, 0, 0, 1000, 1000, src, 0, 0, SRCCOPY);
SelectObject(src, oldBitmap);
DeleteDC(src);
DeleteObject(map);
std::cout << getTime()-initTime;
std::cin.get();
return 0;
}


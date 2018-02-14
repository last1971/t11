// t11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <windows.h>
//#include <libssh.h> 
#include <commctrl.h>


using namespace std;








int _tmain(int argc, _TCHAR* argv[])
{

//	ssh_session my_ssh_session = ssh_new();

	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );
	CreateProcess( NULL,"c:\\TrClient\\TrClient.exe",NULL,NULL,FALSE,CREATE_NEW_PROCESS_GROUP,NULL,NULL,&si,&pi );
	//WinExec("c:\\TrClient\\TrClient.exe",0);
		HWND h1=NULL;
	HWND h2 = NULL;
	Sleep(5000);
  
  h1 = FindWindow("TfrmLogin", "Подключение к Магазин 2015");
  
  h2 = FindWindowEx(h1, NULL, "TEdit", "");

  PostMessage(h2, WM_KEYDOWN, 0x35, 0);
  Sleep(1000);
  PostMessage(h2, WM_KEYDOWN, 0x39, 0);
  Sleep(1000);
  PostMessage(h2, WM_KEYDOWN, 0x31, 0);
  Sleep(1000);
  PostMessage(h2, WM_KEYDOWN, 0x37, 0);
  Sleep(1000);

  PostMessage(h2, WM_KEYDOWN, 0x31, 0);
  Sleep(1000);

  PostMessage(h2, WM_KEYDOWN, 0x37, 0);
  Sleep(1000);

  PostMessage(h2, WM_KEYDOWN, VK_RETURN, 0);
  Sleep(20000);               
  h1 = FindWindow("TfrmMain","Магазин 2015:  Дилер");
  HWND h11=h1;
  Sleep(3000);
  HMENU hm = GetMenu(h1);
  HMENU hm1 =GetSubMenu(hm,0);
  UINT u=GetMenuItemID(hm1,0);
  PostMessage(h1,WM_COMMAND,u,0);
  
   Sleep(3000);
  h2 = FindWindowEx(h1, NULL, "TtrNotebook", "");
  HWND h3 = FindWindowEx(h2,NULL,"TPage","Оптовая продажа");
 
  HWND h4 = FindWindowEx(h3,NULL,"TTrActivePageControl","");


  TabCtrl_SetCurFocus(h4,1);
  Sleep(3000);
  HWND h5 = FindWindowEx(h4,NULL,"TTrActiveTabSheet","   Счета   ");

  HWND h6 = FindWindowEx(h5,NULL,"TGuideGrid","ggrdСчёт");
  
  HWND h9 = FindWindowEx(h6,NULL,"TTrActiveDBGrid","");
 PostMessage(h9, WM_ACTIVATE, WA_ACTIVE,0); 
    PostMessage(h9, WM_SETFOCUS, 0, 0); 
  Sleep(20000);
  PostMessage(h9,WM_KEYDOWN,VK_F5,0);
   Sleep(2000);
   HWND h7 = FindWindow("TMessageForm","Подтвердите");
   
  PostMessage(h7,WM_KEYDOWN,VK_RETURN,0);
  
 TabCtrl_SetCurFocus(h4,2);
 Sleep(30000);
 h5 = FindWindowEx(h4,NULL,"TTrActiveTabSheet","   Позиции   ");
 h2 = FindWindowEx(h5,NULL,"TtrPanel","");
 
 h1 = FindWindowEx(h5,h2,"TtrPanel","");
 h3 = FindWindowEx(h1,NULL,"TGuideGrid","ggrdТовары");
 h2 = FindWindowEx(h3,NULL,"TTrActiveDBGrid","");
 PostMessage(h2,WM_KEYDOWN,VK_F5,0);
  Sleep(200000);
 hm1 =GetSubMenu(hm,2);
 HMENU hm2 =GetSubMenu(hm1,1);

 u=GetMenuItemID(hm2,1);
  PostMessage(h11,WM_COMMAND,u,0);
  Sleep(5000);
  h1 = FindWindow("#32770","Экспорт таблицы в dbf файл");;
  cout << h1;
  h2 = FindWindowEx(h1,NULL,"Edit","");
  cout << h2;

 SendMessage(h2, WM_SETTEXT, NULL, (LONG)"prom.dbf");
 Sleep(1000);
  PostMessage(h2,WM_KEYDOWN,VK_RETURN,0);

 Sleep(360000);
 PostMessage(h11, WM_QUIT, 0, 0);
  WaitForSingleObject( pi.hProcess, INFINITE );
  CloseHandle( pi.hProcess );
  CloseHandle( pi.hThread );
	return 0; 
}

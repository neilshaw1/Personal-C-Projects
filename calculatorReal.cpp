#include <windows.h>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;
int getMinMaxCt=0;
HWND buttons[10];
HWND opButtons[10];
HWND window;
HWND eqButton;
HWND txt;
HWND AnsButton;
string array[] = {"+","-","*","/",".","^","log","sqrt","CL1","CLA"};
string param1="";
string operation = "";
string param2="";
long double result=0;
string ans="";
WNDCLASS* createWindowClass(
	WNDPROC winProcess,
	//This is the procedure function for this window element. It should be defined before createWindowClass with the following header: LRESULT Wndproc(HWND hwnd,UINT umsg,WPARAM wParam,LPARAM lParam)
	LPCSTR className,
	//The window class name, with a maximum length of 256 chars. If a standard non-child window is being created, this should be a unique identifier to the created WINCLASS structure.
	//This parameter can also be used to specify the type of child window being created. Valid child window types include: BUTTON COMBOBOX EDIT LISTBOX MDICLIENT RichEdit RICHEDIT_CLASS SCROLLBAR STATIC
	HBRUSH winBackground = NULL,
	//Background color for the window. Can be NULL or 1 added to any of the default values COLOR_ACTIVEBORDER COLOR_ACTIVECAPTION COLOR_APPWORKSPACE COLOR_BACKGROUND COLOR_BTNFACE COLOR_BTNSHADOW COLOR_BTNTEXT COLOR_CAPTIONTEXT COLOR_GRAYTEXT COLOR_HIGHLIGHT COLOR_HIGHLIGHTTEXT COLOR_INACTIVEBORDER COLOR_INACTIVECAPTION COLOR_MENU COLOR_MENUTEXT COLOR_SCROLLBAR COLOR_WINDOW COLOR_WINDOWFRAME COLOR_WINDOWTEXT
	//You can also use the value returned by GetStockObject(int i) as your HBRUSH. If you do this, make sure to explicitly cast it to HBRUSH first. As a parameter to GetStockObject, you can use any of the following values: BLACK_BRUSH DKGRAY_BRUSH DC_BRUSH GRAY_BRUSH HOLLOW_BRUSH (same as NULL_BRUSH) LTGRAY_BRUSH NULL_BRUSH WHITE_BRUSH
	//To create a custom color brush, use CreateSolidBrush, with a COLORREF value as input. To create the COLORREF value, use the RGB function, with numbers from 0-255 as input specifying the red, green, and blue intensities, respectively.
	UINT style = 0,
	//Options: CS_BYTEALIGNCLIENT CS_BYTEALIGNWINDOW CS_CLASSDC CS_DBLCLKS CS_DROPSHADOW CS_GLOBALCLASS CS_HREDRAW CS_NOCLOSE CS_OWNDC CS_PARENTDC CS_SAVEBITS CS_VREDRAW. To use more than one style at a time, separate the styles with the bitwise or (|) operator. For more info, go to https://learn.microsoft.com/en-us/windows/win32/winmsg/window-class-styles
	HINSTANCE hInstance = GetModuleHandle(NULL),
	//Handle to main window. Most of the time, use the current window HINSTANCE for this value.
	HICON icon = LoadIcon(NULL,IDI_APPLICATION),
	//Use the LoadIcon function to select a window icon. The first parameter is an HINSTANCE to a .dll/.exe containing the icon. The second parameter specifies the icon by name.
	//The second parameter can be an application-defined or default system icon name. For more info, go to https://learn.microsoft.com/en-us/windows/win32/menurc/about-icons
	//Possible default system icon names include: IDI_APPLICATION IDI_ERROR IDI_QUESTION IDI_WARNING IDI_INFORMATION IDI_WINLOGO IDI_SHIELD. You can also create icons.
	HCURSOR cursor = LoadCursor(NULL,IDC_ARROW),
	//Use the LoadCursor function to select a cursor.The first parameter is an HINSTANCE to the .dll/.exe that contains the cursor.The second parameter specifies the cursor by name.
	//The second parameter can by an application-defined or default cursor name. For info on using cursors, see https://learn.microsoft.com/en-us/windows/win32/menurc/about-cursors
	//Possible default cursor names include: IDC_ARROW IDC_IBEAM IDC_WAIT IDC_CROSS IDC_UPARROW IDC_SIZENWSE IDC_SIZENESW IDC_SIZEWE IDC_SIZENS IDC_SIZEALL IDC_NO IDC_HAND
	//IDC_APPSTARTING IDC_HELP IDC_PIN IDC_PERSON. One can also load cursors from a .CUR or .ANI file using the HCURSOR LoadCursorFromFileA or HANDLE LoadImage function.
	int classExtraBytes = 0,
	//Extra bytes to allocate for this window class structure. Most of the time, 0 is used.
	int wndExtraBytes = 0,
	//Extra bytes to allocate for the window instance. Use 0 except when working with dialog boxes, in which case you should use DLGWINDOWEXTRA.
	LPCSTR menuName = NULL
	//The name of the menu in the resource file that you would like to associate with this window class. 
  ){
	  static WNDCLASS myWinClass;
	  //Initialize window class as WNDCLASS struct, and specify it as "static" so it will retain a place in memory.
	  myWinClass.style = style;
	  myWinClass.lpfnWndProc = winProcess;
	  myWinClass.hInstance = hInstance;
	  myWinClass.hIcon = icon;
	  myWinClass.hCursor = cursor;
	  myWinClass.hbrBackground = winBackground;
	  myWinClass.lpszMenuName = menuName;
	  myWinClass.lpszClassName = className;
	  myWinClass.cbClsExtra=classExtraBytes;
	  myWinClass.cbWndExtra=wndExtraBytes;
	  return &myWinClass;//Return pointer to the static variable so it can be directly inputted into the registerClass function.
}//Register this class by putting it as an input to the RegisterClass function.
HWND newWindow(
	LPCSTR className,
	//Class name of window. Use the same name given as a class name using createWindowClass.
	//In addition, you can use any of the predefined system classes, which consist of the following: BUTTON COMBOBOX EDIT LISTBOX MDICLIENT RichEdit RICHEDIT_CLASS SCROLLBAR STATIC
	LPCSTR windowName,
	//The string value of this parameter specifies the title of a main window, or the text within a child window (i.e buttons,listboxes).
	int width,
	//Width of the window being created, in pixels. This can be set to CW_USEDEFAULT for popup or overlapped windows to use the default width/height, in which case the height parameter will be ignored.
	int height,
	//Height of the window being created, in pixels.
	int xCoord = 0,
	//This parameter specifies, in pixels, the x coordinate of the window with respect to the top left corner of the screen, or the x coordinate of a child window with respect to the top left corner of its parent.
	int yCoord = 0,
	//This parameter specifies, in pixels, the y coordinate of the window with respect to the top left corner of the screen, or the y coordinate of a child window with respect to the top left corner of its parent.
	DWORD style= WS_OVERLAPPEDWINDOW | WS_VISIBLE,
	//This parameter specifies a list of styles to modify the appearance of the window to be created. For this parameter, you can use a combination of the standard window styles (beginning with WS_), as well as a combination of child window styles used to modify the appearance of a particular control (if you are using predefined system classes).
	//You can use any of the following predefined system classes: WS_BORDER WS_CAPTION WS_CHILD WS_CHILDWINDOW WS_CLIPCHILDREN WS_CLIPSIBLINGS WS_DISABLED WS_DLGFRAME WS_GROUP WS_HSCROLL WS_ICONIC WS_MAXIMIZE WS_MAXIMIZEBOX WS_MINIMIZE WS_MINIMIZEBOX WS_OVERLAPPED WS_OVERLAPPEDWINDOW WS_POPUP WS_POPUPWINDOW WS_SIZEBOX WS_SYSMENU WS_TABSTOP WS_THICKFRAME WS_TILED WS_TILEDWINDOW WS_VISIBLE WS_VSCROLL (WS_TILED and WS_OVERLAPPED are the same, WS_CHILD and WS_CHILDWINDOW are the same, and WS_TILEDWINDOW and WS_OVERLAPPEDWINDOW are the same). WS_OVERLAPPEDWINDOW is made from the styles WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX. For more info, see https://learn.microsoft.com/en-us/windows/win32/winmsg/window-styles
	//Here are the styles you can use with each individual predefined class:
	//Button: BS_3STATE BS_AUTO3STATE BS_AUTOCHECKBOX BS_AUTORADIOBUTTON BS_BITMAP BS_BOTTOM BS_CENTER BS_CHECKBOX BS_COMMANDLINK BS_DEFCOMMANDLINK BS_DEFPUSHBUTTON BS_DEFSPLITBUTTON BS_GROUPBOX BS_ICON BS_FLAT BS_LEFT BS_LEFTTEXT BS_MULTILINE BS_NOTIFY BS_OWNERDRAW BS_PUSHBUTTON BS_PUSHLIKE BS_RADIOBUTTON BS_RIGHT BS_RIGHTBUTTON BS_SPLITBUTTON BS_TEXT BS_TOP BS_TYPEMASK BS_USERBUTTON BS_VCENTER (for information see https://learn.microsoft.com/en-us/windows/win32/controls/button-styles)
	//Combobox (consists of a list box and selection field): CBS_AUTOHSCROLL CBS_DISABLENOSCROLL CBS_DROPDOWN CBS_DROPDOWNLIST CBS_HASSTRINGS CBS_LOWERCASE CBS_NOINTEGRALHEIGHT CBS_OEMCONVERT CBS_OWNERDRAWFIXED CBS_OWNERDRAWVARIABLE CBS_SIMPLE CBS_SORT CBS_UPPERCASE (for information see https://learn.microsoft.com/en-us/windows/win32/controls/combo-box-styles)
	//Edit (defines an input field): ES_AUTOHSCROLL ES_AUTOVSCROLL ES_CENTER ES_LEFT ES_LOWERCASE ES_MULTILINE ES_NOHIDESEL ES_NUMBER ES_OEMCONVERT ES_PASSWORD\n ES_READONLY ES_RIGHT ES_UPPERCASE ES_WANTRETURN (for information see https://learn.microsoft.com/en-us/windows/win32/controls/edit-control-styles).
	//Listbox (List of strings): LBS_COMBOBOX LBS_DISABLENOSCROLL LBS_EXTENDEDSEL LBS_HASSTRINGS LBS_MULTICOLUMN LBS_MULTIPLESEL LBS_NODATA LBS_NOINTEGRALHEIGHT LBS_NOREDRAW LBS_NOSEL LBS_NOTIFY LBS_OWNERDRAWFIXED LBS_OWNERDRAWVARIABLE LBS_SORT LBS_STANDARD LBS_USETABSTOPS LBS_WANTKEYBOARDINPUT (for information see https://learn.microsoft.com/en-us/windows/win32/controls/list-box-styles)
	//RichEdit (defines a RichEdit 1.0 specialized text control): ES_DISABLENOSCROLL ES_EX_NOCALLOLEINIT ES_NOIME ES_NOOLEDRAGDROP ES_SAVESEL ES_SELECTIONBAR ES_SELFIME ES_SUNKEN ES_VERTICAL, and RichEdit inherits the following styles from edit controls: ES_AUTOHSCROLL ES_AUTOVSCROLL ES_CENTER ES_LEFT ES_MULTILINE ES_NOHIDESEL ES_NUMBER ES_PASSWORD ES_READONLY ES_RIGHT ES_WANTRETURN (for more information see https://learn.microsoft.com/en-us/windows/win32/controls/rich-edit-control-styles)
	//RICHEDIT_CLASS (defines a RichEdit 2.0 specialized text control): same styles as RichEdit
    //SCROLLBAR (defines a scrollbar for a child window): SBS_BOTTOMALIGN SBS_HORZ SBS_LEFTALIGN SBS_RIGHTALIGN SBS_SIZEBOX SBS_SIZEBOXBOTTOMRIGHTALIGN SBS_SIZEBOXTOPLEFTALIGN SBS_SIZEGRIP SBS_TOPALIGN SBS_VERT (for more info see https://learn.microsoft.com/en-us/windows/win32/controls/scroll-bar-control-styles)
	//STATIC (defines a box or text field that does not take user input): SS_BITMAP SS_BLACKFRAME SS_BLACKRECT SS_CENTER SS_CENTERIMAGE SS_EDITCONTROL SS_ENDELLIPSIS SS_ENHMETAFILE SS_ETCHEDFRAME SS_ETCHEDHORZ SS_ETCHEDVERT SS_GRAYFRAME SS_GRAYRECT SS_ICON SS_LEFT SS_LEFTNOWORDWRAP SS_NOPREFIX SS_NOTIFY SS_OWNERDRAW SS_PATHELLIPSIS SS_REALSIZECONTROL SS_REALSIZEIMAGE SS_RIGHT SS_RIGHTJUST SS_SIMPLE SS_SUNKEN SS_TYPEMASK SS_WHITEFRAME SS_WHITERECT SS_WORDELLIPSIS (for information see https://learn.microsoft.com/en-us/windows/win32/controls/static-control-styles)
	//Separate all styles by the bitwise OR (|) operator
	HWND parentWindow=NULL,
	//Window handle specifying the parent window. This is mandatory for child windows, but is optional for popup/overlapped windows.
	HMENU id = NULL,
	//A handle to a menu, which can be used as an identifier for a child window or a parent window. If the value is NULL for a parent window, it is assumed that the window's class name will be used for its indentification.
	HINSTANCE instance = NULL,
	//An optional parameter giving an option to associate another window instance with the window being created. If this is not desired, use NULL.
	LPVOID lParam = NULL
	//An optional pointer to be passed to a CREATESTRUCT structure, for purposes of gathering more information about the window. Most of the time, this is not necessary, so this value should be NULL.
	){
		//You can send any of the following messages to the window created using SendMessage: MN_GETHMENU WM_ERASEBKGND WM_GETFONT WM_GETTEXT WM_GETTEXTLENGTH WM_SETFONT WM_SETICON WM_SETTEXT WM_ACTIVATEAPP WM_CANCELMODE WM_CHILDACTIVATE WM_CLOSE WM_COMPACTING WM_CREATE WM_DESTROY WM_DPICHANGED WM_ENABLE WM_ENTERSIZEMOVE WM_EXITSIZEMOVE WM_GETICON WM_GETMINMAXINFO WM_INPUTLANGCHANGE WM_INPUTLANGCHANGEREQUEST WM_MOVE WM_MOVING WM_NCACTIVATE WM_NCCALCSIZE WM_NCCREATE WM_NCDESTROY WM_NULL WM_QUERYDRAGICON WM_QUERYOPEN WM_QUIT WM_SHOWWINDOW WM_SIZE WM_SIZING WM_STYLECHANGED WM_STYLECHANGING WM_THEMECHANGED WM_USERCHANGED WM_WINDOWPOSCHANGED WM_WINDOWPOSCHANGING
		return CreateWindow(className,windowName,style,xCoord,yCoord,width,height,parentWindow,id,instance,lParam);
	}
LRESULT CALLBACK MainWinProc(HWND hwnd,UINT umsg,WPARAM wParam,LPARAM lParam){
	if(umsg == WM_GETMINMAXINFO && getMinMaxCt < 2){
		txt = newWindow("STATIC","",500,20,10,0,WS_CHILD | WS_VISIBLE | SS_LEFTNOWORDWRAP,window);
		getMinMaxCt ++;
		for(int i=0;i<9;i++){
			buttons[i+1] = newWindow("BUTTON",to_string(i+1).c_str(),30,30,10+30*(i % 3),50+30*(i/3),WS_CHILD | WS_VISIBLE,window);
		}
		buttons[0] = newWindow("BUTTON","0",30,30,10+30*0,50+30*3,WS_CHILD | WS_VISIBLE,window);
		for(int i=0;i<4;i++){
			opButtons[i] = newWindow("BUTTON",(array[i]).c_str(),30,30,100,50+30*i,WS_CHILD | WS_VISIBLE,window);
			opButtons[i+6] = newWindow("BUTTON",array[i+6].c_str(),30,30,10+30*i,20,WS_CHILD | WS_VISIBLE,window);
		}
		opButtons[4] = newWindow("BUTTON",array[4].c_str(),30,30,40,50+30*3,WS_CHILD | WS_VISIBLE,window);
		opButtons[5] = newWindow("BUTTON",array[5].c_str(),30,30,70,50+30*3,WS_CHILD | WS_VISIBLE,window);
		AnsButton = newWindow("BUTTON","Ans",30,25,10,170,WS_CHILD | WS_VISIBLE,window);
		eqButton = newWindow("BUTTON","=",90,25,40,170,WS_CHILD | WS_VISIBLE,window);
	}
	if(umsg == WM_COMMAND){
		if(HIWORD(wParam) == BN_CLICKED){
			for(int i=0;i<10;i++){
				if(((HWND) lParam) == buttons[i]){
					if(operation == ""){
						param1 += to_string(i);
					}else{
						param2 += to_string(i);
					}
				}
				if(((HWND) lParam) == opButtons[i]){
					if(i != 4){
						if(i < 8){
					if(operation == "" && (i != 6 || param1 == "") && (i != 7 || param1 == "")){
						operation = array[i];
						}
						}else{
							if(i == 8){
								if(param2 != ""){param2.erase(param2.length()-1,1);}else if(operation != ""){operation = "";}else if(param1 != ""){param1.erase(param1.length()-1,1);};
							}else if(i == 9){
								param1 = "";
								operation = "";
								param2 = "";
							}
						}
						
						}else{
						if(operation == ""){
						param1 += ".";
					}else{
						param2 += ".";
					}
					}
				}
			}
			if((HWND) lParam == eqButton){
				if(param1 == "") param1 = "0";
				if(param2 == "") param2 = "0";
				long double num1 = stold(param1);
				long double num2 = stold(param2);
				if(operation == "+") result=num1+num2;
				if(operation == "-") result=num1-num2;
				if(operation == "*") result=num1*num2;
				if(operation == "/") result=num1/num2;
				if(operation == "^") result=pow(num1,num2);
				if(operation == "log") result=log10(num2);
				if(operation == "sqrt") result=sqrt(num2);
				if(operation == "") result=num1;
				stringstream myStr;
				myStr << result;
				param1 = myStr.str();ans=param1;operation="";param2 = "";
			}
			if((HWND) lParam == AnsButton){
				if(operation == ""){
					param1=((ans != "") ? ans : "0");
			}else{param2=((ans != "") ? ans : "0");}
		}
		SetWindowText(txt,(param1+" "+operation+" "+param2).c_str());
	}
	}
	return DefWindowProc(hwnd,umsg,wParam,lParam);//DefWindowProc handles messages according to the default settings that were not handled earlier on in the function.
}
int WinMain(HINSTANCE currInst,HINSTANCE prevInst,LPSTR strCmd,int cmdInt){
	LPCSTR className="My Window Process";
	RegisterClass(createWindowClass(MainWinProc,className,CreateSolidBrush(RGB(240,240,240))));
	window = newWindow(className,"Calculator",250,250);
	MSG msg;
	//Message data structure. Values that can be obtained from this struct: hwnd (handle to window receiving message), message (UINT equal to a WM message), wParam (Extra parameter 1 dependent on the message), lParam (Extra parameter 2 dependent on the message), time (message receiving time), pt (POINT struct containing x and y variables of type LONG, which specifies cursor position), lPrivate (set but not used).
	while(GetMessage(&msg,window,0,0)){
		//Message loop. Required to prevent the window from closing without having a frozen window. The MSG structure can be used to get information about messages passed to the window. GetMessage returns 0 when WM_QUIT is fired, returns -1 when an invalid handle is passed to it, and returns a positive integer otherwise. To prevent an infinite loop if an invalid handle is passed to the function, use >0 (this will close the window instead if GetMessage returns -1).
		//GetMessage takes parameters: pointer to MSG struct, HWND to message receiving window,UINT of minimum value to filter, and UINT of maximum value to filter. Setting UINT min = UINT max = 0 will filter no values. Processes messages into MSG struct, and fills MSG struct data.
		TranslateMessage(&msg);
		//TranslateMessage takes input of the MSG struct but does not modify it. Instead, it fires certain messages when other messages are being called at the same instant. For example, it will turn the WM_KEYUP and WM_KEYDOWN messages into the WM_CHAR message, which may be more helpful to the programmer.
		DispatchMessage(&msg);
		//DispatchMessage sends the message in the MSG struct provided into the function as a pointer. This sends the message back to the window procedure, thus keeping the loop going. The loop will run idly until another message is fired, which will change the MSG struct and allow the application to react to the message programatically.
	};
	return 0;//Exit program when loop stops, when GetMessage becomes 0 (which means that the WM_QUIT or WM_DESTROY message was fired).
};

#include <Windows.h>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HWND btnAdd, btnDelete, btnShow, txtFieldName, txtFieldClass, listBox;

string arrSV[100], strSV, line, strSV1, strSV2;
int chiso = 0, sel;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG  msg;
	WNDCLASS wc = { 0 };
	wc.lpszClassName = TEXT("Basic Form");
	wc.hInstance = hInstance;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wc.lpfnWndProc = WndProc;
	wc.hCursor = LoadCursor(0, IDC_ARROW);

	RegisterClass(&wc);
	CreateWindow(wc.lpszClassName, TEXT("::Student Manager::"),
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		300, 300, 650, 500, 0, 0, hInstance, 0);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
	{
		CreateWindowW(L"static", TEXT("Name"),
			WS_CHILD | WS_VISIBLE | SS_LEFT,
			40, 55, 60, 40, hwnd, (HMENU)8, NULL, NULL);

		CreateWindowW(L"static", TEXT("Class"),
			WS_CHILD | WS_VISIBLE | SS_LEFT,
			40, 105, 60, 40, hwnd, (HMENU)9, NULL, NULL);

		txtFieldName = CreateWindow(TEXT("edit"), TEXT(""),
			WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL,
			100, 50, 300, 30,
			hwnd, (HMENU)5, NULL, NULL);

		txtFieldClass = CreateWindow(TEXT("edit"), TEXT(""),
			WS_VISIBLE | WS_CHILD | WS_BORDER,
			100, 100, 300, 30,
			hwnd, (HMENU)6, NULL, NULL);

		listBox = CreateWindow(TEXT("listbox"), NULL,
			WS_VISIBLE | WS_CHILD | WS_BORDER /*| LBS_MULTIPLESEL*/ | WS_VSCROLL | LBS_NOTIFY,
			100, 170, 300, 220,
			hwnd, (HMENU)7, NULL, NULL);

		btnAdd = CreateWindow(TEXT("button"), TEXT("Add"),
			WS_VISIBLE | WS_CHILD | WS_BORDER,
			450, 75, 100, 30,
			hwnd, (HMENU)1, NULL, NULL);

		btnDelete = CreateWindow(TEXT("button"), TEXT("Delete"),
			WS_VISIBLE | WS_CHILD | WS_BORDER,
			450, 200, 100, 30,
			hwnd, (HMENU)2, NULL, NULL);

		btnShow = CreateWindow(TEXT("button"), TEXT("Show"),
			WS_VISIBLE | WS_CHILD | WS_BORDER,
			450, 250, 100, 30,
			hwnd, (HMENU)3, NULL, NULL);

		CreateWindow(TEXT("button"), TEXT("Exit"),
			WS_VISIBLE | WS_CHILD | WS_BORDER,
			450, 300, 100, 30,
			hwnd, (HMENU)4, NULL, NULL);
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case 1: // btnAdd
		{
			int bufferLen1 = GetWindowTextLength(txtFieldName) + 10;
			string data1(bufferLen1, '\0');
			GetWindowText(txtFieldName, (LPWSTR)&data1[0], bufferLen1);

			int bufferLen2 = GetWindowTextLength(txtFieldClass) + 5;
			string data2(bufferLen2, '\0');
			GetWindowText(txtFieldClass, (LPWSTR)&data2[0], bufferLen2);

			// Write
			fstream f;
			f.open("sv.txt", ios::out);
			f << data1 << data2 << endl;
			f.close();

			// Read
			ifstream ifs;
			ifs.open("sv.txt");
			while (getline(ifs, line)) {
				istringstream iss(line);
				if (!(iss >> strSV)) { break; }
				else {
					arrSV[chiso] = strSV;
					chiso++;
				}
			}
			f.close();

			// Send
			SendMessage(listBox, LB_RESETCONTENT, 0, 0);
			for (int i = 0; i < chiso; i++)
			{
				SendMessage(listBox, LB_ADDSTRING, 0, (LPARAM)arrSV[i].c_str());
			}
			break;
		}

		case 2: // btnDelete
		{
			for (int i = sel; i < chiso - 1; i++)
			{
				arrSV[i] = arrSV[i + 1];
			}
			chiso--;
		}

		case 3: // btnShow
		{
			// Reset ListBox
			SendMessage(listBox, LB_RESETCONTENT, 0, 0);
			// Send Data to ListBox
			for (int i = 0; i < chiso; i++)
			{
				SendMessage(listBox, LB_ADDSTRING, 0, (LPARAM)arrSV[i].c_str());
			}
			break;
		}

		case 7: //listbox
		{
			if (HIWORD(wParam) == LBN_SELCHANGE)
			{
				sel = (int)SendMessage(listBox, LB_GETCURSEL, 0, 0);
			}
			break;
		}

		case 4:
		{
			PostQuitMessage(0);
		}

		}
		break;
	}

	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break;
	}
	}
	return DefWindowProc(hwnd, msg, wParam, lParam);
}
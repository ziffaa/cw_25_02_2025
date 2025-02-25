#include <windows.h>
#include <tchar.h>
#include "resource.h"

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

HWND hCombo, hList, hEdit, hRadio1, hRadio2, hRadio3;
int option = 1;
int group, student;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
    return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

void SetListData();
void SetGroup();

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		return TRUE;

	case WM_INITDIALOG:
		hCombo = GetDlgItem(hWnd, IDC_COMBO1);
		hList = GetDlgItem(hWnd, IDC_LIST1);
		hEdit = GetDlgItem(hWnd, IDC_EDIT2);
		hRadio1 = GetDlgItem(hWnd, IDC_RADIO1);

		SendMessage(hRadio1, BM_SETCHECK, WPARAM(BST_CHECKED), 0);

		SendMessage(hCombo, CB_ADDSTRING, 0, LPARAM(TEXT("GROUP1")));
		SendMessage(hCombo, CB_ADDSTRING, 0, LPARAM(TEXT("GROUP2")));
		return TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDC_COMBO1 && HIWORD(wParam) == CBN_SELCHANGE)
		{
			group = SendMessage(hCombo, CB_GETCURSEL, 0, 0);
			SetGroup();
			SetListData();
		}
		if (LOWORD(wParam) == IDC_LIST1 && HIWORD(wParam) == LBN_SELCHANGE)
		{
			int index = SendMessage(hList, LB_GETCURSEL, 0, 0);
			student = index;
			int grade = SendMessage(hList, LB_GETITEMDATA, index, 0);
			TCHAR buffer[100];
			SendMessage(hList, LB_GETTEXT, index, LPARAM(buffer));

			wsprintf(buffer, TEXT("%d"), grade);
			SendMessage(hEdit, WM_SETTEXT, 0, LPARAM(buffer));
		}

		switch (LOWORD(wParam))
		{
		case IDC_RADIO1:
			option = 1;
			SetListData();
			break;
		case IDC_RADIO2:
			option = 2;
			SetListData();
			break;
		case IDC_RADIO3:
			option = 3;
			SetListData();
			break;
		}

		return TRUE;
	}
	return FALSE;
}

void SetListData()
{
	int index = 0;

	switch (group)
	{
	case 0:
		switch (option)
		{
		case 1:
			SendMessage(hList, LB_SETITEMDATA, index++, 8);
			SendMessage(hList, LB_SETITEMDATA, index++, 10);
			SendMessage(hList, LB_SETITEMDATA, index, 11);
			break;
		case 2:
			SendMessage(hList, LB_SETITEMDATA, index++, 10);
			SendMessage(hList, LB_SETITEMDATA, index++, 8);
			SendMessage(hList, LB_SETITEMDATA, index, 10);
			break;
		case 3:
			SendMessage(hList, LB_SETITEMDATA, index++, 6);
			SendMessage(hList, LB_SETITEMDATA, index++, 9);
			SendMessage(hList, LB_SETITEMDATA, index, 6);
			break;
		default:
			break;
		}
		break;

	case 1:
		switch (option)
		{
		case 1:
			SendMessage(hList, LB_SETITEMDATA, index++, 3);
			SendMessage(hList, LB_SETITEMDATA, index++, 2);
			SendMessage(hList, LB_SETITEMDATA, index, 2);
			break;
		case 2:
			SendMessage(hList, LB_SETITEMDATA, index++, 3);
			SendMessage(hList, LB_SETITEMDATA, index++, 4);
			SendMessage(hList, LB_SETITEMDATA, index, 7);
			break;
		case 3:
			SendMessage(hList, LB_SETITEMDATA, index++, 4);
			SendMessage(hList, LB_SETITEMDATA, index++, 5);
			SendMessage(hList, LB_SETITEMDATA, index, 6);
			break;
		default:
			break;
		}
	}

	int grade = SendMessage(hList, LB_GETITEMDATA, student, 0);
	TCHAR buffer[100];
	SendMessage(hList, LB_GETTEXT, option, LPARAM(buffer));

	wsprintf(buffer, TEXT("%d"), grade);
	SendMessage(hEdit, WM_SETTEXT, 0, LPARAM(buffer));
}

void SetGroup()
{
	int index;

	SendMessage(hList, LB_RESETCONTENT, 0, 0);

	switch (group)
	{
	case 0:
		switch (option)
		{
		case 1:
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G1_STUDENT1")));
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G1_STUDENT2")));
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G1_STUDENT3")));
			break;
		case 2:
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G1_STUDENT1")));
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G1_STUDENT2")));
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G1_STUDENT3")));
			break;
		case 3:
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G1_STUDENT1")));
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G1_STUDENT2")));
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G1_STUDENT3")));
			break;
		default:
			break;
		}
		break;

	case 1:
		switch (option)
		{
		case 1:
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G2_STUDENT1")));
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G2_STUDENT2")));
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G2_STUDENT3")));
			break;
		case 2:
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G2_STUDENT1")));
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G2_STUDENT2")));
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G2_STUDENT3")));
			break;
		case 3:
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G2_STUDENT1")));
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G2_STUDENT2")));
			index = SendMessage(hList, LB_ADDSTRING, 0, LPARAM(TEXT("G2_STUDENT3")));
			break;
		default:
			break;
		}
	}
}
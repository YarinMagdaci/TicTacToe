
// MFCApplication3Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication3.h"
#include "MFCApplication3Dlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <iomanip>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// CMFCApplication3Dlg dialog

CMFCApplication3Dlg::CMFCApplication3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION3_DIALOG, pParent)
	, boxString(_T(""))
	, playerWinsBox(_T(""))
	, PCWinsBox(_T(""))
	, clickedNewGame(false)
	, pcStart(false)
	, playersTurn(false)
	, Winner('-')
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	setXs();
	setOs();
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			board[i][j] = '-';
		}
	}
}

void CMFCApplication3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, boxString);
}

BEGIN_MESSAGE_MAP(CMFCApplication3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication3Dlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication3Dlg::OnEnChangeEdit1)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication3Dlg::OnBnClickedButton1)
	//ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication3Dlg::OnEnChangeEdit3)
END_MESSAGE_MAP()

int CMFCApplication3Dlg::playerWins = 0;
int CMFCApplication3Dlg::pcWins = 0;

void CMFCApplication3Dlg::setXs() {
	Xs[0] = { 115, 70 };
	Xs[1] = { 215, 70 };
	Xs[2] = { 315, 70 };
	Xs[3] = { 115, 150 };
	Xs[4] = { 215, 150 };
	Xs[5] = { 315, 150 };
	Xs[6] = { 115, 230 };
	Xs[7] = { 215, 230 };
	Xs[8] = { 315, 230 };
}

void CMFCApplication3Dlg::setOs() {
	Os[0] = { 170,90,130,130 };
	Os[1] = { 275,90,225,130 };
	Os[2] = { 380,90,330,130 };
	Os[3] = { 135,148,195,195 };
	Os[4] = { 275,148,225,195 };
	Os[5] = { 380,148,330,195 };
	Os[6] = { 170,220,130,265 };
	Os[7] = { 275,220,225,265 };
	Os[8] = { 380,220,330,265 };
}

// CMFCApplication3Dlg message handlers

BOOL CMFCApplication3Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//CPP project
//Beginning

pairs CMFCApplication3Dlg::findSpot(int spot) {
	int i, j, counter = 0;
	i = j = 0;
	pairs newPair;
	for (i = 0; i < 3 && counter != spot; i++) {
		for (j = 0; j < 3 && counter != spot; j++) {
			counter++;
		}
	}
	newPair = { i - 1, j - 1 };
	return newPair;
}

void CMFCApplication3Dlg::warnPC(int& line, int& column) {
	int i;
	pairs pos1, pos2, pos3;
	for (i = 0; i < 8; i++) {
		pos1 = findSpot(combinationsOfWinning[i][0]);
		pos2 = findSpot(combinationsOfWinning[i][1]);
		pos3 = findSpot(combinationsOfWinning[i][2]);
		if (board[pos1.first][pos1.second] == playerSign
			&& board[pos2.first][pos2.second] == playerSign
			&& board[pos3.first][pos3.second] == '-') {
			line = pos3.first;
			column = pos3.second;
			return;
		}
		else if (board[pos1.first][pos1.second] == playerSign
			&& board[pos2.first][pos2.second] == '-'
			&& board[pos3.first][pos3.second] == playerSign) {
			line = pos2.first;
			column = pos2.second;
			return;
		}
		else  if (board[pos1.first][pos1.second] == '-'
			&& board[pos2.first][pos2.second] == playerSign
			&& board[pos3.first][pos3.second] == playerSign) {
			line = pos1.first;
			column = pos1.second;
			return;
		}
		else {
			continue;
		}
	}
	line = column = -1;
}

void CMFCApplication3Dlg::adviceToPC(int& line, int& column) {
	int i, j;
	pairs pos1, pos2, pos3;
	for (i = 0; i < 8; i++) {
		pos1 = findSpot(combinationsOfWinning[i][0]);
		pos2 = findSpot(combinationsOfWinning[i][1]);
		pos3 = findSpot(combinationsOfWinning[i][2]);
		if (board[pos1.first][pos1.second] == playerSign
			|| board[pos2.first][pos2.second] == playerSign
			|| board[pos3.first][pos3.second] == playerSign) {
			continue;
		}
		else {
			if (board[pos1.first][pos1.second] == '-') {
				line = pos1.first;
				column = pos1.second;
				return;
			}
			else if (board[pos2.first][pos2.second] == '-') {
				line = pos2.first;
				column = pos2.second;
				return;
			}
			else {
				line = pos3.first;
				column = pos3.second;
				return;
			}
		}
	}
	line = column = -1;
}

pairs CMFCApplication3Dlg::generatePCMove() {
	int occupied = 1, line, column;
	pairs newPair;
	warnPC(line, column);
	if (line == -1 && column == -1) {
		adviceToPC(line, column);
	}
	if (line != -1 && column != -1) {
		occupied = 0;
	}
	while (occupied) {
		line = rand() % 3;
		column = rand() % 3;
		if (board[line][column] == '-') {
			occupied = 0;
		}
	}
	newPair = { line, column };
	return newPair;
}


void CMFCApplication3Dlg::newGame() {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			board[i][j] = '-';
		}
	}
	if (pcStart) {
		pairs pos = generatePCMove();
		board[pos.first][pos.second] = pcSign;
		drawPCSign(pos.first, pos.second);
		UpdateData(FALSE);
	}
}

void CMFCApplication3Dlg::pcTurn() {
	pairs pos = generatePCMove();
	drawPCSign(pos.first, pos.second);
}


bool CMFCApplication3Dlg::canDoMove(int line, int col) {
	if (line < 0 || line >= 3 || col < 0 || col >= 3 || board[line][col] != '-') {
		return false;
	}
	return true;
}

void CMFCApplication3Dlg::applyMove(int spot) {
	int i, j, counter, movePossible;
	counter = movePossible = 0;
	pairs pos;
	do {
		pos = findSpot(spot);
		if (canDoMove(pos.first, pos.second)) {
			movePossible = 1;
		}
		else {
			boxString.AppendFormat(L"Invalid spot!try again between[1 - 9]\r\n");
			counter = 0;
			return ;
		}
	} while (!movePossible);
	board[pos.first][pos.second] = playerSign;
}


bool CMFCApplication3Dlg::checkIfWon() {
	int i, j;
	pairs pos1;
	pairs pos2;
	pairs pos3;
	for (i = 0; i < 8; i++) {
		pos1 = findSpot(combinationsOfWinning[i][0]);
		pos2 = findSpot(combinationsOfWinning[i][1]);
		pos3 = findSpot(combinationsOfWinning[i][2]);
		if (board[pos1.first][pos1.second] != '-' &&
			board[pos1.first][pos1.second] == board[pos2.first][pos2.second] &&
			board[pos2.first][pos2.second] == board[pos3.first][pos3.second]) {
			Winner = board[pos1.first][pos1.second];
			drawWinner(i);
			UpdateData(FALSE);
			return true;
		}
	}
	Winner = '-';
	return false;
}

bool CMFCApplication3Dlg::isItFull() {
	int i, j, counter = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (board[i][j] != '-') {
				counter++;
			}
		}
	}
	return counter == 9;
}

void CMFCApplication3Dlg::headsOrTails() {
	int choice;
	int randomnum;
	choice = 1;
	randomnum = (rand() % 2) + 1;//generates a random number 1/2
	if (choice == randomnum) {
		this->pcStart = false;
		playersTurn = true;
		return;
	}
	else {
		this->pcStart = true;
		playersTurn = false;
		return;
	}
}

void CMFCApplication3Dlg::declareWinner() {
	CClientDC dc(this);
	//int pWins;
	CString MyString;
	boxString.Format(L"");
	if (Winner == '-') {
		boxString.AppendFormat(L"It was a tie!\r\n");
	}
	else if (Winner == pcSign) {
		boxString.AppendFormat(L"PC Won!\r\n");
		pcWins++;
	}
	else {
		boxString.AppendFormat(L"You won! congratulations!\r\n");
		playerWins++;
	}
	MyString.Format(L"%d                       %d", playerWins, pcWins);
	dc.SetTextColor(RGB(255, 0, 0));
	dc.TextOutW(695, 205, MyString);
	boxString.AppendFormat(L"\r\nIf you would like to have another game, Press start!\r\n");
	UpdateData(FALSE);
}
//End

void CMFCApplication3Dlg::drawBoard() {
	CClientDC dc(this);
	dc.MoveTo(200, 300);
	dc.LineTo(200, 50);
	dc.MoveTo(300, 300);
	dc.LineTo(300, 50);
	dc.MoveTo(400, 210);
	dc.LineTo(100, 210);
	dc.MoveTo(400, 140);
	dc.LineTo(100, 140);

	UpdateData(FALSE);
}

void CMFCApplication3Dlg::resetBoard() {
	Invalidate();
	//UpdateData(FALSE);
	//drawBoard();
	//UpdateData(FALSE);
}

void CMFCApplication3Dlg::drawX(int x1, int y1) {
	CClientDC dc(this);
	dc.MoveTo(x1, y1);
	dc.LineTo(x1+70, y1+50);
	dc.MoveTo(x1+70, y1);
	dc.LineTo(x1, y1+50);
}


void CMFCApplication3Dlg::drawO(int x1, int y1, int x2, int y2) {
	CClientDC dc(this);
	dc.Ellipse(x1, y1, x2, y2);
}

void CMFCApplication3Dlg::OnBnClickedOk()//newGame button
{
	int randomnum;
	newGame();
	Winner = '-';
	if (clickedNewGame == false) {
		clickedNewGame = true;
	}
	drawBoard();
	UpdateData(FALSE);
	boxString.Format(L"");
	randomnum = (rand() % 2) + 1;//generates a random number 1/2
	if (randomnum == 1) {
		playerSign = 'O';
		pcSign = 'X';
		boxString.AppendFormat(L"Player = O\r\n");
	}
	else {
		playerSign = 'X';
		pcSign = 'O';
		boxString.AppendFormat(L"Player = X\r\n");
	}
	UpdateData(FALSE);
	headsOrTails();
	if (pcStart) {
		boxString.AppendFormat(L"\r\nPC Begin!\r\n");
		/*pairs pos = generatePCMove();
		drawPCSign(pos.first, pos.second);
		board[pos.first][pos.second] = pcSign;*/
		pcTurn();
	}
	else {
		playersTurn = true;
		boxString.AppendFormat(L"\r\nPlayer Begin!\r\n");
	}
	UpdateData(FALSE);
}


void CMFCApplication3Dlg::OnEnChangeEdit1()//Chat box
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CMFCApplication3Dlg::OnLButtonDblClk(UINT nFlags, CPoint point)//No need
{
	CDialogEx::OnLButtonDblClk(nFlags, point);
}

bool CMFCApplication3Dlg::checkifAvailable(int index) {
	int i, j, counter = 0;
	pairs newPair = findSpot(index);
	if (board[newPair.first][newPair.second] != '-' && playersTurn) {
		boxString.AppendFormat(L"Occupied spot, try again!\r\n");
		UpdateData(FALSE);
		return false;
	}
	else {
		if (playersTurn) {
			board[newPair.first][newPair.second] = playerSign;
			//playersTurn = !playersTurn;
		}
		else {
			board[newPair.first][newPair.second] = pcSign;
			//playersTurn = !playersTurn;
		}
	}
	return true;
}

void CMFCApplication3Dlg::drawPlayerSign(int index) {
	pairs newPair = findSpot(index);
	index = index - 1;
	if (playerSign == 'O') {
		drawO(Os[index].x1, Os[index].y1, Os[index].x2, Os[index].y2);
	}
	else{
		drawX(Xs[index].x, Xs[index].y);
	}
	//board[newPair.first][newPair.second] = playerSign;
	playersTurn = false;
}

void CMFCApplication3Dlg::drawPCSign(int line, int column) {
	int i, j, counter;
	counter = line * 3 + column + 1;
	if (checkifAvailable(counter) == true) {
		if (pcSign == 'X') {
			drawX(Xs[counter-1].x, Xs[counter - 1].y);
		}
		else {
			drawO(Os[counter - 1].x1, Os[counter - 1].y1, Os[counter - 1].x2, Os[counter - 1].y2);
		}
		UpdateData(FALSE);
		playersTurn = true;
	}
}

void CMFCApplication3Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	int index = 0;
	if (playersTurn && Winner == '-') {
		if (clickedNewGame == false) {
			boxString.Format(L"");
			boxString.AppendFormat(L"First you have to click on start!\r\n");
			UpdateData(FALSE);
			return;
		}
		if (point.x >= Xs[0].x && point.x <= Xs[0].x + 70 && point.y <= Xs[0].y + 50 && point.y >= Xs[0].y) {//LEFT EDGE UP 1
			index = 1;
		}
		else if (point.x >= Xs[1].x && point.x <= Xs[1].x + 70 && point.y <= Xs[1].y + 50 && point.y >= Xs[1].y) {//MIDDLE UP 2
			index = 2;
		}
		else if (point.x >= Xs[2].x && point.x <= Xs[2].x + 70 && point.y <= Xs[2].y + 50 && point.y >= Xs[2].y) {//RIGHT EDGE UP 3
			index = 3;
		}
		else if (point.x >= Xs[3].x && point.x <= Xs[3].x + 70 && point.y <= Xs[3].y + 50 && point.y >= Xs[3].y) {//MIDDLE Left 4
			index = 4;
		}
		else if (point.x >= Xs[4].x && point.x <= Xs[4].x + 70 && point.y <= Xs[4].y + 50 && point.y >= Xs[4].y) {//MIDDLE Middle 5
			index = 5;
		}
		else if (point.x >= Xs[5].x && point.x <= Xs[5].x + 70 && point.y <= Xs[5].y + 50 && point.y >= Xs[5].y) {//MIDDLE Right 6
			index = 6;
		}
		else if (point.x >= Xs[6].x && point.x <= Xs[6].x + 70 && point.y <= Xs[6].y + 50 && point.y >= Xs[6].y) {//Left Down 7
			index = 7;
		}
		else if (point.x >= Xs[7].x && point.x <= Xs[7].x + 70 && point.y <= Xs[7].y + 50 && point.y >= Xs[7].y) {//Middle Down 8
			index = 8;
		}
		else if (point.x >= Xs[8].x && point.x <= Xs[8].x + 70 && point.y <= Xs[8].y + 50 && point.y >= Xs[8].y) {//Middle Right 9
			index = 9;
		}
		if (index >= 1 && index <= 9 && checkifAvailable(index) == true) {
			drawPlayerSign(index);
			playersTurn = false;
			if (checkIfWon() || isItFull()) {
				declareWinner();
			}
			//Here pc's turn
			pcTurn();
			if (checkIfWon() || isItFull()) {
				declareWinner();
			}
		}
	}
	UpdateData(FALSE);
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMFCApplication3Dlg::OnBnClickedButton1()//Clear Button
{
	int i, j;
	Invalidate();
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			board[i][j] = '-';
		}
	}
	playersTurn = false;
	headsOrTails();
	drawBoard();
	newGame();
}


void CMFCApplication3Dlg::drawWinner(int index) {
	CClientDC dc(this);
	CPen winnerIsPlayer(PS_SOLID, 9, RGB(0, 255, 0));
	CPen winnerIsPC(PS_SOLID, 9, RGB(255, 0, 0));
	if (Winner == pcSign) {
		dc.SelectObject(&winnerIsPC);
	}
	else if(Winner == playerSign){
		dc.SelectObject(&winnerIsPlayer);
	}
	if(Winner=='-') {
		return;
	}
	if (index == 0) {
		dc.MoveTo(115, 70);//1 [CombinationsOfWinning[0]]
		dc.LineTo(420, 300);//1 [CombinationsOfWinning[0]]
	}
	else if (index == 1) {
		dc.MoveTo(375, 70);//2 [CombinationsOfWinning[1]]
		dc.LineTo(115, 300);//2 [CombinationsOfWinning[1]]
	}
	else if (index == 2) {
		dc.MoveTo(150, 70);//3[CombinationsOfWinning[2]]
		dc.LineTo(150, 300);//3[CombinationsOfWinning[2]]
	}
	else if (index == 3) {
		dc.MoveTo(250, 70);//4 [CombinationsOfWinning[3]]
		dc.LineTo(250, 300);//4 [CombinationsOfWinning[3]]
	}
	else if (index == 4) {
		dc.MoveTo(350, 70);//5 [CombinationsOfWinning[4]]
		dc.LineTo(350, 300);//5 [CombinationsOfWinning[4]]
	}
	else if (index == 5) {
		dc.MoveTo(115, 90);//6[CombinationsOfWinning[5]]
		dc.LineTo(400, 90);//6[CombinationsOfWinning[5]]
	}
	else if (index == 6) {
		dc.MoveTo(110, 175);//7 [CombinationsOfWinning[6]]
		dc.LineTo(410, 175);//7 [CombinationsOfWinning[6]]
	}
	else if (index == 7) {
		dc.MoveTo(110, 250);//8 [CombinationsOfWinning[7]]
		dc.LineTo(410, 250);//8 [CombinationsOfWinning[7]]
	}
	else if (index == 8) {
		dc.MoveTo(115, 250);//9 [CombinationsOfWinning[8]]
		dc.LineTo(350, 250);//9 [CombinationsOfWinning[8]]
	}

}

// MFCApplication3Dlg.h : header file
//

#pragma once
typedef struct pairp {
	int x;
	int y;
}pairp;

typedef struct pointsCircles {
	int x1;
	int y1;
	int x2;
	int y2;
}pointsCircles;

typedef struct pairs {
	int first;
	int second;
}pairs;

// CMFCApplication3Dlg dialog
class CMFCApplication3Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication3Dlg(CWnd* pParent = nullptr);	// standard constructor
	void drawBoard();
	void drawX(int x1, int y1);
	void drawO(int x1, int y1, int x2, int y2);
	void setXs();
	void setOs();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION3_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	static int playerWins;
	static int pcWins;
public:
	void drawWinner(int index);
	void resetBoard();
	void drawPCSign(int line, int column);
	void drawPlayerSign(int index);
	bool checkifAvailable(int index);
	void declareWinner();
	void headsOrTails();
	bool isItFull();
	bool checkIfWon();
	void applyMove(int spot);
	bool canDoMove(int line, int col);

	void pcTurn();
	void newGame();
	pairs generatePCMove();
	void adviceToPC(int& line, int& column);
	void warnPC(int& line, int& column);
	pairs findSpot(int spot);

	pairp Xs[9];
	pointsCircles Os[9];
	afx_msg void OnBnClickedOk();
	CString boxString;
	CString playerWinsBox;
	CString PCWinsBox;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);

	char playerSign = 'O';
	char pcSign = 'X';

	int combinationsOfWinning[8][3] = { {1,5,9}
				,{3,5,7}
				,{1,4,7}
				,{2,5,8 }
				,{3,6,9}
				,{1,2,3}
				,{4,5,6}
				,{7,8,9}
	};
	char board[3][3];
	char Winner;
	bool clickedNewGame;
	bool pcStart;
	bool playersTurn;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit3();
};

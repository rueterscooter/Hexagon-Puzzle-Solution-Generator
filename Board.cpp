#include"Board.h"
#include"Hex.h"
#include<iostream>
using namespace std;


void Board::drawHexAtOffset(int offsetX, int offsetY, char hexArray[8][9]) {
	for (int rows = 0; rows < 8; rows++) {
		for (int cols = 0; cols < 9; cols++) {
			if (hexArray[rows][cols] != ' ')
				boardArray[rows + offsetX][cols + offsetY] = hexArray[rows][cols];
		}
	}
}

Board::Board(int drawingStyle) {
	Hex HexA(0);
	tiles[0] = HexA;
	Hex HexB(HexA.thisHex);
	tiles[1] = HexB;
	while (compareWithAllHexes(HexB))
		HexB.reGenHex();
	Hex HexC(HexB.thisHex);
	tiles[2] = HexC;
	while (compareWithAllHexes(HexC))
		HexC.reGenHex();
	Hex HexD(HexC.thisHex);
	tiles[3] = HexD;
	while (compareWithAllHexes(HexD))
		HexD.reGenHex();
	Hex HexE(HexD.thisHex);
	tiles[4] = HexE;
	while (compareWithAllHexes(HexE))
		HexE.reGenHex();
	Hex HexF(HexE.thisHex);
	tiles[5] = HexF;
	while (compareWithAllHexes(HexF))
		HexF.reGenHex();
	Hex HexG(HexF.thisHex);
	tiles[6] = HexG;
	while (compareWithAllHexes(HexG))
		HexG.reGenHex();
	switch (drawingStyle) {
	case 1:
		drawHexAtOffset(3, 0, HexG.hexArray);
		drawHexAtOffset(9, 0, HexF.hexArray);
		drawHexAtOffset(0, 8, HexB.hexArray);
		drawHexAtOffset(6, 8, HexA.hexArray);
		drawHexAtOffset(12, 8, HexE.hexArray);
		drawHexAtOffset(3, 16, HexC.hexArray);
		drawHexAtOffset(9, 16, HexD.hexArray);
		break;
	case 2:
		drawHexAtOffset(3, 0, HexG.hexArray);
		drawHexAtOffset(10, 0, HexF.hexArray);
		drawHexAtOffset(0, 8, HexB.hexArray);
		drawHexAtOffset(7, 8, HexA.hexArray);
		drawHexAtOffset(14, 8, HexE.hexArray);
		drawHexAtOffset(3, 16, HexC.hexArray);
		drawHexAtOffset(10, 16, HexD.hexArray);
		break;
	case 3:
		drawHexAtOffset(3, 2, HexG.hexArray);
		drawHexAtOffset(9, 2, HexF.hexArray);
		drawHexAtOffset(0, 8, HexB.hexArray);
		drawHexAtOffset(6, 8, HexA.hexArray);
		drawHexAtOffset(12, 8, HexE.hexArray);
		drawHexAtOffset(3, 14, HexC.hexArray);
		drawHexAtOffset(9, 14, HexD.hexArray);
		break;
	}
	drawBoard(drawingStyle);
}

bool Board::compareWithAllHexes(Hex HexPar) {
	for (int i = 0; i < HexPar.getTileNum(); i++) {
		if (compareHexes(HexPar, tiles[i]))
			return true;
	}
	return false;
}

bool Board::compareHexes(Hex HexParA, Hex HexParB) {
	bool arraysInSameOrder = false;
	for (int i = 0; i < 6; i++) {
		if (HexParA.getSideValue(0) == HexParB.getSideValue(i)) {
			for (int j = 1; j < 6; j++) {
				if (i + j >= 6) {
					if (HexParA.getSideValue(j) == HexParB.getSideValue(i + j - 6))
						arraysInSameOrder = true;
					else {
						arraysInSameOrder = false;
						return arraysInSameOrder;
					}
				}
				else if (HexParA.getSideValue(j) == HexParB.getSideValue(i + j))
					arraysInSameOrder = true;
				else {
					arraysInSameOrder = false;
					return arraysInSameOrder;
				}
			}
		}
	}
	return arraysInSameOrder;
}

void Board::drawBoard(int drawingStyle) {
	if (drawingStyle == 2) {
		for (int i = 0; i < 22; i++) {
			for (int j = 0; j < 25; j++) {
				cout << boardArray[i][j];
			}
			cout << endl;
		}
	}
	else {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 25; j++) {
				cout << boardArray[i][j];
			}
			cout << endl;
		}
	}
}
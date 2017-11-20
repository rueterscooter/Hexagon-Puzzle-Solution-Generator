#include"Hex.h"
#include<cstdlib>
#include<ctime>

Hex::Hex() {

}

Hex::Hex(int hexID) {
	tileNum = hexID;
	srand(time(0));
	generateRandomArray();
	generateHexagon();
	lastHex = nullptr;
	centerHex = this;
}

Hex::Hex(Hex* lastHexPar) {
	lastHex = lastHexPar;
	centerHex = lastHex->centerHex;
	tileNum = lastHex->tileNum + 1;
	if (tileNum + 2 >= 6) {
		sideValues[tileNum - 4] = centerHex->getSideValue(tileNum - 1);
		doNotChangeIndexA = tileNum - 4;
	}
	else {
		sideValues[tileNum + 2] = centerHex->getSideValue(tileNum - 1);
		doNotChangeIndexA = tileNum + 2;
	}
	if (lastHex != centerHex) {
		if (tileNum + 3 >= 6) {
			if (tileNum == 6)
				sideValues[tileNum - 3] = lastHex->getSideValue(0);
			else
				sideValues[tileNum - 3] = lastHex->getSideValue(tileNum);
			doNotChangeIndexB = tileNum - 3;
		}
		else {
			sideValues[tileNum + 3] = lastHex->getSideValue(tileNum);
			doNotChangeIndexB = tileNum + 3;
		}
	}
	if (tileNum == 6) {
		while (lastHex != centerHex) {
			lastHex = lastHex->lastHex;
			if (lastHex->tileNum == 1)
				sideValues[1] = lastHex->getSideValue(4);
		}
		doNotChangeIndexC = 1;
	}
	generateRandomArray();
	generateHexagon();
}

void Hex::generateHexagon() {
	for (int row = 0; row < 8; row++) {
		for (int col = 0; col < 9; col++) {
			if (row == 0) {
				hexArray[row][3] = '_';
				hexArray[row][4] = sideValues[0] + 48;
				hexArray[row][5] = '_';
			}
			else if (row == 1) {
				hexArray[row][2] = '/';
				hexArray[row][6] = '\\';
			}
			else if (row == 2) {
				hexArray[row][1] = sideValues[5] + 48;
				hexArray[row][7] = sideValues[1] + 48;
			}
			else if (row == 3) {
				hexArray[row][0] = '/';
				hexArray[row][4] = tileNum + 48;
				hexArray[row][8] = '\\';
			}
			else if (row == 4) {
				hexArray[row][0] = '\\';
				hexArray[row][8] = '/';
			}
			else if (row == 5) {
				hexArray[row][1] = sideValues[4] + 48;
				hexArray[row][7] = sideValues[2] + 48;
			}
			else if (row == 6) {
				hexArray[row][2] = '\\';
				hexArray[row][3] = '_';
				hexArray[row][4] = sideValues[3] + 48;
				hexArray[row][5] = '_';
				hexArray[row][6] = '/';
			}
		}
	}
}

int Hex::generateRandNum() {
	return (rand() % 6 + 1);
}

void Hex::generateRandomArray() {
	srand(time(0));
	for (int i = 0; i < 6; i++) {
		if (i != doNotChangeIndexA && i != doNotChangeIndexB && i != doNotChangeIndexC) {
			sideValues[i] = generateRandNum();
			for (int j = 0; j < 6; j++) {
				if (i != j) {
					if (sideValues[i] == sideValues[j]) {
						sideValues[i] = generateRandNum();
						j = -1;
					}
				}
			}
		}
	}
}

void Hex::clearValuesArray() {
	for (int i = 0; i < 6; i++) {
		if (i != doNotChangeIndexA && i != doNotChangeIndexB && i != doNotChangeIndexC) {
			sideValues[i] = 0;
		}
	}
}

void Hex::reGenHex() {
	clearValuesArray();
	generateRandomArray();
	generateHexagon();
}

int Hex::getSideValue(int sideIndex) {
	return sideValues[sideIndex];
}

int Hex::getTileNum() {
	return tileNum;
}
#ifndef _HEX
#define _HEX

class Hex {
public:
	char hexArray[8][9] = { {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}, 
							{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
							{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '} };
	void generateHexagon();
	Hex* lastHex = nullptr;
	Hex* centerHex = nullptr;
	Hex* thisHex = this;

	Hex();
	Hex(int hexID);
	Hex(Hex* lastHexPar);
	void clearValuesArray();
	void reGenHex();
	int getSideValue(int sideIndex);
	int getTileNum();

private:
	int doNotChangeIndexA = -1;
	int doNotChangeIndexB = -1;
	int doNotChangeIndexC = -1;
	int sideValues[6] = { 0, 0, 0, 0, 0, 0 };
	int tileNum = 0;

	int generateRandNum();
	void generateRandomArray();
};

#endif // !_HEX
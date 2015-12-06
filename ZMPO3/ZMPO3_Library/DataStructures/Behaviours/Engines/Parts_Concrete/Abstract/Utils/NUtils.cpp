#include "stdafx.h"
#include "NUtils.h"

int NUtils::ToEqualsInt(char aValue0)
{
	return int(aValue0) - 48;
}

char* NUtils::hexaTobinArrUnit(char aInChar)
{
	char* aOutDecimal = new char[4];

	switch (aInChar)
	{

	case '0':
	{
		aOutDecimal[0] = '0';
		aOutDecimal[1] = '0';
		aOutDecimal[2] = '0';
		aOutDecimal[3] = '0';
		break;
	}
	case '1':
	{
		aOutDecimal[0] = '0';
		aOutDecimal[1] = '0';
		aOutDecimal[2] = '0';
		aOutDecimal[3] = '1';
		break;
	}
	case '2':
	{
		aOutDecimal[0] = '0';
		aOutDecimal[1] = '0';
		aOutDecimal[2] = '1';
		aOutDecimal[3] = '0';
		break;
	}
	case '3':
	{
		aOutDecimal[0] = '0';
		aOutDecimal[1] = '0';
		aOutDecimal[2] = '1';
		aOutDecimal[3] = '1';
		break;
	}
	case '4':
	{
		aOutDecimal[0] = '0';
		aOutDecimal[1] = '1';
		aOutDecimal[2] = '0';
		aOutDecimal[3] = '0';
		break;
	}
	case '5':
	{
		aOutDecimal[0] = '0';
		aOutDecimal[1] = '1';
		aOutDecimal[2] = '0';
		aOutDecimal[3] = '1';
		break;
	}
	case '6':
	{
		aOutDecimal[0] = '0';
		aOutDecimal[1] = '1';
		aOutDecimal[2] = '1';
		aOutDecimal[3] = '0';
		break;
	}
	case '7':
	{
		aOutDecimal[0] = '0';
		aOutDecimal[1] = '1';
		aOutDecimal[2] = '1';
		aOutDecimal[3] = '1';
		break;
	}
	case '8':
	{
		aOutDecimal[0] = '1';
		aOutDecimal[1] = '0';
		aOutDecimal[2] = '0';
		aOutDecimal[3] = '0';
		break;
	}
	case '9':
	{
		aOutDecimal[0] = '1';
		aOutDecimal[1] = '0';
		aOutDecimal[2] = '0';
		aOutDecimal[3] = '1';
		break;
	}
	case 'A':
	{
		aOutDecimal[0] = '1';
		aOutDecimal[1] = '0';
		aOutDecimal[2] = '1';
		aOutDecimal[3] = '0';
		break;
	}
	case 'B':
	{
		aOutDecimal[0] = '1';
		aOutDecimal[1] = '0';
		aOutDecimal[2] = '1';
		aOutDecimal[3] = '1';
		break;
	}
	case 'C':
	{
		aOutDecimal[0] = '1';
		aOutDecimal[1] = '1';
		aOutDecimal[2] = '0';
		aOutDecimal[3] = '0';
		break;
	}
	case 'D':
	{
		aOutDecimal[0] = '1';
		aOutDecimal[1] = '1';
		aOutDecimal[2] = '0';
		aOutDecimal[3] = '1';
		break;
	}
	case 'E':
	{
		aOutDecimal[0] = '1';
		aOutDecimal[1] = '1';
		aOutDecimal[2] = '1';
		aOutDecimal[3] = '0';
		break;
	}
	case 'F':
	{
		aOutDecimal[0] = '1';
		aOutDecimal[1] = '1';
		aOutDecimal[2] = '1';
		aOutDecimal[3] = '1';
		break;
	}
	default:
	{
		aOutDecimal[0] = '0';
		aOutDecimal[1] = '0';
		aOutDecimal[2] = '0';
		aOutDecimal[3] = '0';
	};
	}

	aOutDecimal[4] = '\0';

	return aOutDecimal;
}

char NUtils::BinTradeToHexaUnit(char *aInChar)
{
	char* aOutDecimal = new char[4];
	aOutDecimal = aInChar;

	char outVal = '0';

	if (aOutDecimal[0] == '0' &&
		aOutDecimal[1] == '0' &&
		aOutDecimal[2] == '0'&&
		aOutDecimal[3] == '0')	outVal = '0';
	else
		if (aOutDecimal[0] == '0' &&
			aOutDecimal[1] == '0' &&
			aOutDecimal[2] == '0'&&
			aOutDecimal[3] == '1')	outVal = '1';
		else
			if (aOutDecimal[0] == '0' &&
				aOutDecimal[1] == '0' &&
				aOutDecimal[2] == '1'&&
				aOutDecimal[3] == '0')	outVal = '2';
			else
				if (aOutDecimal[0] == '0' &&
					aOutDecimal[1] == '0' &&
					aOutDecimal[2] == '1'&&
					aOutDecimal[3] == '1')	outVal = '3';
				else
					if (aOutDecimal[0] == '0' &&
						aOutDecimal[1] == '1' &&
						aOutDecimal[2] == '0'&&
						aOutDecimal[3] == '0')	outVal = '4';
					else
						if (aOutDecimal[0] == '0' &&
							aOutDecimal[1] == '1' &&
							aOutDecimal[2] == '0'&&
							aOutDecimal[3] == '1')	outVal = '5';
						else
							if (aOutDecimal[0] == '0' &&
								aOutDecimal[1] == '1' &&
								aOutDecimal[2] == '1'&&
								aOutDecimal[3] == '0')	outVal = '6';
							else
								if (aOutDecimal[0] == '0' &&
									aOutDecimal[1] == '1' &&
									aOutDecimal[2] == '1'&&
									aOutDecimal[3] == '1')	outVal = '7';
								else
									if (aOutDecimal[0] == '1' &&
										aOutDecimal[1] == '0' &&
										aOutDecimal[2] == '0'&&
										aOutDecimal[3] == '0')	outVal = '8';
									else
										if (aOutDecimal[0] == '1' &&
											aOutDecimal[1] == '0' &&
											aOutDecimal[2] == '0'&&
											aOutDecimal[3] == '1')	outVal = '9';
										else
											if (aOutDecimal[0] == '1' &&
												aOutDecimal[1] == '0' &&
												aOutDecimal[2] == '1'&&
												aOutDecimal[3] == '0')	outVal = 'A';
											else
												if (aOutDecimal[0] == '1' &&
													aOutDecimal[1] == '0' &&
													aOutDecimal[2] == '1'&&
													aOutDecimal[3] == '1')	outVal = 'B';
												else
													if (aOutDecimal[0] == '1' &&
														aOutDecimal[1] == '1' &&
														aOutDecimal[2] == '0'&&
														aOutDecimal[3] == '0')	outVal = 'C';
													else
														if (aOutDecimal[0] == '1' &&
															aOutDecimal[1] == '1' &&
															aOutDecimal[2] == '0'&&
															aOutDecimal[3] == '1')	outVal = 'D';
														else
															if (aOutDecimal[0] == '1' &&
																aOutDecimal[1] == '1' &&
																aOutDecimal[2] == '1'&&
																aOutDecimal[3] == '0')	outVal = 'E';
															else
																if (aOutDecimal[0] == '1' &&
																	aOutDecimal[1] == '1' &&
																	aOutDecimal[2] == '1'&&
																	aOutDecimal[3] == '1')	outVal = 'F';
																else
																	outVal = '0';

	return outVal;
}

char NUtils::ToEqualsChar(int aValue0)
{
	return char(aValue0 + 48);
}

bool NUtils::contains(char aVal, vector<char> aTerminalVals)
{
	return std::find(
		aTerminalVals.begin(),
		aTerminalVals.end(),
		aVal) != aTerminalVals.end();
}

bool NUtils::isNumber(char aVal)
{
	vector<char> buffDigits{ '0','1','2','3','4','5','6','7','8','9','0' };

	return std::find(
		buffDigits.begin(),
		buffDigits.end(),
		aVal) != buffDigits.end();
}
//CHeksa* NUtils::AddZM(CHeksa* aValUp, CHeksa* aValDown)
//{
//	// calculating maximum size of table to collect all
//	int lengthUp = aValUp->GetSize();
//	int lengthDown = aValDown->GetSize();
//	int maxLength = (lengthUp > lengthDown) ? lengthUp + 1 : lengthDown + 1;
//	int subtractOfMaxAndUpSize = maxLength - lengthUp;
//	int subtractOfMaxAndDownSize = maxLength - lengthDown;
//	char* emptyTemp = new char[maxLength];
//
//
//	for (int i = 0; i < maxLength;i++)
//	{
//		emptyTemp[i] = '0';
//	}
//
//	// creating And zero suitable buffers
//	CHeksa* buffUp = new CHeksa(NUtils::ToEqualsChar(maxLength), emptyTemp);
//	CHeksa* buffDown = new CHeksa(NUtils::ToEqualsChar(maxLength), emptyTemp);
//	CHeksa* buffOut = new CHeksa(NUtils::ToEqualsChar(maxLength), emptyTemp);
//	CHeksa* buffHelp = new CHeksa(NUtils::ToEqualsChar(maxLength), emptyTemp);
//
//	// adding
//	for (int i = maxLength - 1; i >-1; i--)
//	{
//		int up = charToint(buffUp[i]);
//		int down = charToint(buffDown[i]);
//
//		// constant operations with added divide by zero
//		int total = down == 0 ? 0 : up / down;
//		int module = down == 0 ? up : abs(up - down); // 0 mod 1 != 1
//
//													  //// reachedIvalue
//		int reachedValue = ToEqualsInt(buffHelp[i]) + module;
//
//		// reachedValueWithBase
//		if ((reachedValue / base) != 0)
//		{
//			int reachedWholes = reachedValue / base;
//			int reachedMods = reachedValue % base;
//
//			// reachedOverflow
//			buffHelp[i - 1] = ToEqualsChar(reachedWholes);
//			// writing result
//			buffOut[i] = ToEqualsChar(reachedMods);
//		}
//		else
//		{
//			// reachedOverflow
//			buffHelp[i - 1] = ToEqualsChar(total);
//			// writing result
//			buffOut[i] = ToEqualsChar(reachedValue);
//		}
//	}
//
//	return buffOut;
//}
// digit quries
#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <stdio.h>
#include <string>

int main()
{
	int q;
	cin >> q;
	vector<long long> powerOfTen(19, 1);
	for (int i = 1; i < 19; i++)
		powerOfTen[i] = powerOfTen[i - 1] * 10;
	while (q--)
	{
		long long index;
		cin >> index;
		long long digitsSoFar = 0;
		long long digitsBeforeActualBlock = 0;
		int numberOfDigit;
		for (int i = 1; i <= 18; i++)
		{
			digitsSoFar += (powerOfTen[i] - powerOfTen[i - 1]) * i;
			if (digitsSoFar >= index)
			{
				numberOfDigit = i;
				break;
			}
			digitsBeforeActualBlock += (powerOfTen[i] - powerOfTen[i - 1] * i);
		}
		long long smalestValue = powerOfTen[numberOfDigit - 1];
		long long largestValue = powerOfTen[numberOfDigit] - 1;
		long long bestValue = 0;
		long long startingPsistionOfBestValue;
		while (smalestValue <= largestValue)
		{
			long long actualValue = (smalestValue + largestValue) / 2;
			long long staringPositionOfActualValue = 1 + digitsBeforeActualBlock + (actualValue - powerOfTen[numberOfDigit]) * numberOfDigit;
			if (startingPsistionOfBestValue <= index)
			{
				if (actualValue > bestValue)
				{
					bestValue = actualValue;
					startingPsistionOfBestValue = staringPositionOfActualValue;
				}
				smalestValue = actualValue + 1;
			}
			else
				largestValue = actualValue - 1;
		}
		string number = to_string(bestValue);
		cout << number[index - startingPsistionOfBestValue] << endl;
	}

	return 0;
}
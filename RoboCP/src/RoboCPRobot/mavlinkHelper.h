#pragma once
#include "qglobal.h"


quint16 crc_accumulate(uchar b, quint16 crc)
{
	uchar ch = (uchar)(b ^ (uchar)(crc & 0x00ff));
	ch = (uchar)(ch ^ (ch << 4));
	return (quint16)((crc >> 8) ^ (ch << 8) ^ (ch << 3) ^ (ch >> 4));
}
quint16 crc_calculate(uchar *pBuffer, int length)
{
	if (length < 1)
	{
		return 0xffff;
	}

	quint16 crcTmp;
	int i;

	crcTmp = 0xffff;

	for (i = 1; i < length; i++) // skips header
	{
		crcTmp = crc_accumulate(pBuffer[i], crcTmp);
	}

	return (crcTmp);
}
int checksum(unsigned char *data, int length)
{
	uchar MAVLINK_MESSAGE_CRCS[] = { 50, 124, 137, 0, 237, 217, 104, 119, 0, 0, 0,
		89, 0, 0, 0, 0, 0, 0, 0, 0, 214, 159, 220, 168, 24, 23, 170, 144, 67, 115, 39,
		246, 185, 104, 237, 244, 222, 212, 9, 254, 230, 28, 28, 132, 221, 232, 11, 153,
		41, 39, 78, 0, 0, 0, 15, 3, 0, 0, 0, 0, 0, 153, 183, 51, 82, 118, 148, 21, 0,
		243, 124, 0, 0, 38, 20, 158, 152, 143, 0, 0, 0, 106, 49, 22, 143, 140, 5, 150,
		0, 231, 183, 63, 54, 0, 0, 0, 0, 0, 0, 0, 175, 102, 158, 208, 56, 93, 138, 108,
		32, 185, 84, 34, 0, 124, 237, 4, 76, 128, 56, 116, 134, 237, 203, 250, 87, 203,
		220, 25, 226, 0, 29, 223, 85, 6, 229, 203, 1, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		154, 178, 0, 134, 219, 208, 188, 84, 22, 19, 21, 134, 0, 78, 68, 189, 127, 154,
		21, 21, 144, 1, 234, 73, 181, 22, 83, 167, 138, 234, 240, 47, 189, 52, 174,
		229, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8, 204, 49, 170, 44, 83, 46, 0 };
	if (length < 5)
		return 0;
	quint16 res = crc_calculate(data, length + 6);
	res = crc_accumulate(MAVLINK_MESSAGE_CRCS[data[5]], res);
	//uchar ck_a = (uchar)(res & 0xFF); ///< High byte
	//uchar ck_b = (uchar)(res >> 8); ///< Low byte
	//cout << (int)ck_a << " " << (int)ck_b;
	return res;
}
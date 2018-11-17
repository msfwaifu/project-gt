#define GetPointer(X) *(int*)(X)

typedef unsigned char byte;
typedef unsigned char BYTE;
typedef unsigned char* PBYTE;
//typedef void VOID;
typedef void* PVOID;
typedef long long __int64;
typedef unsigned int uint;

#define __int32 int
#define __int16 short

#define VOID void
#define BOOL bool
#define TRUE true
#define FALSE false
#define FLOAT float
#define INT int

//PS3:
namespace PS3Lib
{
	float ReadSingleFloat(int Address)
	{
		return *(float*)Address;
	}
	float floatArray[100];
	float* ReadFloat(int address, int length)
	{
		for (int i = 0; i < length; i++)
		{
			floatArray[i] = *(float*)(address + (i * 0x04));
		}
		return floatArray;
	}

	char byteArrayz[100];
	char* ReadBytes(int address, int length)
	{
		for (int i = 0; i < length; i++)
		{
			byteArrayz[i] = *(char*)(address + (i));
		}
		return byteArrayz;
	}

	void WriteFloat(int address, float* input, int length)
	{
		for (int i = 0; i < length; i++)
		{
			*(float*)(address + (i * 4)) = input[i];
		}
	}

	void WriteSingleFloat(int Address, float Input)
	{
		*(float*)Address = Input;
	}

	void WriteBytes(int address, char* input, int length)
	{
		for (int i = 0; i < length; i++)
		{
			*(char*)(address + (i)) = input[i];
		}
	}
	void WriteByte(int Address, unsigned char Input)
	{
		*(unsigned char*)Address = Input;
	}
	float intArray[100];
	float* ReadInt(int address, int length)
	{
		for (int i = 0; i < length; i++)
		{
			intArray[i] = *(int*)(address + (i * 0x04));
		}
		return intArray;
	}

	void WriteInt(int address, int* input, int length)
	{
		for (int i = 0; i < length; i++)
		{
			*(int*)(intArray + (i * 0x04)) = input[i];
		}
	}
	void WriteInt32(int Address, int Input)
	{
		*(int*)Address = Input;
	}

	void WriteString(int address, char* string)
	{
		int FreeMem = 0x1D00000;
		int strlength = std::strlen(string);
		*(char**)FreeMem = string;
		char* StrBytes = ReadBytes(*(int*)FreeMem, strlength);
		WriteBytes(address, StrBytes, strlength);
	}
	struct readstr
	{
		char returnRead[100];
	}ReturnRead[1000];
	int strcount;

	char* ReadStringz(int address)
	{
		strcount++;
		memset(&ReturnRead[strcount].returnRead[0], 0, sizeof(ReturnRead[strcount].returnRead));
		int strlength = 100;
		char* StrBytes = ReadBytes(address, strlength);
		for (int i = 0; i < strlength; i++)
		{
			if (StrBytes[i] != 0x00)
				ReturnRead[strcount].returnRead[i] = StrBytes[i];
			else
				break;
		}
		return ReturnRead[strcount].returnRead;
	}
	char byteArray[100];
	char* ReadBytesC(int address, int length)
	{
		for (int i = 0; i < length; i++)
		{
			byteArray[i] = *(char*)(address + (i));
		}
		return byteArray;
	}
	char returnRead[100];
	char* ReadStringC(int address)
	{
		memset(&returnRead[0], 0, sizeof(returnRead));
		int strlength = 100;
		char* StrBytes = ReadBytesC(address, strlength);
		for (int i = 0; i < strlength; i++)
		{
			if (StrBytes[i] != 0x00)
				returnRead[i] = StrBytes[i];
			else
				break;
		}
		return returnRead;
	}
	int ReadInt32(int Address)
	{
		return *(int*)Address;
	}
	char* ReadString(int Address)
	{
		return (char*)Address;
	}
	char returnReadd[100];
	char* ReadStringzz(int address, bool IncludeSpaces) {
		int strlength = 100;
		char* StrBytes = PS3Lib::ReadBytes(address, strlength);

		char StopBytes = 0x00;
		if (!IncludeSpaces)
			StopBytes = 0x20;

		for (int i = 0; i < strlength; i++)
			returnReadd[i] = 0;
		for (int i = 0; i < strlength; i++) {
			if (StrBytes[i] != StopBytes)
				returnReadd[i] = StrBytes[i];
		}
		return returnReadd;
	}
};

//Console Commands
int32_t write_process(uint64_t ea, const void * data, uint32_t size)
{
	system_call_4(905, (uint64_t)sys_process_getpid(), ea, size, (uint64_t)data);
	return_to_user_prog(int32_t);
}
void* read_process(uint64_t ea, uint32_t size)
{
	void* data;
	system_call_4(904, (uint64_t)sys_process_getpid(), ea, size, (uint64_t)data);
	return data;
}

//Hook Functions


//Create Thread

//Sprintf
void reverse(char s[])
{
	int i, j;
	char c;
	for (i = 0, j = strlen(s) - 1; i<j; i++, j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
void itoa(int n, char s[])
{
	int i, sign;
	if ((sign = n) < 0)  /* record sign */
		n = -n;          /* make n positive */
	i = 0;
	do  		/* generate digits in reverse order */
	{
		s[i++] = n % 10 + '0';	/* get next digit */
	} while ((n /= 10) > 0);	/* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}
int atoi(char* str)
{
	int val = 0;
	while (*str)
	{
		val = val * 10 + (*str++ - '0');
	}
	return val;
}
bool isdigit(char Num) {
	return (Num >= 0x30 && Num <= 0x39);
}
int VSprintf(char *ptr, const char *fmt, va_list ap)
{
	if (!ptr || !fmt)
		return -1;
	__int64 Int;
	int sLen;
	char* String;
	char* aPtr;
	byte bTemp;
	char Buf[0x500];
	while (*fmt)
	{
		char Temp = *fmt;
		int Length = -1;
		if (Temp == '%')
		{
			fmt++;
			if (*fmt == '0')
			{
				fmt++;
				Length = 0;
				char* aPtr = Buf;
				while (isdigit(Temp = *fmt))
				{
					*aPtr = Temp;
					aPtr++;
					fmt++;
					*aPtr = 0;
				}
				Length = atoi(Buf);
			}
			switch (*fmt)
			{
			case 's':
				String = va_arg(ap, char*);
				if (String)
				{
					while (*String)
					{
						*ptr = *String;
						String++;
						if (*String)
							ptr++;
					}
				}
				break;
			case 'p':
				Length = 8;
			case 'X':
			case 'x':
				bool Found;
				bool Caps;
				Int = va_arg(ap, __int64);
				if (Length == -1)
					Int = Int & 0xFFFFFFFF;
				Caps = *fmt != 'x';
				Found = false;
				for (int i = 0; i < 8; i++)   // for each bit :: 0 0   0 0   0 0   0 0
				{
					bTemp = (Int >> (28 - (i * 4))) & 0xF;
					if ((8 - i) <= Length)
						Found = true;
					if (Length == -1 && !Found && bTemp)
						Found = true;
					if (Found)
					{
						if (bTemp <= 9)// decimal
							*ptr = 0x30 + bTemp;
						else// hex
							*ptr = (Caps ? 0x40 : 0x60) + bTemp - 9;
						if (i != 7)
							*ptr++;
					}
				}
				break;
			case 'i':
			case 'd':
				memset(Buf, '0', 0xFF);
				Int = va_arg(ap, __int64);
				if (Length == -1)
					Int = Int & 0xFFFFFFFF;
				aPtr = ptr;
				itoa((int)Int, ptr);
				sLen = strlen(ptr);
				if (Length == -1)
					Length = sLen;
				memcpy(Buf + 0xFF - sLen, aPtr, sLen);
				memcpy(aPtr, Buf + 0xFF - Length, Length);
				ptr = aPtr + Length - 1;
				break;
			case 'f':
				break;
			}
		}
		else
			*ptr = Temp;
		ptr++;
		fmt++;
	}
	*ptr = 0;
	return 1;
}
int Sprintf(char *ptr, const char *fmt, /*args*/ ...)  // %s, %i, %d, %x, %X, %p
{
	if (!ptr || !fmt)
		return -1;
	va_list ap;
	va_start(ap, fmt);
	VSprintf(ptr, fmt, ap);
	va_end(ap);
	return 1;
}

char vaBuffer[0x2000];
char* va(const char* fmt, ...) {
	va_list ap;
	va_start(ap, fmt);

	VSprintf(vaBuffer, fmt, ap);

	va_end(ap);
	return vaBuffer;
}

//cString Compare
int cstrcmp(const char* s1, const char* s2)//Please note if its equal to zero the strings are equal
{
	while (*s1 && (*s1 == *s2))
		s1++, s2++;
	return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}
bool Compare(const char* String1, const char* String2) {
	return !strcmp(String1, String2);
}

//Sprint Commands
int cPrint(const char* string) {
	char buf[100];
	Sprintf(buf, "%s\n", string);
}
int clientIntPrint(int percentInt, const char* string) {
	char buf[100];
	Sprintf(buf, "[%i] %s\n", percentInt, string);
}
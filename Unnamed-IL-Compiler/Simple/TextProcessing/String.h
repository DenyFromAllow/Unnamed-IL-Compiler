#pragma once

void SimpleTP_Int8ToString		(char * buffer, int8		InInt8);	/*»º³åÇø>=5*/
void SimpleTP_Int16ToString		(char * buffer, int16		InInt16);	/*»º³åÇø>=7*/
void SimpleTP_Int32ToString		(char * buffer, int32		InInt32);	/*»º³åÇø>=12*/
void SimpleTP_Int64ToString		(char * buffer, int64		InInt64);	/*»º³åÇø>=21*/
void SimpleTP_Uint8ToString		(char * buffer, uint8		InInt8);	/*»º³åÇø>=4*/
void SimpleTP_Uint16ToString	(char * buffer, uint16		InInt16);	/*»º³åÇø>=6*/
void SimpleTP_Uint32ToString	(char * buffer, uint32		InInt32);	/*»º³åÇø>=11*/
void SimpleTP_Uint64ToString	(char * buffer, uint64		InInt64);	/*»º³åÇø>=21*/
void SimpleTP_FloatToString		(char * string, float		InFloat);	/*»º³åÇø>=12*/
void SimpleTP_DoubleToString	(char * string, double		InDouble);	/*»º³åÇø>=22*/
void SimpleTP_TimeToString		(char * string, SIMPLE_TIME	InTime);	/*»º³åÇø>=25*/

void SimpleTP_Int8ToString		(char * buffer, uint8 InLength, int8	InInt8);	/*»º³åÇø>=5  && »º³åÇø>=InLength*/
void SimpleTP_Int16ToString		(char * buffer, uint8 InLength, int16	InInt16);	/*»º³åÇø>=7  && »º³åÇø>=InLength*/
void SimpleTP_Int32ToString		(char * buffer, uint8 InLength, int32	InInt32);	/*»º³åÇø>=12 && »º³åÇø>=InLength*/
void SimpleTP_Int64ToString		(char * buffer, uint8 InLength, int64	InInt64);	/*»º³åÇø>=21 && »º³åÇø>=InLength*/
void SimpleTP_Uint8ToString		(char * buffer, uint8 InLength, uint8	InInt8);	/*»º³åÇø>=4  && »º³åÇø>=InLength*/
void SimpleTP_Uint16ToString	(char * buffer, uint8 InLength, uint16	InInt16);	/*»º³åÇø>=6  && »º³åÇø>=InLength*/
void SimpleTP_Uint32ToString	(char * buffer, uint8 InLength, uint32	InInt32);	/*»º³åÇø>=11 && »º³åÇø>=InLength*/
void SimpleTP_Uint64ToString	(char * buffer, uint8 InLength, uint64	InInt64);	/*»º³åÇø>=21 && »º³åÇø>=InLength*/

class SIMPLE_STRING {
private:
	char *StringPointer = nullptr;
	uint32 First = 0, Last = 0, MemLength = 0;

public:
	FORCEINLINE uint32 size() const { return Last - First; }
	FORCEINLINE char *begin() const { return StringPointer + First; }
	FORCEINLINE char *end()   const { return StringPointer + Last; }
	FORCEINLINE void clear() { if(StringPointer)delete[]StringPointer; First = Last = MemLength = 0; StringPointer = nullptr; }
	FORCEINLINE bool IsEmpty() { return !StringPointer || !MemLength || First >= Last || !(*begin()); }

	FORCEINLINE SIMPLE_STRING() { }
	FORCEINLINE ~SIMPLE_STRING() { clear(); }
	SIMPLE_STRING(const char			*InChar);
	SIMPLE_STRING(const char			*InChar, const uint32 count);
	SIMPLE_STRING(const char			InChar);
	SIMPLE_STRING(const SIMPLE_STRING	&InString);
	SIMPLE_STRING(		SIMPLE_STRING	&&InString);
	SIMPLE_STRING(const std::string		&InStdString);
	SIMPLE_STRING(const int32			&In);
	SIMPLE_STRING(const int64			&In);
	SIMPLE_STRING(const uint32			&In);
	SIMPLE_STRING(const uint64			&In);
	SIMPLE_STRING(const int				&In);
	SIMPLE_STRING(const unsigned int	&In);
	SIMPLE_STRING(const float			&In);
	SIMPLE_STRING(const double			&In);
	SIMPLE_STRING(const SIMPLE_TIME		&In);
	explicit SIMPLE_STRING(const uint8 InLength, const int32		&In);
	explicit SIMPLE_STRING(const uint8 InLength, const int64		&In);
	explicit SIMPLE_STRING(const uint8 InLength, const uint32		&In);
	explicit SIMPLE_STRING(const uint8 InLength, const uint64		&In);
	explicit SIMPLE_STRING(const uint8 InLength, const int			&In);
	explicit SIMPLE_STRING(const uint8 InLength, const unsigned int	&In);


	SIMPLE_STRING &PushBack (const char				*In);
	SIMPLE_STRING &PushFront(const char				*In);
	SIMPLE_STRING &PushBack (const char				*In, const uint32 count);
	SIMPLE_STRING &PushFront(const char				*In, const uint32 count);
	SIMPLE_STRING &PushBack (const char				In);
	SIMPLE_STRING &PushFront(const char				In);
	SIMPLE_STRING &PushBack (const SIMPLE_STRING	&In);
	SIMPLE_STRING &PushFront(const SIMPLE_STRING	&In);
	SIMPLE_STRING &PushBack (const std::string		&In);
	SIMPLE_STRING &PushFront(const std::string		&In);

	FORCEINLINE SIMPLE_STRING &PushFront(const int32		&In) { char buffer[12]; SimpleTP_Int32ToString (buffer, In); return PushFront(buffer); }
	FORCEINLINE SIMPLE_STRING &PushFront(const int64		&In) { char buffer[21]; SimpleTP_Int64ToString (buffer, In); return PushFront(buffer); }
	FORCEINLINE SIMPLE_STRING &PushFront(const uint32		&In) { char buffer[11]; SimpleTP_Uint32ToString(buffer, In); return PushFront(buffer); }
	FORCEINLINE SIMPLE_STRING &PushFront(const uint64		&In) { char buffer[21]; SimpleTP_Uint64ToString(buffer, In); return PushFront(buffer); }
	FORCEINLINE SIMPLE_STRING &PushFront(const int			&In) { char buffer[12]; SimpleTP_Int32ToString (buffer, In); return PushFront(buffer); }
	FORCEINLINE SIMPLE_STRING &PushFront(const unsigned int	&In) { char buffer[11]; SimpleTP_Uint32ToString(buffer, In); return PushFront(buffer); }
	FORCEINLINE SIMPLE_STRING &PushFront(const float		&In) { char buffer[12]; SimpleTP_FloatToString (buffer, In); return PushFront(buffer); }
	FORCEINLINE SIMPLE_STRING &PushFront(const double		&In) { char buffer[22]; SimpleTP_DoubleToString(buffer, In); return PushFront(buffer); }
	FORCEINLINE SIMPLE_STRING &PushFront(const SIMPLE_TIME	&In) { char buffer[25]; SimpleTP_TimeToString  (buffer, In); return PushFront(buffer); }

	FORCEINLINE SIMPLE_STRING &PushBack(const int32			&In) { char buffer[12]; SimpleTP_Int32ToString (buffer, In); return PushBack(buffer); }
	FORCEINLINE SIMPLE_STRING &PushBack(const int64			&In) { char buffer[20]; SimpleTP_Int64ToString (buffer, In); return PushBack(buffer); }
	FORCEINLINE SIMPLE_STRING &PushBack(const uint32		&In) { char buffer[11]; SimpleTP_Uint32ToString(buffer, In); return PushBack(buffer); }
	FORCEINLINE SIMPLE_STRING &PushBack(const uint64		&In) { char buffer[20]; SimpleTP_Uint64ToString(buffer, In); return PushBack(buffer); }
	FORCEINLINE SIMPLE_STRING &PushBack(const int			&In) { char buffer[12]; SimpleTP_Int32ToString (buffer, In); return PushBack(buffer); }
	FORCEINLINE SIMPLE_STRING &PushBack(const unsigned int	&In) { char buffer[11]; SimpleTP_Uint32ToString(buffer, In); return PushBack(buffer); }
	FORCEINLINE SIMPLE_STRING &PushBack(const float			&In) { char buffer[12]; SimpleTP_FloatToString (buffer, In); return PushBack(buffer); }
	FORCEINLINE SIMPLE_STRING &PushBack(const double		&In) { char buffer[22]; SimpleTP_DoubleToString(buffer, In); return PushBack(buffer); }
	FORCEINLINE SIMPLE_STRING &PushBack(const SIMPLE_TIME	&In) { char buffer[25]; SimpleTP_TimeToString  (buffer, In); return PushBack(buffer); }

	FORCEINLINE SIMPLE_STRING &PushFront(const uint8 InLength, const int32			&In) { char buffer[257]; SimpleTP_Int32ToString (buffer, InLength, In); return PushFront(buffer); }
	FORCEINLINE SIMPLE_STRING &PushFront(const uint8 InLength, const int64			&In) { char buffer[257]; SimpleTP_Int64ToString (buffer, InLength, In); return PushFront(buffer); }
	FORCEINLINE SIMPLE_STRING &PushFront(const uint8 InLength, const uint32			&In) { char buffer[256]; SimpleTP_Uint32ToString(buffer, InLength, In); return PushFront(buffer); }
	FORCEINLINE SIMPLE_STRING &PushFront(const uint8 InLength, const uint64			&In) { char buffer[256]; SimpleTP_Uint64ToString(buffer, InLength, In); return PushFront(buffer); }
	FORCEINLINE SIMPLE_STRING &PushFront(const uint8 InLength, const int			&In) { char buffer[257]; SimpleTP_Int32ToString (buffer, InLength, In); return PushFront(buffer); }
	FORCEINLINE SIMPLE_STRING &PushFront(const uint8 InLength, const unsigned int	&In) { char buffer[256]; SimpleTP_Uint32ToString(buffer, InLength, In); return PushFront(buffer); }

	FORCEINLINE SIMPLE_STRING &PushBack(const uint8 InLength, const int32			&In) { char buffer[257]; SimpleTP_Int32ToString (buffer, InLength, In); return PushBack(buffer); }
	FORCEINLINE SIMPLE_STRING &PushBack(const uint8 InLength, const int64			&In) { char buffer[257]; SimpleTP_Int64ToString (buffer, InLength, In); return PushBack(buffer); }
	FORCEINLINE SIMPLE_STRING &PushBack(const uint8 InLength, const uint32			&In) { char buffer[256]; SimpleTP_Uint32ToString(buffer, InLength, In); return PushBack(buffer); }
	FORCEINLINE SIMPLE_STRING &PushBack(const uint8 InLength, const uint64			&In) { char buffer[256]; SimpleTP_Uint64ToString(buffer, InLength, In); return PushBack(buffer); }
	FORCEINLINE SIMPLE_STRING &PushBack(const uint8 InLength, const int				&In) { char buffer[257]; SimpleTP_Int32ToString (buffer, InLength, In); return PushBack(buffer); }
	FORCEINLINE SIMPLE_STRING &PushBack(const uint8 InLength, const unsigned int	&In) { char buffer[256]; SimpleTP_Uint32ToString(buffer, InLength, In); return PushBack(buffer); }

	bool OCTToint32(int32 &Out);
	bool DECToint32(int32 &Out);
	bool HEXToint32(int32 &Out);
	bool OCTTouint32(uint32 &Out);
	bool DECTouint32(uint32 &Out);
	bool HEXTouint32(uint32 &Out);
	bool OCTToint64(int64 &Out);
	bool DECToint64(int64 &Out);
	bool HEXToint64(int64 &Out);
	bool OCTTouint64(uint64 &Out);
	bool DECTouint64(uint64 &Out);
	bool HEXTouint64(uint64 &Out);

	FORCEINLINE SIMPLE_STRING &operator>>(SIMPLE_STRING &In) const	{ return In.PushBack(*this); }
	FORCEINLINE SIMPLE_STRING &operator<<(const char *In)			{ return PushBack(In); }
	FORCEINLINE SIMPLE_STRING &operator<<(const char In)			{ return PushBack(In); }
	FORCEINLINE SIMPLE_STRING &operator<<(const SIMPLE_STRING &In)	{ return PushBack(In); }
	FORCEINLINE SIMPLE_STRING &operator<<(const std::string &In)	{ return PushBack(In); }

	FORCEINLINE SIMPLE_STRING &operator<<(const int32			&In) { return PushBack(In); }
	FORCEINLINE SIMPLE_STRING &operator<<(const int64			&In) { return PushBack(In); }
	FORCEINLINE SIMPLE_STRING &operator<<(const uint32			&In) { return PushBack(In); }
	FORCEINLINE SIMPLE_STRING &operator<<(const uint64			&In) { return PushBack(In); }
	FORCEINLINE SIMPLE_STRING &operator<<(const int				&In) { return PushBack(In); }
	FORCEINLINE SIMPLE_STRING &operator<<(const unsigned int	&In) { return PushBack(In); }
	FORCEINLINE SIMPLE_STRING &operator<<(const float			&In) { return PushBack(In); }
	FORCEINLINE SIMPLE_STRING &operator<<(const double			&In) { return PushBack(In); }
	FORCEINLINE SIMPLE_STRING &operator<<(const SIMPLE_TIME		&In) { return PushBack(In); }

	SIMPLE_STRING &operator=(const char				*In);
	SIMPLE_STRING &operator=(const SIMPLE_STRING	&In);
	SIMPLE_STRING &operator=(SIMPLE_STRING			&&In);
	SIMPLE_STRING &operator=(const std::string		&In);
	FORCEINLINE SIMPLE_STRING &operator=(const int32		&In) { char buffer[12]; SimpleTP_Int32ToString (buffer, In); return operator=(buffer); }
	FORCEINLINE SIMPLE_STRING &operator=(const int64		&In) { char buffer[20]; SimpleTP_Int64ToString (buffer, In); return operator=(buffer); }
	FORCEINLINE SIMPLE_STRING &operator=(const uint32		&In) { char buffer[11]; SimpleTP_Uint32ToString(buffer, In); return operator=(buffer); }
	FORCEINLINE SIMPLE_STRING &operator=(const uint64		&In) { char buffer[20]; SimpleTP_Uint64ToString(buffer, In); return operator=(buffer); }
	FORCEINLINE SIMPLE_STRING &operator=(const int			&In) { char buffer[12]; SimpleTP_Int32ToString (buffer, In); return operator=(buffer); }
	FORCEINLINE SIMPLE_STRING &operator=(const unsigned int	&In) { char buffer[11]; SimpleTP_Uint32ToString(buffer, In); return operator=(buffer); }
	FORCEINLINE SIMPLE_STRING &operator=(const float		&In) { char buffer[12]; SimpleTP_FloatToString (buffer, In); return operator=(buffer); }
	FORCEINLINE SIMPLE_STRING &operator=(const double		&In) { char buffer[22]; SimpleTP_DoubleToString(buffer, In); return operator=(buffer); }
	FORCEINLINE SIMPLE_STRING &operator=(const SIMPLE_TIME	&In) { char buffer[22]; SimpleTP_TimeToString  (buffer, In); return operator=(buffer); }

	bool operator==(const char			*In) const;
	bool operator==(const SIMPLE_STRING	&In) const;
	bool operator==(const std::string	&In) const;

	FORCEINLINE SIMPLE_STRING operator+(const char			*In) { SIMPLE_STRING ret = *this; ret << In; return ret; }
	FORCEINLINE SIMPLE_STRING operator+(const SIMPLE_STRING	&In) { SIMPLE_STRING ret = *this; ret << In; return ret; }
	FORCEINLINE SIMPLE_STRING operator+(const std::string	&In) { SIMPLE_STRING ret = *this; ret << In; return ret; }

	FORCEINLINE void operator++()	{ if(StringPointer && MemLength && Last > First) printf("%s", begin()); }
	FORCEINLINE void operator++(int){ if(StringPointer && MemLength && Last > First) printf("%s", begin()); }
	FORCEINLINE void operator~()	{ clear(); }
	FORCEINLINE char &operator[](uint32 index) { return begin()[index]; }
	FORCEINLINE SIMPLE_STRING &operator<<(SIMPLE_STRING &(*Function)(SIMPLE_STRING&)) { return Function(*this); }

	operator std::string();
	#if defined(_IOSTREAM_) || defined(_GLIBCXX_IOSTREAM)
	friend FORCEINLINE std::ostream& operator<<(std::ostream& stream, SIMPLE_STRING &InString);
	#endif

	friend SIMPLE_STRING &print(SIMPLE_STRING &InString);
	friend SIMPLE_STRING &flush(SIMPLE_STRING &InString);
	friend SIMPLE_STRING &clear(SIMPLE_STRING &InString);
	friend SIMPLE_STRING &endl(SIMPLE_STRING &InString);
	friend SIMPLE_STRING &end(SIMPLE_STRING &InString);
};

#if defined(_IOSTREAM_) || defined(_GLIBCXX_IOSTREAM)
FORCEINLINE std::ostream& operator<<(std::ostream& stream, SIMPLE_STRING &InString) { if(!InString.StringPointer || !InString.MemLength || InString.Last < InString.First)stream << InString.begin(); return stream; }
#endif

FORCEINLINE SIMPLE_STRING &operator>>(const std::string		&In, SIMPLE_STRING &InString) { return InString.PushFront(In); }
FORCEINLINE SIMPLE_STRING &operator>>(const char		*InChar, SIMPLE_STRING &InString) { return InString.PushFront(InChar); }
FORCEINLINE SIMPLE_STRING &operator>>(const char		 InChar, SIMPLE_STRING &InString) { return InString.PushFront(InChar); }
FORCEINLINE SIMPLE_STRING &operator>>(const int32			&In, SIMPLE_STRING &InString) { return InString.PushFront(In); }
FORCEINLINE SIMPLE_STRING &operator>>(const uint32			&In, SIMPLE_STRING &InString) { return InString.PushFront(In); }
FORCEINLINE SIMPLE_STRING &operator>>(const int64			&In, SIMPLE_STRING &InString) { return InString.PushFront(In); }
FORCEINLINE SIMPLE_STRING &operator>>(const uint64			&In, SIMPLE_STRING &InString) { return InString.PushFront(In); }
FORCEINLINE SIMPLE_STRING &operator>>(const int				&In, SIMPLE_STRING &InString) { return InString.PushFront(In); }
FORCEINLINE SIMPLE_STRING &operator>>(const unsigned int	&In, SIMPLE_STRING &InString) { return InString.PushFront(In); }
FORCEINLINE SIMPLE_STRING &operator>>(const float			&In, SIMPLE_STRING &InString) { return InString.PushFront(In); }
FORCEINLINE SIMPLE_STRING &operator>>(const double			&In, SIMPLE_STRING &InString) { return InString.PushFront(In); }
FORCEINLINE SIMPLE_STRING &operator>>(const SIMPLE_TIME		&In, SIMPLE_STRING &InString) { return InString.PushFront(In); }

FORCEINLINE SIMPLE_STRING operator+(const char			*In, const SIMPLE_STRING &InString) { SIMPLE_STRING ret = InString; In >> ret; return ret; }
FORCEINLINE SIMPLE_STRING operator+(const std::string	&In, const SIMPLE_STRING &InString) { SIMPLE_STRING ret = InString; In >> ret; return ret; }

FORCEINLINE bool operator==(const char			*In, const SIMPLE_STRING &InString) { return InString == In; }
FORCEINLINE bool operator==(const std::string	&In, const SIMPLE_STRING &InString) { return InString == In; }

char *&operator>>(const SIMPLE_STRING &InString, char *&InChar);
char *&operator<<(char *&InChar, SIMPLE_STRING &InString);
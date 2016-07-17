#pragma once
#ifdef min
#undef min
#endif
class SIMPLE_TIME {
public:
	int64 us;

private:
	SIMPLE_TIME(const int64 &In) :us(In) { }
public:
	SIMPLE_TIME() : us(0) { }
	SIMPLE_TIME(const SIMPLE_TIME &In) :us(In.us) { }

	FORCEINLINE SIMPLE_TIME Nonnegative() { return SIMPLE_TIME(SimpleMath_Max2(us, 0)); }
	FORCEINLINE SIMPLE_TIME ToNonnegative() { us = SimpleMath_Max2(us, 0); return *this; }

	FORCEINLINE SIMPLE_TIME Nonneg() { return SIMPLE_TIME(SimpleMath_Max2(us, 0)); }
	FORCEINLINE SIMPLE_TIME ToNonneg() { us = SimpleMath_Max2(us, 0); return *this; }

	FORCEINLINE int64 usec() { return us; }
	FORCEINLINE int64 msec() { return us / 1000ll; }
	FORCEINLINE int64 ms() { return us / 1000ll; }
	FORCEINLINE int64 sec() { return us / 1000000ll; }
	FORCEINLINE int64 s() { return us / 1000000ll; }
	FORCEINLINE int64 min() { return us / 60000000ll; }
	FORCEINLINE int64 hour() { return us / 3600000000ll; }
	FORCEINLINE int64 day() { return us / 86400000000ll; }
	FORCEINLINE int64 year() { return us / 31536000000000ll; }

	FORCEINLINE uint64 useconly()	{ return (uint64) us % 1000ull; }
	FORCEINLINE uint64 usonly()		{ return (uint64) us % 1000ull; }
	FORCEINLINE uint64 mseconly()	{ return (uint64) us / 1000ull			% 1000ull; }
	FORCEINLINE uint64 msonly()		{ return (uint64) us / 1000ull			% 1000ull; }
	FORCEINLINE uint64 seconly()	{ return (uint64) us / 1000000ull		% 60ull; }
	FORCEINLINE uint64 sonly()		{ return (uint64) us / 1000000ull		% 60ull; }
	FORCEINLINE uint64 minonly()	{ return (uint64) us / 60000000ull		% 60ull; }
	FORCEINLINE uint64 houronly()	{ return (uint64) us / 3600000000ull	% 24ull; }
	FORCEINLINE uint64 dayonly()	{ return (uint64) us / 86400000000ull	% 365ull; }

	FORCEINLINE float Fusec() { return (float) us; }
	FORCEINLINE float Fus() { return (float) us; }
	FORCEINLINE float Fmsec() { return (float) us / 1000ll; }
	FORCEINLINE float Fms() { return (float) us / 1000ll; }
	FORCEINLINE float Fsec() { return (float) us / 1000000ll; }
	FORCEINLINE float Fs() { return (float) us / 1000000ll; }
	FORCEINLINE float Fmin() { return (float) us / 60000000ll; }
	FORCEINLINE float Fhour() { return (float) us / 3600000000ll; }
	FORCEINLINE float Fday() { return (float) us / 86400000000ll; }
	FORCEINLINE float Fyear() { return (float) us / 31536000000000ll; }

	FORCEINLINE double Dusec() { return (double) us; }
	FORCEINLINE double Dus() { return (double) us; }
	FORCEINLINE double Dmsec() { return (double) us / 1000ll; }
	FORCEINLINE double Dms() { return (double) us / 1000ll; }
	FORCEINLINE double Dsec() { return (double) us / 1000000ll; }
	FORCEINLINE double Ds() { return (double) us / 1000000ll; }
	FORCEINLINE double Dmin() { return (double) us / 60000000ll; }
	FORCEINLINE double Dhour() { return (double) us / 3600000000ll; }
	FORCEINLINE double Dday() { return (double) us / 86400000000ll; }
	FORCEINLINE double Dyear() { return (double) us / 31536000000000ll; }

	FORCEINLINE SIMPLE_TIME operator+(SIMPLE_TIME T) { return SIMPLE_TIME(us + T.us); }
	FORCEINLINE SIMPLE_TIME operator-(SIMPLE_TIME T) { return SIMPLE_TIME(us - T.us); }
	FORCEINLINE SIMPLE_TIME operator%(SIMPLE_TIME T) { return SIMPLE_TIME(us % T.us); }
	FORCEINLINE SIMPLE_TIME operator=(SIMPLE_TIME T) { us = T.us; return *this; }
	FORCEINLINE SIMPLE_TIME operator<<(int64 Count) { return SIMPLE_TIME(us << Count); }
	FORCEINLINE SIMPLE_TIME operator>>(int64 Count) { return SIMPLE_TIME(us >> Count); }
	FORCEINLINE SIMPLE_TIME operator*(int64 Scale) { return SIMPLE_TIME(us * Scale); }
	FORCEINLINE SIMPLE_TIME operator/(int64 Scale) { return SIMPLE_TIME(us / Scale); }
	FORCEINLINE SIMPLE_TIME operator*(float Scale) { return SIMPLE_TIME(int64(us * Scale)); }
	FORCEINLINE SIMPLE_TIME operator/(float Scale) { return SIMPLE_TIME(int64(us / Scale)); }
	FORCEINLINE SIMPLE_TIME operator*(double Scale) { return SIMPLE_TIME(int64(us * Scale)); }
	FORCEINLINE SIMPLE_TIME operator/(double Scale) { return SIMPLE_TIME(int64(us / Scale)); }

	FORCEINLINE SIMPLE_TIME operator+=(SIMPLE_TIME T) { us += T.us; return *this; }
	FORCEINLINE SIMPLE_TIME operator-=(SIMPLE_TIME T) { us -= T.us; return *this; }
	FORCEINLINE SIMPLE_TIME operator%=(SIMPLE_TIME T) { us %= T.us; return *this; }
	FORCEINLINE SIMPLE_TIME operator<<=(int64 Count) { us <<= Count; return *this; }
	FORCEINLINE SIMPLE_TIME operator>>=(int64 Count) { us >>= Count; return *this; }
	FORCEINLINE SIMPLE_TIME operator*=(int64 Scale) { us *= Scale; return *this; }
	FORCEINLINE SIMPLE_TIME operator/=(int64 Scale) { us /= Scale; return *this; }
	FORCEINLINE SIMPLE_TIME operator*=(float Scale) { us = int64(us * Scale); return *this; }
	FORCEINLINE SIMPLE_TIME operator/=(float Scale) { us = int64(us / Scale); return *this; }
	FORCEINLINE SIMPLE_TIME operator*=(double Scale) { us = int64(us * Scale); return *this; }
	FORCEINLINE SIMPLE_TIME operator/=(double Scale) { us = int64(us / Scale); return *this; }

	FORCEINLINE SIMPLE_TIME operator-() { return SIMPLE_TIME(-us); }

	FORCEINLINE bool operator==(SIMPLE_TIME T) { return us == T.us; }
	FORCEINLINE bool operator!=(SIMPLE_TIME T) { return us != T.us; }
	FORCEINLINE bool operator<(SIMPLE_TIME T) { return us < T.us; }
	FORCEINLINE bool operator>(SIMPLE_TIME T) { return us > T.us; }
	FORCEINLINE bool operator<=(SIMPLE_TIME T) { return us <= T.us; }
	FORCEINLINE bool operator>=(SIMPLE_TIME T) { return us >= T.us; }

	FORCEINLINE operator bool() { return us > 0; }

	//#pragma warning(push)
	//#pragma warning(disable:4455)
	FORCEINLINE friend const SIMPLE_TIME operator""_usec(const uint64 InUS);
	FORCEINLINE friend const SIMPLE_TIME operator""_us(const uint64 InUS);
	FORCEINLINE friend const SIMPLE_TIME operator""_msec(const uint64 InMS);
	FORCEINLINE friend const SIMPLE_TIME operator""_ms(const uint64 InMS);
	FORCEINLINE friend const SIMPLE_TIME operator""_sec(const uint64 InS);
	FORCEINLINE friend const SIMPLE_TIME operator""_s(const uint64 InS);
	FORCEINLINE friend const SIMPLE_TIME operator""_min(const uint64 InM);
	FORCEINLINE friend const SIMPLE_TIME operator""_hour(const uint64 InH);
	FORCEINLINE friend const SIMPLE_TIME operator""_h(const uint64 InH);
	FORCEINLINE friend const SIMPLE_TIME operator""_day(const uint64 InD);
	FORCEINLINE friend const SIMPLE_TIME operator""_year(const uint64 InY);

	FORCEINLINE friend const SIMPLE_TIME operator""_usec(const long double InUS);
	FORCEINLINE friend const SIMPLE_TIME operator""_us(const long double InUS);
	FORCEINLINE friend const SIMPLE_TIME operator""_msec(const long double InMS);
	FORCEINLINE friend const SIMPLE_TIME operator""_ms(const long double InMS);
	FORCEINLINE friend const SIMPLE_TIME operator""_sec(const long double InS);
	FORCEINLINE friend const SIMPLE_TIME operator""_s(const long double InS);
	FORCEINLINE friend const SIMPLE_TIME operator""_min(const long double InM);
	FORCEINLINE friend const SIMPLE_TIME operator""_hour(const long double InH);
	FORCEINLINE friend const SIMPLE_TIME operator""_h(const long double InH);
	FORCEINLINE friend const SIMPLE_TIME operator""_day(const long double InD);
	FORCEINLINE friend const SIMPLE_TIME operator""_year(const long double InY);
	//#pragma warning(pop)

	friend class SIMPLE_TIMER;
};

FORCEINLINE const SIMPLE_TIME operator""_usec(const uint64 InUS) { return SIMPLE_TIME(InUS); }
FORCEINLINE const SIMPLE_TIME operator""_us(const uint64 InUS) { return SIMPLE_TIME(InUS); }
FORCEINLINE const SIMPLE_TIME operator""_msec(const uint64 InMS) { return SIMPLE_TIME(InMS * 1000ll); }
FORCEINLINE const SIMPLE_TIME operator""_ms(const uint64 InMS) { return SIMPLE_TIME(InMS * 1000ll); }
FORCEINLINE const SIMPLE_TIME operator""_sec(const uint64 InS) { return SIMPLE_TIME(InS * 1000000ll); }
FORCEINLINE const SIMPLE_TIME operator""_s(const uint64 InS) { return SIMPLE_TIME(InS * 1000000ll); }
FORCEINLINE const SIMPLE_TIME operator""_min(const uint64 InM) { return SIMPLE_TIME(InM * 60000000ll); }
FORCEINLINE const SIMPLE_TIME operator""_hour(const uint64 InH) { return SIMPLE_TIME(InH * 3600000000ll); }
FORCEINLINE const SIMPLE_TIME operator""_h(const uint64 InH) { return SIMPLE_TIME(InH * 3600000000ll); }
FORCEINLINE const SIMPLE_TIME operator""_day(const uint64 InD) { return SIMPLE_TIME(InD * 86400000000ll); }
FORCEINLINE const SIMPLE_TIME operator""_year(const uint64 InY) { return SIMPLE_TIME(InY * 31536000000000ll); }

FORCEINLINE const SIMPLE_TIME operator""_usec(const long double InUS) { return SIMPLE_TIME(int64(InUS)); }
FORCEINLINE const SIMPLE_TIME operator""_us(const long double InUS) { return SIMPLE_TIME(int64(InUS)); }
FORCEINLINE const SIMPLE_TIME operator""_msec(const long double InMS) { return SIMPLE_TIME(int64(InMS * 1000ll)); }
FORCEINLINE const SIMPLE_TIME operator""_ms(const long double InMS) { return SIMPLE_TIME(int64(InMS * 1000ll)); }
FORCEINLINE const SIMPLE_TIME operator""_sec(const long double InS) { return SIMPLE_TIME(int64(InS * 1000000ll)); }
FORCEINLINE const SIMPLE_TIME operator""_s(const long double InS) { return SIMPLE_TIME(int64(InS * 1000000ll)); }
FORCEINLINE const SIMPLE_TIME operator""_min(const long double InM) { return SIMPLE_TIME(int64(InM * 60000000ll)); }
FORCEINLINE const SIMPLE_TIME operator""_hour(const long double InH) { return SIMPLE_TIME(int64(InH * 3600000000ll)); }
FORCEINLINE const SIMPLE_TIME operator""_h(const long double InH) { return SIMPLE_TIME(int64(InH * 3600000000ll)); }
FORCEINLINE const SIMPLE_TIME operator""_day(const long double InD) { return SIMPLE_TIME(int64(InD * 86400000000ll)); }
FORCEINLINE const SIMPLE_TIME operator""_year(const long double InY) { return SIMPLE_TIME(int64(InY * 31536000000000ll)); }

#if defined(_IOSTREAM_) || defined(_GLIBCXX_IOSTREAM)
std::ostream& operator<<(std::ostream& stream, SIMPLE_TIME T) {
	return stream << T.dayonly()
		<< ((T.houronly() < 10) ? "day 0" : "day ") << T.houronly()
		<< ((T.minonly() < 10) ? ":0" : ":") << T.minonly()
		<< ((T.seconly() < 10) ? ":0" : ":") << T.seconly()
		<< ((T.mseconly() < 10) ? ".00" : (T.mseconly() < 100) ? ".0" : ".") << T.mseconly()
		<< ((T.useconly() < 10) ? "00" : (T.useconly() < 100) ? "0" : "") << T.useconly();
}
#endif

FORCEINLINE void Sleep(SIMPLE_TIME time) {
	#ifdef _WIN32
	if(time.msec() > 0)Sleep(int32(time.msec()));
	#else
	if(time.us > 0)usleep(time.us);
	#endif
}

FORCEINLINE void sleep(SIMPLE_TIME time) {
	#ifdef _WIN32
	if(time.msec() > 0)Sleep(int32(time.msec()));
	#else
	if(time.us > 0)usleep(time.us);
	#endif
}

class  SIMPLE_TIMER {
private:
	bool privateStarted = false, privatePaused = false;
public:
	#ifdef _WIN32
	int64 StartTime, PauseTime, Frequency;
	#else
	timeval StartTime, PauseTime;
	#endif
	const bool &Started = privateStarted, &Paused = privatePaused;
	
	FORCEINLINE SIMPLE_TIMER() { }
	
	void start();
	void StartAndPause();
	void reset();
	void ResetAndStart();
	void ResetAndPause();
	void pause();
	void resume();

	FORCEINLINE void operator+=(SIMPLE_TIME T) {
		if(!privateStarted)return;
		#ifdef _WIN32
		StartTime -= T.us * Frequency / 1000000;
		#else
		StartTime.tv_usec -= T.us % 1000000;
		StartTime.tv_sec -= T.us / 1000000;
		if(!StartTime.tv_usec<0) {
			StartTime.tv_usec += 1000000;
			StartTime.tv_sec -= 1;
		}
		#endif
	}

	FORCEINLINE void operator-=(SIMPLE_TIME T) {
		if(!privateStarted)return;
		#ifdef _WIN32
		StartTime += T.us * Frequency / 1000000;
		#else
		StartTime.tv_usec += T.us % 1000000;
		StartTime.tv_sec += T.us / 1000000;
		if(!StartTime.tv_usec >= 1000000) {
			StartTime.tv_usec -= 1000000;
			StartTime.tv_sec += 1;
		}
		#endif
	}

	SIMPLE_TIME Get() const;
	SIMPLE_TIME GetTime() const;
	SIMPLE_TIME GetInterval();
};

class  SIMPLE_INTERVAL {
private:
	bool privateStarted = false;
	std::thread *IntervalThread;

public:
	SIMPLE_TIMER Timer;
	void (*Function)();
	SIMPLE_TIME Interval;

	FORCEINLINE SIMPLE_INTERVAL() :Timer(), Function(nullptr), Interval() { }
	FORCEINLINE SIMPLE_INTERVAL(void (*InFunction)()) :Timer(), Function(InFunction), Interval() { }
	FORCEINLINE SIMPLE_INTERVAL(SIMPLE_TIME InInterval) :Timer(), Function(nullptr), Interval(InInterval) { }
	FORCEINLINE SIMPLE_INTERVAL(void (*InFunction)(), SIMPLE_TIME InInterval) :Timer(), Function(InFunction), Interval(InInterval) { }
	FORCEINLINE SIMPLE_INTERVAL(SIMPLE_TIME InInterval, void (*InFunction)()) :Timer(), Function(InFunction), Interval(InInterval) { }

	void Start();
	void TimerStart();

	bool Wait();

private:
	static void ThreadFunc(SIMPLE_INTERVAL *InThis);
	//void SetTime
};

class  SIMPLE_HIGH_PRECISION_INTERVAL {
private:
	bool privateStarted = false;
	std::thread *IntervalThread;

public:
	SIMPLE_TIMER Timer;
	void (*Function)();
	SIMPLE_TIME Interval;
	SIMPLE_TIME ReserveTime = 1000_us;
	SIMPLE_TIME EstimatedTime;

	FORCEINLINE SIMPLE_HIGH_PRECISION_INTERVAL() :Timer(), Function(nullptr), Interval() { }
	FORCEINLINE SIMPLE_HIGH_PRECISION_INTERVAL(void (*InFunction)()) : Timer(), Function(InFunction), Interval() { }
	FORCEINLINE SIMPLE_HIGH_PRECISION_INTERVAL(SIMPLE_TIME InInterval) : Timer(), Function(nullptr), Interval(InInterval) { }
	FORCEINLINE SIMPLE_HIGH_PRECISION_INTERVAL(SIMPLE_TIME InInterval, SIMPLE_TIME InReserve) : Timer(), Function(nullptr), Interval(InInterval), ReserveTime(InReserve) { }
	FORCEINLINE SIMPLE_HIGH_PRECISION_INTERVAL(void (*InFunction)(), SIMPLE_TIME InInterval) : Timer(), Function(InFunction), Interval(InInterval) { }
	FORCEINLINE SIMPLE_HIGH_PRECISION_INTERVAL(void (*InFunction)(), SIMPLE_TIME InInterval, SIMPLE_TIME InReserve) : Timer(), Function(InFunction), Interval(InInterval), ReserveTime(InReserve) { }
	FORCEINLINE SIMPLE_HIGH_PRECISION_INTERVAL(SIMPLE_TIME InInterval, void (*InFunction)()) : Timer(), Function(InFunction), Interval(InInterval) { }
	FORCEINLINE SIMPLE_HIGH_PRECISION_INTERVAL(SIMPLE_TIME InInterval, SIMPLE_TIME InReserve, void (*InFunction)()) : Timer(), Function(InFunction), Interval(InInterval), ReserveTime(InReserve) { }

	void Start();
	void TimerStart();

	bool Wait();

private:
	static void ThreadFunc(SIMPLE_HIGH_PRECISION_INTERVAL *InThis);
	//void SetTime
};

class  SIMPLE_EXTREMELY_BRIEF_INTERVAL {
private:
	bool privateStarted = false;
	std::thread *IntervalThread;

public:
	SIMPLE_TIMER Timer;
	void (*Function)();
	SIMPLE_TIME Interval;
	SIMPLE_TIME EstimatedTime;

	FORCEINLINE SIMPLE_EXTREMELY_BRIEF_INTERVAL() :Timer(), Function(nullptr), Interval() { }
	FORCEINLINE SIMPLE_EXTREMELY_BRIEF_INTERVAL(void (*InFunction)()) : Timer(), Function(InFunction), Interval() { }
	FORCEINLINE SIMPLE_EXTREMELY_BRIEF_INTERVAL(SIMPLE_TIME InInterval) : Timer(), Function(nullptr), Interval(InInterval) { }
	FORCEINLINE SIMPLE_EXTREMELY_BRIEF_INTERVAL(void (*InFunction)(), SIMPLE_TIME InInterval) : Timer(), Function(InFunction), Interval(InInterval) { }
	FORCEINLINE SIMPLE_EXTREMELY_BRIEF_INTERVAL(SIMPLE_TIME InInterval, void (*InFunction)()) : Timer(), Function(InFunction), Interval(InInterval) { }

	void Start();
	void TimerStart();

	bool Wait();

private:
	static void ThreadFunc(SIMPLE_EXTREMELY_BRIEF_INTERVAL *InThis);
	//void SetTime
};
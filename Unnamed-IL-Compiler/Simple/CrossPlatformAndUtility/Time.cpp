#include "../simple.h"

void SIMPLE_TIMER::start() {
	if(privatePaused && privateStarted) {
		resume();
		return;
	}
	if(privateStarted)return;
	#ifdef _WIN32
	QueryPerformanceFrequency((LARGE_INTEGER*) &Frequency);
	QueryPerformanceCounter((LARGE_INTEGER*) &StartTime);
	#else
	gettimeofday(&StartTime, NULL);
	#endif
	privateStarted = true;
}

void SIMPLE_TIMER::StartAndPause() {
	if(privatePaused && privateStarted) {
		resume();
		return;
	}
	if(privateStarted)return;
	#ifdef _WIN32
	QueryPerformanceFrequency((LARGE_INTEGER*) &Frequency);
	QueryPerformanceCounter((LARGE_INTEGER*) &StartTime);
	#else
	gettimeofday(&StartTime, NULL);
	#endif
	PauseTime = StartTime;
	privatePaused = true;
	privateStarted = true;
}

void SIMPLE_TIMER::reset() {
	if(!privateStarted) {
		start();
		return;
	}
	#ifdef _WIN32
	QueryPerformanceCounter((LARGE_INTEGER*) &StartTime);
	#else
	gettimeofday(&StartTime, NULL);
	#endif
	if(privatePaused)PauseTime = StartTime;
}

void SIMPLE_TIMER::ResetAndStart() {
	if(!privateStarted) {
		start();
		return;
	}
	#ifdef _WIN32
	QueryPerformanceCounter((LARGE_INTEGER*) &StartTime);
	#else
	gettimeofday(&StartTime, NULL);
	#endif
	privatePaused = false;
}

void SIMPLE_TIMER::ResetAndPause() {
	if(!privateStarted) {
		StartAndPause();
		return;
	}
	if(!privateStarted)return;
	#ifdef _WIN32
	QueryPerformanceCounter((LARGE_INTEGER*) &StartTime);
	#else
	gettimeofday(&StartTime, NULL);
	#endif
	PauseTime = StartTime;
	privatePaused = true;
}

void SIMPLE_TIMER::pause() {
	if(!privateStarted || privatePaused)return;
	#ifdef _WIN32
	QueryPerformanceCounter((LARGE_INTEGER*) &PauseTime);
	#else
	gettimeofday(&PauseTime, NULL);
	#endif
	privatePaused = true;
}

void SIMPLE_TIMER::resume() {
	if(!privateStarted || !privatePaused)return;
	#ifdef _WIN32
	int64 Now;
	QueryPerformanceCounter((LARGE_INTEGER*) &Now);
	StartTime += Now - PauseTime;
	#else
	timeval Now;
	timeval OldStartTime=StartTime;
	gettimeofday(&Now, NULL);
	StartTime.tv_usec = (OldStartTime.tv_usec > Now.tv_usec) ? OldStartTime.tv_usec - Now.tv_usec : 1000000 + OldStartTime.tv_usec - Now.tv_usec;
	StartTime.tv_sec = (OldStartTime.tv_usec > Now.tv_usec) ? OldStartTime.tv_sec - Now.tv_sec : OldStartTime.tv_sec - Now.tv_sec - 1;
	#endif
	privatePaused = false;
}

SIMPLE_TIME SIMPLE_TIMER::Get() const {
	if(!privateStarted)return 0;
	#ifdef _WIN32
	int64 Now;
	if(privatePaused) {
		Now = PauseTime;
	} else {
		QueryPerformanceCounter((LARGE_INTEGER*) &Now);
	}
	return SIMPLE_TIME((Now - StartTime) * 1000000 / Frequency);
	#else
	timeval Now;
	if(Paused) {
		Now = PauseTime;
	} else {
		gettimeofday(&Now, NULL);
	}
	return SIMPLE_TIME((Now.tv_sec - StartTime.tv_sec) * 1000000 + Now.tv_usec - StartTime.tv_usec);
	#endif
}
SIMPLE_TIME SIMPLE_TIMER::GetTime() const {
	if(!privateStarted)return 0;
	#ifdef _WIN32
	int64 Now;
	if(privatePaused) {
		Now = PauseTime;
	} else {
		QueryPerformanceCounter((LARGE_INTEGER*) &Now);
	}
	return SIMPLE_TIME((Now - StartTime) * 1000000 / Frequency);
	#else
	timeval Now;
	if(Paused) {
		Now = PauseTime;
	} else {
		gettimeofday(&Now, NULL);
	}
	return SIMPLE_TIME((Now.tv_sec - StartTime.tv_sec) * 1000000 + Now.tv_usec - StartTime.tv_usec);
	#endif
}
SIMPLE_TIME SIMPLE_TIMER::GetInterval() {
	if(!privateStarted)return 0;
	#ifdef _WIN32
	int64 Now;
	if(privatePaused) {
		Now = PauseTime;
	} else {
		QueryPerformanceCounter((LARGE_INTEGER*) &Now);
	}
	int64 Interval = (Now - StartTime) * 1000000 / Frequency;
	StartTime += Interval * Frequency / 1000000;
	return SIMPLE_TIME(Interval);
	#else
	timeval Now;
	if(Paused) {
		Now = PauseTime;
	} else {
		gettimeofday(&Now, NULL);
	}
	int64 Interval = (Now.tv_sec - StartTime.tv_sec) * 1000000 + Now.tv_usec - StartTime.tv_usec;
	StartTime.tv_usec = (StartTime.tv_usec + Interval) % 1000000;
	StartTime.tv_sec += (StartTime.tv_usec + Interval) / 1000000;
	return SIMPLE_TIME(Interval);
	#endif
}


void SIMPLE_INTERVAL::Start() {
	if(Interval == SIMPLE_TIME() || Function == nullptr)return;
	IntervalThread = new std::thread(ThreadFunc, this);
	IntervalThread->detach();
}
void SIMPLE_INTERVAL::TimerStart() {
	Timer.start();
}

bool SIMPLE_INTERVAL::Wait() {
	SIMPLE_TIME TimeRemaining = Interval - Timer.Get();
	Sleep(TimeRemaining);
	Timer -= Interval;
	return TimeRemaining.us >= 0;
}

void SIMPLE_INTERVAL::ThreadFunc(SIMPLE_INTERVAL *InThis) {
	while(1) {
		if(InThis->Interval == SIMPLE_TIME() || InThis->Function == nullptr)return;
		InThis->Function();
		Sleep(InThis->Interval - InThis->Timer.Get());
		InThis->Timer -= InThis->Interval;
	}
}


void SIMPLE_HIGH_PRECISION_INTERVAL::Start() {
	if(Interval == SIMPLE_TIME() || Function == nullptr)return;
	IntervalThread = new std::thread(ThreadFunc, this);
	IntervalThread->detach();
}
void SIMPLE_HIGH_PRECISION_INTERVAL::TimerStart() {
	Timer.start();
	EstimatedTime = Interval;
}

bool SIMPLE_HIGH_PRECISION_INTERVAL::Wait() {
	SIMPLE_TIME TimeRemaining = EstimatedTime - Timer.Get();
	Sleep(TimeRemaining - ReserveTime);
	while(EstimatedTime > Timer.Get()) {
	}
	EstimatedTime += Interval;
	return TimeRemaining.us >= 0;
}

void SIMPLE_HIGH_PRECISION_INTERVAL::ThreadFunc(SIMPLE_HIGH_PRECISION_INTERVAL *InThis) {
	while(1) {
		if(InThis->Interval == SIMPLE_TIME() || InThis->Function == nullptr)return;
		InThis->Function();
		Sleep(InThis->EstimatedTime - InThis->ReserveTime - InThis->Timer.Get());
		while(InThis->EstimatedTime > InThis->Timer.Get()) {
		}
		InThis->EstimatedTime += InThis->Interval;
	}
}


void SIMPLE_EXTREMELY_BRIEF_INTERVAL::Start() {
	if(Interval == SIMPLE_TIME() || Function == nullptr)return;
	IntervalThread = new std::thread(ThreadFunc, this);
	IntervalThread->detach();
}
void SIMPLE_EXTREMELY_BRIEF_INTERVAL::TimerStart() {
	Timer.start();
}

bool SIMPLE_EXTREMELY_BRIEF_INTERVAL::Wait() {
	SIMPLE_TIME TimeRemaining = EstimatedTime - Timer.Get();
	while(EstimatedTime > Timer.Get()) {
	}
	EstimatedTime += Interval;
	return TimeRemaining.us >= 0;
}

void SIMPLE_EXTREMELY_BRIEF_INTERVAL::ThreadFunc(SIMPLE_EXTREMELY_BRIEF_INTERVAL *InThis) {
	while(1) {
		if(InThis->Interval == SIMPLE_TIME() || InThis->Function == nullptr)return;
		InThis->Function();
		while(InThis->EstimatedTime > InThis->Timer.Get()) {
		}
		InThis->EstimatedTime += InThis->Interval;
	}
}
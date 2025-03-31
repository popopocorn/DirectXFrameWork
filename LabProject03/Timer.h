#pragma once

const ULONG MAX_SAMPLE_COUNT = 50;

class CGameTimer{
public:
	CGameTimer();
	virtual ~CGameTimer();

	void Start() {}
	void Stop(){}
	void Reset();
	void Tick(float fLockFPS = 0.0f);
	unsigned long GetFrameRate(LPTSTR lpszString = nullptr, int nCharacters = 0);
	float GetTimeElapsed();

private:
	bool m_bHardWareHasPerformanceCounter;
	float m_fTimeScale;
	float m_fTimeElapsed;
	__int64 m_nCurrentTime;
	__int64 m_nLastTime;
	__int64 m_nPerformanceFrequency;

	float m_fFrameTime[MAX_SAMPLE_COUNT];
	ULONG m_nSampleCount;

	unsigned long m_nCurrentFrameRate;
	unsigned long m_nFramePerSecond;
	float m_fFPSTimeElapsed;

	bool m_bStopped;
};


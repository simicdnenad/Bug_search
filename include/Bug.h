#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <thread>
using namespace std;

#define LINES_PER_THREAD		50000

class CBug
{
	unsigned m_uNumOfBugs;
	static unsigned s_uBugMaxDim, s_uBugDimNum, s_uNumOfLines;
#ifdef MULTI_THREAD
	static unsigned s_uNumOfThreads;
	unsigned m_uThreadId;
#endif
	static list<string> s_lFileLand, s_lFileBug;
	list<string>::iterator *m_aiSearchForBug;
	static list<string>::iterator *s_aiBugItself;
	bool SearchBugPart(/**unsigned*/ int found_at, /**unsigned*/ int &start_from, unsigned int currbugdim);
	unsigned MaxBugPart (unsigned dim);
#ifdef SIMPLE_LOG
	unsigned m_uCurrLine;
	ofstream m_fWriteFound;
#endif
public:
	CBug();
	virtual ~CBug();
#ifdef MULTI_THREAD
	static bool OnInit(int ac, char** av);
#else
	bool OnInit(int ac, char** av);
#endif
	unsigned int NumOfBugs(unsigned int start_line=0);
	static unsigned int GetNumOfLines();
	unsigned int GetNumOfBugs() const;
#ifdef NOTDEF 					// not working!!!
	void operator()()			// should be thread's function
	{
		NumOfBugs(0);
	}
#endif
};


/*
 * Copyright 2010 Reef Angel / Roberto Imai
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

 /*
  * Updated by:  Curt Binder
  * Updates Released under Apache License, Version 2.0
  */

#ifndef __TIMEDPORT_H__
#define __TIMEDPORT_H__

#include <Globals.h>
#include <ReefAngel.h>

/*
    TimedPort Class
*/

class TimedPort
{
public:
	TimedPort();
	byte ID; // Port (i.e. Box1_Port2);
	byte Delay; // For use as a DelayedOn port
	int Offset; // Timer offset
	int Repeat;	 // 0 for disabled - Must be larger than Time
	int Time; // Scheduled runtime
	int StartTime; // How long to run triggered from Start();
	int StopTime; // How long to run triggered from Stop();
    double Scale; // Default is seconds (for minutes use 60, hours use 3600);

	void Init();

	// These are just like the corresponding Relay functions
	void On(); 
	void Off(); 
    void Auto();
	void DelayedOn();
	void DelayedOn(byte delay);
    void Override(byte type);
    void Toggle();
	void Set(bool status);
	inline void Write() { ReefAngel.Relay.Write(); }
	inline bool Status() { return ReefAngel.Relay.Status(ID); }
	inline bool isMaskOn() { return ReefAngel.Relay.isMaskOn(ID); }
    inline bool isMaskOff() { return ReefAngel.Relay.isMaskOff(ID); }

	inline bool IsRunning() { return running; }
	inline bool IsStarted() { return started; }
	inline bool IsStopped() { return stopped; }
    inline bool IsActive() { return activestatus; };
  	inline void Pause() { activestatus=false; }
	inline void Resume() { activestatus=true; }
	inline void SetActive(bool status) { activestatus=status; }
	void Run(); // Run Schedule + manual timers  
	void Osc(); // Ignore timers run schedule
	void Start(); // Start now for OnTime seconds
	void Stop(); // Disable for OffTime seconds

	void Run(int offset, int ontime, int offtime, bool status); 
	void Osc(int offset, int ontime, int offtime, bool status); 
	void Start(int time); // Start now for specified seconds
	void Stop(int time); // Disable for specified seconds
	
	// Starting variable location to initialize or save a ports settings
	void Load(int memStart);
	void Save(int memStart);
  
	inline unsigned long GetTimer() { return timer; }
  
private:
	unsigned long timer;
	bool started;
	bool stopped;
    bool running;
    bool activestatus;
};

#endif  // __TIMEDPORT_H__


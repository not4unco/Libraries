// Star

DS1307RTC RTC;
RA_TouchLCD TouchLCD;
RA_TFT TFT;
FontClass SmallFont;
FontClass Font;
FontClass LargeFont;
RA_TS TS;
ButtonClass OkButton;
ButtonClass CancelButton;
ProgressBarClass PB[6];
SliderClass Slider;
RA_ATOALARMClass AlarmInput;

ParamsStruct LastParams;
typedef void (ReefAngelClass::* FuncPtr) (); // declare function pointers
FuncPtr MenuFunctionPtr;
FuncPtr menu_button_functions1[6];
FuncPtr menu_button_functions2[6];
FuncPtr menu_button_functions3[6];
FuncPtr menu_button_functions4[6];
int CustomExpansionValue[8];
int CustomExpansionLastValue[8];

byte LastOrientation;
boolean MilitaryTime;
signed char DisplayedScreen;
signed char RecallScreen;
bool NeedsRedraw;
bool TouchEnabled;
bool Sleeping;
byte orientation;
//byte LongTouch;
bool SDFound;
time_t newnow;
int CalVal1, CalVal2;
int CloudCalVal;
byte CalStep;
unsigned long lastRedraw; 
unsigned long lastDisplayChange; 

void ChangeOrientation();
void SetOrientation(byte o);
void CalibrateTouchScreen();
void ChangeDisplayedScreen(signed char index);
void MainScreen();
void ResetScreenSaver();
void SetupTouchDateTime();
void SetupTouchCalibratePH();
void SetupTouchCalibrateSal();
void SetupTouchCalibrateORP();
void SetupTouchCalibratePHExp();
void SetupTouchCalibrateWL(byte channel);
inline void SetupTouchCalibrateWL0() { SetupTouchCalibrateWL(0); };
inline void SetupTouchCalibrateWL1() { SetupTouchCalibrateWL(1); };
inline void SetupTouchCalibrateWL2() { SetupTouchCalibrateWL(2); };
inline void SetupTouchCalibrateWL3() { SetupTouchCalibrateWL(3); };
inline void SetupTouchCalibrateWL4() { SetupTouchCalibrateWL(4); };
void ApplySalinityCompensation();
void CheckMenuTimeout();
inline void ShowTouchMenu() { ShowTouchMenu(MAIN_MENU_SCREEN); };
void ShowTouchMenu(byte index);
void ShowTouchInterface();	
void ReDrawScreen();
void ProcessTouch();
void CheckTouch();

void BuzzerOn(byte style=0);
void BuzzerOff();

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the TDF_API_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// TDF_API_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef TDF_API_EXPORTS
#define TDF_API __declspec(dllexport)
#else
#define TDF_API __declspec(dllimport)
#endif

// kdb+ 32-bit API
#ifdef WIN32
#define K_DECL	_cdecl
#else
#define K_DECL
#endif

#pragma comment(lib, "TDFAPI30.lib")

#ifdef __cplusplus
extern "C" {
#endif

	TDF_API K K_DECL setTimeout(
		K hbInterval,	//-5h or -6h or -7h
		K hbMissing,	//-5h or -6h or -7h
		K openTimeout	//-5h or -6h or -7h
		);

	TDF_API K K_DECL TDF_login(
		K servers,		//99h: `host`port`username`password!(-11h or 10h;5h or 6h or 7h;-11h or 10h;-11h or 10h)
		K markets,		//-11h or 11h
		K tickers,		//-11h or 11h
		K types,		//-11h or 11h
		K startTime		//-19h
		);

	TDF_API K K_DECL TDF_logout(
		K tdf		//-7h
		);

#ifdef __cplusplus
}//extern "C"
#endif

/////////////////////////////////////////////////////////////////////////////
namespace TDF {

	// Default settings for Wind TDF's remote calls
	//NOTE: szUser & szPwd in this variable shall _not_ be used!
	extern ::TDF_OPEN_SETTING_EXT SETTINGS;

}//namespace TDF
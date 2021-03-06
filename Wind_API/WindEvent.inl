#ifndef __WINDEVENT_H__
static_assert(0, "Include Wind_API/WindEvent.h instead!");
#endif

#include "win32.util/hexDump.h"

template <typename Char, typename Traits>
std::basic_ostream<Char, Traits>& Wind::operator<<(std::basic_ostream<Char, Traits>& os, ::WQEvent const& event) {
	os << "{(" << event.Version << ')'
		<< "Type:[" << event.EventType << ']' << util::eventType2Text(event.EventType) << ','
		<< "ID:" << event.EventID << ','
		<< "ReqID:" << event.RequestID << ',';
	if (event.ErrCode != WQERR_OK) {
		os << "Err:[" << event.ErrCode << ']' << util::error2Text(event.ErrCode) << ',';
	}
	os << "Data:*" << ::util::hexBytes(event.pQuantData) << '}';
	return os;
}
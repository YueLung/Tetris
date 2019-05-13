#include "Event.h"


Event::Event(isAllowFun isAllowfun, onFun onFun):
	m_onEvent(isAllowfun),
	m_isAllowEvent(onFun)
{
}

Event::~Event()
{
}

/*
  The contents of this file are subject to the Initial Developer's Public
  License Version 1.0 (the "License"); you may not use this file except in
  compliance with the License. You may obtain a copy of the License here:
  http://www.flamerobin.org/license.html.

  Software distributed under the License is distributed on an "AS IS"
  basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
  License for the specific language governing rights and limitations under
  the License.

  The Original Code is FlameRobin (TM).

  The Initial Developer of the Original Code is Gregory Sapunkov.

  Portions created by the original developer
  are Copyright (C) 2004 Gregory Sapunkov.

  All Rights Reserved.

  Contributor(s): Milan Babuskov.
*/

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// for all others, include the necessary headers (this file is usually all you
// need because it includes almost all "standard" wxWindows headers
#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

//
//
//
//
//-----------------------------------------------------------------------------
#include <list>
#include <algorithm>
#include "observer.h"
#include "subject.h"

Observer::Observer()
{
}
//-----------------------------------------------------------------------------
Observer::~Observer()
{
	std::list<Subject *>::iterator it;
	while (true)
	{
		it = observedObjectsM.begin();
		if (it == observedObjectsM.end())
			break;
		(*it)->detach(this);	// object will be removed by removeObservedObject()
	}
}
//-----------------------------------------------------------------------------
Subject *Observer::getFirstObservedObject()
{
	if (observedObjectsM.empty())
		return 0;
	else
		return *(observedObjectsM.begin());
}
//-----------------------------------------------------------------------------
void Observer::addObservedObject(Subject *object)
{
	observedObjectsM.push_back(object);
}
//-----------------------------------------------------------------------------
void Observer::removeObservedObject(Subject *object)
{
	observedObjectsM.erase(std::find(observedObjectsM.begin(), observedObjectsM.end(), object));
}
//-----------------------------------------------------------------------------

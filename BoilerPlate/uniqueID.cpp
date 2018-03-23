
#include "uniqueID.hpp"

namespace engine
{
	namespace core
	{
		int uniqueID::mNextID = 0;

		uniqueID::uniqueID()
		{
			mID = ++mNextID;
		}

		uniqueID::uniqueID(const uniqueID& assignedID)
		{
			mID = assignedID.mID;
		}

		uniqueID& uniqueID::operator=(const uniqueID& assignedID)
		{
			mID = assignedID.mID;
			return(*this);
		}
	}
}
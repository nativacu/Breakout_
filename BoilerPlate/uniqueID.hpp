#pragma once
#ifndef _UNIQUEID_HPP_
#define _UNIQUEID_HPP_

namespace engine
{
	namespace core
	{
		class uniqueID
		{
		public:
			// CTOR
			uniqueID();
			uniqueID(const uniqueID& assignedID);

			// OPERATORS
			uniqueID& operator=(const uniqueID& assignedID);

			// MEMBERS
			int mID;
		protected:
			static int mNextID;
		};

	}
}

#endif // !_UNIQUEID_HPP_

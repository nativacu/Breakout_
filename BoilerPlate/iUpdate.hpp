#pragma once
#ifndef _IUPDATE_HPP_
#define _IUPDATE_HPP_

namespace engine
{
	namespace core
	{
		class iUpdate
		{
		public:
			// CTOR
			iUpdate() : mNumberOfUpdates(0) {}
			virtual ~iUpdate() = default;

			// PUBLIC FUNCTIONS
			void virtual update(double deltaTime) { mNumberOfUpdates++; };
		protected:
			// MEMBERS
			int	mNumberOfUpdates;
		};
	}
}

#endif // !_IUPDATE_HPP_

#pragma once
#ifndef _IRENDER_HPP_
#define _IRENDER_HPP_

namespace engine
{
	namespace core
	{
		class iRender
		{
		public:
			virtual ~iRender() = default;
			// PUBLIC FUNCTIONS
			void virtual render() = 0;
		};
	}
}

#endif // !_IRENDER_HPP_
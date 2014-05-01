#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <iostream>

namespace Candy{
	template <typename T>
	class Singleton
	{
		protected:
			static T * mInstance;
			~Singleton(){};
			Singleton(const Singleton &);
		public:
			Singleton(){
			mInstance=(T*)this;
			};
			static T & getInstance()
			{
				return *mInstance;
			}
	};

};
template<typename T> T * Candy::Singleton<T>::mInstance= nullptr;
#endif

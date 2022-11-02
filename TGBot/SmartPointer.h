#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include <utility>

// Ligh smart pointer
namespace SmartPointer
{
	template <class T>
	class SmartPointer
	{
	private:
		T* obj = nullptr;

	public:
		SmartPointer(T* _obj = nullptr);
		SmartPointer(SmartPointer&& _other)				noexcept;
		SmartPointer& operator=(SmartPointer&& _other)	noexcept;
		~SmartPointer()									noexcept;
	public:
		SmartPointer(const SmartPointer&)				= delete;
		SmartPointer& operator=(const SmartPointer&)	= delete;

	public:
		T& operator*() noexcept;
		T* operator->();

	public:
		T* Release();
		T* Get();
		void Reset();

	private:
		void clear();
	};

	// Implic {
	template<class T>
	inline SmartPointer<T>::SmartPointer(T* _obj) : obj{ _obj }
	{
	}

	template<class T>
	inline SmartPointer<T>::SmartPointer(SmartPointer&& _other) noexcept
	{
		if (this != &_other)
		{
			clear();

			obj = std::move(_other.obj);
			_other.obj = nullptr;
		}
	}

	template<class T>
	inline SmartPointer<T>& SmartPointer<T>::operator=(SmartPointer&& _other) noexcept
	{
		if (this != &_other)
		{
			clear();

			obj = std::move(_other.obj);
			_other.obj = nullptr;
		}

		return *this;
	}

	template<class T>
	inline SmartPointer<T>::~SmartPointer() noexcept
	{
		if (obj)
			delete obj;
	}

	template<class T>
	inline T& SmartPointer<T>::operator*() noexcept
	{
		return *obj;
	}

	template<class T>
	inline T* SmartPointer<T>::Release()
	{
		auto temp = std::move(obj);
		obj = nullptr;

		return temp;
	}

	template<class T>
	inline T* SmartPointer<T>::Get()
	{
		return obj;
	}


	template<class T>
	inline void SmartPointer<T>::Reset()
	{
		clear();
	}

	template<class T>
	inline T* SmartPointer<T>::operator->()
	{
		return obj;
	}
	template<class T>
	inline void SmartPointer<T>::clear()
	{
		if (obj)
			delete obj;
	}
	// Implic }
}






#endif

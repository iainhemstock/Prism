/*
 * Allocator.h
 * v1
 *
 *  Created on: Sep 15, 2016
 *      Author: iainhemstock
 */

#ifndef PRISM_ALLOCATOR_H_
#define PRISM_ALLOCATOR_H_

#include <utility> // for std::forward
#include <ostream>

namespace prism {

//================================================================
// AllocatorTraits
//================================================================
template <class Allocator>
struct AllocatorTraits {
	typedef Allocator							allocator_type;
	typedef typename Allocator::value_type 		value_type;
	typedef typename Allocator::pointer 		pointer;
	typedef typename Allocator::reference 		reference;
	typedef typename Allocator::const_pointer 	const_pointer;
	typedef typename Allocator::const_reference const_reference;
	typedef typename Allocator::size_type  		size_type;
	typedef typename Allocator::difference_type difference_type;

	static
	pointer
	allocate(Allocator& alloc, const size_type num) {
		return alloc.allocate(num);
	}

	static
	void
	deallocate(Allocator& alloc, pointer p) {
		alloc.deallocate(p);
	}

	static
	void
	destroy(Allocator& alloc, pointer p) {
		alloc.destroy(p);
	}

	template <typename ...Args>
	static
	void
	construct(Allocator& alloc, pointer p, Args&& ...args) {
		alloc.construct(p, args...);
	}
};
//================================================================
// Allocator
//================================================================
template <class T>
class Allocator {
public:
	typedef T 					value_type;
	typedef T*	 				pointer;
	typedef T& 					reference;
	typedef const T*	 		const_pointer;
	typedef const T&	 		const_reference;
	typedef size_t	 			size_type;
	typedef std::ptrdiff_t	 	difference_type;

	/*
	 * example usage (using an int allocator to create a String allocator):
	 * 	typedef typename Allocator<int>::template rebind<String>::other StringAllocator;
	 */
	template <class U>
	struct rebind { typedef Allocator<U> other; };

    struct propagate_on_container_copy_assignment
    : std::true_type
    {};

    struct propagate_on_container_move_assignment
    : std::true_type
    {};

    struct propagate_on_container_swap
    : std::true_type
    {};

	/*
	 *
	 */
	Allocator()
	{/* nothing to initialize */}

	/**
	 *
	 */
	Allocator(const Allocator<T>& copy)
	{/* nothing to copy */}

	/**
	 *
	 */
	template <class U>
	Allocator(const Allocator<U>& copy)
	{/* nothing to copy */}

	/**
	 *
	 */
	template <class U>
	Allocator(const Allocator<U>&& copy)
	{/* nothing to move */}

	/**
	 *
	 */
	virtual ~Allocator()
	{/* nothing to destruct */}

	/**
	 *
	 */
	pointer
	address(const_reference value)
	{ return &value; }

	/**
	 *
	 */
	const_pointer
	address(const_reference value) const
	{ return &value; }

	/**
	 *
	 */
	pointer
	allocate(const size_type num, const_pointer p=0) {
		pointer ptr = static_cast<pointer>(::operator new(num * sizeof(T)));
		return ptr;
	}

	/**
	 *
	 */
//	template <class U, typename ...Args>
	template <typename ...Args>
	void
	construct(pointer p, Args&& ...args)
	{ ::new (static_cast<void*>(p)) T(std::forward<Args>(args)...); }

	/**
	 *
	 */
	void
	deallocate(pointer p, const size_type num=0)
	{ ::operator delete(p); }

	/**
	 *
	 */
	void
	destroy(pointer p)
	{ p->~T(); }

	/**
	 *
	 */
	size_type
	max_size() const
	{ return static_cast<size_type>(-1) / sizeof(value_type); }

	/**
	 *
	 */
	template <class T2>
	const bool
	operator==(const Allocator<T2>& rhs)
	{ return true; }

	/**
	 *
	 */
	template <class T2>
	const bool
	operator!=(const Allocator<T2>& rhs)
	{ return false; }

	/**
	 *
	 */
	void operator=(const Allocator<T>& rhs)
	{/* nothing to copy*/}

	/**
	 *
	 */
	void operator=(const Allocator<T>&& rhs)
	{/* nothing to move*/}

	/**
	 *
	 */
	template <class U>
	void operator=(const Allocator<U>& rhs)
	{/* nothing to assign */}

	/**
	 *
	 */
	template <class U>
	void operator=(const Allocator<U>&& rhs)
	{/* nothing to move */}

	/**
	 *
	 */
    Allocator select_on_container_copy_construction(const Allocator &a)
    { return a; }
};

/**
 *
 */
template<class T>
bool
operator==(const Allocator<T> &a1, const Allocator<T> &a2)
{ return true; }

} /* namespace prism */

#endif /* PRISM_ALLOCATOR_H_ */











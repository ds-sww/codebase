#include "bits/stdc++.h"

/* since bits/stdc++.h is not recommended, and not portable.
 * I've included my own copy.
 */

#include "Iterable.h"
#include "Iterator.h"
#include "List.h"

template <typename T> class ArrayList;

class ArrayIndexOutOfBoundsException : public std::range_error {
	public:
		explicit ArrayIndexOutOfBoundsException(const std::string& what) : std::range_error(what) {}
};

class ContainerModifiedException : public std::logic_error {
	public:
		explicit ContainerModifiedException(const std::string& what) : std::logic_error(what) {}
};

template <typename T> class ArrayListIterator : public Iterator<T> {

	private:
		ArrayList<T> *owner;
		T* current_ptr;
		int _StartRevision;

	public:

		ArrayListIterator(ArrayList<T> *_owner) : owner(_owner) {
			current_ptr = owner -> _Container;
			_StartRevision = owner -> _Revision;
		}

		bool hasNext() {
			if (_StartRevision != owner -> _Revision)
				throw ContainerModifiedException(std::string("revision changed"));
			return current_ptr != owner -> _EndPos;
		}

		T next() {
			if (!hasNext())
				throw ArrayIndexOutOfBoundsException(std::string("no more elements"));
			return *(current_ptr ++);
		}
};


template <typename T> class ArrayList : public List<T> {

	public:

		T* _Container, *_Container_End;
		T* _EndPos;
		int _Revision;

		inline int _container_size() const {
			return _Container_End - _Container;
		}

		ArrayList(const int &size = 16) {
			_Container = new T[size];
			_Container_End = _Container + size;
			_EndPos = _Container;
			_Revision = 0;
		}

		~ArrayList() {
			delete[] _Container;
		}

		int size() const {
			return _EndPos - _Container;
		}

		bool isEmpty() const {
			return !size();
		}

		T get(int idx) const {
			if ((size_t)idx >= (size_t)size())
				throw ArrayIndexOutOfBoundsException(std::string("get out of bounds"));
			return _Container[idx];
		}

		void add(T elem) {
			++ _Revision;
			if (_EndPos == _Container_End) { /* reallocation required. */
				int current_size = this -> size();
				T* _new_container = new T[current_size << 1];
				std::copy(_Container, _EndPos, _new_container);
				delete[] _Container;
				_Container = _new_container;
				_Container_End = _new_container + (current_size << 1);
				_EndPos = _Container + current_size;
				assert(_EndPos < _Container_End);
			}
			*(_EndPos ++) = elem;
		}

		T remove(int idx) {
			++ _Revision;
			if ((size_t)idx >= (size_t)size())
				throw ArrayIndexOutOfBoundsException(std::string("remove out of bounds"));
			std::copy(_Container + idx + 1, _EndPos, _Container + idx);
			-- _EndPos;
			if ( (size() << 2) < _container_size() && (size() > 4) ) {
				/* reduce container size */
				int current_size = this -> size();
				T* _new_container = new T[current_size << 1];
				std::copy(_Container, _EndPos, _new_container);
				delete[] _Container;
				_Container = _new_container;
				_Container_End = _new_container + (current_size << 1);
				_EndPos = _Container + current_size;
				assert(_EndPos < _Container_End);
			}
		}

		Iterator<T> *iterator() {
			return new ArrayListIterator<T>(this);
		}
};

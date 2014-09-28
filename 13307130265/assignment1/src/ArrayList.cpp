
/**
 * @author whimsycwd
 * @date   2014.9.26
 * 类似Vector
 */
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cassert>
#include "List.h"

using namespace std;

template <typename T>
class ArrayList : public List<T> {

	private:
		int list_size;
		int capicity;
		T *array;
		int revision;
		const static int init_capicity = 32;
		
		void range_check(const int &index) const {
			assert(index >= 0 && index < list_size);
		}
		// WTF vector implements so slow !?
		
		void expandMemory(const int &size) {
			if (size <= capicity) return;
			
			capicity *= 2;
			T *new_array = new T[capicity];
			memcpy(new_array, array, (sizeof(array[0])*size));
			delete [] array;
			array = new_array;
		}
		
		void shrinkMemory(const int &size) {
			if (size >= capicity/2) return;
			if (capicity == init_capicity) return;
			
			capicity >>= 1;
			T *new_array = new T[capicity];
			memcpy(new_array, array, (sizeof(array[0])*list_size));
			delete [] array;
			array = new_array;
		}
	public:
		Iterator<T> *iterator() {
			return new ArrayListIterator<T> (this, array, revision);
		}
		ArrayList(){
			list_size = 0;
			capicity = init_capicity;
			array = new T[capicity];
			revision = 0;
		}
		ArrayList(const int &size) : list_size(size) {
			capicity = max(init_capicity, (1<<(32-__builtin_clz(size))));
			array = new T[capicity];
			memset(array, 0, sizeof(array[0])*list_size);
			revision = 0;
		}
		int size() const {
			return list_size;
		}
		bool isEmpty() const {
			return list_size == 0;
		}
		void add(const T &element) {
			++revision;
			
			expandMemory(list_size+1);
			array[list_size++] = element;
		}
		T get(const int &index) const {
			range_check(index);
			return array[index];
		}
		T remove(const int &index) {
			++revision;
			
			range_check(index);
			T res = array[index];
			for (int x = index; x+1 < list_size; ++x) array[x] = array[x+1];
			shrinkMemory(--list_size);
			return res;
		}
		~ArrayList() {
			delete [] array;
		}
		
		template<typename E>
		class ArrayListIterator : public Iterator<E> {
			private:
				ArrayList *owner;
				T *cur;
				int revision;
			public:
				ArrayListIterator(){}
				ArrayListIterator(ArrayList<T> *owner, T *cur, int revision) : owner(owner), cur(cur), revision(revision) {}
				bool hasNext() {
//					assert(revision == owner->revision);
					if (revision != owner->revision) {
						throw logic_error("the ArrayList HAS been changed");
					}
					return (cur != (owner->array+owner->list_size-1));
				}
				T next() {
					return *cur++; 
				}
		};
};


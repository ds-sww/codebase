
/**
 * @author whimsycwd
 * @date   2014.9.26
 * 类似Vector
 */
#include <iostream>
#include <cassert>
#include "List.h"

using namespace std;

template <typename T>
class ArrayList : public List<T> {

	private:
		int list_size;
		int capicity;
		int revision;
		T *array;
		const static int init_capicity = 32;
		
		void range_check(int index) const {
			assert(index >= 0 && index < list_size);
		}
		// WTF vector implements so slow !?
		
		void expandMemory(int size) {
			if (size <= capicity) return;
			
			capicity *= 2;
			T *new_array = new T[capicity];
			memcpy(new_array, array, (sizeof(array[0])*size));
			delete [] array;
			array = new_array;
		}
		
		void shrinkMemory(int size) {
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
			return &Iterator(this, array, revision);
		}
		ArrayList(){
			list_size = 0;
			capicity = init_capicity;
			array = new T[capicity];
			revision = 0;
		}
		ArrayList(int size) : list_size(size) {
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
		void add(T element) {
			expandMemory(list_size+1);
			array[list_size++] = element;
		}
		T get(int index) const {
			range_check(index);
			return array[index];
		}
		T remove(int index) {
			range_check(index);
			T res = array[index];
			for (int x = index; x+1 < list_size; ++x) array[x] = array[x+1];
			shrinkMemory(--list_size);
			return res;
		}
		~ArrayList() {
			delete [] array;
		}
};
template<typename T>
class Iterator : public Iterator<T> {
	private:
		ArrayList *owner;
		T *cur;
		int revision;
	public:
		Iterator(ArrayList *owner, T *cur, int revision) : owner(owner), cur(cur), revision(revision) {}
		bool hasNext() {
			assert(revision == owner->revision);
			return (cur != (onwer->array+onwer->list_size-1));
		}
		T next() {
			return *cur++; 
		}
};


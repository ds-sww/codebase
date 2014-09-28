
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
class ArrayList {

	private:
		int list_size;
		int capicity;
		T *array;
		const static int init_capicity = 32;
		
		
		void range_check(int index) {
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
		ArrayList(){
			list_size = 0;
			capicity = init_capicity;
			array = new T[capicity];
		}
		ArrayList(int size) : list_size(size) {
			capicity = max(init_capicity, (1<<(32-__builtin_clz(size))));
			array = new T[capicity];
			memset(array, 0, sizeof(array[0])*list_size);
		}
		int size() {
			return list_size;
		}
		bool isEmpty() {
			return list_size == 0;
		}
		void add(T &x) {
			expandMemory(list_size+1);
			array[list_size++] = x;
		}
		T get(int index) {
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

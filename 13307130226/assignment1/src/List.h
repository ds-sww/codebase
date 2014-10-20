/**
 *  @author whimsycwd
 *  @date   2014.9.26
 *
 *  List Interface
 */

template <typename T>
class List {
    


    public :
        virtual int size() const = 0;
        virtual bool isEmpty() const = 0;
        virtual T get(int index) const = 0;
        virtual void add(const T& element) = 0;
        virtual T remove(int index) = 0;

};


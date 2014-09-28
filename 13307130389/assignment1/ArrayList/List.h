/**
 *  @author whimsycwd
 *  @date   2014.9.26
 *
 *  List Interface
 */

/*
    update by xiaoguai0992
    date 2014.9.28
*/
template <typename T>
class List {
    


    public :
        virtual int size() const = 0;
        virtual bool isEmpty() const = 0;
        virtual T get(int index) const = 0;
        virtual void add(T element) = 0;
        virtual T remove(int index) = 0;

};


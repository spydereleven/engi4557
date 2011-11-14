#ifndef __SCOPEDPTR_H__
#define __SCOPEDPTR_H__

template<class T>
class ScopedPtr
{
  public:
    ScopedPtr(T* ptr, bool is_array = false)
        : _is_array(is_array)
    {
      _ptr = ptr;
    }

    ~ScopedPtr()
    {
      // Upon destruction, delete the pointer
      if (_ptr)
      {
        if (_is_array)
        {
          delete[] _ptr; // alloc'd using new[]
        }
        else
        {
          delete _ptr; // alloc'd using new
        }
      }
    }

  bool operator==(T* ptr) const { return _ptr == ptr; }
  bool operator==(ScopedPtr<T> const &sptr) const { return _ptr == sptr._ptr; }

  bool operator!=(T* ptr) const { return _ptr != ptr; }
  bool operator!=(ScopedPtr<T> const &sptr) const { return _ptr != sptr._ptr; }

  T* const& operator->() { return _ptr; }

  private:
    bool _is_array;
    T *_ptr; 
};

#endif

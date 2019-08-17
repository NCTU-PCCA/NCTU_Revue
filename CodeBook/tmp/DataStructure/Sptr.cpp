template <typename T> struct Sptr{
  pair<T, int> *p;
  T *operator->(){return &p->F;}
  T &operator*(){return p->F;}
  operator pair<T, int>*(){return p;}
  Sptr &operator = (const Sptr& t){
    if (p && !--p->S) delete p;
    (p = t.p) && ++p->S;
    return *this;
  }
  Sptr(pair<T, int> *t = 0) : p(t){ p && ++p->S;}
  Sptr(const Sptr &t) : p(t.p) { p && ++p->S; }
  ~Sptr(){ if (p && !--p->S) delete p; }
};

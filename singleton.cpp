#include <cstdio>

// Зачем нужен typename?
template<typename T> static T *m;

// Зачем нужен typename?
template<typename T>
void set_singleton(T *mm) {
    m<T> = mm; // variable template
}

// Зачем нужен typename?
template<typename T>
T *get_singleton() {
    return m<T>;
}

class A {
    public:
        int x = {4};
};

class B {
    public:
        int x = {6};
};

void foo() {
    A *a = get_singleton<A>();
    B *b = get_singleton<B>();

    printf("a %d\n", a->x);
    printf("b %d\n", b->x);
}

int main() {
    A *a = new A();
    B *b = new B();

    set_singleton(a);
    set_singleton(b);

    foo();

    delete a; delete b;
}

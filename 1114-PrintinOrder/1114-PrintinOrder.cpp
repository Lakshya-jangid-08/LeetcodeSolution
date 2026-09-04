// Last updated: 9/4/2026, 9:23:24 PM
1class Foo {
2public:
3    atomic<int> v{0};
4
5    void first(function<void()> printFirst) {
6        while(v != 0) {}
7        printFirst();
8        v = 1;
9    }
10
11    void second(function<void()> printSecond) { 
12        while(v != 1) {}
13        printSecond();
14        v = 2;
15    }
16
17    void third(function<void()> printThird) {
18        while(v != 2) {}
19        printThird();
20        v = 3;
21    }
22};